#include <iostream>
#include <cstring>
using namespace std;

class Student{

    public:
        char name[100];
        int id;
};

int main(){
    Student s1;

    cout << "Enter name: ";
    cin >> s1.name;

    cout << "Enter ID: ";
    cin >> s1.id;
    
    cout << "Student Id is: "<< s1.id << "Name of Student is: " <<s1.name << endl;
}