#include "Course.h"
#include "Student.h"
#include "Instructor.h"

Course::Course() {
    studentCount = 0;
    instructor = nullptr;
}

Course::Course(string c, string n) {
    code = c;
    name = n;
    studentCount = 0;
    instructor = nullptr;
}

string Course::getCode() {
    return code;
}

string Course::getName(){
    return name;
}

int Course::getStudentCount(){
    return studentCount;
}

void Course::assignInstructor(Instructor* i) {
    if (i->getCourseCount() >= 5) {
        cout << "Instructor already has maximum courses.\n";
        return;
    }
    
    instructor = i;
    i->addCourse(this);
}


void Course::enrollStudent(Student* s) {
    if (studentCount < 5) {
        students[studentCount] = s;
        grades[studentCount] = -1;
        studentCount++;
    }
    else {
        cout << "Course is full.\n";
    }
}

void Course::displayCourse() {
    cout << "Course Code: " << code
         << ", Name: " << name << endl;

    if (instructor != nullptr) {
        cout << "Instructor: " << instructor->getId()
             << " - " << instructor->getName() << endl;
    } else {
        cout << "Instructor: Not assigned\n";
    }

    
    if (studentCount == 0) {
        cout << "No students enrolled in this course.\n";
    } else {
        cout << "Enrolled Students:\n";
        for (int i = 0; i < studentCount; i++) {
            Student* s = students[i];
            int grade = grades[i];
            cout << "  - " << s->getRollNo() << " : " << s->getName()
                 << " | Grade: ";
            if (grade == -1)
                cout << "Not Assigned\n";
            else
                cout << grade << endl;
        }
    }

}




void Course::updateGrade(int studentrollNo, int grade){
    for(int i=0; i<studentCount; i++){
        if(students[i]->getRollNo() == studentrollNo){
            grades[i] = grade;
            cout << "Grade updated successfuly.\n";
            return;
        }
    }
    cout << "Student not found in this course.\n";
}

int Course::getGrade(Student* s) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i] == s)
            return grades[i];  
    }
    return -1;  
}
