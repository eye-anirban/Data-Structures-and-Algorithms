#include<stdio.h>
#include<stdlib.h>

    struct csinto
    {
        int roll;
        double cgpa;
        char sub[30];
    };

int main() {
    struct csinto *ptr_643;
    int no_of_students;
    printf("Enter the number of students:");
    scanf("%d",&no_of_students);
    printf("\n");
    ptr_643 = (struct csinto *)malloc(no_of_students * sizeof(struct csinto));
    for(int i=0 ; i< no_of_students; i++)
    {
        printf("Student CS %3d\n\n",i+1);
        printf("Enter roll: ");
        scanf("%d",&(ptr_643+i)->roll);
        printf("Enter cgpa: ");
        scanf("%lf",&(ptr_643+i)->cgpa);
        printf("Enter the subject: ");
        scanf(" %s",&(ptr_643+i)->sub);
    }
    printf("\n\nDisplaying Info:\n\n");
    for (int i=0;i<no_of_students;++i)
    {
        printf("Student CS\n\n");
        printf("Roll no. : ");
        printf("%d\n",(ptr_643+i)->roll);
        printf("CGPA : ");
        printf("%lf\n",(ptr_643+i)->cgpa);
        printf("Subject : ");
        printf("%s\n",(ptr_643+i)->sub);

    }
}



