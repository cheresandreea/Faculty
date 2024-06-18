import Home from './pages/Home'
import {BrowserRouter, Routes, Route} from 'react-router-dom'
import Create from './pages/Create'
import Edit from './pages/Edit'
import View from "./pages/ViewPage";
import ViewReviews from "./pages/ViewReviews";
import EditReview from "./pages/EditReview";
import CreateReview from "./pages/CreateReview";

function App() {
  return (
      <BrowserRouter>
        <Routes>
          <Route path={"/"} element={<Home/>}></Route>
          <Route path={"/reviews"} element={<ViewReviews/>}></Route>
          <Route path={"/create"} element={<Create/>}></Route>
          <Route path={"/edit/:id"} element={<Edit/>}></Route>
          <Route path={"/view/:id"} element={<View/>}></Route>
          <Route path={"/reviews/edit/:id"} element={<EditReview/>}></Route>
          <Route path={"/collars/reviews/create/:id"} element={<CreateReview/>}></Route>
        </Routes>
      </BrowserRouter>
  );
}
export default App;
