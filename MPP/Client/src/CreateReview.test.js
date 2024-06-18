import React from 'react';
import { fireEvent, waitFor } from '@testing-library/react'; // Importing fireEvent and waitFor
import { render } from '@testing-library/react'; // Importing the render function
import { Provider } from 'react-redux';
import {BrowserRouter as Router, useParams} from 'react-router-dom';
import configureStore from 'redux-mock-store';
import Create from './pages/Create';
import {addCollar, addReview} from './CollarReducer';
import CreateReview from "./pages/CreateReview";


const mockStore = configureStore([]);

jest.mock('react-router-dom', () => ({
    ...jest.requireActual('react-router-dom'),
    useParams: jest.fn()
}));

describe('CreateReview Component', () => {
    let store;

    beforeEach(() => {
        store = mockStore({
            collars: {
                dataReviews: []
            }
        });
        useParams.mockReturnValue({ id: '1' }); // Mocking the id parameter
    });

    test('input field values are updated correctly', () => {
        const { getByLabelText } = render(
            <Provider store={store}>
                <Router>
                    <CreateReview />
                </Router>
            </Provider>
        );

        fireEvent.change(getByLabelText('Description'), { target: { value: 'New Review' } });
        fireEvent.change(getByLabelText('Stars'), { target: { value: '5' } });
        fireEvent.change(getByLabelText('Customer Name'), { target: { value: 'John Doe' } });

        expect(getByLabelText('Description').value).toBe('New Review');
        expect(getByLabelText('Stars').value).toBe('5');
        expect(getByLabelText('Customer Name').value).toBe('John Doe');
    });

    test('form submission dispatches correct action and navigates to home page', async () => {
        const { getByLabelText, getByText } = render(
            <Provider store={store}>
                <Router>
                    <CreateReview />
                </Router>
            </Provider>
        );

        fireEvent.change(getByLabelText('Description'), { target: { value: 'New Review' } });
        fireEvent.change(getByLabelText('Stars'), { target: { value: '5' } });
        fireEvent.change(getByLabelText('Customer Name'), { target: { value: 'John Doe' } });

        fireEvent.submit(getByText('Submit'));

        await waitFor(() => {
            expect(store.getActions()).toEqual([
                addReview({
                    id: '1',
                    product_id: '1',
                    description: 'New Review',
                    stars: 5,
                    customer_name: 'A'
                })
            ]);
        });

        expect(window.location.pathname).toEqual('/');
    });

});
