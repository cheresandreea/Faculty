import React from 'react';
import { fireEvent, waitFor } from '@testing-library/react'; // Importing fireEvent and waitFor
import { render } from '@testing-library/react'; // Importing the render function
import { Provider } from 'react-redux';
import { BrowserRouter as Router } from 'react-router-dom';
import configureStore from 'redux-mock-store';
import Create from './pages/Create';
import { addCollar } from './CollarReducer';

const mockStore = configureStore([]);

jest.mock('react-router-dom', () => ({
    ...jest.requireActual('react-router-dom'),
    useParams: jest.fn()
}));

describe('Create Component', () => {
    let store;

    store = mockStore({
        collars: [
            { id: 1, title:"a", description: 'Collar 1', material: 'Leather', price: 10, stars: 4 },
            { id: 2, title: "a", description: 'Collar 2', material: 'Nylon', price: 8, stars: 3 }
        ]
    });

    test('renders input fields correctly', () => {
        const { getByLabelText } = render(
            <Provider store={store}>
                <Router>
                    <Create />
                </Router>
            </Provider>
        );

    });

    test('input field values are updated correctly', () => {
        const { getByLabelText } = render(
            <Provider store={store}>
                <Router>
                    <Create />
                </Router>
            </Provider>
        );

        fireEvent.change(getByLabelText('Description'), { target: { value: 'New Description' } });
        fireEvent.change(getByLabelText('Material'), { target: { value: 'New Material' } });
        fireEvent.change(getByLabelText('Price'), { target: { value: '20' } });
        fireEvent.change(getByLabelText('Stars'), { target: { value: '5' } });

        expect(getByLabelText('Description').value).toBe('New Description');
        expect(getByLabelText('Material').value).toBe('New Material');
        expect(getByLabelText('Price').value).toBe('20');
        expect(getByLabelText('Stars').value).toBe('5');
    });

    test('form submission dispatches correct action and navigates to home page', async () => {
        store = mockStore({
            collars: [
                { id: 1, title:"a", description: 'Collar 1', material: 'Leather', price: 10, stars: 4 },
                { id: 2, title: "a", description: 'Collar 2', material: 'Nylon', price: 8, stars: 3 }
            ]
        });
        const { getByLabelText, getByText } = render(
            <Provider store={store}>
                <Router>
                    <Create />
                </Router>
            </Provider>
        );

        fireEvent.change(getByLabelText('Description'), { target: { value: 'New Description' } });
        fireEvent.change(getByLabelText('Title'), { target: { value: 'New Description' } });
        fireEvent.change(getByLabelText('Material'), { target: { value: 'New Material' } });
        fireEvent.change(getByLabelText('Price'), { target: { value: '20' } });
        fireEvent.change(getByLabelText('Stars'), { target: { value: '5' } });

        fireEvent.submit(getByText('Submit'));

        console.log('Actions dispatched:', store.getActions());

        await waitFor(() => {
            expect(store.getActions()).toEqual([
                addCollar({
                    id: "3",
                    title: "New title",
                    price: "20",
                    description: 'New Description',
                    material: 'New Material',
                    stars:"5"
                })
            ]);
        });

        // Check if navigation occurred
        //expect(window.location.pathname).toEqual('/');
    });

});
