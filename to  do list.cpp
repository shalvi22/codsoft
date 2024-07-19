to do list 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int ID = 0; // Initialize ID

// Custom type todo which has two fields id and task
struct todo {
    int id;
    string task;
};

// Function to display the header
void displayHeader() {
    system("cls"); // Clears the screen
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t*                      WELCOME TO Your ToDo List                      *" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
}

// Function to add a new task
void addTodo() {
    displayHeader();
    
    todo newTodo;
    cout << "\n\tEnter new task: ";
    cin.ignore();
    getline(cin, newTodo.task); 
    ID++; 

    // Write this task to the todo.txt file
    ofstream write("todo.txt", ios::app);
    write << ID << endl;
    write << newTodo.task << endl;
    write.close();

    // Write the id to id.txt so that we can use this id later to add new tasks
    ofstream writeId("id.txt");
    writeId << ID;
    writeId.close();

    char ch;
    cout << "\n\tDo you want to add more tasks? (y/n): "; 
    cin >> ch;

    if (ch == 'y' || ch == 'Y') {
        addTodo();
    } else {
        cout << "\n\tTask has been added successfully." << endl;
    }
}

// Function to display added tasks
void print(const todo &s) {
    cout << "\tID: " << s.id << "\tTask: " << s.task << endl;
}

// Function to read added tasks from todo.txt
void readData() {
    displayHeader();
    
    todo task;
    ifstream read("todo.txt");
    cout << "\n\t\t\t------------------Your current Tasks in the list--------------------" << endl;
    
    // Read the data from the file
    while (read >> task.id) {
        read.ignore();
        getline(read, task.task);
        print(task);
    }
    read.close();
}

// Function to search for a specific task by ID
int searchData() {
    displayHeader();

    int id;
    cout << "\n\tEnter task ID: ";     
    cin >> id;

    todo task;
    ifstream read("todo.txt");
    
    // Search for the task with the given ID
    while (read >> task.id) {
        read.ignore();
        getline(read, task.task);
        if (task.id == id) {
            print(task);
            return id;
        }
    }
    read.close();
    cout << "\n\tTask not found." << endl;
    return -1; // Return -1 if the task is not found
}

// Function to delete a task
void deleteData() {
    displayHeader();

    int id = searchData();
    if (id == -1) return; // If task not found, return

    cout << "\n\tDo you want to delete this task? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        todo task;
        ofstream tempFile("temp.txt");
        ifstream read("todo.txt");

        // Write all tasks except the one to delete to a temporary file
        while (read >> task.id) {
            read.ignore();
            getline(read, task.task);
            if (task.id != id) {
                tempFile << task.id << endl;
                tempFile << task.task << endl;
            }
        }
        read.close();
        tempFile.close();

        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfully." << endl;
    } else {
        cout << "\n\tTask not deleted." << endl;
    }
}

int main() {
    system("cls");
    system("Color E0"); // "Color XY", X - background color, Y - text color
    system("title todoapp @copyassignment");

    // Read the last ID from id.txt
    ifstream read("id.txt");
    if (read.good()) {
        read >> ID;
    }
    read.close();

    while (true) {
        displayHeader();
        cout << "\n\t1. Add a new task";
        cout << "\n\t2. View all tasks";
        cout << "\n\t3. Search for a task";
        cout << "\n\t4. Delete a task";
        cout << "\n\t5. Exit";
        
        int choice;
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addTodo();
                break;
            case 2:
                readData();
                break;
            case 3:
                searchData();
                break;
            case 4:
                deleteData();
                break;
            case 5:
                cout << "\n\tExiting the program..." << endl;
                return 0;
            default: 
                cout << "\n\tInvalid choice. Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}
