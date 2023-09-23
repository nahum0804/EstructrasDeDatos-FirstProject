#include <iostream>

using namespace std;

// Employee System Structs

// Define a struct to represent a Journey (workday)
struct Journey {
    string date;     // Date of the workday
    string hours;    // Hours worked on the workday
    string modality; // Modality of the workday (e.g., normal, extra, double, etc.)

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
struct Material{
    string name;
    Material *next;
    Material *previous;

    Material(string _name){
        name = _name;
        next = NULL;
        previous = NULL;
    }   
};

// Define a struct to represent a Product
struct Product {
    string name;        // Product name
    string id;          // Product ID or identification number
    string description; // Product description
    string productionStage; // Product production stage

    Product *next;     // Pointer to the next Product in a list
    Product *previous;

    // Constructor to initialize a Product object   --  Config circular list
    Product(string _name, string _id, string _description)
    {
        // Initialize Product properties
        name = _name;
        id = _id;
        description = _description;

        // Initialize pointers to NULL
        next = NULL;
        previous = NULL;
    }
};


//---------------------------- Functions for program --------------------------

void insertEmployee(Employee *employee)
{
    // Insert employee in the bottom of the list
    if (headEmployee == NULL)
    {
        headEmployee = employee;
        tailEmployee = employee;
    }
    else
    {
        tailEmployee->next = employee;
        employee->previous = tailEmployee;
        tailEmployee = employee;
    }
}

void recolectNewEmployeeData()
{
    cout << endl;
    cout << endl;
    // Add a new employee to the list
    cout << "Add a new employee" << endl;
    cout << endl;
    cout << "Insert the employee name: ";
    string name;
    getline(cin, name);
    cout << "Insert the employee last name: ";
    string lastName;
    getline(cin, lastName);
    cout << "Insert the employee ID: ";
    string id;
    getline(cin, id);
    cout << "Insert the employee age: ";
    int age;
    cin >> age;
    cin.ignore();
    cout << "Insert the employee position: ";
    string position;
    getline(cin, position);
    cout << "Insert the employee department: ";
    string department;
    getline(cin, department);
    cout << "Insert the employee email: ";
    string email;
    getline(cin, email);
    cout << "Insert the employee phone: ";
    string phone;
    getline(cin, phone);
    cout << "Insert the employee modality pay: ";
    string modalityPay;
    getline(cin, modalityPay);
    cout << "Insert the employee salary: ";
    string salary;
    getline(cin, salary);

    // Create the new employee
    Employee *newEmployee = new Employee(name, lastName, id, age, position, department, email, phone, modalityPay, salary);
    insertEmployee(newEmployee);

}

void addData(){
    // Employee data
    Employee *employee1 = new Employee("Juan", "Perez", "123456789", 25, "Gerente", "Gerencia", "juan@corro.com", "12345678", "Mensual", "1000000");
    insertEmployee(employee1);
    Employee *employee2 = new Employee("Maria", "Gonzalez", "987654321", 30, "Gerente", "Gerencia", "maria@correo", "87654321", "Mensual", "1000000");
    insertEmployee(employee2);
    Employee *employee3 = new Employee("Pedro", "Garcia", "123456789", 25, "Gerente", "Gerencia", "pedro@correo", "12345678", "Mensual", "1000000");
    insertEmployee(employee3);

    // Inventory data
    Material *material1 = new Material("Silicon");
    Material *material2 = new Material("Plastic");
    Material *material3 = new Material("Copper");
    Material *material4 = new Material("Steel");
    Material *material5 = new Material("Aluminum");
    Material *material6 = new Material("Silicon");
    //Add more Microprocessors materials
}


// Employee System Functions --------------------------------------------------
void consultEmployee()
{
    //Print menu options for consult employee
    cout << endl;
 cout << endl;
    cout << "Choose the option you want to perform:" << endl;
    cout << "1 - Add a new employee" << endl;
    cout << "2 - Modify an employee" << endl;
    cout << "3 - Sort employees by alphabetic order" << endl;
    cout << "4 - Sort employees by ag" << endl;
    cout << "5 - Print employee list" << endl;
    cout << "6 - Calculate salary for an employee" << endl;
    cout << "7 - Close menu" << endl;

    // Choose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        cout << "Add a new employee" << endl;
        // addNewEmployee(); // <- Call the function to add a new employee
        break;
    case 2:
        cout << "Modify an employee" << endl;
        // modifyEmployee(); // <- Call the function to modify an employee
        break;
    case 3:
        cout << "Sort employees by alphabetic order" << endl;
        // sortEmployeesByAlphOrder(); // <- Call the function to sort employees by criteria 1
        break;
    case 4:
        cout << "Sort employees by age" << endl;
        // sortEmployeesByAge(); // <- Call the function to sort employees by criteria 2
        break;
    case 5:
        cout << "Print employee list" << endl;
        // printEmployeeList(); // <- Call the function to print the employee list
        break;
    case 6:
        cout << "Calculate salary for an employee" << endl;
        // calculateSalary(); // <- Call the function to calculate salary for an employee
        break;
    case 7:
        cout << "Close menu" << endl;
        // Only close the menu
        break;
    default:
        break;
    }
}

// Employee System Functions --------------------------------------------------


// Inventory System Functions -------------------------------------------------
void consultInventory()
{
    // Print menu options for consult inventory
    cout << endl;
    cout << endl;
    cout << "Choose the option you want to perform:" << endl;
    cout << "1 - Consult the stock" << endl;
    cout << "2 - Consult a product list sorted by quantity" << endl;
    cout << "3 - Consult a product list sorted by alphabetical order" << endl;
    cout << "4 - Add a new product" << endl;
    cout << "5 - Increase stock for an existing product" << endl;
    cout << "6 - Decrease stock for an existing product" << endl;
    cout << "7 - Show stock by category" << endl;
    cout << "8 - Close menu" << endl;

    // Choose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        cout << "Consult the stock" << endl;
        // consultStock(); // <- Call the function to consult the stock
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
        cout << "Add a new product" << endl;
        // addNewProduct(); // <- Call the function to add a new product
        break;
    case 5:
        cout << "Increase stock for an existing product" << endl;
        // increaseStock(); // <- Call the function to increase stock for an existing product
        break;
    case 6:
        cout << "Decrease stock for an existing product" << endl;
        // decreaseStock(); // <- Call the function to decrease stock for an existing product
        break;
    case 7:
        cout << "Show stock by category" << endl;
        // showStockByCategory(); // <- Call the function to show stock by category
        break;
    case 8:
        cout << "Close menu" << endl;
        // Only close the menu
        break;
    default:
        break;
    }
}
// Inventory System Functions -------------------------------------------------



//Procution Line System Functions ---------------------------------------------
void consultProductionLine()
{
    // Print menu options for consult production line
    cout << endl;
    cout << "Choose the option you want to perform:" << endl;
    cout << "1 - Consult a production line data" << endl;
    cout << "2 - Consult a specific product" << endl;
    cout << "3 - Modify the state of a product" << endl;
    cout << "4 - Close menu" << endl;

    // Choose the option
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
        cout << "Consult a specific product" << endl;
        // consultSpecificProduct(); // <- Call the function to consult a specific product
        break;
    case 3:
        cout << "Modify the state of a product" << endl;
        // modifyProductState(); // <- Call the function to modify the state of a product
        break;
    case 4:
        cout << "Close menu" << endl;
        // Only close the menu
        break;
    default:
        break;
    }
}
//Procution Line System Functions ---------------------------------------------


// ---------------------------- Functions for program --------------------------







// ------------------------------- Main function --------------------------------
int main()
{
    //addData(); // <- Call the function to add data to the program
    cout << "Welcome to SiliconLogic - Your Job Information Portal" << endl;   
    cout << "What area of the company would you like to see?:" << endl;
    cout << endl;
    cout << "1 - View employee information" << endl;
    cout << "2 - Consult Inventory" << endl;
    cout << "3 - Check the Production Line" << endl;
    cout << "4 - Close menu" << endl;
    cout << endl;

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