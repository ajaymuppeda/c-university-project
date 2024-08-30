
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Student
typedef struct Student {
    int id;
    char name[20];
    char program[20];
    float fee;
    float paidFee;
    float marks;
    int attendance;
} Student;

// Define structure for Lecturer
typedef struct Lecturer {
    int id;
    char name[20];
    char department[20];
} Lecturer;

// Define structure for College
typedef struct College {
    Student* students;
    Lecturer* lecturers;
} College;

// Function to add a student
void addStudent(College* college) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter Student ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter Student Name: ");
    scanf("%s", newStudent->name);
    printf("Enter Student Program: ");
    scanf("%s", newStudent->program);
    printf("Enter Student Fee: ");
    scanf("%f", &newStudent->fee);
    newStudent->paidFee = 0;
    printf("Enter Student Marks: ");
    scanf("%f", &newStudent->marks);
    printf("Enter Student Attendance: ");
    scanf("%d", &newStudent->attendance);
    college->students = newStudent;
    printf("Student added successfully!\n");
}

// Function to update student fee
void updateStudentFee(College* college) {
    int studentId;
    printf("Enter Student ID: ");
    scanf("%d", &studentId);
    // Find the student by ID and update the fee
    if (college->students->id == studentId) {
        printf("Enter paid fee: ");
        scanf("%f", &college->students->paidFee);
        printf("Fee updated successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}

// Function to update student marks
void updateStudentMarks(College* college) {
    int studentId;
    printf("Enter Student ID: ");
    scanf("%d", &studentId);
    // Find the student by ID and update the marks
    if (college->students->id == studentId) {
        printf("Enter new marks: ");
        scanf("%f", &college->students->marks);
        printf("Marks updated successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}

// Function to update student attendance
void updateStudentAttendance(College* college) {
    int studentId;
    printf("Enter Student ID: ");
    scanf("%d", &studentId);
    // Find the student by ID and update the attendance
    if (college->students->id == studentId) {
        printf("Enter new attendance: ");
        scanf("%d", &college->students->attendance);
        printf("Attendance updated successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}

// Function to list students
void listStudents(College* college) {
    if (college->students != NULL) {
        printf("Student ID: %d\n", college->students->id);
        printf("Student Name: %s\n", college->students->name);
        printf("Student Program: %s\n", college->students->program);
        printf("Original Fee: %.2f\n", college->students->fee);
        printf("Last Paid Fee: %.2f\n", college->students->paidFee);
        printf("Remaining Fee: %.2f\n", college->students->fee - college->students->paidFee);
        printf("Student Marks: %.2f\n", college->students->marks);
        printf("Student Attendance: %d\n", college->students->attendance);
    } else {
        printf("No students added yet!\n");
    }
}

// Function to add a lecturer
void addLecturer(College* college) {
    Lecturer* newLecturer = (Lecturer*)malloc(sizeof(Lecturer));
    printf("Enter Lecturer ID: ");
    scanf("%d", &newLecturer->id);
    printf("Enter Lecturer Name: ");
    scanf("%s", newLecturer->name);
    printf("Enter Lecturer Department: ");
    scanf("%s", newLecturer->department);
    college->lecturers = newLecturer;
    printf("Lecturer added successfully!\n");
}

// Function to update lecturer department
void updateLecturerDepartment(College* college) {
    int lecturerId;
    printf("Enter Lecturer ID: ");
    scanf("%d", &lecturerId);
    // Find the lecturer by ID and update the department
    if (college->lecturers->id == lecturerId) {
        printf("Enter new department: ");
        scanf("%s", college->lecturers->department);
        printf("Department updated successfully!\n");
    } else {
        printf("Lecturer not found!\n");
    }
}

// Function to list lecturers
void listLecturers(College* college) {
    if (college->lecturers != NULL) {
        printf("Lecturer ID: %d\n", college->lecturers->id);
        printf("Lecturer Name: %s\n", college->lecturers->name);
        printf("Lecturer Department: %s\n", college->lecturers->department);
    } else {
        printf("No lecturers added yet!\n");
    }
}

int main() {
    College college;
    college.students = NULL;
    college.lecturers = NULL;

    int choice;
    do {
        printf("WELCOME TO NANAY NETWORKS\n");
        printf("1. Students Portal\n");
        printf("2. Lecturers Portal\n");
         printf("3. Administration Portal\n");
        printf("4. Exit\n");
        printf("\nENTER THE OPTION:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int studentChoice;
                do {
                    printf("Student Management\n");
                    printf("1. Register Student\n");
                    printf("2. Update Student Fee\n");
                    printf("3. Update Student Marks\n");
                    printf("4. Update Student Attendance\n");
                    printf("5. List Students\n");
                    printf("6. Back\n");
                    printf("\nChoose the option:");
                    scanf("%d", &studentChoice);

                    switch (studentChoice) {
                        case 1:
                            addStudent(&college);
                            break;
                        case 2:
                            updateStudentFee(&college);
                            break;
                        case 3:
                            updateStudentMarks(&college);
                            break;
                            case 4:
                            updateStudentAttendance(&college);
                            break;
                        case 5:
                            listStudents(&college);
                            break;
                        case 6:
                            printf("Back to main menu\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (studentChoice != 6);
                break;
           
case 2:
    int lecturerChoice;
    do {
        printf("Lecturer Management\n");
        printf("1. Register Lecture\n");
        printf("2. Update Lecturer Department\n");
        printf("3. List Lecturers\n");
        printf("4. Student Management\n");
        printf("5. Back\n");
         printf("\nChoose the option:");
        scanf("%d", &lecturerChoice);

        switch (lecturerChoice) {
            case 1:
                addLecturer(&college);
                break;
            case 2:
                updateLecturerDepartment(&college);
                break;
            case 3:
                listLecturers(&college);
                break;
            case 4:
                int studentChoice;
                do {
                    printf("Student Management\n");
                    printf("1. Register Student\n");
                    printf("2. Update Student Fee\n");
                    printf("3. Update Student Marks\n");
                    printf("4. Update Student Attendance\n");
                    printf("5. List Students\n");
                    printf("6. Back\n");
                     printf("\nChoose the option:");
                    scanf("%d", &studentChoice);

                    switch (studentChoice) {
                        case 1:
                            addStudent(&college);
                            break;
                        case 2:
                            updateStudentFee(&college);
                            break;
                        case 3:
                            updateStudentMarks(&college);
                            break;
                        case 4:
                            updateStudentAttendance(&college);
                            break;
                        case 5:
                            listStudents(&college);
                            break;
                        case 6:
                            printf("Back to lecturer management\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (studentChoice != 6);
                break;
            case 5:
                printf("Back to main menu\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (lecturerChoice != 5);
    break;
    
case 3:
    int administrationChoice;
    do {
        printf("Administration Management\n");
        printf("1. Lecture Management\n");
        printf("2. Student Management\n");
        printf("3. Back\n");
         printf("\nChoose the option:");
        scanf("%d", &administrationChoice);

        switch (administrationChoice) {
            case 1:
                int lecturerChoice;
                do {
                    printf("Lecture Management\n");
                    printf("1. Register Lecture\n");
                    printf("2. Update Lecturer Department\n");
                    printf("3. List Lecturers\n");
                    printf("4. Back\n");
                     printf("\nChoose the option:");
                    scanf("%d", &lecturerChoice);

                    switch (lecturerChoice) {
                        case 1:
                            addLecturer(&college);
                            break;
                        case 2:
                            updateLecturerDepartment(&college);
                            break;
                        case 3:
                            listLecturers(&college);
                            break;
                        case 4:
                            printf("Back to administration management\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (lecturerChoice != 4);
                break;
            case 2:
                int studentChoice;
                do {
                    printf("Student Management\n");
                    printf("1. Register Student\n");
                    printf("2. Update Student Fee\n");
                    printf("3. Update Student Marks\n");
                    printf("4. Update Student Attendance\n");
                    printf("5. List Students\n");
                    printf("6. Back\n");
                     printf("\nChoose the option:");
                    scanf("%d", &studentChoice);

                    switch (studentChoice) {
                        case 1:
                            addStudent(&college);
                            break;
                        case 2:
                            updateStudentFee(&college);
                            break;
                        case 3:
                            updateStudentMarks(&college);
                            break;
                        case 4:
                            updateStudentAttendance(&college);
                            break;
                        case 5:
                            listStudents(&college);
                            break;
                        case 6:
                            printf("Back to administration management\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (studentChoice != 6);
                break;
            case 3:
                printf("Back to main menu\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (administrationChoice != 3);
    break;

            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}