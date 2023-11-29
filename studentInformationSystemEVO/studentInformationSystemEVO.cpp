
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string studentNo;
    string name;
    string sex;
    int age;
    string institution;
    string major;
};

struct Course {
    string courseNo;
    string courseName;
    float courseCredit;
    string courseProperty; // compulsory or optional
};

struct StudentScore {
    string studentNo;
    string courseNo;
    float courseScore;
};

vector<Student> students;
vector<Course> courses;
vector<StudentScore> studentScores;

void addStudent() {
    Student newStudent;
    cout << "Enter Student No: ";
    cin >> newStudent.studentNo;

    // Check if the student already exists
    for (const Student& student : students) {
        if (student.studentNo == newStudent.studentNo) {
            cout << "This student already exists." << endl;
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> newStudent.name;
    cout << "Enter Sex: ";
    cin >> newStudent.sex;
    cout << "Enter Age: ";
    cin >> newStudent.age;
    cout << "Enter Institution: ";
    cin >> newStudent.institution;
    cout << "Enter Major: ";
    cin >> newStudent.major;

    students.push_back(newStudent);
    cout << "Student added successfully." << endl;
}

void addCourse() {
    Course newCourse;
    cout << "Enter Course No: ";
    cin >> newCourse.courseNo;

    // Check if the course already exists
    for (const Course& course : courses) {
        if (course.courseNo == newCourse.courseNo) {
            cout << "This course already exists." << endl;
            return;
        }
    }

    cout << "Enter Course Name: ";
    cin >> newCourse.courseName;
    cout << "Enter Course Credit: ";
    cin >> newCourse.courseCredit;
    cout << "Enter Course Property (compulsory or optional): ";
    cin >> newCourse.courseProperty;

    courses.push_back(newCourse);
    cout << "Course added successfully." << endl;
}

void addStudentScore() {
    StudentScore newScore;
    cout << "Enter Student No: ";
    cin >> newScore.studentNo;

    // Check if the student exists
    bool studentExists = false;
    for (const Student& student : students) {
        if (student.studentNo == newScore.studentNo) {
            studentExists = true;
            break;
        }
    }

    if (!studentExists) {
        cout << "Student not found." << endl;
        return;
    }

    cout << "Enter Course No: ";
    cin >> newScore.courseNo;

    // Check if the course exists
    bool courseExists = false;
    for (const Course& course : courses) {
        if (course.courseNo == newScore.courseNo) {
            courseExists = true;
            break;
        }
    }

    if (!courseExists) {
        cout << "Course not found." << endl;
        return;
    }

    cout << "Enter Course Score: ";
    cin >> newScore.courseScore;

    studentScores.push_back(newScore);
    cout << "Student score added successfully." << endl;
}

void displayStudentInformation() {
    cout << "Enter Student No: ";
    string studentNo;
    cin >> studentNo;

    for (const Student& student : students) {
        if (student.studentNo == studentNo) {
            cout << "Student Information:" << endl;
            cout << "Student No: " << student.studentNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Sex: " << student.sex << endl;
            cout << "Age: " << student.age << endl;
            cout << "Institution: " << student.institution << endl;
            cout << "Major: " << student.major << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

void displayCourseInformation() {
    cout << "Enter Course No: ";
    string courseNo;
    cin >> courseNo;

    for (const Course& course : courses) {
        if (course.courseNo == courseNo) {
            cout << "Course Information:" << endl;
            cout << "Course No: " << course.courseNo << endl;
            cout << "Course Name: " << course.courseName << endl;
            cout << "Course Credit: " << course.courseCredit << endl;
            cout << "Course Property: " << course.courseProperty << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

void displayStudentScores() {
    cout << "Enter Student No: ";
    string studentNo;
    cin >> studentNo;

    cout << "Student Scores:" << endl;

    for (const StudentScore& score : studentScores) {
        if (score.studentNo == studentNo) {
            cout << "Course No: " << score.courseNo << ", Score: " << score.courseScore << endl;
        }
    }
}

int main() {
    bool flag;
    do {
        cout << "What operation is needed?" << endl;
        cout << "1- Add Student\n2- Add Course\n3- Add Student Score\n";
        cout << "4- Display Student Information\n5- Display Course Information\n";
        cout << "6- Display Student Scores\n7- Exit" << endl;

        int input;
        cin >> input;

        switch (input) {
        case 1:
            addStudent();
            break;
        case 2:
            addCourse();
            break;
        case 3:
            addStudentScore();
            break;
        case 4:
            displayStudentInformation();
            break;
        case 5:
            displayCourseInformation();
            break;
        case 6:
            displayStudentScores();
            break;
        case 7:
            flag = false;
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
        }

        cout << "Do you want to perform another operation?\n1- Yes\n2- No" << endl;
        int choice;
        cin >> choice;
        flag = (choice == 1);

    } while (flag);

    return 0;
}
