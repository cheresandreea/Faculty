import React from 'react';
import { fireEvent, render, waitFor } from '@testing-library/react';
import { Provider } from 'react-redux';
import { BrowserRouter as Router, useParams } from 'react-router-dom';
import configureStore from 'redux-mock-store';
import axios from 'axios'; // Import axios for mocking
import EditReview from './EditReview';
import { editReview } from '../CollarReducer';

// Mock useParams
jest.mock('react-router-dom', () => ({
    ...jest.requireActual('react-router-dom'),
    useParams: jest.fn(),
}));

// Mock axios
jest.mock('axios');

describe('EditReview Component', () => {
    let store;
    const mockDispatch = jest.fn();

    beforeEach(() => {
        store = configureStore()({});
        useParams.mockReturnValue({ id: '1' });
        jest.spyOn(React, 'useDispatch').mockReturnValue(mockDispatch);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    test('input field values are updated correctly', () => {
        const { getByLabelText } = render(
            <Provider store={store}>
                <Router>
                    <EditReview />
                </Router>
            </Provider>
        );

        fireEvent.change(getByLabelText('Description'), { target: { value: 'New Review' } });
        fireEvent.change(getByLabelText('Stars'), { target: { value: '5' } });

        expect(getByLabelText('Description').value).toBe('New Review');
        expect(getByLabelText('Stars').value).toBe('5');
    });

    test('form submission dispatches correct action and navigates to reviews page', async () => {
        const { getByLabelText, getByText } = render(
            <Provider store={store}>
                <Router>
                    <EditReview />
                </Router>
            </Provider>
        );

        fireEvent.change(getByLabelText('Description'), { target: { value: 'New Review' } });
        fireEvent.change(getByLabelText('Stars'), { target: { value: '5' } });
        fireEvent.submit(getByText('Submit'));

        // Wait for the axios PUT call to resolve
        await waitFor(() => {
            expect(axios.put).toHaveBeenCalledWith('http://localhost:4000/collars/reviews/edit/1', {
                description: 'New Review',
                stars: '5',
            });
        });

        // Check if the editReview action was dispatched with the correct payload
        expect(mockDispatch).toHaveBeenCalledWith(
            editReview({
                id: '1',
                description: 'New Review',
                stars: '5',
            })
        );

        // Check if navigation occurred
        expect(window.location.pathname).toEqual('/reviews');
    });
});
