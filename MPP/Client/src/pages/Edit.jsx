import {Button, Grid, TextField} from "@mui/material";
import React, {useEffect, useState} from "react";
import {useNavigate, useParams} from "react-router-dom";
import {useSelector} from "react-redux";
import {useDispatch} from "react-redux";
import {editCollar} from "../CollarReducer";
import store from "../index";
import axios from "axios";

function Edit() {
    const { id } = useParams();

    const dispatch = useDispatch();
    const collars = useSelector((state) => state.collars.dataCollars)

    const existingCollar = collars.find((collar) => collar.id == id);

    const navigate = useNavigate();

    const [ctitle, setTitle] = useState("");
    const [cdescription, setDescription] = useState("");
    const [cmaterial, setMaterial] = useState("");
    const [cprice, setPrice] = useState("");
    const [cstars, setStars] = useState("");
    const [error, setError] = useState('');

    useEffect(() => {
        // Set initial state when the existing collar is available
        if (existingCollar) {
            const { title, description, material, price, stars } = existingCollar;
            setTitle(title);
            setDescription(description);
            setMaterial(material);
            setPrice(price);
            setStars(stars);
        }
    }, [existingCollar]);


    const handleSubmit = async (event) => {
        event.preventDefault();
        try {
            if (!ctitle || !cdescription || !cmaterial || !cprice || !cstars) {
                setError('All fields are required');
                return;
            }

            const parsedPrice = parseFloat(cprice);
            if (isNaN(parsedPrice) || parsedPrice <= 0) {
                setError("Error: Price must be a positive number");
                return;
            }

            if (isNaN(parseInt(cstars)) || cstars < 1 || cstars > 5) {
                setError("Error: Stars must be a number between 1 and 5");
                return;
            }
            await axios.put(`http://localhost:4000/collars/edit/${id}`,{
                    title: ctitle,
                    description: cdescription,
                    material: cmaterial,
                    price: cprice,
                    stars: cstars,
            });
            dispatch(
                editCollar({
                    id,
                    title: ctitle,
                    description: cdescription,
                    material: cmaterial,
                    price: cprice,
                    stars: cstars,
                })
            );

        }catch (error) {
            console.error("Error editing collar:", error);
        }
        navigate('/')
    };
    console.log('Updated Redux Store State1:', store.getState().collars.dataCollars);


    return (
        <div>
            <h2>PawsInStyle</h2>
            <h2>Edit collar</h2>
            <Grid container justifyContent="center">
                <Grid>
                    <form onSubmit={handleSubmit} style={{margin: '5rem'}}>
                        <TextField
                            label="Title"
                            type="text"
                            value={ctitle}
                            onChange={e => setTitle(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Title"
                            style={{marginBottom: '10px'}}
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
                            label="Material"
                            type="text"
                            value={cmaterial}
                            onChange={e => setMaterial(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Material"
                            style={{marginBottom: '10px'}}
                        />
                        <TextField
                            label="Price"
                            type="text"
                            value={cprice}
                            onChange={e => setPrice(e.target.value)}
                            fullWidth
                            margin="normal"
                            variant="outlined"
                            placeholder="Price"
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

export default Edit;