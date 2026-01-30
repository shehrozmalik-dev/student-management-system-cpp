#include "Student.h"
#include "Course.h"

int Student::totalStudents = 0;

Student::Student() {
    rollNo = 0;
    courseCount = 0;
}

Student::Student(string n, int a) : Person(n, a) {
    rollNo = ++totalStudents;
    courseCount = 0;
}

int Student::getRollNo() {
    return rollNo;
}

int Student::getCourseCount() {
    return courseCount;
}

string Student::getName(){
    return name;
}

int Student::getAge(){
    return age;
}

void Student::enroll(Course* c) {
    if (courseCount < 5) {
        courses[courseCount++] = c;
    }
}

void Student::displayDetails() {
    cout << "Student rollNo: " << rollNo
         << ", Name: " << name
         << ", Age: " << age << endl;

    if (courseCount == 0) {
        cout << "Student is not enrolled in any courses.\n";
    } else {
        cout << "Enrolled courses:\n";
        for (int i = 0; i < courseCount; i++) {
            Course* c = courses[i];
            int grade = c->getGrade(this);
            cout << "  - " << c->getCode() << " : " 
                 << c->getName() << " | Grade: ";
            if (grade == -1)
                cout << "Not Assigned\n";
            else
                cout << grade << endl;
        }
    }
    
    return;
}

