import React from 'react';
import {render, fireEvent, waitFor, getByLabelText} from '@testing-library/react';
import {Provider} from 'react-redux';
import {BrowserRouter as Router} from 'react-router-dom';
import configureStore from 'redux-mock-store';
import Create from './pages/Create';
import {addCollar} from './CollarReducer';

const mockStore = configureStore([]);

describe('Create Component', () => {
    let store;

    beforeEach(() => {
        store = mockStore({
            collars: [
                { id: 1, description: 'Collar 1', material: 'Leather', price: 10, stars: 4 },
                { id: 2, description: 'Collar 2', material: 'Nylon', price: 8, stars: 3 }
            ]
        });
    });

    test('renders input fields correctly', () => {
        const { getByLabelText } = render(
            <Provider store={store}>
                <Router>
                    <Create />
                </Router>
            </Provider>
        );

        expect(getByLabelText('Description')).toBeInTheDocument();
        expect(getByLabelText('Material')).toBeInTheDocument();
        expect(getByLabelText('Price')).toBeInTheDocument();
        expect(getByLabelText('Stars')).toBeInTheDocument();
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
        const { getByLabelText, getByText } = render(
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

        fireEvent.submit(getByText('Submit'));

        console.log('Actions dispatched:', store.getActions());

        // Wait for the dispatch to complete
        await waitFor(() => expect(store.getActions()).toContainEqual(addCollar({
            id: 3,
            description: 'New Description',
            material: 'New Material',
            price: '20',
            stars: '5'
        })));

        // Check if navigation occurred
        expect(window.location.pathname).toEqual('/');
    });

});
