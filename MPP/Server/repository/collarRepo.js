
const sql = require('mssql');
const {connectToDatabase} = require("./database");
let generatedCollars = require('../models/GeneratedCollars')(); // Call the function directly


// Function to retrieve all collars from the database
const getAllCollarsFromRepo = async (review) => {
    try {
        const request = new sql.Request();
        const result = await request.query("SELECT * FROM Product");
        return result.recordset;
    } catch (error) {
        console.error('Error retrieving collars:', error);
        throw error;
    }
};

populateDataBaseRepo = async () =>{
    try {
        await connectToDatabase(); // Establish database connection
        for (const collar of generatedCollars) {
            await editCollarFromRepo(collar);
        }

    } catch (error) {
        console.error('Error:', error);
    }
}

const editCollarFromRepo = async (collar) => {
    try {
        const request = new sql.Request();
        await request.query(
            `UPDATE Product SET title = '${collar.title}', price = ${collar.price}, description = '${collar.description}', stars = ${collar.stars}, material = '${collar.material}' WHERE id = ${collar.id}`
          );
    } catch (error) {
        console.error('Error adding collar:', error);
        throw error;
    }

}
const deleteCollarFromRepo = async (collar) => {
    try{
        const request = new sql.Request();
        await request.query(`DELETE FROM Product WHERE id = ${collar.id}`);
    } catch (error){
        console.error('Error deleting collar:', error);
        throw error;
    }
}
const addCollarFromRepo = async (collar) => {
    try {
        const request = new sql.Request();
        await request.query(`
            INSERT INTO Product (id, title, price, description, stars, material, administrator_id, create_date) 
            VALUES ('${collar.id}', '${collar.title}', ${collar.price}, '${collar.description}', ${collar.stars}, '${collar.material}', null, null)
        `);
    } catch (error) {
        console.error('Error adding collar:', error);
        throw error;
    }

}

const getCollarByIdFromRepo = async (req, res) => {
    const { id } = req.params;
    try {
        const request = new sql.Request();
        const result = await request.query(`SELECT * FROM Product WHERE id = ${id}`);
        if (result.recordset.length === 0) {
            res.status(404).json({ message: 'Collar not found' });
        } else {
            res.status(200).json(result.recordset[0]);
        }
    } catch (error) {
        console.error('Error retrieving collar:', error);
        res.status(500).json({ error: 'Internal Server Error' });
    }
}



module.exports= {
    sql,
    populateDataBaseRepo,
    getAllCollarsFromRepo,
    connectToDatabase,
    deleteCollarFromRepo,
    editCollarFromRepo,
    addCollarFromRepo,
    getCollarByIdFromRepo,
}

