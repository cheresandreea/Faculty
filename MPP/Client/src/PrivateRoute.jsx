import React, { useEffect } from 'react';
import { Navigate, useLocation } from 'react-router-dom';
import { useSelector, useDispatch } from 'react-redux';
import { logout } from './UserReducer';

const PrivateRoute = ({ element: Component, ...rest }) => {
    const isAuthenticated = useSelector(state => !!state.user.token);
    const expiresAt = useSelector(state => state.user.expiresAt);
    const dispatch = useDispatch();
    const location = useLocation();

    useEffect(() => {
        const intervalId = setInterval(() => {
            const currentTime = new Date();
            const tokenExpiryTime = new Date(expiresAt);

            console.log(`Current Time: ${currentTime}`);
            console.log(`Token Expiry Time: ${tokenExpiryTime}`);

            if (expiresAt && currentTime > tokenExpiryTime) {
                dispatch(logout());
                window.alert("Your session expired!");
            }
        }, 1000);

        return () => clearInterval(intervalId);
    }, [expiresAt, dispatch]);

    if (!isAuthenticated) {
        return <Navigate to="/login" state={{ from: location }} replace />;
    }

    return <Component {...rest} />;
};

export default PrivateRoute;
