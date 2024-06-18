const jwt = require('jsonwebtoken');
const secretKey = 'secretKey'

const authenticateToken = (req, res, next) => {
    const token = req.headers['authorization'];
    if (!token) {
        return res.status(401).send({error: 'No token provided'});
    }
    jwt.verify(token, secretKey, (error, decoded) => {
        if (error) {
            return res.status(401).send({error: 'Invalid token'});
        }
        req.user = decoded;
        next();
    });
}

module.exports = authenticateToken;