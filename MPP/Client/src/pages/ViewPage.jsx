import {Button, Grid, Typography} from "@mui/material";
import {Link, useNavigate, useParams} from "react-router-dom";
import React, {useEffect, useState} from "react";
import axios from "axios";

function View(){
    const {id} = useParams();
    const [collarDetails, setCollarDetails] = useState({
        id: "",
        title: "",
        description: "",
        material: "",
        price: "",
        stars: ""
    });
    const navigate = useNavigate();

    useEffect(() => {
        const fetchCollarDetails = async () => {
            try{
                const response = await axios.get(`https://mpp-backend-425314.lm.r.appspot.com/collars/${id}`);
                setCollarDetails(response.data);

            }catch (error){
                console.error("Error fetching collar details:", error);
            }
        }

        fetchCollarDetails();
    }, [id]);
    const handleBack = () => {
        navigate('/');
    };

    const { title, description, material, price, stars } = collarDetails;
    return (
        <div>
            <h2>Collar Details</h2>
            <Grid>
                <Typography>Title: {title}</Typography>
                <Typography>Description: {description}</Typography>
                <Typography>Material: {material}</Typography>
                <Typography>Price: {price}</Typography>
                <Typography>Stars: {stars}</Typography>
                <Button onClick={handleBack}>Back</Button>
                <Link to={`/collars/reviews/create/${id}`}>
                    <Button sx={{ background: '#5D9C59', color: 'white' }}>Add a review for this product</Button>
                </Link>
            </Grid>
        </div>
    )
}

export default View;