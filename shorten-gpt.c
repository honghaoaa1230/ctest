#include <stdio.h>

#define MAX_CLASS_SIZE 20
#define MAX_EXAM_MARK 40
#define MAX_ASSIGNMENTS_MARK 60
#define NOT_FOUND -1

enum LoopSentinel {
    STOP_LOOPING,
    KEEP_LOOPING
};

enum Command {
    HELP,
    PRINT_STUDENT,
    PRINT_CLASS,
    QUIT,
    INVALID_COMMAND
};

enum DegreeType {
    UGRD,
    PGRD,
    INVALID_DEGREE
};

enum Major {
    COMPA1,
    COMPD1,
    COMPE1,
    COMPI1,
    COMPJ1,
    COMPN1,
    COMPS1,
    COMPY1,
    NONE
};

struct Student {
    int z_id;
    enum Major major;
    enum DegreeType degree_type;
    double assignments_mark;
    double exam_mark;
    double course_grade;
};

int validate_class_size(int class_size) {
    return class_size > 0 && class_size <= MAX_CLASS_SIZE;
}

enum DegreeType get_degree_type() {
    int scanned_degree_type;
    printf("Select Degree Type:\n");
    printf("0: Undergraduate\n");
    printf("1: Postgraduate\n");
    scanf("%d", &scanned_degree_type);

    if (scanned_degree_type == UGRD || scanned_degree_type == PGRD) {
        return scanned_degree_type;
    }

    return INVALID_DEGREE;
}

enum Major get_major(enum DegreeType degree_type) {
    if (degree_type != UGRD) {
        return NONE;
    }

    int major = 0;
    printf("Select Major:\n");
    while (major < 9) {
        printf("%d: ", major);

        switch (major) {
            case COMPA1:
                printf("Computer Science\n");
                break;
            case COMPD1:
                printf("Database Systems\n");
                break;
            case COMPE1:
                printf("eCommerce Systems\n");
                break;
            case COMPI1:
                printf("Artificial Intelligence\n");
                break;
            case COMPJ1:
                printf("Programming Languages\n");
                break;
            case COMPN1:
                printf("Computer Networks\n");
                break;
            case COMPS1:
                printf("Embedded Systems\n");
                break;
            case COMPY1:
                printf("Security Engineering\n");
                break;
            default:
                printf("None\n");
                break;
        }

        major++;
    }

    int scanned_major;
    scanf("%d", &scanned_major);

    if (scanned_major >= 0 && scanned_major < 9) {
        return scanned_major;
    }

    return NONE;
}

double validate_mark(double mark, double max_mark) {
    if (mark > max_mark) {
        return max_mark;
    } else if (mark < 0) {
        return 0;
    }

    return mark;
}

void print_student_details(struct Student student) {
    printf("z%07d: {\n", student.z_id);
    printf("\tDegree Type: ");
    if (student.degree_type == UGRD) {
        printf("Undergraduate\n");
        printf("\tMajor: ");
        switch (student.major) {
            case COMPA1:
                printf("Computer Science\n");
                break;
            case COMPD1:
                printf("Database Systems\n");
                break;
            case COMPE1:
                printf("eCommerce Systems\n");
                break;
            case COMPI1:
                printf("Artificial Intelligence\n");
                break;
            case COMPJ1:
                printf("Programming Languages\n");
                break;
            case COMPN1:
                printf("Computer Networks\n");
                break;
            case COMPS1:
                printf("Embedded Systems\n");
                break;
            case COMPY1:
                printf("Security Engineering\n");
                break;
            default:
                printf("None\n");
                break;
        }
    } else if (student.degree_type == PGRD) {
        printf("Postgraduate\n");
        printf("\tMajor: None\n");
    } else {
        printf("INVALID\n");
    }
    printf("\tAssignments Mark: %.2lf/%d\n", student.assignments_mark, MAX_ASSIGNMENTS_MARK);
    printf("\tExam Mark: %.2lf/%d\n", student.exam_mark, MAX_EXAM_MARK);
    printf("\tCourse Grade: %.2lf/%d\n", student.course_grade, MAX_ASSIGNMENTS_MARK + MAX_EXAM_MARK);
    printf("}\n");
}

int main(void) {
    int class_size;
    printf("Enter Class Size: ");
    scanf("%d", &class_size);

    if (!validate_class_size(class_size)) {
        printf("Class Size must be between 1 and %d\n", MAX_CLASS_SIZE);
        return 0;
    }

    struct Student class[MAX_CLASS_SIZE];

    int i = 0;
    while (i < class_size) {
        printf("Student %d:\n", i + 1);
        struct Student new_student;

        printf("Enter zID: ");
        scanf("%d", &new_student.z_id);

        new_student.degree_type = get_degree_type();

        new_student.major = get_major(new_student.degree_type);

        printf("Enter Assignments mark (out of %d): ", MAX_ASSIGNMENTS_MARK);
        scanf("%lf", &new_student.assignments_mark);
        new_student.assignments_mark = validate_mark(new_student.assignments_mark, MAX_ASSIGNMENTS_MARK);

        printf("Enter exam mark (out of %d): ", MAX_EXAM_MARK);
        scanf("%lf", &new_student.exam_mark);
        new_student.exam_mark = validate_mark(new_student.exam_mark, MAX_EXAM_MARK);

        new_student.course_grade = new_student.exam_mark + new_student.assignments_mark;

        class[i] = new_student;
        i++;
    }

    int is_looping = 1;
    while (is_looping) {
        printf("Enter Command Number (0 for Help): ");

        int scanned_command;
        scanf("%d", &scanned_command);

        enum Command command;
        if (scanned_command >= 0 && scanned_command <= 3) {
            command = scanned_command;
        } else {
            command = INVALID_COMMAND;
        }

        switch (command) {
            case HELP:
                printf("Enter a number corresponding to one of the following commands:\n");
                printf("0 (Help): Display program instructions\n");
                printf("1 (Display Student): Print the details of a specific student\n");
                printf("2 (Display Class): Print the details of all students in a class\n");
                printf("3 (Quit): Exit the program\n");
                break;
            case PRINT_STUDENT:
                printf("Enter Student zID: ");
                int z_id;
                scanf("%d", &z_id);

                int student_index = NOT_FOUND;
                i = 0;
                while (i < class_size) {
                    if (class[i].z_id == z_id) {
                        student_index = i;
                        break;
                    }
                    i++;
                }

                if (student_index == NOT_FOUND) {
                    printf("No student with that zID exists\n");
                } else {
                    print_student_details(class[student_index]);
                }
                break;
            case PRINT_CLASS:
                i = 0;
                while (i < class_size) {
                    print_student_details(class[i]);
                    i++;
                }
                break;
            case QUIT:
                is_looping = 0;
                printf("Exiting Program\n");
                break;
            case INVALID_COMMAND:
                printf("Invalid Command\n");
                break;
        }
    }

    return 0;
}
