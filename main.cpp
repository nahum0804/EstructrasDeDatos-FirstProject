#include <iostream>

using namespace std;

// Employee System Structs

// Define a struct to represent a Journey (workday)
struct Journey {
    string date;     // Date of the workday
    int hours;    // Hours worked on the workday
    string modality; // Modality of the workday (Per hour or complete day)

    Journey *next;   // Pointer to the next Journey in a list

    // Constructor to initialize a Journey object
    Journey(string _date, int _hours, string _modality)
    {
        // Initialize Journey properties
        date = _date;
        hours = _hours;
        modality = _modality;

        // Initialize pointer to NULL
        next = NULL;
    }
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
    int salary;         // Employee's base salary

    Employee *next;        // Pointer to the next Employee in a list
    Employee *previous;    // Pointer to the previous Employee in a list
    Employee *boss;        // Pointer to the Employee's boss (if applicable)
    
    Journey journeys; // Pointer to a list of Journeys associated with the Employee

    // Constructor to initialize an Employee object
    Employee(string _name, string _lastName, string _id, int _age, string _position, string _department, string _email, string _phone, string _modalityPay, int _salary)
        : journeys("",0,"")
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

        // Initialize the list of Journeys
    }
} *headEmployee, *tailEmployee; 



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

//Prototypes 
void consultEmployee();
void consultInventory();
void consultProductionLine();
void addData();

//Prototypes for Employee System
void insertEmployee(Employee *employee);
void recolectNewEmployeeData();
void printEmployeeList();

void modifyEmployee();
void modifyEmployeeName(string id);
void modifyEmployeeLastName(string id);
void modifyEmployeeAge(string id);
void modifyEmployeePosition(string id);
void modifyEmployeeDepartment(string id);
void modifyEmployeeEmail(string id);
void modifyEmployeePhone(string id);
void modifyEmployeeModalityPay(string id);
void modifyEmployeeSalary(string id);
void addJourney(string id, Journey *journey);
void calculateSalary();



//Prototypes for Inventory System


//Prototypes for Production Line System



//---------------------------- Functions for program --------------------------

void insertJourney(string id, Journey *journey)
{
    //Search the employee
    Employee *current = headEmployee;
    if(current == NULL){
        cout << "Employee not found" << endl;
        return;
    } else {
        while(current != NULL){
            if(current->id == id){
                //Insert the journey like simple list
                Journey *currentJourney = &current->journeys;
                while(currentJourney->next != NULL){
                    currentJourney = currentJourney->next;
                }
                currentJourney->next = journey;
                cout << "Journey added successfully" << endl;
            }
            current = current->next;
        }
    }
}


void insertEmployee(Employee *employee)
{
    // Check if an employee with the same ID already exists
    Employee *current = headEmployee;
    while (current != nullptr)
    {
        if (current->id == employee->id)
        {
            cout << "Employee with ID " << employee->id << " already exists in the list." << endl;
            return; // Exit the function if an employee with the same ID is found
        }
        current = current->next;
    }

    // Insert employee in the bottom of the list
    if (headEmployee == nullptr)
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

    cout << "Employee added successfully." << endl;
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
    int salary;
    cin >> salary;
    cin.ignore();

    // Create the new employee
    Employee *newEmployee = new Employee(name, lastName, id, age, position, department, email, phone, modalityPay, salary);
    insertEmployee(newEmployee);

}

//Print Employee List
void printEmployeeList(){
    Employee *current = headEmployee;
    while(current != NULL){
        cout << "Name: " << current->name << endl;
        cout << "Last Name: " << current->lastName << endl;
        cout << "ID: " << current->id << endl;
        cout << "Age: " << current->age << endl;
        cout << "Position: " << current->position << endl;
        cout << "Department: " << current->department << endl;
        cout << "Email: " << current->email << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Modality Pay: " << current->modalityPay << endl;
        cout << "Salary: " << current->salary << endl;
        cout << endl;
        current = current->next;
    }

    //Jump to the employee menu
    consultEmployee();
}

//Modify Employee
void modifyEmployee(){

    //Get ID of the employee to modify
    cout << "Insert the ID of the employee you want to modify: ";
    string id;
    getline(cin, id);

    //Print menu options for modify employee
    cout << endl;
    cout << endl;
    cout << "Choose the option you want to perform:" << endl;
    cout << "1 - Modify employee name" << endl;
    cout << "2 - Modify employee last name" << endl;
    cout << "3 - Modify employee age" << endl;
    cout << "4 - Modify employee position" << endl;
    cout << "5 - Modify employee department" << endl;
    cout << "6 - Modify employee email" << endl;
    cout << "7 - Modify employee phone" << endl;
    cout << "8 - Modify employee modality pay" << endl;
    cout << "9 - Modify employee salary" << endl;
    cout << "10 - Close menu" << endl;

    // Choose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        cout << "Modify employee name" << endl;
        modifyEmployeeName(id); // <- Call the function to modify employee name
        break;
    case 2:
        cout << "Modify employee last name" << endl;
        modifyEmployeeLastName(id); // <- Call the function to modify employee last name
        break;
    case 3:
        cout << "Modify employee age" << endl;
        modifyEmployeeAge(id); // <- Call the function to modify employee age
        break;
    case 4:
        cout << "Modify employee position" << endl;
        modifyEmployeePosition(id); // <- Call the function to modify employee position
        break;
    case 5:
        cout << "Modify employee department" << endl;
        modifyEmployeeDepartment(id); // <- Call the function to modify employee department
        break;
    case 6:
        cout << "Modify employee email" << endl;
        modifyEmployeeEmail(id); // <- Call the function to modify employee email
        break;
    case 7:
        cout << "Modify employee phone" << endl;
        modifyEmployeePhone(id); // <- Call the function to modify employee phone
        break;
    case 8:
        cout << "Modify employee modality pay" << endl;
        modifyEmployeeModalityPay(id); // <- Call the function to modify employee modality pay
        break;
    case 9:
        cout << "Modify employee salary" << endl;
        modifyEmployeeSalary(id); // <- Call the function to modify employee salary
        break;
    case 10:
        cout << "Close menu" << endl;
        // Only close the menu
        break;
    default:
        break;
    }

    cout << endl;
    cout << endl;
    printEmployeeList();  // <- Call the function to print the employee list with the new employee
}

//Modify Functions
void modifyEmployeeName(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new name: ";
            string name;
            getline(cin, name);
            current->name = name;
            cout << "Name modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}

void modifyEmployeeLastName(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new last name: ";
            string lastName;
            getline(cin, lastName);
            current->lastName = lastName;
            cout << "Last name modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}

void modifyEmployeeAge(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new age: ";
            int age;
            cin >> age;
            cin.ignore();
            current->age = age;
            cout << "Age modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}

void modifyEmployeePosition(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new position: ";
            string position;
            getline(cin, position);
            current->position = position;
            cout << "Position modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}

void modifyEmployeeDepartment(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new department: ";
            string department;
            getline(cin, department);
            current->department = department;
            cout << "Department modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}

void modifyEmployeeEmail(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new email: ";
            string email;
            getline(cin, email);
            current->email = email;
            cout << "Email modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}

void modifyEmployeePhone(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new phone: ";
            string phone;
            getline(cin, phone);
            current->phone = phone;
            cout << "Phone modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}

void modifyEmployeeModalityPay(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new modality pay: ";
            string modalityPay;
            getline(cin, modalityPay);
            current->modalityPay = modalityPay;
            cout << "Modality pay modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}

void modifyEmployeeSalary(string id){
    Employee *current = headEmployee;
    while(current != NULL){
        if(current->id == id){
            cout << "Insert the new salary: ";
            int salary;
            cin >> salary;
            cin.ignore();
            current->salary = salary;
            cout << "Salary modified successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found" << endl;
}


//Print sorted employee list by age - Minor to major
void printSortEmployeesByAgeMinorTo() {
    // Create a temporary copy of the employee list
    Employee *tempList = nullptr;
    Employee *current = headEmployee;
    while (current != nullptr) {
        Employee *newEmployee = new Employee(*current); // Create a copy of the employee
        newEmployee->next = tempList;
        tempList = newEmployee;
        current = current->next;
    }

    // Perform a bubble sort on the temporary list by age (from youngest to oldest)
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        current = tempList;
        Employee *prev = nullptr;
        Employee *nextNode = nullptr;

        while (current->next != nullptr) {
            nextNode = current->next;

            if (current->age > nextNode->age) {
                // Swap the pointers, not the content of nodes
                current->next = nextNode->next;
                nextNode->next = current;

                if (prev == nullptr) {
                    tempList = nextNode;
                } else {
                    prev->next = nextNode;
                }

                prev = nextNode;
                sorted = false;
            } else {
                prev = current;
                current = nextNode;
            }
        }
    }

    // Print the sorted temporary list (from youngest to oldest)
    current = tempList;
    while (current != nullptr) {
        cout << "Name: " << current->name << endl;
        cout << "Last Name: " << current->lastName << endl;
        cout << "ID: " << current->id << endl;
        cout << "Age: " << current->age << endl;
        cout << "Position: " << current->position << endl;
        cout << "Department: " << current->department << endl;
        cout << "Email: " << current->email << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Modality Pay: " << current->modalityPay << endl;
        cout << "Salary: " << current->salary << endl;
        cout << endl;
        current = current->next;
    }

    // Clean up the temporary list (delete allocated memory)
    current = tempList;
    while (current != nullptr) {
        Employee *next = current->next;
        delete current;
        current = next;
    }

    // Jump to the employee menu
    consultEmployee();
}

//Print sorted employee list by age  - Major to minor
void printSortEmployeesByAgeMajorTo() {
    Employee *current = headEmployee;
    Employee *prev = nullptr;
    Employee *nextNode = nullptr;

    // If the list is empty or has only one element, there's no need to sort it.
    if (headEmployee == nullptr || headEmployee->next == nullptr) {
        consultEmployee(); // Exit the function
    }

    // Perform a bubble sort on the linked list by age (from oldest to youngest)
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        current = headEmployee;
        prev = nullptr;

        while (current->next != nullptr) {
            nextNode = current->next;

            if (current->age < nextNode->age) {
                // Swap the pointers, not the content of nodes
                current->next = nextNode->next;
                nextNode->next = current;

                if (prev == nullptr) {
                    headEmployee = nextNode;
                } else {
                    prev->next = nextNode;
                }

                prev = nextNode;
                sorted = false;
            } else {
                prev = current;
                current = nextNode;
            }
        }
    }

    // Print the sorted list
    current = headEmployee;
    while (current != nullptr) {
        cout << "Name: " << current->name << endl;
        cout << "Last Name: " << current->lastName << endl;
        cout << "ID: " << current->id << endl;
        cout << "Age: " << current->age << endl;
        cout << "Position: " << current->position << endl;
        cout << "Department: " << current->department << endl;
        cout << "Email: " << current->email << endl;
        cout << "Phone: " << current->phone << endl;
        cout << "Modality Pay: " << current->modalityPay << endl;
        cout << "Salary: " << current->salary << endl;
        cout << endl;
        current = current->next;
    }

    // Jump to the employee menu
    consultEmployee();
}



//Add Data
void addData(){
    // Employee data
    Employee *employee1 = new Employee("Juan", "Perez", "123456789", 25, "Gerente", "Gerencia", "juan@corro.com", "12345678", "Complete Journey", 10000);
    insertEmployee(employee1);

      //Add Journeys to employee1
    Journey *journey1 = new Journey("01/01/2021", 8, "Normal");
    insertJourney(employee1->id, journey1);
    Journey *journey2 = new Journey("02/01/2021", 3, "Holiday");
    insertJourney(employee1->id, journey2);
    Journey *journey3 = new Journey("03/01/2021", 5, "Weekend");
    insertJourney(employee1->id, journey3);

    Employee *employee2 = new Employee("Maria", "Gonzalez", "987654321", 30, "Gerente", "Gerencia", "maria@correo", "87654321", "Per hour", 1500);
    insertEmployee(employee2);

    //Add Journeys to employee2
    Journey *journey4 = new Journey("01/01/2021", 19, "Normal");
    insertJourney(employee2->id, journey4);
    Journey *journey5 = new Journey("02/01/2021", 3, "Holiday");
    insertJourney(employee2->id, journey5);


    Employee *employee3 = new Employee("Pedro", "Garcia", "12345678", 25, "Gerente", "Gerencia", "pedro@correo", "12345678", "Complete Journey", 15000);
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

//Calculate Salary
void calculateSalary(){
    //Calculate salary for an employee
    //  - Search the employee
    //  - Search and calculate the salary in the journeys
    //  - Normal: 1000 per hour
    //  - Extra: 1500 per hour
    //  - Double: 2000 per hour
    //  - Holiday: 2500 per hour
    //  - Weekend: 3000 per hour



    //Get ID of the employee to calculate salary
    cout << "Insert the ID of the employee you want to calculate salary: ";
    string id;
    getline(cin, id);

    //Search the employee
    Employee *current = headEmployee;
    if(current == NULL){
        cout << "Employee not found" << endl;
        return;
    } else {
        while(current != NULL){
            if(current->id == id){
                cout << current->modalityPay << endl;
                //Search and calculate the salary in the journeys
                Journey *currentJourney = &current->journeys;
                int amountPay = 0;
                if(current->modalityPay == "Complete Journey"){
                    while(currentJourney->next != NULL){
                        if(currentJourney->hours == 8){
                            amountPay += current->salary;  //Normal hours
                        } else if(currentJourney->hours > 8){
                            amountPay += current->salary + ((currentJourney->hours - 8) * (current->salary * 1.5));  //Extra hours
                        } else if(currentJourney->hours < 8){
                            amountPay += current->salary - ((8 - currentJourney->hours) * (current->salary * 1.5));  //Less hours 
                        }
                        currentJourney = currentJourney->next;
                    }
                    cout << "Salary: " << amountPay << endl;
                    //Back to the employee menu
                    consultEmployee();
                    return;
                } else if(current->modalityPay == "Per hour"){
                    while(currentJourney->next != NULL){
                        if(currentJourney->modality == "Normal"){
                            amountPay += currentJourney->hours * current->salary;
                        } else if(currentJourney->modality == "Extra"){
                            amountPay += currentJourney->hours * ((current->salary) * 1.5) ;
                        } else if(currentJourney->modality == "Double"){
                            amountPay += currentJourney->hours * ((current->salary) * 2);
                        } else if(currentJourney->modality == "Holiday"){
                            amountPay += currentJourney->hours * ((current->salary) * 1.75);
                        } else if(currentJourney->modality == "Weekend"){
                            amountPay += currentJourney->hours * ((current->salary) * 1.85);
                        }
                        currentJourney = currentJourney->next;
                    }
                    cout << "Salary: " << amountPay << endl;
                    //Back to the employee menu
                    consultEmployee();
                }
            }
            current = current->next;
        }
    }
    cout << "Employee not found" << endl;
}

//Delete Employee
void deleteEmployee(){
    //Get ID of the employee to delete
    cout << "Insert the ID of the employee you want to delete: ";
    string id;
    getline(cin, id);

    //Search the employee
    Employee *current = headEmployee;
    if(current == NULL){
        cout << "Employee not found" << endl;
        return;
    } else {
        while(current != NULL){
            if(current->id == id){
                //Delete the employee
                if(current == headEmployee){
                    headEmployee = current->next;
                    headEmployee->previous = NULL;
                    delete current;
                    cout << "Employee deleted successfully" << endl;
                    return;
                    //Back to the employee menu
                    consultEmployee();
                } else if(current == tailEmployee){
                    tailEmployee = current->previous;
                    tailEmployee->next = NULL;
                    delete current;
                    cout << "Employee deleted successfully" << endl;
                    //Back to the employee menu
                    consultEmployee();
                    return;
                } else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    delete current;
                    cout << "Employee deleted successfully" << endl;
                    //Back to the employee menu
                    consultEmployee();
                    return;
                }
            }
            current = current->next;
        }
    }
    cout << "Employee not found" << endl;
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
    cout << "3 - Sort employees by age - Minor to Major" << endl;
    cout << "4 - Sort employees by age - Mayor To Minor" << endl;
    cout << "5 - Print employee list" << endl;
    cout << "6 - Calculate salary for an employee" << endl;
    cout << "7 - Delete an employee" << endl;
    cout << "8 - Exit" << endl;

    // Choose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        recolectNewEmployeeData(); // <- Call the function to add a new employee
        cout << endl;
        cout << endl;
        printEmployeeList();  // <- Call the function to print the employee list with the new employee
        break;
    case 2:
        modifyEmployee(); // <- Call the function to modify an employee
        break;
    case 3:
        printSortEmployeesByAgeMinorTo(); // <- Call the function to sort employees by criteria 1
        break;
    case 4:
        printSortEmployeesByAgeMajorTo(); // <- Call the function to sort employees by criteria 2
        break;
    case 5:
        printEmployeeList(); // <- Call the function to print the employee list
        break;
    case 6:
        calculateSalary(); // <- Call the function to calculate salary for an employee
        break;
    case 7:
        // deleteEmployee(); // <- Call the function to delete an employee
        break;
    case 8:
        // Close the menu
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
    addData(); // <- Call the function to add data to the program
    cout << endl;
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