#include <stdio.h>
int main(){
    int theoryrequirement,practicalrequirement,theorymarks,practicalmarks,depart;
    float attendance,attendancerequirement;

    
    printf("1.Computer Science\n2.Electrical Engineering\n3.Business Administration\n4.Mathematics\n");
    printf("Select Department:");
    scanf("%d",&depart);
    printf("Enter theory marks:");
    scanf("%d",&theorymarks);
    printf("Enter practical marks:");
    scanf("%d",&practicalmarks);
    printf("Enter attendance:");
    scanf("%f",&attendance);
    printf("====UNIVERSITY EXAMINATION RESULT====\n");
    switch(depart){
        case 1:
            theoryrequirement = 50;
            practicalrequirement = 40;
            attendancerequirement = 75;
            printf("Department: Computer Science\n");
            break;
        case 2:
            theoryrequirement = 55;
            practicalrequirement = 45;
            attendancerequirement = 75;
            printf("Department: Electrical Engineering\n");
            break;
        case 3:
            theoryrequirement = 50;
            practicalrequirement = 35;
            attendancerequirement = 80;
            printf("Department: Business Administration\n");
            break;
        case 4:
            theoryrequirement = 60;
            practicalrequirement = 40;
            attendancerequirement = 75;
            printf("Department: Mathematics\n");
            break;
        default:
            printf("\nInvalid department.");
            return 0;
    }
    printf("Attendance: %.02f%%\n",attendance);
    printf("Attendance Requirement: %.02f%%\n",attendancerequirement);
    printf("Theory Marks: %d\n",theorymarks);
    printf("Theory Marks Requirement: %d\n",theoryrequirement);
    printf("Practical Marks: %d\n",practicalmarks);
    printf("Practical Marks Requirement: %d\n",practicalrequirement);
    
    printf("Status: %s\n",(theorymarks>=theoryrequirement && practicalmarks>=practicalrequirement && attendance>=attendancerequirement) ?
        "PASS": "FAIL");
    
    printf("Distinction: %s\n",(theorymarks>=85 && practicalmarks>=80 && attendance>=90) ? "Eligible":"Not Eligible");
    
    
    if (theorymarks%3 == 0){
        printf("Seat Category: A\n");
    } else if(theorymarks%3 == 1){
        printf("Seat Category: B\n");
    } else if(theorymarks%3 == 2){
        printf("Seat Category: C\n");
    }
    return 0;
}
