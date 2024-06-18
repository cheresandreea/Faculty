import React, {useState} from 'react';
import {Button, Grid, TextField} from "@mui/material";
import {addCollar, addReview} from "../CollarReducer";
import {useDispatch, useSelector} from "react-redux";
import {useNavigate, useParams} from "react-router-dom";
import axios from "axios";

function CreateReview() {
    const { id } = useParams();
    const [customer_name, setCustomerName] = useState('');
    const [description, setDescription] = useState('');
    const [stars, setStars] = useState('');
    const [error, setError] = useState('');

    const reviews = useSelector((state) => state.collars.dataReviews);

    const dispatch = useDispatch();
    const navigate = useNavigate();


    const handleSubmit = async (event) => {
        event.preventDefault();
        // Perform client-side validation
        if (!customer_name || !description || !stars) {
            setError('All fields are required');
            return;
        }

        if (isNaN(parseInt(stars)) || stars < 1 || stars > 5) {
            setError("Error: Stars must be a number between 1 and 5");
            return;
        }

        try {
            const newId = reviews.length > 0 ? reviews[reviews.length - 1].id + 1 : 1;
            await axios.post(`http://localhost:4000/collars/reviews/create/${id}`, {
                id: newId,
                product_id: id,
                customer_name,
                description,
                stars,
            });
            dispatch(addReview({
                id: newId,
                product_id: id,
                customer_name,
                description,
                stars
            }));

        }catch (error) {
            setError('Error adding review: ' + error.message);
            return;
        }

        navigate('/');
    }


    return (
        <div>
            <h2>PawsInStyle</h2>
            <h2>Add new review</h2>
            <Grid container justifyContent="center">
                <Grid>
                    <form onSubmit={handleSubmit} style={{ margin: '5rem' }}>
                        <TextField
                            label="Description"
                            type="text"
                            value={description}
                            onChange={(e) => setDescription(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Description"
                            style={{ marginBottom: '10px' }}
                        />

                        <TextField
                            label="Stars"
                            type="text"
                            value={stars}
                            onChange={(e) => setStars(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Stars"
                            style={{ marginBottom: '10px' }}
                        />

                        <TextField
                            label="Customer Name"
                            type="text"
                            value={customer_name}
                            onChange={(e) => setCustomerName(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Customer Name"
                            style={{ marginBottom: '10px' }}
                        />

                        <Button
                            type="submit"
                            variant="contained"
                            color="primary"
                            fullWidth
                        >
                            Submit
                        </Button>
                        {error && <div className="error-message">{error}</div>}
                    </form>
                </Grid>
            </Grid>
        </div>
    )
}

export default CreateReview;
