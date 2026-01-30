#include "CMS.h"

int main() {
    CMS cms;
    int choice;

    do {
        cout << "\n--- Course Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Add Instructor\n";
        cout << "3. Add Course\n";
        cout << "4. Enroll Student in Course\n";
        cout << "5. Assign Instructor to Course\n";
        cout << "6. Show All Students and Instructors\n";
        cout << "7. Assign Student Grade\n";
        cout << "8. Assign New Instructor to Course\n";
        cout << "9. Show All Students\n";
        cout << "10. Show All Instructors\n";
        cout << "11. Delete Student\n";
        cout << "12. Delete Instructor\n";
        cout << "13. View Course\n";
        cout << "14. View All Courses\n";
        cout << "15. Delete Course\n";
        cout << "16. Search Student\n";
        cout << "17. Search Instructor\n";
        cout << "18. Export Data To Files\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cms.addStudent(); break;
        case 2: cms.addInstructor(); break;
        case 3: cms.addCourse(); break;
        case 4: cms.enrollStudentInCourse(); break;
        case 5: cms.assignInstructorToCourse(); break;
        case 6: cms.showAllPersons(); break;
        case 7: cms.assignGrade(); break;
        case 8: cms.assignNewInstructor(); break;
        case 9: cms.showAllStudents(); break;
        case 10: cms.showAllInstructors(); break;
        case 11: cms.deleteStudent(); break;
        case 12: cms.deleteInstructor(); break;
        case 13: cms.viewCourse(); break;
        case 14: cms.viewAllCourses(); break;
        case 15: cms.deleteCourse(); break;
        case 16: cms.searchStudent(); break;
        case 17: cms.searchInstructor(); break;
        case 18: cms.exportToFiles(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
