#include <string>
using namespace std;

namespace employee{
class Employee{
private:

    string name;
    string department;
    int age;
    int id;
public: 
    Employee(); 
    Employee(string name, string department, int age);
    void addEmployee(Employee emp);
    string getName();
    string getDepartment();
    int getAge();


};

};
