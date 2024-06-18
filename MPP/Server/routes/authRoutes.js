const express = require('express');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcrypt');
const { getUserByUsername, createUser } = require('../repository/userRepo');
const router = express.Router();

const secretKey = 'secretKey';

router.post('/register', async (req, res) => {
    const { username, password, email } = req.body;
    const hashedPassword = await bcrypt.hash(password, 10);
    try {
        await createUser(username, hashedPassword, email);
        res.status(201).send({ message: 'User created successfully' });
    } catch (error) {
        res.status(500).send({ error: 'A user with this username already exists!' });
    }
});

router.post('/login', async (req, res) => {
    const { username, password } = req.body;
    try {
        const user = await getUserByUsername(username);

        if (!user) {
            return res.status(401).send({ error: 'Invalid credentials' });
        }

        const isPasswordValid = await bcrypt.compare(password, user.password);
        if (!isPasswordValid) {
            return res.status(401).send({ error: 'Invalid credentials' });
        }

        const userDetails = { username: user.username, email: user.email };
        const token = jwt.sign({ username: user.username }, secretKey, { expiresIn: '1m' });
        const decodedToken = jwt.decode(token);

        res.status(200).send({
            token,
            user: userDetails,
            expiresAt: new Date(decodedToken.exp * 1000).toISOString() // Send as ISO string
        });
    } catch (error) {
        res.status(500).send({ error: 'Login failed' });
    }
});

router.get('/user', async (req, res) => {
    const token = req.headers.authorization;

    if (!token || !token.startsWith('Bearer ')) {
        return res.status(401).json({ error: 'Invalid token format' });
    }

    const tokenString = token.split(' ')[1]; // Extract token string from "Bearer <token>"

    jwt.verify(tokenString, secretKey, async (err, decoded) => {
        if (err) {
            return res.status(401).json({ error: 'Invalid token' });
        }

        try {
            const user = await getUserByUsername(decoded.username);
            if (!user) {
                return res.status(404).json({ error: 'User not found' });
            }
            const tokenExpirationDate = new Date(decoded.exp * 1000).toISOString(); // Send as ISO string
            res.status(200).json({ user, expiresAt: tokenExpirationDate });
        } catch (error) {
            res.status(500).json({ error: 'Internal server error' });
        }
    });
});

module.exports = router;
