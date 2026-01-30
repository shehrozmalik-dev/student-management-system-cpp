#include "CMS.h"
#include<iostream>
#include <fstream>
using namespace std;

CMS::CMS() {
    studentCount = 0;
    instructorCount = 0;
    courseCount = 0;
}

void CMS::addStudent() {
    if (studentCount >= 20) {
        cout << "Student limit reached!\n";
        return;
    }

    string n;
    int a;
    cout << "Enter name: ";
    cin >> n;
    cout << "\nEnter age: ";
    cin >> a;
    
    students[studentCount++] = Student(n, a);
    cout << "Student added successfully.\n";
    return;
}

void CMS::addInstructor() {
    if (instructorCount >= 10) {
        cout << "Instructor limit reached!\n";
        return;
    }

    string n;
    int a;
    cout << "Enter name: ";
    cin >> n;
    cout << "\nEnter age: ";
    cin >> a;

    instructors[instructorCount++] = Instructor(n, a);
    cout << "Instructor added successfully.\n";
    return;
}

void CMS::assignNewInstructor(){
    string ccode;
    int iid;

    cout << "enter course code: ";
    cin >> ccode;
    cout << "enter instructor id: ";
    cin >> iid;

    Course* courseptr = nullptr;
    Instructor* instructorptr = nullptr;

    for(int i=0; i<courseCount; i++){
        if(courses[i].getCode() == ccode){
            courseptr = &courses[i];
            break;
        }
    }

    for(int i=0; i<instructorCount; i++){
        if(instructors[i].getId() == iid){
            instructorptr = &instructors[i];
            break;
        }
    }

    if(courseptr && instructorptr){
        courseptr->assignInstructor(instructorptr);
        cout << "New Instrutor assigned Successfully.\n";
    }

    else{
        cout << "Invalid Course or instructor!\n";
        return;
    }


}

void CMS::addCourse() {
    if (courseCount >= 10) {
        cout << "Course limit reached!\n";
        return;
    }

    string c, n;
    cout << "Enter course code: ";
    cin >> c ;
    cout << "Enter course name: ";
    cin >> n ;

    courses[courseCount++] = Course(c, n);
    cout << "Course added successfully.\n";
    return;
}

void CMS::showAllPersons() {
    Person* p;

    cout << "\t\t\tSTUDENTS\n";
    for (int i = 0; i < studentCount; i++) {
        p = &students[i];
        p->displayDetails();   
    }

    cout << "\t\t\tINSTRUCTORS\n";
    for (int i = 0; i < instructorCount; i++) {
        p = &instructors[i];
        p->displayDetails();   
    }
    return;
}


void CMS::enrollStudentInCourse() {
    
    int sroll;
    string ccode;

    cout << "Enter Student RollNo: ";
    cin >> sroll;

    cout << "Enter Course Code: ";
    cin >> ccode;

    Student* s = nullptr;
    Course* c = nullptr;

    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == sroll) {
            s = &students[i];
            break;
        }
    }

    
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].getCode() == ccode) {
            c = &courses[i];
            break;
        }
    }

    if (s == nullptr || c == nullptr) {
        cout << "Student or course not found.\n";
        return;
    }

    if (s->getCourseCount() >= 5) {   
        cout << "Student already enrolled in 5 courses.\n";
        return;
    }

    if (c->getStudentCount() >= 5) {  
        cout << "Course is full.\n";
        return;
    }

    s->enroll(c);
    c->enrollStudent(s);

    cout << "Student enrolled successfully.\n";
    return;
}



void CMS::assignInstructorToCourse() {
    int iid;
    string ccode;

    cout << "Enter Instructor ID: ";
    cin >> iid;

    cout << "Enter Course Code: ";
    cin >> ccode;

    Instructor* ins = nullptr;
    Course* c = nullptr;

    
    for (int i = 0; i < instructorCount; i++) {
        if (instructors[i].getId() == iid) {
            ins = &instructors[i];
            break;
        }
    }

    
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].getCode() == ccode) {
            c = &courses[i];
            break;
        }
    }

    if(ins==nullptr || c==nullptr){
        cout << "Instructor or Course not found.\n";
        return;
    }
    c->assignInstructor(ins);
    cout << "Instructor assigned succcessfuly.\n";
    return;
}

void CMS::assignGrade() {
    string ccode;
    int sroll, grade;

    cout << "Enter Course Code: ";
    cin >> ccode;

    cout << "Enter Student RollNo: ";
    cin >> sroll;

    cout << "Enter Grade: ";
    cin >> grade;

    for (int i = 0; i < courseCount; i++) {
        if (courses[i].getCode() == ccode) {
            courses[i].updateGrade(sroll, grade);
            return;
        }
    }

    cout << "Course not found.\n";
    return;
}

void CMS::showAllStudents(){
    Person* p;

    cout << "\t\t\tSTUDENTS\n";
    for (int i = 0; i < studentCount; i++) {
        p = &students[i];
        p->displayDetails();   
    }
    return;
}

void CMS::showAllInstructors(){
    Person* p;

    cout << "\t\t\tINSTRUCTORS\n";
    for (int i = 0; i < instructorCount; i++) {
        p = &instructors[i];
        p->displayDetails();   
    }
    return;
}

void CMS::deleteStudent() {
    int sroll;
    cout << "Enter Student rollNo to delete: ";
    cin >> sroll;

    Student* s = nullptr;
    int index = -1;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == sroll) {
            s = &students[i];
            index = i;
            break;
        }
    }

    if (s == nullptr) {
        cout << "Student not found.\n";
        return;
    }

    for (int i = 0; i < s->courseCount; i++) {  
        Course* c = s->courses[i];              
        if (c != nullptr) {
            int idx = -1;
            for (int j = 0; j < c->studentCount; j++) {
                if (c->students[j] == s) {
                    idx = j;
                    break;
                }
            }
            if (idx != -1) {
                
                for (int j = idx; j < c->studentCount - 1; j++) {
                    c->students[j] = c->students[j + 1];
                    c->grades[j] = c->grades[j + 1];
                }
                c->studentCount--;
                c->students[c->studentCount] = nullptr;
                c->grades[c->studentCount] = -1;
            }
        }
    }

    
    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;

    cout << "Student deleted successfully.\n";
}

void CMS::deleteInstructor() {
    int iid;
    cout << "Enter Instructor ID to delete: ";
    cin >> iid;

    Instructor* inst = nullptr;
    int index = -1;

    
    for (int i = 0; i < instructorCount; i++) {
        if (instructors[i].getId() == iid) {
            inst = &instructors[i];
            index = i;
            break;
        }
    }

    if (inst == nullptr) {
        cout << "Instructor not found.\n";
        return;
    }

    
    for (int i = 0; i < inst->courseCount; i++) {  
        Course* c = inst->courses[i];              
        if (c != nullptr) {
            c->instructor = nullptr;              
        }
    }

    
    for (int i = index; i < instructorCount - 1; i++) {
        instructors[i] = instructors[i + 1];
    }
    instructorCount--;

    cout << "Instructor deleted successfully.\n";
}

void CMS::viewCourse() {
    string ccode;
    cout << "Enter Course Code to view: ";
    cin >> ccode;

    Course* c = nullptr;

    
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].getCode() == ccode) {
            c = &courses[i];
            break;
        }
    }

    if (c == nullptr) {
        cout << "Course not found.\n";
        return;
    }

    c->displayCourse();
    return;
    
}

void CMS::viewAllCourses() {
    if (courseCount == 0) {
        cout << "No courses available.\n";
        return;
    }

    for (int i = 0; i < courseCount; i++) {
        Course* c = &courses[i];
        c->displayCourse();

        cout << "-------------------------------------\n";
    }
}

void CMS::deleteCourse() {
    string ccode;
    cout << "Enter Course Code to delete: ";
    cin >> ccode;

    Course* c = nullptr;
    int index = -1;

    
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].getCode() == ccode) {
            c = &courses[i];
            index = i;
            break;
        }
    }

    if (c == nullptr) {
        cout << "Course not found.\n";
        return;
    }

    
    for (int i = 0; i < c->studentCount; i++) {
        Student* s = c->students[i];
        if (s != nullptr) {
            
            int idx = -1;
            for (int j = 0; j < s->courseCount; j++) {
                if (s->courses[j] == c) {
                    idx = j;
                    break;
                }
            }

            
            if (idx != -1) {
                for (int j = idx; j < s->courseCount - 1; j++) {
                    s->courses[j] = s->courses[j + 1];
                }
                s->courseCount--;
                s->courses[s->courseCount] = nullptr;
            }
        }
    }

    
    if (c->instructor != nullptr) {
        Instructor* inst = c->instructor;
        
        int idx = -1;
        for (int j = 0; j < inst->courseCount; j++) {
            if (inst->courses[j] == c) {
                idx = j;
                break;
            }
        }
        if (idx != -1) {
            for (int j = idx; j < inst->courseCount - 1; j++) {
                inst->courses[j] = inst->courses[j + 1];
            }
            inst->courseCount--;
            inst->courses[inst->courseCount] = nullptr;
        }
        c->instructor = nullptr;
    }

    
    for (int i = index; i < courseCount - 1; i++) {
        courses[i] = courses[i + 1];
    }
    courseCount--;

    cout << "Course deleted successfully.\n";
}


void CMS::searchStudent() {
    int choice;
    cout << "Search student by:\n";
    cout << "1. RollNo\n2. Name\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        int sroll;
        cout << "Enter Student RollNo: ";
        cin >> sroll;

        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNo() == sroll) {
                students[i].displayDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student not found.\n";
        }

    } else if (choice == 2) {
        string sname;
        cout << "Enter Student Name: ";
        cin >> sname;

        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getName() == sname) {
                students[i].displayDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "Student not found.\n";
        }

    } else {
        cout << "Invalid choice.\n";
    }
}

void CMS::searchInstructor() {
    int choice;
    cout << "Search instructor by:\n";
    cout << "1. ID\n2. Name\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        int iid;
        cout << "Enter Instructor ID: ";
        cin >> iid;

        bool found = false;
        for (int i = 0; i < instructorCount; i++) {
            if (instructors[i].getId() == iid) {
                instructors[i].displayDetails();  
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Instructor not found.\n";
        }

    } else if (choice == 2) {
        string iname;
        cout << "Enter Instructor Name: ";
        cin >> iname;

        bool found = false;
        for (int i = 0; i < instructorCount; i++) {
            if (instructors[i].getName() == iname) {
                instructors[i].displayDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "Instructor not found.\n";
        }

    } else {
        cout << "Invalid choice.\n";
    }
}



void CMS::exportToFiles() {
    
    ofstream studentFile("students.txt");
    if (!studentFile) {
        cout << "Error opening students.txt for writing.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        Student& s = students[i];
        studentFile << "RollNo: " << s.getRollNo() << ", Name: " << s.getName()
                    << ", Age: " << s.getAge() << endl;

        if (s.courseCount == 0) {
            studentFile << "Enrolled Courses: None\n";
        } else {
            studentFile << "Enrolled Courses:\n";
            for (int j = 0; j < s.courseCount; j++) {
                Course* c = s.courses[j];
                int grade = c->getGrade(&s);  
                studentFile << "  - " << c->getCode() << " : " << c->getName()
                            << " | Grade: ";
                if (grade == -1)
                    studentFile << "Not Assigned\n";
                else
                    studentFile << grade << endl;
            }
        }
        studentFile << "-------------------------------------\n";
    }
    studentFile.close();

    
    ofstream instructorFile("instructors.txt");
    if (!instructorFile) {
        cout << "Error opening instructors.txt for writing.\n";
        return;
    }

    for (int i = 0; i < instructorCount; i++) {
        Instructor& inst = instructors[i];
        instructorFile << "ID: " << inst.getId() << ", Name: " << inst.getName()
                       << ", Age: " << inst.getAge() << endl;

        if (inst.courseCount == 0) {
            instructorFile << "Courses Taught: None\n";
        } else {
            instructorFile << "Courses Taught:\n";
            for (int j = 0; j < inst.courseCount; j++) {
                Course* c = inst.courses[j];
                instructorFile << "  - " << c->getCode() << " : " << c->getName() << endl;
            }
        }
        instructorFile << "-------------------------------------\n";
    }
    instructorFile.close();

    ofstream courseFile("courses.txt");
    if (!courseFile) {
        cout << "Error opening courses.txt for writing.\n";
        return;
    }

    for (int i = 0; i < courseCount; i++) {
        Course& c = courses[i];
        courseFile << "Code: " << c.getCode() << ", Name: " << c.getName() << endl;

        if (c.instructor != nullptr)
            courseFile << "Instructor: " << c.instructor->getId() << " - " 
                       << c.instructor->getName() << endl;
        else
            courseFile << "Instructor: Not Assigned\n";

        if (c.studentCount == 0)
            courseFile << "No students enrolled.\n";
        else {
            courseFile << "Enrolled Students:\n";
            for (int j = 0; j < c.studentCount; j++) {
                Student* s = c.students[j];
                int grade = c.grades[j];
                courseFile << "  - " << s->getRollNo() << " : " << s->getName()
                           << " | Grade: ";
                if (grade == -1)
                    courseFile << "Not Assigned\n";
                else
                    courseFile << grade << endl;
            }
        }
        courseFile << "-------------------------------------\n";
    }
    courseFile.close();

    cout << "All data exported to students.txt, instructors.txt, and courses.txt successfully.\n";
}
