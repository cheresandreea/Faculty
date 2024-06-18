import React, { useEffect, useState } from 'react';
import { useDispatch, useSelector } from "react-redux";
import {
    Table,
    TableHead,
    TableRow,
    TableCell,
    TableBody,
    Button,
    Select,
    MenuItem,
    Pagination,
    PaginationItem,
} from "@mui/material";
import {Link, useNavigate} from 'react-router-dom';
import { deleteCollar, fetchCollars } from "../CollarReducer";
import PieChart from "../Chart";
import store from "../index";
import axios from "axios";
import {logout} from "../UserReducer";

function Home() {
    const collars = useSelector((state) => state.collars.dataCollars);
    const dispatch = useDispatch();
    const navigate = useNavigate();

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
                await axios.get('http://localhost:4000/collars');
            } catch (error) {
                setServerError('Server is down. Please try again later.')
            }
        };

        checkServerStatus();

        dispatch(fetchCollars());
    }, [dispatch]); // Dependency array includes dispatch

    const handleDelete = async (id) => {

        const confirmed = window.confirm("Are you sure you want to delete?");
        if (confirmed) {
            try {
                await axios.delete(`http://localhost:4000/collars/delete/${id}`);
                dispatch(deleteCollar({id: id}));
            } catch (error) {
                console.error("Error deleting collar:", error);
            }
        }

    }

    useEffect(() => {
        console.log('Updated Redux Store State:', store.getState().collars.dataCollars);
    }, [collars]);


    const sortedCollars = [...collars].sort((a, b) => a.title.localeCompare(b.title));

    const [currentPage, setCurrentPage] = useState(1);
    const [itemsPerPage, setItemsPerPage] = useState(5);

    const startIndex = (currentPage - 1) * itemsPerPage;
    const endIndex = startIndex + itemsPerPage;

    const paginatedCollars = sortedCollars.slice(startIndex, endIndex);

    const totalPages = Math.ceil(sortedCollars.length / itemsPerPage);

    const handlePageChange = (event, value) => {
        setCurrentPage(value);
    }

    const handleItemsPerPageChange = (event) => {
        setItemsPerPage(event.target.value);
        setCurrentPage(1);
    }

    const [lowestPriceCollar, setLowestPriceCollar] = useState({
        title: "",
        description: "",
        price: "",
        material: "",
        stars: ""
    });

    useEffect(() => {
        if (!loading && !error) {
            const collarsByPrice = [...collars].sort((a, b) => a.price - b.price);
            if (collarsByPrice.length > 0) {
                setLowestPriceCollar(collarsByPrice[0]);
            } else {
                setLowestPriceCollar({
                    title: "No collars available",
                    description: "No collars available",
                    price: "",
                    material: "",
                    stars: ""
                });
            }
        }
    }, [collars, loading, error]);

    const handleLogout = () => {
        dispatch(logout());
        navigate('/login');
    };


    return (
        <div>
            {serverError && <p style={{color: "red"}}>{serverError}</p>}
            {collars.id}
            {loading && <div>Loading...</div>}
            {/*{error && <div>Error: {error}</div>}*/}


            <h2>PawsInStyle</h2>
            <h2>Welcome to Your Dashboard</h2>
            <Link to={"/private"}>
                <Button>View Private Information</Button>
            </Link>
            <Button onClick={handleLogout}>Logout</Button>
            <br></br>
            <Link to={"/create"}>
                <Button style={{background: '#662549', color: 'white'}}>Create +</Button>
            </Link>

            <Link to={"/reviews"}>
                <Button style={{background: '#662549', color: 'white'}}>See Reviews</Button>
            </Link>

            <Table>
                <TableBody>
                    <TableRow>
                        <TableCell>
                            {lowestPriceCollar.title}<br/>
                            {lowestPriceCollar.description}<br/>
                            {lowestPriceCollar.price}<br/>
                            {lowestPriceCollar.material}<br/>
                            {lowestPriceCollar.stars}<br/>
                        </TableCell>
                    </TableRow>
                </TableBody>
            </Table>

            {paginatedCollars.length > 0 ? (
                <Table>
                    <TableHead>
                        <TableRow>
                            <TableCell style={{fontWeight: 'bold', fontSize: '15px'}}>Title</TableCell>
                            <TableCell style={{fontWeight: 'bold', fontSize: '15px'}}>Material</TableCell>
                            <TableCell style={{fontWeight: 'bold', fontSize: '15px'}}>Price</TableCell>
                            <TableCell style={{fontWeight: 'bold', fontSize: '15px'}}>Stars</TableCell>
                            <TableCell style={{fontWeight: 'bold', fontSize: '15px'}}>Actions</TableCell>
                        </TableRow>
                    </TableHead>

                    <TableBody>
                        {paginatedCollars.map(collar => (
                            <TableRow key={collar.id}>
                                <TableCell>{collar.title}</TableCell>
                                <TableCell>{collar.material}</TableCell>
                                <TableCell>{collar.price}</TableCell>
                                <TableCell>{collar.stars}</TableCell>
                                <TableCell>
                                    <Link to={`/edit/${collar.id}`}>
                                        <Button sx={{background: '#006E7F', color: 'white'}}>Edit</Button>
                                    </Link>

                                    <Button onClick={() => handleDelete(collar.id)}
                                            sx={{background: '#CD1818', color: 'white'}}>Delete</Button>

                                    <Link to={`/view/${collar.id}`}>
                                        <Button sx={{background: '#5D9C59', color: 'white'}}>View Details</Button>
                                    </Link>
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

export default Home;
