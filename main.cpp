#include <iostream>
#include <functios.h>

using namespace std;

// Employee System Structs
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
    string address;        // Employee's address
    string city;           // Employee's city of residence
    string modalityPay;    // Employee's pay modality (e.g., hourly or full-time)
    string salary;         // Employee's base salary

    Employee *next;        // Pointer to the next Employee in a list
    Employee *previous;    // Pointer to the previous Employee in a list
    Employee *boss;        // Pointer to the Employee's boss (if applicable)
    
    JourneyList journeyList; // Pointer to a list of Journeys associated with the Employee

    // Constructor to initialize an Employee object
    Employee(string _name, string _lastName, string _id, int _age, string _position, string _department,
             string _email, string _phone, string _address, string _city, string _modalityPay, string _salary)
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
        address = _address;
        city = _city;
        modalityPay = _modalityPay;
        salary = _salary;
        
        // Initialize pointers to NULL
        next = NULL;
        previous = NULL;
        boss = NULL;
        journeyList = NULL; // Initialize the Journey list to NULL
    }
};

// Define a struct to represent a Journey (workday)
struct Journey {
    string date;     // Date of the workday
    string hours;    // Hours worked on the workday

    Journey *next;   // Pointer to the next Journey in a list
};


// Inventory System Structs
// Define a struct to represent a Product
struct Products {
    string name;        // Product name
    string id;          // Product ID or identification number
    string description; // Product description
    string quantity;    // Product quantity

    Products *next;     // Pointer to the next Product in a list

    // Constructor to initialize a Product object
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
            //consultEmployee();   // <- Call the function to consult the employee
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