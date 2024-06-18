// import React from 'react';
// import {fireEvent, getAllByText, render} from '@testing-library/react';
// import { Provider } from 'react-redux';
// import {BrowserRouter as Router, Route, Routes} from 'react-router-dom';
// import configureStore from 'redux-mock-store';
// import Home from './pages/Home';
// import {deleteCollar} from "./CollarReducer";
// import Create from "./pages/Create";
// import Edit from "./pages/Edit";
// import View from "./pages/ViewPage";
//
// const mockStore = configureStore([]);
//
// describe('Home Component', () => {
//     let store;
//
//     beforeEach(() => {
//         store = mockStore({
//             collars: [
//                 { id: 2, description: 'Collar a', material: 'leather', price: 10, stars: 4 },
//                 { id: 3, description: 'Collar b', material: 'silk', price: 8, stars: 5 },
//             ]
//         });
//     });
//
//     test('renders without crashing', () => {
//         const { getByText } = render(
//             <Provider store={store}>
//                 <Router>
//                     <Home />
//                 </Router>
//             </Provider>
//         );
//         expect(getByText('PawsInStyle')).toBeInTheDocument();
//     });
//
//     test('renders table with correct data', () => {
//         const { getByText } = render(
//             <Provider store={store}>
//                 <Router>
//                     <Home />
//                 </Router>
//             </Provider>
//         );
//
//         expect(getByText('ID')).toBeInTheDocument();
//         expect(getByText('Description')).toBeInTheDocument();
//         expect(getByText('Material')).toBeInTheDocument();
//         expect(getByText('Price')).toBeInTheDocument();
//         expect(getByText('Stars')).toBeInTheDocument();
//
//         expect(getByText('2')).toBeInTheDocument(); // ID
//         expect(getByText('Collar a')).toBeInTheDocument(); // Description
//         expect(getByText('leather')).toBeInTheDocument(); // Material
//         expect(getByText('10')).toBeInTheDocument(); // Price
//         expect(getByText('4')).toBeInTheDocument(); // Stars
//
//         expect(getByText('3')).toBeInTheDocument(); // ID
//         expect(getByText('Collar b')).toBeInTheDocument(); // Description
//         expect(getByText('silk')).toBeInTheDocument(); // Material
//         expect(getByText('8')).toBeInTheDocument(); // Price
//         expect(getByText('5')).toBeInTheDocument(); // Stars
//     });
//
//     test('delete button dispatches correct action', () => {
//         const { getAllByText } = render(
//             <Provider store={store}>
//                 <Router>
//                     <Home />
//                 </Router>
//             </Provider>
//         );
//
//         const deleteButtons = getAllByText('Delete');
//
//         fireEvent.click(deleteButtons[0]);
//
//         expect(store.getActions()).toEqual([deleteCollar({ id: 2 })]);
//     });
//
//     test('navigation links navigate to correct routes', () => {
//         const { getByText} = render(
//             <Provider store={store}>
//                 <Router initialEntries={['/']}>
//                     <Routes>
//                         <Route path="/" element={<Home />} />
//                         <Route path="/create" element={<Create />} />
//                         <Route path="/edit/:id" element={<Edit />} />
//                         <Route path="/view/:id" element={<View />} />
//                     </Routes>
//                 </Router>
//             </Provider>
//         );
//
//         // Navigate to create route
//         fireEvent.click(getByText('Create +'));
//         expect(getByText('Add new collar')).toBeInTheDocument();
//     });
//
// });
