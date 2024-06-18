import {Button, Grid, TextField} from "@mui/material";
import React, {useEffect, useState} from "react";
import {useNavigate, useParams} from "react-router-dom";
import {useSelector} from "react-redux";
import {useDispatch} from "react-redux";
import {editCollar, editReview} from "../CollarReducer";
import store from "../index";
import axios from "axios";

function EditReview() {
    const { id } = useParams();

    const dispatch = useDispatch();
    const reviews = useSelector((state) => state.collars.dataReviews)

    const existingReview = reviews.find((review) => review.id == id);

    const navigate = useNavigate();

    const [cproduct_name, setProductName] = useState("");
    const [cdescription, setDescription] = useState("");
    const [cstars, setStars] = useState("");
    const [error, setError] = useState('');

    useEffect(() => {
        // Set initial state when the existing collar is available
        if (existingReview) {
            const { product_name, description, stars } = existingReview;
            setProductName(product_name);
            setDescription(description);
            setStars(stars);
        }
    }, [existingReview]);


    const handleSubmit = async (event) => {
        event.preventDefault();
        try {
            if (!cdescription || !cstars) {
                setError('All fields are required');
                return;
            }

            if (isNaN(parseInt(cstars)) || cstars < 1 || cstars > 5) {
                setError("Error: Stars must be a number between 1 and 5");
                return;
            }
            await axios.put(`http://localhost:4000/collars/reviews/edit/${id}`,{
                description: cdescription,
                stars: cstars,
            });
            dispatch(
                editReview({
                    id,
                    description: cdescription,
                    stars: cstars,
                })
            );

        }catch (error) {
            console.error("Error editing collar:", error);
        }
        navigate('/reviews')
    };

    return (
        <div>
            <h2>PawsInStyle</h2>
            <h2>Edit collar</h2>
            <Grid container justifyContent="center">
                <Grid>
                    <form onSubmit={handleSubmit} style={{margin: '5rem'}}>
                        <TextField
                            label="Product Name"
                            type="text"
                            value={cproduct_name}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Product Name"
                            style={{marginBottom: '10px'}}
                            readOnly
                        />
                        <TextField
                            label="Description"
                            type="text"
                            value={cdescription}
                            onChange={e => setDescription(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Description"
                            style={{marginBottom: '10px'}}
                        />
                        <TextField
                            label="Stars"
                            type="text"
                            value={cstars}
                            onChange={e => setStars(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Stars"
                            style={{marginBottom: '10px'}}
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

export default EditReview;