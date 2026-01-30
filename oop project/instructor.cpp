#include "Instructor.h"
#include "course.h"


int Instructor::totalInstructors = 0;

Instructor::Instructor() {
    id = 0;
}

Instructor::Instructor(string n, int a) : Person(n, a) {
    id = ++totalInstructors;
    courseCount = 0;
}

int Instructor::getId() {
    return id;
}

string Instructor::getName(){
    return name;
}

int Instructor::getAge(){
    return age;
}

int Instructor::getCourseCount(){
    return courseCount;
}

void Instructor::addCourse(Course* c){
    courses[courseCount++] = c;
}

void Instructor::displayDetails() {
    cout << "Instructor ID: " << id
         << ", Name: " << name
         << ", Age: " << age << endl;

    if (courseCount == 0) {
        cout << "This instructor is not assigned to any courses.\n";
    } else {
        cout << "Courses taught:\n";
        for (int i = 0; i < courseCount; i++) {
            Course* c = courses[i];
            cout << "  - " << c->getCode() << " : " << c->getName() << endl;
        }
    }
    return;
}


