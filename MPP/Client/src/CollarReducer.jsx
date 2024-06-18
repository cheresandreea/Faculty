import {createSlice} from "@reduxjs/toolkit";
import axios from "axios";

const collarSlice = createSlice({
    name: "collars",
    initialState: {
        dataCollars: [],
        dataReviews: [],
        field: 0,
        loading: false,
        error: null,
    },
    reducers: {
        fetchCollarsStart: (state) => {
            state.loading = true;
            state.error = null;
        },
        fetchCollarsSuccess: (state, action) => {
            state.loading = false;
            state.dataCollars = action.payload;
        },
        fetchCollarsFailure: (state, action) => {
            state.loading = false;
            state.error = action.payload;
        },


        addCollar: (state, action) => {
            state.dataCollars.push(action.payload)
        },

        editCollar: (state, action) =>{
            const {id, title, description, material, price, stars} = action.payload;
            const editedCollar = state.dataCollars.find(collar => collar.id == id);
            if(editedCollar){
                editedCollar.title = title;
                editedCollar.description = description;
                editedCollar.material = material;
                editedCollar.price = price;
                editedCollar.stars = stars;
            }
        },

        deleteCollar: (state, action) => {
            const { id } = action.payload;
            state.dataCollars = state.dataCollars.filter(collar => collar.id !== id);
        },

        fetchReviewsStart: (state) => {
            state.loading = true;
            state.error = null;
        },
        fetchReviewsSuccess: (state, action) => {
            state.loading = false;
            state.dataReviews = action.payload;
        },
        fetchReviewsFailure: (state, action) => {
            state.loading = false;
            state.error = action.payload;
        },

        addReview: (state, action) => {
            state.dataReviews.push(action.payload)
        },

        editReview: (state, action) =>{
            const {id, id_product, customer_name, description, stars} = action.payload;
            const editedReview = state.dataReviews.find(review => review.id == id);
            if(editedReview){
                editedReview.description = description;
                editedReview.stars = stars;
            }
        },

        deleteReview: (state, action) => {
            const {id} = action.payload;
            state.dataReviews = state.dataReviews.filter(review => review.id !== id);
        }

    }

})

export const {
    fetchCollarsStart,
    fetchCollarsSuccess,
    fetchCollarsFailure,
    addCollar,
    editCollar,
    deleteCollar,
    fetchReviewsStart,
    fetchReviewsSuccess,
    fetchReviewsFailure,
    addReview,
    editReview,
    deleteReview


} = collarSlice.actions;

export const fetchCollars = () => async (dispatch) => {
    dispatch(fetchCollarsStart());
    try {
        const res = await axios.get("http://localhost:4000/collars");
        dispatch(fetchCollarsSuccess(res.data));
    } catch (error) {
        dispatch(fetchCollarsFailure(error.message));
    }
};

export const fetchReviews = () => async (dispatch) => {
    dispatch(fetchReviewsStart());
    try {
        const res = await axios.get("http://localhost:4000/collars/reviews");
        dispatch(fetchReviewsSuccess(res.data));
    } catch (error) {
        dispatch(fetchReviewsFailure(error.message));
    }
};


export default collarSlice.reducer;