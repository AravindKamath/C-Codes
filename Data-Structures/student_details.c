#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[20];
    int sem;
    float m1,m2,m3;
};

void main() {
    struct student s[2];
    struct student *ptr = s;
    float total = 0;
    float s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < 2; i++) {
        printf("Enter details of student %d", i + 1);
        printf("\nRoll: ");
        scanf("%d", &ptr -> roll);
        printf("\nName: ");
        scanf("%s", ptr -> name);
        printf("\nSemester: ");
        scanf("%d", &ptr -> sem);
        printf("\nMarks of 3 Subjects: ");
        scanf("%f %f %f", &ptr -> m1, &ptr -> m2, &ptr -> m3);
        ptr++;
    }

    ptr = s;
    for (int i = 0; i < 2; i++) {
        printf("\nRoll: %d\nName: %s\nSemester: %d\nMark1: %f\nMark2: %f\nMark3: %f", ptr -> roll, ptr -> name, ptr -> sem, ptr -> m1, ptr -> m2, ptr -> m3);
        ptr++;
    }

    ptr = s;
    for (int i = 0; i < 2; i++) {
        printf("\nTotal Marks of Student %d\n", i + 1);
        total = ptr -> m1 + ptr -> m2 + ptr -> m3;
        printf("%f", total);
        ptr++;
    }

    ptr = s;
    ptr = s;
    for (int i = 0; i < 2; i++) {
        s1 = s1 + ptr -> m1;
        s2 = s2 + ptr -> m1;
        s3 = s3 + ptr -> m1;
        ptr++;
    }

    printf("\nSubject 1 total marks : %f", s1);
    printf("\nSubject 2 total marks : %f", s2);
    printf("\nSubject 3 total marks : %f", s3);
}