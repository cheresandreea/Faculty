// repository/userRepo.js

const sql = require('mssql');
const {connectToDatabase} = require("./database");
const getUserByUsername = async (username) => {
    try {
        const request = new sql.Request();
        request.input('username', sql.VarChar, username);
        const result = await request.query("SELECT * FROM Users WHERE username = @username");
        return result.recordset[0];
    } catch (error) {
        console.error('Error retrieving user by username:', error);
        throw error;
    }
};

const createUser = async (username, hashedPassword, email) => {
    try {
        const request = new sql.Request();
        const existingUserQuery = `
            SELECT COUNT(*) AS count FROM Users WHERE username = '${username}'`;
        const { recordset } = await request.query(existingUserQuery);
        const existingUserCount = recordset[0].count;
        if (existingUserCount > 0) {
            throw new Error('User with the same username already exists');
        }

        const query = `
            INSERT INTO Users (username, password, email) 
            VALUES ('${username}', '${hashedPassword}', '${email}')`;
        await request.query(query);
    } catch (error) {
        console.error('Error creating user:', error);
        throw error;
    }
};

module.exports = {
    getUserByUsername,
    createUser
};
