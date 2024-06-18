const express = require('express')
const {response} = require("express");
const router = express.Router()
const collarController = require('../controller/collarController');
const reviewController = require('../controller/reviewController');



router.get('/reviews', reviewController.getAllReviewsFromController);
router.get('/', collarController.getAllCollars1);
router.get('/:id', collarController.getCollarByIdFromController);


router.put('/edit/:id', collarController.editCollarFromController);
router.put('/reviews/edit/:id', reviewController.editReviewFromController);

router.delete('/delete/:id', collarController.deleteCollarFromController);
router.delete('/reviews/delete/:id', reviewController.deleteReviewFromController);

router.post('/create', collarController.addCollarFromController);
router.post('/reviews/create/:id', reviewController.addReviewFromController);




module.exports = router;