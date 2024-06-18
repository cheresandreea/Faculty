const sql = require('mssql');

const config = {
    user: "userMPP",
    password: "123",
    server: "192.168.1.225",
    port: 1235,
    database: "DogCollarsShop",
    options: {
        trustedConnection: true,
        encrypt: false
    }
}

// Export a function to establish the database connection
const connectToDatabase = async () => {
    try {
        await sql.connect(config);
        console.log("Connected to database");
    } catch (error) {
        console.error('Error connecting to database:', error);
        throw error; // Re-throw the error to be caught by the caller
    }
};

module.exports = {
    config,
    connectToDatabase,
}