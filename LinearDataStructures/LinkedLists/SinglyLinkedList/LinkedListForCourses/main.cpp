#include <iostream>
#include "CourseLinkedList.h"
#include "Course.h"
using namespace std;

int main(int argc, char** argv) {
    CourseLinkedList<Course*> list;
    int choice;

    do {
        cout << endl;
        cout << "Press 1 to Add New Course";
        cout << "\nPress 2 to Display Your Courses";
        cout << "\nPress 0 to Exit";
        cout << endl;

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string courseCode;
                string courseName;
                int creditHour;
                cout << "Enter course code: ";
                cin >> courseCode;
                cout << "Enter course name: ";
                cin >> courseName;
                cout << "Enter credit hour: ";
                cin >> creditHour;
                list.addToHead(new Course(courseCode, courseName, creditHour));
                break;
            }
            case 2:
                cout << "The courses are: " << endl;
                list.traverse();
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    while (true);

    return 0;
}