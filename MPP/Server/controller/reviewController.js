
const {getAllReviewsFromRepo, editReviewFromRepo, deleteReviewFromRepo, addReviewFromRepo} = require("../repository/reviewRepo");


let allReviews = [];

getAllReviewsFromController = async (req, res) => {
    try {
        allReviews = await getAllReviewsFromRepo();
        res.status(200).json(allReviews);
    } catch (error) {
        console.error('Error in getAllReviews controller:', error);
        res.status(500).json({error: 'Internal Server Error'});
    }
}

editReviewFromController = (req, res) => {
    const { id } = req.params;
    const {description, stars } = req.body;
    const index = allReviews.findIndex((review) => review.id === parseInt(id));

    if(!description || !stars){
        return res.status(400).json({ error: 'All fields are required' });
    }
    if(isNaN(parseInt(stars)) || stars < 1 || stars > 5){
        return res.status(400).json({ error: 'Stars must be a number between 1 and 5' });
    }

    if (index !== -1) {
        editReviewFromRepo({ id: parseInt(id), description, stars})
        res.status(200).json({ message: 'Review updated successfully' });
    } else {
        res.status(404).json({ message: 'Review not found' });
    }

}

deleteReviewFromController = async (req, res) => {
    const { id } = req.params;
    const index = allReviews.findIndex((review) => review.id === parseInt(id));
    if (index !== -1) {
        allReviews.splice(index, 1); // Remove the review at the found index
        await deleteReviewFromRepo({id: parseInt(id)});
        res.status(200).json({ message: 'Review deleted successfully' });
    } else {
        res.status(404).json({ message: 'Review not found' });
    }

}

addReviewFromController = async (req, res) => {
    const { id, product_id, customer_name, description, stars } = req.body;
    if (!product_id || !customer_name || !description || !stars) {
        return res.status(400).json({ error: 'All fields are required' });
    }
    if (isNaN(parseInt(stars)) || stars < 1 || stars > 5) {
        return res.status(400).json({ error: 'Stars must be a number between 1 and 5' });
    }

    allReviews.push({ id, product_id, customer_name, description, stars });
    await addReviewFromRepo({ id, product_id, customer_name, description, stars });
    res.status(201).json({ message: 'Review added successfully' });
}

module.exports = {
    getAllReviewsFromController,
    editReviewFromController,
    deleteReviewFromController,
    addReviewFromController
}