#include <iostream>

using namespace std;

// Employee System Structs

// Define a struct to represent a Journey (workday)
struct Journey {
    string date;     // Date of the workday
    string hours;    // Hours worked on the workday

    Journey *next;   // Pointer to the next Journey in a list
};


// Define a struct to represent an Employee
struct Employee {
    string name;           // Employee's first name
    string lastName;       // Employee's last name
    string id;             // Employee's ID or identification number
    int age;               // Employee's age
    string position;       // Employee's job position
    string department;     // Employee's department
    string email;          // Employee's email address
    string phone;          // Employee's phone number
    string modalityPay;    // Employee's pay modality (e.g., hourly or full-time)
    string salary;         // Employee's base salary

    Employee *next;        // Pointer to the next Employee in a list
    Employee *previous;    // Pointer to the previous Employee in a list
    Employee *boss;        // Pointer to the Employee's boss (if applicable)
    
    Journey journeys; // Pointer to a list of Journeys associated with the Employee

    // Constructor to initialize an Employee object
    Employee(string _name, string _lastName, string _id, int _age, string _position, string _department, string _email, string _phone, string _modalityPay, string _salary)
    {
        // Initialize Employee properties
        name = _name;
        lastName = _lastName;
        id = _id;
        age = _age;
        position = _position;
        department = _department;
        email = _email;
        phone = _phone;
        modalityPay = _modalityPay;
        salary = _salary;

        // Initialize pointers to NULL
        next = NULL;
        previous = NULL;
        boss = NULL;
    }
};


// Inventory System Structs
// Define a struct to represent a Product
struct Product {
    string name;        // Product name
    string id;          // Product ID or identification number
    string description; // Product description
    string productionStage // Product production stage

    Products *next;     // Pointer to the next Product in a list

    // Constructor to initialize a Product object   --  Config circular list
    Products(string _name, string _id, string _description, string _quantity)
    {
        // Initialize Product properties
        name = _name;
        id = _id;
        description = _description;
        quantity = _quantity;

        // Initialize pointers to NULL
        next = NULL;
    }
};


//---------------------------- Functions for program --------------------------

// Employee System Functions
void consultEmployee()
{
    //Print menu options for consult employee
    cout << endl;
    cout << endl;
    cout << "Choose the option you want to consult:" << endl;
    cout << endl;
    cout << "1 - Consult month's salary amount" << endl;
    cout << "2 - Consult this month's salary data" << endl;
    cout << "3 - Consult an employee data" << endl;
    cout << "4 - Consult an employee list sorted by age" << endl;
    cout << "5 - Consult an employee list sorted by alphabetical order" << endl;
    cout << "6 - Consult an subordinates list" << endl;
    cout << "7 - Close menu" << endl;

    //Chose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        cout << "Consult month's salary amount" << endl;
        // consultMonthSalaryAmount(); // <- Call the function to consult the month's salary amount
        break;
    case 2:
        cout << "Consult this month's salary data" << endl;
        // consultMonthSalaryData(); // <- Call the function to consult the month's salary data
        break;
    case 3:
        cout << "Consult an employee data" << endl;
        // consultEmployeeData(); // <- Call the function to consult an employee data
        break;

    case 4:
        cout << "Consult an employee list sorted by age" << endl;
        // consultEmployeeListByAge(); // <- Call the function to consult an employee list sorted by age
        break;
    case 5: 
        cout << "Consult an employee list sorted by alphabetical order" << endl;
        // consultEmployeeListByAlphabeticalOrder(); // <- Call the function to consult an employee list sorted by alphabetical order
        break;
    case 6:
        cout << "Consult an subordinates list" << endl;
        // consultSubordinatesList(); // <- Call the function to consult an subordinates list
        break;
    case 7:
        cout << "Close menu" << endl;
        // Only close the menu
        break;
    default:
        break;
    }
}



// Inventory System Functions
void consultInventory()
{
    //Print menu options for consult inventory
    cout << endl;
    cout << endl;
    cout << "Choose the option you want to consult:" << endl;
    cout << endl;
    cout << "1 - Consult a product data" << endl;
    cout << "2 - Consult a product list sorted by quantity" << endl;
    cout << "3 - Consult a product list sorted by alphabetical order" << endl;
    cout << "4 - Close menu" << endl;

    //Chose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        cout << "Consult a product data" << endl;
        // consultProductData(); // <- Call the function to consult a product data
        break;
    case 2:
        cout << "Consult a product list sorted by quantity" << endl;
        // consultProductListByQuantity(); // <- Call the function to consult a product list sorted by quantity
        break;
    case 3:
        cout << "Consult a product list sorted by alphabetical order" << endl;
        // consultProductListByAlphabeticalOrder(); // <- Call the function to consult a product list sorted by alphabetical order
        break;
    case 4:
        cout << "Close menu" << endl;
        // Only close the menu
        break;
    default:
        break;
    }
}


//Procution Line System Functions
void consultProductionLine()
{
    //Print menu options for consult production line
    cout << endl;
    cout << endl;
    cout << "Choose the option you want to consult:" << endl;
    cout << endl;
    cout << "1 - Consult a production line data" << endl;
    cout << "2 - Consult a specific product" << endl;
    cout << "3 - Consult a production stage" << endl;
    cout << "4 - Close menu" << endl;

    //Chose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        cout << "Consult a production line data" << endl;
        // consultProductionLineData(); // <- Call the function to consult a production line data
        break;
    case 2:
        cout << "Consult a production line list sorted by quantity" << endl;
        // consultProductionLineListByQuantity(); // <- Call the function to consult a production line list sorted by quantity
        break;
    case 3:
        cout << "Consult a production line list sorted by alphabetical order" << endl;
        // consultProductionLineListByAlphabeticalOrder(); // <- Call the function to consult a production line list sorted by alphabetical order
        break;
    case 4:
        cout << "Close menu" << endl;
        // Only close the menu
        break;
    default:
        break;
    }
}


// ---------------------------- Functions for program --------------------------







// ------------------------------- Main function --------------------------------
int main()
{
    cout << "Menu" << endl;   
    cout << "What area of the company would you like to see?:" << endl;
    cout << endl;
    cout << "1 - View employee information" << endl;
    cout << "2 - Consult Inventory" << endl;
    cout << "3 - Check the Production Line" << endl;
    cout << "4 - Close menu" << endl;

    //Chose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {   
        case 1:
            cout << "Employee information" << endl;
            consultEmployee();   // <- Call the function to consult the employee
            break;
        case 2:
            cout << "Inventory" << endl;
            // consultInventory();  // <- Call the function to consult the inventory
            break;
        case 3:
            cout << "Production Line" << endl;
            // consultProductionLine(); // <- Call the function to consult the production line
            break;
        case 4:
            cout << "Close menu" << endl;
            // Only close the menu
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }

    return 0;
}