// PrivateInfo.js
import React, { useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { logout } from '../UserReducer';
import { useNavigate } from 'react-router-dom';
import axios from 'axios';

const PrivateInfo = () => {
    const dispatch = useDispatch();
    const user = useSelector(state => state.user);
    const navigate = useNavigate();
    const [tokenInput, setTokenInput] = useState('');
    const [userData, setUserData] = useState(null);


    const handleLogout = () => {
        dispatch(logout());
        navigate('/login');
    };

    const handleShowDetails = async () => {
        try {
            const response = await axios.get('https://mpp-backend-425314.lm.r.appspot.com/auth/user', {
                headers: {
                    Authorization: `Bearer ${tokenInput}`
                }
            });
            setUserData(response.data.user);
        } catch (error) {
            console.error('Error fetching user details:', error);
        }
    };

    return (
        <div>
            <h2>Welcome!</h2>
            <p>Your token is: {user.token}</p>
            <p>Token expiration time: {user.expiresAt ? new Date(user.expiresAt).toLocaleString('ro-RO') : 'N/A'}</p>
            <p>Enter your token: </p>
            <input
                type="text"
                value={tokenInput}
                onChange={e => setTokenInput(e.target.value)}
            />
            <button onClick={handleShowDetails}>Show details</button>
            {userData && (
                <div>
                    <h3>User Details</h3>
                    <p>Username: {userData.username}</p>
                    <p>Password: {userData.password}</p>
                    <p>Email: {userData.email}</p>
                </div>
            )}

            <button onClick={handleLogout}>Logout</button>
            <button onClick={() => navigate('/')}>Back</button>
        </div>
    );
};

export default PrivateInfo;
