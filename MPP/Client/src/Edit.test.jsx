import React from 'react';
import { render, fireEvent, waitFor } from '@testing-library/react';
import { Provider } from 'react-redux';
import { BrowserRouter as Router, useParams } from 'react-router-dom';
import configureStore from 'redux-mock-store';
import Edit from './pages/Edit';
import { editCollar } from './CollarReducer';

const mockStore = configureStore([]);

jest.mock('react-router-dom', () => ({
    ...jest.requireActual('react-router-dom'),
    useParams: jest.fn()
}));

describe('Edit Component', () => {
    let store;

    beforeEach(() => {
        store = mockStore({
            collars: [
                { id: 1, title: "a", description: 'Collar 1', material: 'Leather', price: 10, stars: 4 },
                { id: 2, title: "a", description: 'Collar 2', material: 'Nylon', price: 8, stars: 3 }
            ]
        });
        useParams.mockReturnValue({ id: '1' }); // Mocking the id parameter
    });

    test('renders edit form and submits successfully', async () => {
        const { getByLabelText, getByText } = render(
            <Provider store={store}>
                <Router>
                    <Edit />
                </Router>
            </Provider>
        );


        fireEvent.change(getByLabelText('Description'), { target: { value: 'Updated Description' } });
        fireEvent.change(getByLabelText('Material'), { target: { value: 'Updated Material' } });
        fireEvent.change(getByLabelText('Price'), { target: { value: '15' } });
        fireEvent.change(getByLabelText('Stars'), { target: { value: '5' } });

        fireEvent.click(getByText('Submit'));

        await waitFor(() => {
            expect(store.getActions()).toEqual([
                editCollar({
                    id: 3,
                    title: "New title",
                    description: 'Updated Description',
                    material: 'Updated Material',
                    price: 15,
                    stars: 3
                })
            ]);
        });
    });
});
