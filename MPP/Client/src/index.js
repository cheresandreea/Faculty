import ReactDOM from "react-dom/client";
import React from "react";
import App from './App';
import {Provider} from "react-redux";
import {configureStore} from "@reduxjs/toolkit";

import collarReducer from './CollarReducer'


const store = configureStore({
    reducer: {
        collars: collarReducer
    }
})

ReactDOM.createRoot(document.getElementById('root')).render(
    <React.StrictMode>
        <Provider store={store}>
            <App />
        </Provider>

    </React.StrictMode>
);

export default store;