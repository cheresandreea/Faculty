import Home from './pages/Home'
import {BrowserRouter, Routes, Route} from 'react-router-dom'
import Create from './pages/Create'
import Edit from './pages/Edit'
import View from "./pages/ViewPage";
import ViewReviews from "./pages/ViewReviews";
import EditReview from "./pages/EditReview";
import CreateReview from "./pages/CreateReview";
import Login from "./pages/LogIn";
import PrivateRoute from "./PrivateRoute";
import Register from "./pages/Register";
import PrivateInfo from "./pages/PrivateInfo";

function App() {
  return (
      <BrowserRouter>
        <Routes>
            {/*<Route path={"/login"} element={<Login/>}></Route>*/}
            {/*<Route path={"/register"} element={<Register/>}></Route>*/}
            {/*<Route path={"/private"} element={<PrivateInfo/>}></Route>*/}
            {/*<Route path="/" element={<PrivateRoute element={Home} />} />*/}
            {/*<Route path="/reviews" element={<PrivateRoute element={ViewReviews} />} />*/}
            {/*<Route path="/create" element={<PrivateRoute element={Create} />} />*/}
            {/*<Route path="/edit/:id" element={<PrivateRoute element={Edit} />} />*/}
            {/*<Route path="/view/:id" element={<PrivateRoute element={View} />} />*/}
            {/*<Route path="/reviews/edit/:id" element={<PrivateRoute element={EditReview} />} />*/}
            {/*<Route path="/collars/reviews/create/:id" element={<PrivateRoute element={CreateReview} />} />*/}

            <Route path="/" element={<Home />} />
            <Route path="/reviews" element={<ViewReviews />} />
            <Route path="/create" element={<Create />} />
            <Route path="/edit/:id" element={<Edit />} />
            <Route path="/view/:id" element={<View />} />
            <Route path="/reviews/edit/:id" element={<EditReview />} />
            <Route path="/collars/reviews/create/:id" element={<CreateReview />} />
            <Route path="/login" element={<Login />} />
            <Route path="/register" element={<Register />} />

        </Routes>
      </BrowserRouter>
  );
}
export default App;
