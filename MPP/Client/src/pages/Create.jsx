import React, {useState} from 'react';
import {Button, Grid, TextField} from "@mui/material";
import {addCollar} from "../CollarReducer";
import {useDispatch, useSelector} from "react-redux";
import {useNavigate} from "react-router-dom";
import axios from "axios";


function Create() {
    const [title, setTitle] = useState('');
    const [description, setDescription] = useState('');
    const [material, setMaterial] = useState('');
    const [price, setPrice] = useState('');
    const [stars, setStars] = useState('');
    const [error, setError] = useState('');

    const collars = useSelector((state) => state.collars.dataCollars);

    const dispatch = useDispatch();
    const navigate = useNavigate()


    const handleSubmit = async (event) => {
        event.preventDefault();
        // Perform client-side validation
        if (!description || !material || !price || !stars) {
            setError('All fields are required');
            return;
        }

        const parsedPrice = parseFloat(price);
        if (isNaN(parsedPrice) || parsedPrice <= 0) {
            setError("Error: Price must be a positive number");
            return;
        }
        //
        if (isNaN(parseInt(stars)) || stars < 1 || stars > 5) {
            setError("Error: Stars must be a number between 1 and 5");
            return;
        }

        try {
            const newId = collars.length > 0 ? collars[collars.length - 1].id + 1 : 1;
            await axios.post('https://mpp-backend-425314.lm.r.appspot.com/collars/create', {
                id: newId,
                title: title,
                price: price,
                description: description,
                material: material,
                stars: stars,
            });
            dispatch(addCollar({
                id: collars[collars.length - 1].id + 1,
                title,
                description,
                material,
                price,
                stars
            }));

        }catch (error) {
            setError('Error adding collar: ' + error.message);
            return;
        }

        navigate('/');
    }


    return (
        <div>
            <h2>PawsInStyle</h2>
            <h2>Add new collar</h2>
            <Grid container justifyContent="center">
                <Grid>
                    <form onSubmit={handleSubmit} style={{ margin: '5rem' }}>
                        <TextField
                            label="Title"
                            type="text"
                            value={title}
                            onChange={(e) => setTitle(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Title"
                            style={{ marginBottom: '10px' }}
                        />

                        <TextField
                            label="Price"
                            type="text"
                            value={price}
                            onChange={(e) => setPrice(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Price"
                            style={{ marginBottom: '10px' }}
                        />
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
                            label="Material"
                            type="text"
                            value={material}
                            onChange={(e) => setMaterial(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Material"
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

export default Create;
