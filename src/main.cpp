#include <iostream>
#include <string>
#include "../include/Employee.hpp"
#include "../include/lib.hpp"
using namespace std;
using namespace employee;
using namespace liba;
#define MENU_ITEMS 4
#define MAX_EMPLOYEES 2
#define MAX_STUDENTS 2
void drawMenu(const char* items[], int count, int selected, int row, int col) {
    for (int i = 0; i < count; i++) {
        if (i == selected)
            display(row + i, col, items[i], Color::YELLOW);
        else
            display(row + i, col, items[i]);
    }
}

int runMenu(const char* items[], int count, int row, int col) {
    int selected = 0;

    while (true) {
        drawMenu(items, count, selected, row, col);

        Key k = readKey();
        if (k == Key::Up)         selected = (selected - 1 + count) % count;
        else if (k == Key::Down)  selected = (selected + 1) % count;
        else if (k == Key::Enter) return selected;
        else if (k == Key::Quit)  return -1;
    }
}

Employee createEmployee() {
    string name, department;
    int age = 0;

    clearScreen();
    display(2, 10, "New Employee", Color::YELLOW);

    goTo(4, 10);
    cout << "Name: ";
    cin>>name;
    goTo(5, 10);
    cout << "Department: ";
    cin>>department;
    goTo(6, 10);
    cout << "Age: ";
    cin >> age;
    while(age <=0){
        goTo(7, 10);
        cout<<"Age must be greater than 0"<<endl;
        goTo(8, 10);
        cout << "Age: ";
        cin>>age;
    }
   
    

    return Employee(name, department, age);
}
struct Student {
    string name;
    int age;
    string major;
};
Student createStudent() {
    string name;
    string major;
    int age;

    clearScreen();
    display(2, 10, "New Student", Color::YELLOW);

    goTo(4, 10);
    cout << "Name: ";
    cin>>name;
    goTo(5, 10);
    cout << "Major: ";
    cin>>major;
    goTo(6, 10);
    cout << "Age: ";
    cin >> age;
    while(age <=0){
        goTo(7, 10);
        cout<<"Age must be greater than 0"<<endl;
        goTo(8, 10);
        cout << "Age: ";
        cin>>age;
    }

    return Student{name, age, major};
}

int main() {
    const char* items[] = {"New Employee","New Student", "Display Employees", "Exit"};
    Employee Employees[MAX_EMPLOYEES];
    Student *Students = new Student[MAX_STUDENTS];
    int stuSize = MAX_STUDENTS;
    int empCount = 0;
    int stuCount = 0;

    while (true) {
        clearScreen();
        int choice = runMenu(items, MENU_ITEMS, 4, 10);

        if (choice == 0) {                       
            if (empCount < MAX_EMPLOYEES) {
                Employees[empCount] = createEmployee();
                empCount++;
            }
            else {
                clearScreen();
                display(4, 10, "Max employees", Color::YELLOW);
                display(6, 10, "Press anything to go back");
                getch_linux();
            }
        }
        else if (choice == 1) {                  
            if (stuCount < stuSize) {
                Students[stuCount] = createStudent();
                stuCount++;
            }
            else {
                clearScreen();
                stuSize += 2;
                
                Student *newStudents = new Student[stuSize];
                for (int i = 0; i < stuCount; i++) {
                    newStudents[i] = Students[i];
                }
                delete[] Students;
                Students = newStudents;
                Students[stuCount] = createStudent();
                stuCount++;
                

            }
            
        }
        else if (choice == 2) {                  
            clearScreen();
            if (empCount == 0) {
                cout << "No employees\n";
            }
            for (int i = 0; i < empCount; i++) {
                cout << Employees[i].getName() << " | "
                     << Employees[i].getDepartment() << " | "
                     << Employees[i].getAge() << "\n";
            }
            cout << "\nPress any key to go back...";
            getch_linux();
        }
        else {                                   
            break;
        }
    }

    return 0;
}