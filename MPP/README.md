Medii de proiectare si programare
## Introduction

The Collar Management System is a web application designed to manage a list of collars. Users can create, update, and delete collars, and view them sorted and paginated. The application also includes a chart to display different materials used for the collars. Additionally, users can register and log in to access the application.

## Features

- User authentication (registration and login)
- Create, update, and delete collars
- View collars sorted and paginated
- Chart displaying materials used for collars

## Technologies Used

### Backend

- **Node.js** with **Express.js**: Server-side logic and API routes
- **SQL Server**: Database to store collar information

### Frontend

- **React**: User interface
- **Redux**: State management

## Usage

- Access the application at `http://localhost:4000`.
- Register for a new account or log in with existing credentials.
- Use the UI to create, update, and delete collars.
- View the list of collars with pagination and sorting options.
- Check the chart for an overview of materials used.

## API Endpoints

### Auth

- **POST /api/auth/register**: Register a new user
- **POST /api/auth/login**: Log in a user

### Collars

- **GET /api/collars**: Get a list of collars (with pagination and sorting)
- **POST /api/collars**: Create a new collar
- **PUT /api/collars/:id**: Update an existing collar
- **DELETE /api/collars/:id**: Delete a collar

### Materials

- **GET /api/materials**: Get a list of materials

![image](https://github.com/cheresandreea/Faculty/assets/115451911/b8714519-c03c-4bde-ad71-dbb7c8d01167)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/ce52af2f-a797-4240-92e5-11597312be64)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/03156ea6-1693-4006-be06-8e1ebad5b177)
![image](https://github.com/cheresandreea/Faculty/assets/115451911/7348d5ac-ee67-40a8-a435-6fd5d2793882)



