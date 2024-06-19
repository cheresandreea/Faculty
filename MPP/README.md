Medii de proiectare si programare
## Introduction

The Collar Management System is a web application designed to manage a list of collars. Users can create, update, and delete collars, and view them sorted and paginated. The application also includes a chart to display different materials used for the collars. Additionally, users can register and log in to access the application.

## Features

- User authentication (registration and login)
- See user details based on generated token
- Create, update and delete collars
- View collars sorted and paginated
- Create, update and delete reviews
- View reviews sorted and paginated
- Chart displaying materials used for collars
- Note: Initial collar data is generated using the Faker library for demonstration purposes.

## Technologies Used

### Backend

- **Node.js** with **Express.js**: Server-side logic and API routes
- **SQL Server**: Database to store users, collars and reviews information

### Frontend

- **React**: User interface
- **Redux**: State management

## Usage

### Frontend

- Access the frontend application at `http://localhost:3000`.
- Register for a new account or log in with existing credentials.
- See your user details based on the generated token.
- Use the UI to create, update, delete collars and reviews.
- View the list of collars with pagination and sorting options.
- View the list of reviews with pagination and sorting options.
- Check the chart for an overview of materials used.

### Backend

- The backend server runs at `http://localhost:4000`.
- Ensure the backend server is running before accessing the frontend application.

## API Endpoints

### Auth

- **POST /auth/register**: Register a new user
- **POST /auth/login**: Log in a user

### Collars

- **GET /collars**: Get a list of collars (with pagination and sorting)
- **POST /collars/create**: Create a new collar
- **PUT /collars/edit/:id**: Update an existing collar
- **DELETE /collars/delete/:id**: Delete a collar

### Reviews

- **GET /collars/reviews**: Get a list of reviews
- **POST /collars/reviews/create/:id**: Create a new review for a certain collar
- **PUT /collars/reviews/edit/:id**: Update an existing review
- **DELETE /collars/reviews/delete/:id**: Delete a review
  
![image](https://github.com/cheresandreea/Faculty/assets/115451911/f4c60726-d8af-40d0-9a62-93deb564aebe)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/09ab58b6-4c56-42a6-85c7-fa9729eee24e)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/cff6c97b-a30a-41bb-91b0-e42d249b53b9)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/b6befa6e-bc61-4ce1-8586-7b3c7cc19ad3)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/ce52af2f-a797-4240-92e5-11597312be64)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/03156ea6-1693-4006-be06-8e1ebad5b177)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/7348d5ac-ee67-40a8-a435-6fd5d2793882)



