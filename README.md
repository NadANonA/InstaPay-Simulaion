# InstaPay Simulation


## Description

The InstaPay Simulation is a C++ project that mimics the functionality of the InstaPay mobile application. It allows users to perform various banking operations, such as checking their account balance, transferring money, and managing their favorite contacts.


## Features

- **User Management**: The application supports user registration, login, and account management.

- **Balance Management**: Users can check their current account balance and transfer money to other users.

- **Favorite Contacts**: Users can maintain a list of their favorite contacts, making it easier to transfer money to these users.

- **Polymorphism**: The application utilizes polymorphism to handle different types of banking operations, making the code more extensible and maintainable.

- **Pure Functions**: Several functions in the project are designed as pure functions, ensuring they have no side effects and are easier to test and reason about.

- **Interfaces**: The project incorporates interfaces to define the expected behavior of various components, promoting modularity and flexibility.


## Usage
To use the InstaPay Simulation, follow these steps:

1. Clone the repository to your local machine.

2. Compile the project using a C++ compiler (e.g., g++ or clang++).

3. Run the compiled executable.

4. Follow the on-screen instructions to perform various banking operations.


## Architecture
The InstaPay Simulation is designed using the following architectural components:

- **User** : Represents a user of the application, including their personal information, account balance, and favorite contacts.

- **BankingOperation** : An abstract interface that defines the common methods for banking operations, such as `TransferMoney()` and `LoadMoney()`.

- **BankAccount**, **VisaCard**, and **MasterCard** : Concrete implementations of the `BankingOperation` interface, handling the respective banking operations.

- **FavoriteList** : A component that manages the user's list of favorite contacts, allowing for efficient money transfers to these users.

- **Other Functions** : The project also utilizes pure functions, such as the `menu1()`, `menu2()`, `menu3()`, and `menu4()` functions, which provide the main menu options without any side effects.

## Test you can use 

- first account :

	    1- Name : naz

        2- Password : 542lkm

        3- Phone Number : 6845312686543

        4- Bank name :A

        5- pin : 123

        6- balance : 1000

- second account :

	    1- Name : nevana

        2- Password : 951231

        3- Phone Number : 7453147845132

        4- Bank name :B

        5- pin : 456

        6- balance : 0


## Feedback

If you have any feedback, please reach out to me at

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/nada-salah-551713253/)
