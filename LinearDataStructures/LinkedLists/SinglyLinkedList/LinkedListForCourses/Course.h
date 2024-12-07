#include <iostream>
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int creditHours;
public:
    Course(string courseCode, string courseName, int creditHours) {
        this->courseCode = courseCode;
        this->courseName = courseName;
        this->creditHours = creditHours;
    }
    string getCourseCode();
    string getCourseName();
    int getCreditHours();
    void setCourseCode(string courseCode);
    void setCourseName(string courseName);
    void setCreditHours(int creditHours);
    void displayCourse();
};

void Course::setCourseCode(string courseCode) {
    this->courseCode = courseCode;
}

void Course::setCourseName(string courseName) {
    this->courseName = courseName;
}

void Course::setCreditHours(int creditHours) {
    this->creditHours = creditHours;
}

string Course::getCourseCode() {
    return this->courseCode;
}

string Course::getCourseName() {
    return this->courseName;
}

int Course::getCreditHours() {
    return this->creditHours;
}

void Course::displayCourse() {
    cout << endl;
    cout << "Course Code is: " << this->courseCode << endl;
    cout << "Course Name is: " << this->courseName << endl;
    cout << "Credit Hour is: " << this->creditHours << endl;
    cout << endl;
}