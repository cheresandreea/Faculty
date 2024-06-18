import ReactDOM from "react-dom";
import React from "react";
import App from './App';
import { Provider } from "react-redux";
import { configureStore } from "@reduxjs/toolkit";
import collarReducer from './CollarReducer';
import userReducer from "./UserReducer";

const store = configureStore({
    reducer: {
        collars: collarReducer,
        user: userReducer
    }
});

try {
    ReactDOM.createRoot(document.getElementById('root')).render(
        <React.StrictMode>
            <Provider store={store}>
                <App />
            </Provider>
        </React.StrictMode>
    );
} catch (error) {
    console.error("Error mounting React app:", error);
}

export default store;
