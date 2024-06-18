import { createSlice } from "@reduxjs/toolkit";
import axios from "axios";

const initialState = {
    user: null,
    loading: false,
    error: null,
    token: localStorage.getItem('token') || null,
    expiresAt: localStorage.getItem('expiresAt') || null,
};

const userSlice = createSlice({
    name: "user",
    initialState,
    reducers: {
        loginStart: (state) => {
            state.loading = true;
            state.error = null;
        },
        loginSuccess: (state, action) => {
            state.loading = false;
            state.user = action.payload.user;
            state.token = action.payload.token;
            state.expiresAt = action.payload.expiresAt;
            localStorage.setItem('token', action.payload.token);
            localStorage.setItem('expiresAt', action.payload.expiresAt); // Save expiration time
        },
        loginFailure: (state, action) => {
            state.loading = false;
            state.error = action.payload;
        },
        registerStart: (state) => {
            state.loading = true;
            state.error = null;
        },
        registerSuccess: (state, action) => {
            state.loading = false;
            state.user = action.payload.user;
            state.token = action.payload.token;
            state.expiresAt = action.payload.expiresAt;
            localStorage.setItem('token', action.payload.token);
            localStorage.setItem('expiresAt', action.payload.expiresAt);
        },
        registerFailure: (state, action) => {
            state.loading = false;
            state.error = action.payload;
        },
        logout: (state) => {
            state.user = null;
            state.token = null;
            state.expiresAt = null;
            localStorage.removeItem('token');
            localStorage.removeItem('expiresAt');
        },
        setUser: (state, action) => {
            state.user = action.payload.user;
            state.token = localStorage.getItem('token');
            state.expiresAt = localStorage.getItem('expiresAt');
        }
    }
});

export const {
    loginStart,
    loginSuccess,
    loginFailure,
    registerStart,
    registerSuccess,
    registerFailure,
    logout,
    setUser,
} = userSlice.actions;

export const loginUser = (credentials) => async (dispatch) => {
    dispatch(loginStart());
    try {
        const res = await axios.post("http://localhost:4000/auth/login", credentials);
        const { token, user, expiresAt } = res.data;
        dispatch(loginSuccess({ user, token, expiresAt }));
        return Promise.resolve();
    } catch (error) {
        const errorMsg = error.response ? error.response.data.error : error.message;
        dispatch(loginFailure(errorMsg));
        return Promise.reject(errorMsg);
    }
}


export const registerUser = (credentials) => async (dispatch) => {
    dispatch(registerStart());
    try {
        const res = await axios.post("http://localhost:4000/auth/register", credentials);
        const { token, user, expiresAt } = res.data;
        dispatch(registerSuccess({ user, token, expiresAt }));
        return Promise.resolve();
    } catch (error) {
        const errorMsg = error.response ? error.response.data.error : error.message;
        dispatch(registerFailure(errorMsg));
        return Promise.reject(errorMsg);
    }
}

export default userSlice.reducer;
