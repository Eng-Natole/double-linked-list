#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>  // For formatting output
#include <cctype> // For toupper or tolower functions
using namespace std;


// Define the Person structure
struct Person {
    int person_id;
    string person_name;
    int person_age;
    string person_address;
    float person_salary;
    Person* next;
    Person* prev;
};

Person* head = NULL; // Initialize head pointer

// Function to insert a new node at the beginning
void insertAtBeginning() {
    char choice;
    
    do {
        Person* newPerson = new Person();
              system("cls");
         cout<<"+==============================+"<<endl;
         cout<<"== INSERT AT THE BEGGINING ===="<<endl;
        cout<<"+==============================+"<<endl;
        // Input validation for Person ID
        cout << "Enter Person ID: ";
        while (!(cin >> newPerson->person_id)) {
            cout << "Invalid input. Please enter a numeric ID: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Person Name: ";
        cin.ignore();
        getline(cin, newPerson->person_name);

        cout << "Enter Person Age: ";
        while (!(cin >> newPerson->person_age)) {
            cout << "Invalid input. Please enter a numeric age: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Person Address: ";
        cin.ignore();
        getline(cin, newPerson->person_address);

        cout << "Enter Person Salary: ";
        while (!(cin >> newPerson->person_salary)) {
            cout << "Invalid input. Please enter a numeric salary: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        newPerson->next = head;
        newPerson->prev = NULL;
        if (head != NULL)
            head->prev = newPerson;
        head = newPerson;

        cout << "Person added at the beginning.\n";

        cout << "Do you want to add another person? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
               system("cls");
            break;
        }
    } while (true);
}

// Function to insert a new node at the end
void insertAtEnd() {
    char choice;
    do {
        Person* newPerson = new Person();
               system("cls"); 
          cout<<"+==============================+"<<endl;
         cout<<"== INSERT AT THE END====== ===="<<endl;
        cout<<"+==============================+"<<endl;
        // Input validation for Person ID
        cout << "Enter Person ID: ";
        while (!(cin >> newPerson->person_id)) {
            cout << "Invalid input. Please enter a numeric ID: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Person Name: ";
        cin.ignore();
        getline(cin, newPerson->person_name);

        cout << "Enter Person Age: ";
        while (!(cin >> newPerson->person_age)) {
            cout << "Invalid input. Please enter a numeric age: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Person Address: ";
        cin.ignore();
        getline(cin, newPerson->person_address);

        cout << "Enter Person Salary: ";
        while (!(cin >> newPerson->person_salary)) {
            cout << "Invalid input. Please enter a numeric salary: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (head == NULL) {
            newPerson->next = NULL;
            newPerson->prev = NULL;
            head = newPerson;
        } else {
            Person* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newPerson;
            newPerson->prev = temp;
            newPerson->next = NULL;
        }

        cout << "Person added at the end.\n";

        cout << "Do you want to add another person? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
              system("cls");
            break;
        }
    } while (true);
}

// Function to insert a node after a specified position
void insertAfterPosition() {
    char choice;
    do {
        int pos; 
		 system("cls");
		        cout<<"+==============================+"<<endl;
         cout<<"== INSERT AFTER SPECIFITC POSITION====== ===="<<endl;
        cout<<"+==============================+"<<endl;
       
        cout << "Enter position after which to insert: ";
        while (!(cin >> pos)) {
            cout << "Invalid input. Please enter a numeric position: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        Person* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position not found.\n";
            return;
        }

        Person* newPerson = new Person();
   
        // Input validation for Person ID
        cout << "Enter Person ID: ";
        while (!(cin >> newPerson->person_id)) {
            cout << "Invalid input. Please enter a numeric ID: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Person Name: ";
        cin.ignore();
        getline(cin, newPerson->person_name);

        cout << "Enter Person Age: ";
        while (!(cin >> newPerson->person_age)) {
            cout << "Invalid input. Please enter a numeric age: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Person Address: ";
        cin.ignore();
        getline(cin, newPerson->person_address);

        cout << "Enter Person Salary: ";
        while (!(cin >> newPerson->person_salary)) {
            cout << "Invalid input. Please enter a numeric salary: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        newPerson->next = temp->next;
        newPerson->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newPerson;
        temp->next = newPerson;

        cout << "Person inserted after position " << pos << ".\n";

        cout << "Do you want to insert another person? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
              system("cls");
            break;
        }
    } while (true);
}

// Function to delete a node after a specified position
void deleteAfterPosition() {
    char choice;
    do {
        int pos;
              cout<<"+==============================+"<<endl;
         cout<<"== DELETE AFTER SPECIFITC POSITION====== ===="<<endl;
        cout<<"+==============================+"<<endl;
        cout << "Enter position after which to delete: ";
        while (!(cin >> pos)) {
            cout << "Invalid input. Please enter a numeric position: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        Person* temp = head;
        for (int i = 1; i <= pos && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL) {
            cout << "No node to delete after position " << pos << ".\n";
            return;
        }

        Person* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != NULL)
            toDelete->next->prev = temp;
        delete toDelete;
        
        cout << "Person deleted after position " << pos << ".\n";

        cout << "Do you want to delete another person? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
              system("cls");
            break;
        }
    } while (true);
}

// Function to delete the first node
void deleteFirst() {
	     cout<<"+==============================+"<<endl;
         cout<<"== DELETE THE FIRST====== ===="<<endl;
        cout<<"+==============================+"<<endl;
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Person* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
    cout << "First person deleted.\n";
}

// Function to delete the last node
void deleteLast() {
	  cout<<"+==============================+"<<endl;
         cout<<"== DELETE THE LAST====== ===="<<endl;
        cout<<"+==============================+"<<endl;
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Person* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        delete temp;
        cout << "Last person deleted.\n";
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
    cout << "Last person deleted.\n";
}


// Function to display all nodes forward in a structured way
void displayForward() {
        cout<<"+==============================+"<<endl;
        cout<<"== DISPLAY THE LIST FORWARD====== ===="<<endl;
        cout<<"+==============================+"<<endl;
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
  
    // Table header
    cout << "\nDisplaying persons (Forward):\n";
    cout << "_______________________________________________________________\n";  
    cout << setw(10) << "ID No." << setw(20) << " Name" << setw(20) << "Age" 
         << setw(30) << "Address" << setw(15) << "Salary\n";
    cout << "---------------------------------------------------------------\n";

    Person* temp = head;
    while (temp != NULL) {
        cout << setw(10) << temp->person_id 
             << setw(20) << temp->person_name
             << setw(20) << temp->person_age
             << setw(30) << temp->person_address
             << setw(15) << temp->person_salary << " ETB\n";
        temp = temp->next;
    }
    cout << "\n";
}

// Function to display all nodes backward in a structured way
void displayBackward() {
	  cout<<"+==============================+"<<endl;
      cout<<"== DISPLAY THE LIST BACKWARD====== ===="<<endl;
      cout<<"+==============================+"<<endl;
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // Find the last node first
    Person* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Table header
    cout << "\nDisplaying persons (Backward):\n";
    cout << "_______________________________________________________________\n";  
    cout << setw(10) << "ID No." << setw(20) << " Name" << setw(20) << "Age" 
         << setw(30) << "Address" << setw(15) << "Salary\n";
    cout << "---------------------------------------------------------------\n";

    while (temp != NULL) {
        cout << setw(10) << temp->person_id 
             << setw(20) << temp->person_name
             << setw(20) << temp->person_age
             << setw(30) << temp->person_address
             << setw(15) << temp->person_salary << " ETB\n";
        temp = temp->prev;
    }
    cout << "\n";
}

// Function to search for a node by ID and display in a structured way
void searchNode() {
    int id;
      cout<<"+==============================+"<<endl;
        cout<<"== SEARCHING NODE BY ID====== ===="<<endl;
       cout<<"+==============================+"<<endl;
    cout << "Enter Person ID to search: ";
    cin >> id;

    Person* temp = head;
    while (temp != NULL) {
        if (temp->person_id == id) {
            // Display the person details in a structured format
            cout << "\nPerson found:\n";
            cout << "_______________________________________________________________\n";  
            cout << setw(10) << "ID No." << setw(20) << "Name" << setw(20) << "Age" 
                 << setw(30) << "Address" << setw(15) << "Salary\n";
            cout << "---------------------------------------------------------------\n";
            cout << setw(10) << temp->person_id
                 << setw(20) << temp->person_name
                 << setw(20) << temp->person_age
                 << setw(30) << temp->person_address
                 << setw(15) << temp->person_salary << " ETB\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Person not found.\n";
}

void AboutAs() {
	  cout<<"+==============================+"<<endl;
         cout<<"== LIST OF THE GROUP MEMBERS \n===="<<endl;
        cout<<"+==============================+"<<endl;
    cout << "--------------------------------------\n";
    cout << "1. Natinael Getachew........ DDU1501522\n";
    cout << "2. Betelhem Kassahun........ DDU1500955\n";
    cout << "3. Mekdes Demisse........... DDU1501411\n";
    cout << "4. Marta Dereje............. DDU1501391\n";
    cout << "5. Eyob Tesfaye Metaferiya.. DDU1501114\n";
    cout << "6. Hayat Abduselam.......... DDU1501239\n";
    cout << "--------------------------------------\n";
}


// Function to print centered text
void printCenteredText(const string& text, int width) {
    int padding = (width - text.length()) / 2;
    cout << setw(padding + text.length()) << text << endl;
}

void displayMenuAndExecute() {
    int choice;
      
    do {
    

    system("color f4");
    // Set the total width for centering
 
   int width=20;//you can change this to align it center
    cout << "\n\n\n\n\n";
    
    // Print centered menu header
    cout << setw(100-width) << "Menu for Doubly Linked List. Please choose [1-11]:" << endl;

    // Center align all menu options with width set to 90
    cout << setw(85-width) << "1. Insert Person at Beginning" << endl;
    cout << setw(79-width) << "2. Insert Person at End" << endl;
    cout << setw(87-width) << "3. Insert Person After Position" << endl;
    cout << setw(78-width) << "4. Delete First Person" << endl;
    cout << setw(77-width) << "5. Delete Last Person" << endl;
    cout << setw(87-width) << "6. Delete Person After Position" << endl;
    cout << setw(84-width) << "7. Display Persons (Forward)" << endl;
    cout << setw(85-width) << "8. Display Persons (Backward)" << endl;
    cout << setw(78-width) << "9. Search for a Person" << endl;
    cout << setw(67-width) << "10. About Us" << endl;
    cout << setw(65-width) << "11. Exit \n" << endl;

    // Center align the prompt for user input
    cout << setw(70-width) << "Enter your choice.... ";
        cin >> choice;

        switch (choice) {
            case 1: 
			system("cls");
                insertAtBeginning();
                break;
            case 2:
            	   system("cls");
                insertAtEnd();
                break;
            case 3:
            	   system("cls");
                insertAfterPosition();
                break;
            case 4:
            	   system("cls");
                deleteFirst();
                break;
            case 5:
            	   system("cls");
                deleteLast();
                break;
            case 6:
            	   system("cls");
                deleteAfterPosition();
                break;
            case 7:
            	   system("cls");
                displayForward();
                break;
            case 8:
            	   system("cls");
                displayBackward();
                break;
            case 9:
            	   system("cls");
                searchNode();
                break;
            case 10:
            	   system("cls");
                AboutAs();
                break;
            case 11:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
        
          char choiceReturn;
        bool validInput = false; // To track input validity

        cout << "\n=====================================\n";
        
        // Loop until valid input is provided
        while (!validInput) {
            cout << "Do you want to return to the main menu? (Y/N): ";
            cin >> choiceReturn;

            // Convert input to uppercase for simplicity
            choiceReturn = toupper(choiceReturn);

            if (choiceReturn == 'Y' || choiceReturn == 'N') {
                validInput = true; // Valid input provided
            } else {
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";
            }
        }

        if (choiceReturn == 'Y') {
            system("cls");
            continue; // Continue to the next iteration of the loop
        } else {
            cout << "Exiting program...\n";
            break; // Exit the loop and end the program
        }


    } while (true);
}


// Main function
int main() {
	 system("color f4");
    displayMenuAndExecute();
    return 0;
}

