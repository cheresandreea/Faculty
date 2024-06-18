const { getAllCollarsFromRepo, deleteCollarFromRepo, addCollarFromRepo, editCollarFromRepo,
    getCollarByIdFromRepo
} = require('../repository/collarRepo');
const {populateDataBaseRepo} = require("../repository/collarRepo")

let allCollars = [];

async function populateDataBaseController() {
    try {
        await populateDataBaseRepo();
        console.log('Database populated successfully from controller');
    } catch (error) {
        console.error('Error populating database from controller:', error);
        throw error;
    }
}

getAllCollars1 = async (req, res) => {
    try {
        allCollars = await getAllCollarsFromRepo();
        res.status(200).json(allCollars);
    } catch (error) {
        console.error('Error in getAllCollars controller:', error);
        res.status(500).json({error: 'Internal Server Error'});
    }
};


getCollarByIdFromController = (req, res) => {
    getCollarByIdFromRepo(req, res);
};

deleteCollarFromController = async (req, res) => {
    const { id } = req.params;
    const index = allCollars.findIndex((collar) => collar.id === parseInt(id));
    if (index !== -1) {
        allCollars.splice(index, 1); // Remove the collar at the found index
        await deleteCollarFromRepo({id: parseInt(id)});
        res.status(200).json({ message: 'Collar deleted successfully' });
    } else {
        res.status(404).json({ message: 'Collar not found' });
    }
};

editCollarFromController = (req, res) => {
    const { id } = req.params;
    const {title, description, material, price, stars } = req.body;
    const index = allCollars.findIndex((collar) => collar.id === parseInt(id));

    // Check if all fields are provided
    if (!title || !description || !material || !price || !stars) {
        return res.status(400).json({ error: 'All fields are required' });
    }

    // Validate price
    const parsedPrice = parseFloat(price);
    if (isNaN(parsedPrice) || parsedPrice <= 0) {
        return res.status(400).json({ error: 'Price must be a positive number' });
    }

    // Validate stars
    const parsedStars = parseInt(stars);
    if (isNaN(parsedStars) || parsedStars < 1 || parsedStars > 5) {
        return res.status(400).json({ error: 'Stars must be a number between 1 and 5' });
    }

    // Update the collar if found
    if (index !== -1) {
        editCollarFromRepo({ id: parseInt(id), title, description, material, price: parsedPrice, stars: parsedStars });
        res.status(200).json({ message: 'Collar updated successfully' });
    } else {
        // Collar not found
        return res.status(404).json({ error: 'Collar not found' });
    }
}

addCollarFromController = (req, res) => {
    const { id, title, price, description, material, stars } = req.body;
    if (!title || !description || !material || !price || !stars) {
        return res.status(400).json({ error: 'All fields are required' });
    }

    const parsedPrice = parseFloat(price);
    if (isNaN(parsedPrice) || parsedPrice <= 0) {
        return res.status(400).json({ error: 'Price must be a positive number' });
    }

    if (isNaN(parseInt(stars)) || stars < 1 || stars > 5) {
        return res.status(400).json({ error: 'Stars must be a number between 1 and 5' });
    }

    addCollarFromRepo({ id, title, price, description, material, stars });
    res.status(201).json({ message: 'Collar added successfully' });
}

module.exports = {
    populateDataBaseController,
    getAllCollars1,
    deleteCollarFromController,
    editCollarFromController,
    addCollarFromController,
    getCollarByIdFromController,
};