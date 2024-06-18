import React, { useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import {loginUser, setUser} from '../UserReducer';
import axios from "axios";
import {useNavigate} from "react-router-dom";

const Login = () => {
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
    const dispatch = useDispatch();
    const { loading, error } = useSelector((state) => state.user);
    const navigate = useNavigate()

    const handleLogin = async (e) => {
        e.preventDefault();
        try {
            await dispatch(loginUser({ username, password }));
            navigate('/');
        } catch (error) {
            console.error('Login failed', error);
        }
    };

    return(
        <div>
            <h1>LogIn</h1>
            <form onSubmit={handleLogin}>
                <input
                    type={"username"}
                    name={"username"}
                    placeholder={"Username"}
                    value={username}
                    onChange={(e) => setUsername(e.target.value)}
                    />
                <input
                    type={"password"}
                    name={"password"}
                    placeholder={"Password"}
                    value={password}
                    onChange={(e) => setPassword(e.target.value)}
                    />
                <button type={"submit"} disabled={loading}>
                    {loading ? 'Loading...' : 'Log In'}
                </button>
            </form>
            {error && <div>{error}</div>}

            <button onClick={() => navigate('/register')}>Register</button>
        </div>
    )

}

export default Login;