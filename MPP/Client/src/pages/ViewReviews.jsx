import React, { useEffect, useState } from 'react';
import {useDispatch, useSelector} from "react-redux";
import axios from "axios";
import {deleteReview, fetchReviews} from "../CollarReducer";
import {
    Button, MenuItem,
    Pagination,
    PaginationItem,
    Select,
    Table,
    TableBody,
    TableCell,
    TableHead,
    TableRow
} from "@mui/material";
import {Link} from "react-router-dom";

function ViewReviews() {
    const reviews = useSelector((state) => state.collars.dataReviews);
    const dispatch = useDispatch();
    const loading = useSelector((state) => state.collars.loading);
    const error = useSelector((state) => state.collars.error);
    const [serverError, setServerError] = useState('');

    useEffect(() => {
        const checkServerStatus = async () => {
            if (!navigator.onLine) {
                setServerError('No internet connection. Please check your network.');
                return;
            }

            try {
                await axios.get('http://localhost:4000/collars/reviews');
            } catch (error) {
                setServerError('Server is down. Please try again later.')
            }
        };

        checkServerStatus();

        dispatch(fetchReviews());
    }, [dispatch]); // Dependency array includes dispatch

    console.log(reviews);
    const handleDelete = async (id) => {
        const confirmed = window.confirm("Are you sure you want to delete?");
        if (confirmed) {
            try {
                await axios.delete(`http://localhost:4000/collars/reviews/delete/${id}`);
                dispatch(deleteReview({id: id}));
            } catch (error) {
                console.error("Error deleting collar:", error);
            }
        }

    }

    const sortedReviews = [...reviews]; // Create a copy of the reviews array

    sortedReviews.sort((a, b) => {
        return a.product_name.localeCompare(b.product_name)
    });


    const [currentPage, setCurrentPage] = useState(1);
    const [itemsPerPage, setItemsPerPage] = useState(5);

    const startIndex = (currentPage - 1) * itemsPerPage;
    const endIndex = startIndex + itemsPerPage;

    const paginatedReviews = sortedReviews.slice(startIndex, endIndex);

    const totalPages = Math.ceil(sortedReviews.length / itemsPerPage);

    const handlePageChange = (event, value) => {
        setCurrentPage(value);
    }

    const handleItemsPerPageChange = (event) => {
        setItemsPerPage(event.target.value);
        setCurrentPage(1);
    }

    const getProductName = (id) => {
        const product = reviews.find(review => review.id == id);
        return product ? product.title : '';
    }


    return (
        <div>
            {serverError && <p style={{ color: "red" }}>{serverError}</p>}
            {reviews.id}
            {loading && <div>Loading...</div>}
            {/*{error && <div>Error: {error}</div>}*/}

            <h2>PawsInStyle</h2>
            {paginatedReviews.length > 0 ? (
                <Table>
                    <TableHead>
                        <TableRow>
                            <TableCell style={{ fontWeight: 'bold', fontSize: '15px' }}>Product Name</TableCell>
                            <TableCell style={{ fontWeight: 'bold', fontSize: '15px' }}>Description</TableCell>
                            <TableCell style={{ fontWeight: 'bold', fontSize: '15px' }}>Stars</TableCell>
                            <TableCell style={{ fontWeight: 'bold', fontSize: '15px' }}>Customer Name</TableCell>

                        </TableRow>
                    </TableHead>

                    <TableBody>
                        {paginatedReviews.map(review => (
                            <TableRow key={review.id}>
                                <TableCell>{review.product_name}</TableCell>
                                <TableCell>{review.description}</TableCell>
                                <TableCell>{review.stars}</TableCell>
                                <TableCell>{review.customer_name}</TableCell>
                                <TableCell>
                                    <Link to={`/reviews/edit/${review.id}`}>
                                        <Button sx={{ background: '#006E7F', color: 'white' }}>Edit</Button>
                                    </Link>

                                    <Button onClick={() => handleDelete(review.id)}
                                            sx={{ background: '#CD1818', color: 'white' }}>Delete</Button>
                                </TableCell>
                            </TableRow>
                        ))}
                    </TableBody>
                </Table>
            ) : (
                <div>No collars available</div>
            )}

            <Pagination
                count={totalPages}
                page={currentPage}
                onChange={handlePageChange}
                renderItem={(item) => (
                    <PaginationItem
                        component={Button}
                        onClick={(event) => handlePageChange(event, item.page)}
                        {...item}
                    />
                )}
            />

            <Select value={itemsPerPage} onChange={handleItemsPerPageChange}>
                <MenuItem value={1}>1</MenuItem>
                <MenuItem value={3}>3</MenuItem>
                <MenuItem value={7}>7</MenuItem>
            </Select>

            {/*<PieChart>*/}
            {/*</PieChart>*/}
        </div>

    );
}

export default ViewReviews;
