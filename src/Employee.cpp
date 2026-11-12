#include "../include/Employee.hpp"
#include <iostream> 
using namespace std;
namespace employee{

 Employee::Employee(){

 }

 Employee::Employee(string name, string department, int age){

    if(age<=0){
        cout<<"Age must be greater than 0"<<endl;
    }else{
    this->name=name;
    this->department=department;
    this->age=age;
    }
 }

 string Employee::getName(){
    return this->name;
}

 string Employee::getDepartment(){
    return this->department;
}

 int Employee::getAge(){
    return this->age;
}
}