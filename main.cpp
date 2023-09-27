#include <iostream>

// Import libs for generate a random string
#include <string>
#include <random>
#include <ctime>

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
    //Materials for the production line - Names
    // 1 - Silicon
    // 2 - Plastic
    // 3 - Cleaning Chemicals
    // 4 - Copper
    // 5 - Gold

    string name;
    string id;
    Material *next;
    Material *previous;

    Material(string _name, string _id){
        name = _name;
        id = _id;
        next = NULL;
        previous = NULL;
    }   
} *headMaterial, *tailMaterial;

// Define a struct to represent a Product
struct Product {
    string name;        // Product name
    string id;          // Product ID or identification number
    string description; // Product description
    string productionStage; // Product production stage
    // Procuction Stages 
    // 1 - Design and deploy the product
    // 2 - wafer build - Less Silicon
    // 3 - Material Layer Deposition - Less Copper
    // 4 - Testing and Assembly - Less Plastic, less gold, less cleaning chemicals 


    Product *next;     // Pointer to the next Product in a list
    Product *previous; // Pointer to the previous Product in a list

    // Constructor to initialize a Product object   --  Config circular list
    Product(string _name, string _id, string _description, string _productionStage)
    {
        // Initialize Product properties
        name = _name;
        id = _id;
        description = _description;
        productionStage = _productionStage;

        // Initialize pointers to NULL
        next = NULL;
        previous = NULL;
    }
} *headProduct, *tailProduct; // <- Global pointers to the first and last Product in a list

//Prototypes 
void consultEmployee();
void consultInventory();
void consultProductionLine();
void addData();

void menuMain();

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
void addMaterial(Material *material);
void consultStock();
void consultProductListByQuantity();
string generateRandomString();
void deleteMaterial();
void deleteMt(const string& nameToDelete);


//Prototypes for Production Line System
void addProduct(Product *product);
Product* findProductById(const string& idToFind);
void addProductWithCheck();
bool checkMaterialsForCategory(const string& category);
void deleteProduct(const string& idToDelete);
void deletePr();


//---------------------------- Functions for program --------------------------


//This function add Journey to an employee
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


//This function add Employee to the employees list
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

//Collect employee data and then add it to the list
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
        menuMain(); // <- Call the function to return to the main menu
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
    //Using unique ID for search the employee 

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
    //Using unique ID for search the employee 

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
    //Using unique ID for search the employee

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
    //Using unique ID for search the employee

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
    //Using unique ID for search the employee

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
    //Using unique ID for search the employee

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
    //Using unique ID for search the employee

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
    //Using unique ID for search the employee

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
    //Using unique ID for search the employee 

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
    //Function for add data to the program by default

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
    Material *material1 = new Material("Silicon", generateRandomString());
    addMaterial(material1);
    Material *material2 = new Material("Plastic", generateRandomString());
    addMaterial(material2);
    Material *material3 = new Material("Copper", generateRandomString());
    addMaterial(material3);
    Material *material4 = new Material("Cleaning Chemicals", generateRandomString());
    addMaterial(material4);
    Material *material5 = new Material("Cleaning Chemicals", generateRandomString());
    addMaterial(material5);
    Material *material6 = new Material("Silicon", generateRandomString());
    addMaterial(material6);
    Material *material7 = new Material("Plastic", generateRandomString());
    addMaterial(material7);
    Material *material8 = new Material("Copper", generateRandomString());
    addMaterial(material8);
    Material *material9 = new Material("Silicon", generateRandomString());
    addMaterial(material9);
    Material *material10 = new Material("Plastic", generateRandomString());
    addMaterial(material10);
    Material *material11 = new Material("Copper", generateRandomString());
    addMaterial(material11);
    Material *material12 = new Material("Silicon", generateRandomString());
    addMaterial(material12);
    Material *material13 = new Material("Plastic", generateRandomString());
    addMaterial(material13);
    Material *material14 = new Material("Copper", generateRandomString());
    addMaterial(material14);
    Material *material15 = new Material("Cleaning Chemicals", generateRandomString());
    addMaterial(material15);
    Material *material16 = new Material("Cleaning Chemicals", generateRandomString());
    addMaterial(material16);
    Material *material17 = new Material("Silicon", generateRandomString());
    addMaterial(material17);
    Material *material18 = new Material("Gold", generateRandomString());
    addMaterial(material18);
    Material *material19 = new Material("Gold", generateRandomString());
    addMaterial(material19);
    Material *material20 = new Material("Gold", generateRandomString());
    addMaterial(material20);
    Material *material21 = new Material("Gold", generateRandomString());
    addMaterial(material21);
    Material *material22 = new Material("Gold", generateRandomString());
    addMaterial(material22);
    Material *material23 = new Material("Silicon", generateRandomString());
    addMaterial(material23);
    Material *material24 = new Material("Plastic", generateRandomString());
    addMaterial(material24);
    Material *material25 = new Material("Copper", generateRandomString());
    addMaterial(material25);
    Material *material26 = new Material("Cleaning Chemicals", generateRandomString());
    addMaterial(material26);
    Material *material27 = new Material("Cleaning Chemicals", generateRandomString());
    addMaterial(material27);

    //Add more Electronic Components
    Product *product1 = new Product("USB Port", "123456789", "USB port for laptop", "Design and deploy the product");
    addProduct(product1);
    Product *product2 = new Product("HDMI Port", "987654321", "HDMI port for SmartTV", "Wafer build");
    addProduct(product2);
    Product *procuct3 = new Product("SD Card Port", "12345678", "SD Card Port for Camera", "Material Layer Deposition");
    addProduct(procuct3);
    Product *product4 = new Product("Headphone Jack", "87654321", "Headphone Jack", "Testing and Assembly");
    addProduct(product4);
    Product *product5 = new Product("RAM Memory", "2023","RAM Memory DDR5","Design and deploy the product");
    addProduct(product5);
    Product *product6 = new Product("CPU", "2024","CPU Intel i9 knockoff","Wafer build");
    addProduct(product6);
}

//Calculate Salary
void calculateSalary(){
    //Calculate salary for an employee



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
                if(current->modalityPay == "Complete Journey"){  //In case the employee is paid by complete journey
                    while(currentJourney->next != NULL){
                        //Show the Journey data
                        cout << endl;
                        if(currentJourney->date != "" && currentJourney->hours != 0 && currentJourney->modality != ""){
                            cout << "Date: " << currentJourney->date << endl;
                            cout << "Hours: " << currentJourney->hours << endl;
                            cout << "Modality: " << currentJourney->modality << endl;}
                        if(currentJourney->hours == 8){
                            amountPay += current->salary;  //Normal hours
                        } else if(currentJourney->hours > 8){
                            amountPay += current->salary + ((currentJourney->hours - 8) * (current->salary * 1.5));  //Extra hours
                        } else if(currentJourney->hours < 8){
                            //Pay like normal hours
                            amountPay += current->salary;
                        }
                        currentJourney = currentJourney->next;
                    }
                    cout << "Salary: " << amountPay << endl;
                    //Back to the employee menu
                    consultEmployee();
                    return;
                } else if(current->modalityPay == "Per hour"){  //In case the employee is paid per hour
                    while(currentJourney->next != NULL){
                        //Show the Journey data
                        if(currentJourney->date != "" && currentJourney->hours != 0 && currentJourney->modality != ""){
                            cout << endl;
                            cout << "Date: " << currentJourney->date << endl;
                            cout << "Hours: " << currentJourney->hours << endl;
                            cout << "Modality: " << currentJourney->modality << endl;
                        }
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
                    cout << endl;
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
    //Principal menu for consult employee

    //Print menu options for consult employee
    cout << endl;
    cout << endl;
    cout << "Choose the option you want to perform:" << endl;
    cout << "1 - Add a new employee" << endl;
    cout << "2 - Modify an employee" << endl;
    cout << "3 - Print employees sorted by age - Minor to Major" << endl;
    cout << "4 - Print employees by sorted age - Mayor To Minor" << endl;
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
        deleteEmployee(); // <- Call the function to delete an employee
        break;
    case 8:
        menuMain(); // <- Call the function to return to the main menu
        break;
    default:
        break;
    }
}

// Employee System Functions --------------------------------------------------


// Inventory System Functions -------------------------------------------------

std::string generateRandomString() {
    //Function for generate a random string for the ID of the material

    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int stringLength = 6; // Longitud de la cadena aleatoria
    std::string randomString;

    std::random_device rd; // Utiliza una fuente de aleatoriedad verdadera si está disponible
    std::mt19937 gen(rd()); // Mersenne Twister como generador
    std::uniform_int_distribution<int> dis(0, characters.length() - 1);

    for (int i = 0; i < stringLength; ++i) {
        randomString += characters[dis(gen)];
    }

    return randomString;
}

//Add Material
void addMaterial(Material *material)
{
    //Add material in the Inventory Stock

    //Double-linked circular list
    Material *current = headMaterial;
    if(current == NULL){
        headMaterial = material;
        tailMaterial = material;

        tailMaterial->next = headMaterial;
        headMaterial->previous = tailMaterial;
    } else {
        tailMaterial->next = material;
        material->previous = tailMaterial;
        tailMaterial = material;
        tailMaterial->next = headMaterial;
        headMaterial->previous = tailMaterial;
    }
    cout << "Material added successfully" << endl;
}

//Print double-linked circular list
void consultStock() {

    //Print the stock list
    if (headMaterial == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    Material *current = headMaterial;
    //Get ID of the first element in the list
    string firstMaterialID = headMaterial->id;
    int contador = 0;

    //Scroll through the list using the counter variable to mark the initial item in the list and stop at the second time it is encountered.
    do {
        cout << "Name: " << current->name << endl;
        cout << endl;
        current = current->next;
        if(current->id == firstMaterialID){
            contador++;
        }
    } while (contador < 2);

    consultInventory();
}


//Print stock list in base of quantity
void consultProductListByQuantity() {
    //Quantity of each material
    int silicon = 0;
    int plastic = 0;
    int copper = 0;
    int cleaningChemicals = 0;
    int gold = 0;

    if (headMaterial == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Material *current = headMaterial;

    string firstMaterialID = headMaterial->id;

    //Scroll through the list using the unique ID.
    do {
        if (current->name == "Silicon") {
            silicon++;
        } else if (current->name == "Plastic") {
            plastic++;
        } else if (current->name == "Copper") {
            copper++;
        } else if (current->name == "Cleaning Chemicals") {
            cleaningChemicals++;
        } else if (current->name == "Gold") {
            gold++;
        }

        // Move to the next node
        current = current->next;

    } while (current != headMaterial);

    cout << "Quantity of Silicon: " << silicon << endl;
    cout << "Quantity of Plastic: " << plastic << endl;
    cout << "Quantity of Copper: " << copper << endl;
    cout << "Quantity of Cleaning Chemicals: " << cleaningChemicals << endl;
    cout << "Quantity of Gold: " << gold << endl;

    //Back to the material menu
    consultInventory();
}

void addNewMaterial(){
    cout << endl;
    //Print the options for choose
    cout << "Material that you can choose: " << endl;
    cout << "Silicon" << endl;
    cout << "Plastic" << endl;
    cout << "Copper" << endl;
    cout << "Cleaning Chemicals" << endl;
    cout << "Gold" << endl;
    cout << "Choose a option" << endl;
    cout << endl;

    //Get a option
    string material;
    getline(cin, material);

    Material *materialObj = new Material(material, generateRandomString());
    addMaterial(materialObj);
    consultInventory();
}

void deleteMaterial(){
    // Get data
    cout << "Type the name of the material you want to delete (Only deletes the first occurrence in the stock): " << endl;
    string nameDelete;
    getline(cin, nameDelete);

    Material *current = headMaterial;

    // Search for the first element with the desired name
    while (current != nullptr) {
        if (current->name == nameDelete) {
            // Element found, delete it

            // If the element to delete is the first element (headMaterial)
            if (current == headMaterial) {
                headMaterial = headMaterial->next; // Update the list head
                if (headMaterial != nullptr) {
                    headMaterial->previous = tailMaterial; // Update the previous pointer of the new first element
                    tailMaterial->next = headMaterial; // Update the next pointer of the tail element
                } else {
                    // The list is now empty
                    tailMaterial = nullptr;
                }
            } else {
                // The element to delete is not the first element
                current->previous->next = current->next; // Update the next pointer of the previous element
                if (current->next != nullptr) {
                    current->next->previous = current->previous; // Update the previous pointer of the next element
                }
            }

            // Free memory of the deleted element
            delete current;

            cout << "Material with the name '" << nameDelete << "' deleted." << endl;

            // Return to the menu
            consultInventory();
            return; // Exit the function
        }
        current = current->next;
    }

    // If the material is not found, display a message
    cout << "Material with the name '" << nameDelete << "' not found." << endl;

    // Return to the menu
    consultInventory();
}

//Delete materials from the production line
void deleteMt(const string& nameToDelete) {
    Material *current = headMaterial;

    // Search for the first element with the desired name
    while (current != nullptr) {
        if (current->name == nameToDelete) {
            // Element found, delete it

            // If the element to delete is the first element (headMaterial)
            if (current == headMaterial) {
                headMaterial = headMaterial->next; // Update the list head
                if (headMaterial != nullptr) {
                    headMaterial->previous = tailMaterial; // Update the previous pointer of the new first element
                    tailMaterial->next = headMaterial; // Update the next pointer of the tail element
                } else {
                    // The list is now empty
                    tailMaterial = nullptr;
                }
            } else {
                // The element to delete is not the first element
                current->previous->next = current->next; // Update the next pointer of the previous element
                if (current->next != nullptr) {
                    current->next->previous = current->previous; // Update the previous pointer of the next element
                }
            }

            // Free memory of the deleted element
            delete current;

            cout << "Material with the name '" << nameToDelete << "' deleted." << endl;

            return; // Exit the function
        }
        current = current->next;
    }

    // If the material is not found, display a message
    cout << "Material with the name '" << nameToDelete << "' not found." << endl;

    // Return to the menu
    consultInventory();
}


/// Show the materials in the inventory by category
void showByCategory() {
    // Get data
    cout << "Type the name of the material you want to find (Only finds elements with the specified name): " << endl;
    string nameToFind;
    getline(cin, nameToFind);
    cout << endl;

    if (headMaterial == nullptr) {
        // If the list is empty, display a message
        cout << "The list is empty." << endl;
        consultInventory();
        return;
    }

    Material *current = headMaterial;
    bool found = false;

    do {
        if (current->name == nameToFind) {
            // Element found, print its details
            cout << "Name: " << current->name << endl;
            cout << "ID: " << current->id << endl;
            
            cout << endl;

            found = true;
        }
        current = current->next;
    } while (current != headMaterial);

    if (!found) {
        // If no elements with the specified name were found, display a message
        cout << "No materials with the name '" << nameToFind << "' found." << endl;
        cout << "Note: Respect upper and lower case letters." << endl;
    }

    // Return to the menu
    consultInventory();
}


void consultInventory()
{
    // Print menu options for consult inventory
    cout << endl;
    cout << endl;
    cout << "Choose the option you want to perform:" << endl;
    cout << "1 - Consult the stock" << endl;
    cout << "2 - Consult a stock list sorted by quantity" << endl;
    cout << "3 - Add a new material" << endl;
    cout << "4 - Delete a material" << endl;
    cout << "5 - Show stock by category" << endl;
    cout << "6 - Close menu" << endl;

    // Choose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        consultStock(); // <- Call the function to consult the stock
        break;
    case 2:
        consultProductListByQuantity(); // <- Call the function to consult a product list sorted by quantity
        break;
    case 3:
        addNewMaterial(); // <- Call the function to add a new material
        break;
    case 4: 
        deleteMaterial();
        break;
    case 5: 
        showByCategory();
        break;
    case 6:
        menuMain();
        break;
    }
}
// Inventory System Functions -------------------------------------------------



//Procution Line System Functions ---------------------------------------------
void addProductWithCheck() {
    // Get data for the new product
    cout << "Enter the product name: ";
    string name;
    getline(cin, name);

    cout << "Enter the product ID: ";
    string id;
    getline(cin, id);

    cout << "Enter the product description: ";
    string description;
    getline(cin, description);

    cout << "Enter the production stage: " << endl;
    //Show the options for choose the production stage
    cout << "1 - Design and deploy the product" << endl;
    cout << "2 - Wafer build" << endl;
    cout << "3 - Material Layer Deposition" << endl;
    cout << "4 - Testing and Assembly" << endl;
    cout << " Choose a option:" << endl;
    int option;
    cin >> option;
    cin.ignore();
    cout << endl;

    string category;

    //Select the category to add the product
    switch (option)
    {
    case 1:
        category = "Design and deploy the product";
        break;
    case 2:
        category = "Wafer build";
        break;
    case 3:
        category = "Material Layer Deposition";
        break;
    case 4:
        category = "Testing and Assembly";
        break;
    default:
        cout << "Invalid option" << endl;
        consultProductionLine(); // Vuelve al menú de producción si la opción es inválida
        return;
    }

    cout << "Check materials in list..." << endl;
    // Check if the required materials are present for the selected category
    if (!checkMaterialsForCategory(category)) {
        cout << "Error: The required materials for the selected category are not available." << endl;
        consultProductionLine(); // Vuelve al menú de producción
        return;
    }

    // Check if a product with the same ID already exists
    if (findProductById(id) != nullptr) {
        cout << "Error: A product with the same ID already exists." << endl;
        consultProductionLine(); // Vuelve al menú de producción
        return;
    }

    // Create a new Product object and add it to the list
    Product *product = new Product(name, id, description, category);
    addProduct(product);


    // Back to the production line menu
    consultProductionLine();
}


bool checkMaterialsForCategory(const string& category) {
    // Initialize counters for required materials
    int silicon = 0;
    int copper = 0;
    int plastic = 0;
    int gold = 0;
    int cleaningChemicals = 0;

    Material *current = headMaterial;

    string firstMaterialID = headMaterial->id;

    do {
        if (current->name == "Silicon") {
            silicon++;
        } else if (current->name == "Plastic") {
            plastic++;
        } else if (current->name == "Copper") {
            copper++;
        } else if (current->name == "Cleaning Chemicals") {
            cleaningChemicals++;
        } else if (current->name == "Gold") {
            gold++;
        }

        // Move to the next node
        current = current->next;

    } while (current != headMaterial);

    // Check if there are enough materials for the specified category
    if ((category == "Wafer build") && (silicon >= 1)) {
        return true;
    } else if ((category == "Material Layer Deposition") && (copper >= 1)) {
        return true;
    } else if ((category == "Testing and Assembly") && (plastic >= 1) && (gold >= 1) && (cleaningChemicals >= 1)) {
        return true;
    } else if(category == "Design and deploy the product") {
        return true;
    } else {
        return false;
    }
}


Product* findProductById(const string& idToFind) {
    Product *current = headProduct;

    // Search for a product with the specified ID
    while (current != nullptr) {
        if (current->id == idToFind) {
            return current; // Return the found product
        }

        // Move to the next element in the list (circular or not)
        current = current->next;

        // Check if we have completed one full iteration of the list
        if (current == headProduct) {
            break; // Exit the loop if we have completed one cycle
        }
    }

    return nullptr; // ID not found
}


void addProduct(Product *product) {
     // If the list is empty, initialize headProduct and tailProduct
    if (headProduct == nullptr) {
        headProduct = product;
        tailProduct = product;
        tailProduct->next = headProduct;
        headProduct->previous = tailProduct;
    } else {
        // Add the new product to the end of the list
        tailProduct->next = product;
        product->previous = tailProduct;
        tailProduct = product;
        tailProduct->next = headProduct; // Connect the last one to the first to form the circle
        headProduct->previous = tailProduct; // Update the previous pointer of the first
    }
    cout << "Product added successfully" << endl;

    cout << "Product getting materials from the inventory..." << endl;

    // Delete the materials used for the product
    if(product->productionStage == "Wafer build") {
        deleteMt("Silicon");
    } else if (product->productionStage == "Material layer deposition") {
        deleteMt("Silicon");
        deleteMt("Copper");
    } else if (product->productionStage == "Testing and Assembly") {
        deleteMt("Silicon");
        deleteMt("Copper");
        deleteMt("Plastic");
        deleteMt("Gold");
        deleteMt("Cleaning Chemicals");
    }
}

//Print double-linked circular list 
void consultProductionLineData() {
    // Check if the list is empty
    if (headProduct == nullptr) {
        cout << "The list is empty." << endl;
        cout << endl;
        consultProductionLine();
        return;
    }

    // Create a pointer to traverse the circular list
    Product* current = headProduct;

    do {
        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->id << endl;
        cout << "Description: " << current->description << endl;
        cout << "Production Stage: " << current->productionStage << endl;
        cout << endl;

        // Move to the next element in the circular list
        current = current->next;
    } while (current != headProduct); // Continue until we reach the head again
    //Back to the production line menu
    consultProductionLine();
}

//Print the specific product by ID
void consultSpecificProduct(){
    //Get ID of the product to consult
    cout << "Insert the ID of the product you want to consult: ";
    string id;
    getline(cin, id);

    //Search the product
    Product *current = headProduct;
    if(current == NULL){
        cout << "Product not found" << endl;
        return;
    } else {
        while(current != NULL){
            if(current->id == id){
                //Show the product data
                cout << "Name: " << current->name << endl;
                cout << "ID: " << current->id << endl;
                cout << "Description: " << current->description << endl;
                cout << "Production Stage: " << current->productionStage << endl;
                cout << endl;
                //Back to the production line menu
                consultProductionLine();
                return;
            }
            current = current->next;
        }
    }

    //Bakc to the production line menu
    consultProductionLine();
}


//Consult Production Stage
void consultStageProduction() {
    // Get the production stage to consult
    cout << "Insert the production stage you want to consult: ";
    string productionStage;
    getline(cin, productionStage);

    // Show the products in the production stage
    Product *current = headProduct;

    if (current == nullptr) {
        cout << "Product not found" << endl;
        return;
    } else {
        do {
            if (current->productionStage == productionStage) {
                // Show the product data
                cout << "Name: " << current->name << endl;
                cout << "ID: " << current->id << endl;
                cout << "Description: " << current->description << endl;
                cout << "Production Stage: " << current->productionStage << endl;
                cout << endl;
            }
            current = current->next;
        } while (current != headProduct); // Continue until we reach the head again
    }

    // Back to the production line menu
    consultProductionLine();
}

void modifyProductState(){
    //Get ID of the product to modify
    cout << "Insert the ID of the product you want to modify: ";
    string id;
    getline(cin, id);

    //Search the product and change
    Product *current = headProduct;

    //Compair current with null for verify if the list is empty
    if(current == NULL){
        cout << "Product not found" << endl;
        return;
    } else {  //Isn't empty
        while(current != NULL){
            if(current->id == id){
                //Show the product data
                cout << "Name: " << current->name << endl;
                cout << "ID: " << current->id << endl;
                cout << "Description: " << current->description << endl;
                cout << "Production Stage: " << current->productionStage << endl;
                cout << endl;

                //Show the options for choose
                cout << "1 - Design and deploy the product" << endl;
                cout << "2 - Wafer build" << endl;
                cout << "3 - Material Layer Deposition" << endl;
                cout << "4 - Testing and Assembly" << endl;
                cout << "Choose a option" << endl;
                cout << endl;

                //Get a option
                int option;
                cin >> option;
                cin.ignore();


                //Asign the new production stage
                switch (option)
                {
                case 1:
                    current->productionStage = "Design and deploy the product";
                    break;
                case 2:
                    current->productionStage = "Wafer build";
                    break;
                case 3:
                    current->productionStage = "Material Layer Deposition";
                    break;
                case 4:
                    current->productionStage = "Testing and Assembly";
                    break;
                default:
                    cout << "Invalid option" << endl;
                    break;
                }
                //Back to the production line menu
                consultProductionLine();
                return;
            }
            current = current->next;
        }
    }
    //Back to the production line menu
    consultProductionLine();
}

void deletePr(){
    //Get ID from the user to delete

    //  Get ID
    cout << "Insert the ID of the product you want to delete: ";
    string id;
    getline(cin, id);

    // Delete the product
    deleteProduct(id);

    //Back to the production line menu
    consultProductionLine();
}

void deleteProduct(const string& idToDelete) {
    // Delete Product by ID

    // Check if the list is empty
    if (headProduct == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Product *current = headProduct;

    // Search for the product with the specified ID
    while (current != nullptr) {   //Compaire current with null for verify if the list is empty
        if (current->id == idToDelete) {  //Search the product with the ID
            // Product found, delete it

            // If the product to delete is the first product (headProduct)
            if (current == headProduct) {
                headProduct = headProduct->next; // Update the list head

                if (headProduct != nullptr) {
                    // Update the previous pointer of the new head product
                    headProduct->previous = tailProduct;

                    // Update the next pointer of the tail product
                    tailProduct->next = headProduct;
                } else {
                    // The list is now empty
                    tailProduct = nullptr;
                }
            } else {
                // The product to delete is not the first product
                current->previous->next = current->next; // Update the next pointer of the previous product
                current->next->previous = current->previous; // Update the previous pointer of the next product
            }

            // Free memory of the deleted product
            delete current;

            cout << "Product with ID '" << idToDelete << "' deleted." << endl;

            return; // Exit the function
        }

        current = current->next;
    }

    // If the product is not found, display a message
    cout << "Product with ID '" << idToDelete << "' not found." << endl;
}





void consultProductionLine()
{
    //Principal menu for consult production line
    
    // Print menu options for consult production line
    cout << endl;
    cout << "Choose the option you want to perform:" << endl;
    cout << "1 - Consult a production line data" << endl;
    cout << "2 - Consult a specific product" << endl;
    cout << "3 - Consult a specific stage of the production line" << endl;
    cout << "4 - Modify a specific stage of the production line" << endl;
    cout << "5 - Add New Product in the Production Line " << endl;
    cout << "6 - Delete Product in Product Line" << endl;
    cout << "7 - Close menu" << endl;

    // Choose the option
    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        consultProductionLineData(); // <- Call the function to consult a production line data
        break;
    case 2:
        consultSpecificProduct(); // <- Call the function to consult a specific product
        break;
    case 3:
        consultStageProduction(); // <- Call the function to consult a specific stage of the production line   
        break;
    case 4:
        modifyProductState(); // <- Call the function to modify the state of a product
        break;
    case 5: 
        addProductWithCheck(); // <- Call the function to add a new product
        break;
    case 6:
        deletePr(); // <- Call the function to delete a product
        break;
    case 7:
        menuMain(); // <- Call the function to return to the main menu
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

    menuMain(); // <- Call the main menu

    return 0;
}

void menuMain(){
    //Principal menu for the program

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
            consultInventory();  // <- Call the function to consult the inventory
            break;
        case 3:
            cout << "Production Line" << endl;
            consultProductionLine(); // <- Call the function to consult the production line
            break;
        case 4:
            cout << "Thank you for preferring us! :)" << endl;
            // Only close the menu
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
}