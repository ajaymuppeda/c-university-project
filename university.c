
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    char studentId[10];
    char course[50];
    float fee;
    float marks;
    float attendance;
    struct Student* next;
} Student;

// Define structure for Lecturer
typedef struct Lecturer {
    int id;
    char name[20];
    char department[20];
} Lecturer;

typedef struct College {
    char name[50];
    Student* students;
     Lecturer* lecturers;
} College;

void addStudent(College* college) {
    Student* newStudent = (Student*) malloc(sizeof(Student));
     strcpy(newStudent->name, newStudent->name);
    strcpy(newStudent->studentId, newStudent->studentId);
    strcpy(newStudent->course, newStudent->course);
      newStudent->fee = newStudent->fee;
    newStudent->marks = newStudent->marks;
    newStudent->attendance = newStudent->attendance;
    newStudent->next = college->students;
              printf("Enter student name: ");
                scanf("%s", newStudent->name);
                printf("Enter student ID: ");
                scanf("%s", &newStudent->studentId);
                printf("Enter student course: ");
                scanf("%s", newStudent->course);
                printf("Enter student fee: ");
                scanf("%f", &newStudent->fee);
                printf("Enter student marks: ");
                scanf("%f", &newStudent->marks);
                printf("Enter student attendance: ");
                scanf("%f", &newStudent->attendance);
                college->students = newStudent;
                printf("Student added successfully!\n");
                
}

void removeStudent(College* college, char* studentId) {
    if (college->students == NULL) return;

    if (strcmp(college->students->studentId, studentId) == 0) {
        Student* temp = college->students;
        college->students = college->students->next;
        free(temp);
        printf("Student Removed successfully\n");
        return;
    }

    Student* current = college->students;
    while (current->next != NULL) {
        if (strcmp(current->next->studentId, studentId) == 0) {
            Student* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}



void displayStudents(College* college) {
    Student* current = college->students;
    while (current != NULL) {
        printf("\nName: %s, \nStudent ID: %s, \nCourse: %s, \nFee: %.2f, \nMarks: %.2f, \nAttendance: %.2f\n", current->name, current->studentId, current->course, current->fee, current->marks, current->attendance);
        current = current->next;
    }
}
void updateFeePaid(College* college, char* studentId, float amountPaid) {
    Student* current = college->students;
    while (current != NULL) {
        if (strcmp(current->studentId, studentId) == 0) {
            current->fee -= amountPaid;
            printf("Fee updated successfully!\n Remaining amount to be paid: %.2f\n", current->fee);
            return;
        }
        current = current->next;
    }
    printf("Student not found!\n");
}

void updateMarks(College* college, char* studentId, float marks) {
    Student* current = college->students;
    while (current != NULL) {
        if (strcmp(current->studentId, studentId) == 0) {
            current->marks = marks;
            printf("Marks updated successfully!\n");
            return;
        }
        current = current->next;
    }
    printf("Student not found!\n");
}
void updateAttendance(College* college, char* studentId, float attendance) {
    Student* current = college->students;
    while (current != NULL) {
        if (strcmp(current->studentId, studentId) == 0) {
            current->attendance = attendance;
            printf("Attendance updated successfully!\n");
            return;
        }
        current = current->next;
    }
    printf("Student not found!\n");
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
    strcpy(college.name, "ABC College");
    college.students = NULL;
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
        printf("Student System\n");
        printf("1. Register Student\n");
        printf("2. Remove Student\n");
        printf("3. list Students\n");
         printf("4. Update Fee Paid\n");
          printf("5. Update Marks\n");
            printf("6. Update Attendance\n");
        printf("7. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &studentChoice);
        switch (studentChoice) {
            case 1:
                addStudent(&college);
                break;
            case 2:
              char studentId2[10];
                printf("Enter student ID to remove: ");
                scanf("%s", studentId2);
                removeStudent(&college, studentId2);
                break;
            case 3:
                displayStudents(&college);
                break;
           
                 case 4:
                char studentId[10];
                float amountPaid;
                printf("Enter student ID: ");
                scanf("%s", studentId);
                printf("Enter amount paid: ");
                scanf("%f", &amountPaid);
                updateFeePaid(&college, studentId, amountPaid);
                break;
                 case 5:
                char studentId3[10];
                float marks2;
                printf("Enter student ID: ");
                scanf("%s", studentId3);
                printf("Enter new marks: ");
                scanf("%f", &marks2);
                updateMarks(&college, studentId3, marks2);
                break;
                case 6:
                char studentId0[10];
                float attendance;
                printf("Enter student ID: ");
                scanf("%s", studentId0);
                printf("Enter new attendance: ");
                scanf("%f", &attendance);
                updateAttendance(&college, studentId0, attendance);
                break;
            case 7:
                printf("Back to main menu\n");
                            break;
            default:
                printf("Invalid choice!\n");
     }   } while (studentChoice != 7);
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
        printf("Student System\n");
        printf("1. Register Student\n");
        printf("2. Remove Student\n");
        printf("3. list Students\n");
         printf("4. Update Fee Paid\n");
          printf("5. Update Marks\n");
            printf("6. Update Attendance\n");
        printf("7. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &studentChoice);
        switch (studentChoice) {
            case 1:
                addStudent(&college);
                break;
            case 2:
              char studentId2[10];
                printf("Enter student ID to remove: ");
                scanf("%s", studentId2);
                removeStudent(&college, studentId2);
                break;
            case 3:
                displayStudents(&college);
                break;
           
                 case 4:
                char studentId[10];
                float amountPaid;
                printf("Enter student ID: ");
                scanf("%s", studentId);
                printf("Enter amount paid: ");
                scanf("%f", &amountPaid);
                updateFeePaid(&college, studentId, amountPaid);
                break;
                 case 5:
                char studentId3[10];
                float marks2;
                printf("Enter student ID: ");
                scanf("%s", studentId3);
                printf("Enter new marks: ");
                scanf("%f", &marks2);
                updateMarks(&college, studentId3, marks2);
                break;
                case 6:
                char studentId0[10];
                float attendance;
                printf("Enter student ID: ");
                scanf("%s", studentId0);
                printf("Enter new attendance: ");
                scanf("%f", &attendance);
                updateAttendance(&college, studentId0, attendance);
                break;
            case 7:
                printf("Back to main menu\n");
                            break;
            default:
                printf("Invalid choice!\n");
     }   } while (studentChoice != 7);
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
        printf("Student System\n");
        printf("1. Register Student\n");
        printf("2. Remove Student\n");
        printf("3. list Students\n");
         printf("4. Update Fee Paid\n");
          printf("5. Update Marks\n");
            printf("6. Update Attendance\n");
        printf("7. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &studentChoice);
        switch (studentChoice) {
            case 1:
                addStudent(&college);
                break;
            case 2:
              char studentId2[10];
                printf("Enter student ID to remove: ");
                scanf("%s", studentId2);
                removeStudent(&college, studentId2);
                break;
            case 3:
                displayStudents(&college);
                break;
           
                 case 4:
                char studentId[10];
                float amountPaid;
                printf("Enter student ID: ");
                scanf("%s", studentId);
                printf("Enter amount paid: ");
                scanf("%f", &amountPaid);
                updateFeePaid(&college, studentId, amountPaid);
                break;
                 case 5:
                char studentId3[10];
                float marks2;
                printf("Enter student ID: ");
                scanf("%s", studentId3);
                printf("Enter new marks: ");
                scanf("%f", &marks2);
                updateMarks(&college, studentId3, marks2);
                break;
                case 6:
                char studentId0[10];
                float attendance;
                printf("Enter student ID: ");
                scanf("%s", studentId0);
                printf("Enter new attendance: ");
                scanf("%f", &attendance);
                updateAttendance(&college, studentId0, attendance);
                break;
            case 7:
                printf("Back to main menu\n");
                            break;
            default:
                printf("Invalid choice!\n");
     }   } while (studentChoice != 7);
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
