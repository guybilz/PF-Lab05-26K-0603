#include <stdio.h>
#include <string.h>

int main(){
    char depart,consciousness,severity, casecategory;
    int age, heartrate,bodytemp,casenum;
    int iscritical = 0;
    int seniorpriority = 0;
    int departpriority = 0;
    int tempalert = 0;
    char departname[50];
    char decision[50];
    int abnormalhr = 0;

    strcpy(departname,"Unknown");
    strcpy(decision,"Normal Attention");


    printf("Select department\n");
    printf("1.General Emergency\n2.Cardiology\n3.Neurology\n4.Trauma\n");
    printf("Enter selection:");
    scanf(" %c", &depart);
    printf("Enter patient age:");
    scanf("%d",&age);
    printf("Enter patient heart rate:");
    scanf("%d",&heartrate);
    printf("Enter patient body temperature:");
    scanf("%d",&bodytemp);
    printf("Enter patient level of consciousness(C for conscious/U for unconscious):");
    scanf(" %c",&consciousness);
    printf("Enter patient severity level(1 for normal/2 for high):");
    scanf(" %c",&severity);

    if (heartrate<50 || heartrate>120){
        abnormalhr = 1;
    }


    switch(depart){
        case '1':
            strcpy(departname,"General Emergency");
            switch(severity){
                case '1':
                    printf("General Emergency, normal priority");
                    break;
                case '2':
                    departpriority = 1;
                    printf("General Emergency, depart priority increased");
                    break;
                default:
                    printf("Invalid severity");
            }
            break;
        
        case '2':
            strcpy(departname,"Cardiology");
            switch(abnormalhr){
                case 0:
                    printf("Cardiology, normal heart rate");
                    break;
                case 1:
                    departpriority = 1;
                    printf("Cardiology, abnormal heart rate,depart priority increased");
                    break;
                default:
                    printf("Invalid");
            }
            break;
        case '3':
            strcpy(departname,"Neurology");
            switch(consciousness){
                case 'C':
                    printf("Neurology, patient conscious, no emergency");
                    break;
                case 'U':
                    departpriority = 1;
                    printf("Neurology,patient unconscious, immediate emergency, depart priority increased.");
                    break;
                default:
                    printf("Invalid consciousness");
            }
            break;
        case '4':
            strcpy(departname,"Trauma");
            switch(severity){
            case '1':
                printf("Trauma, normal priority");
                break;
            case '2':
                departpriority = 1;
                printf("Trauma, depart priority increased");
                break;
            default:
                printf("Invalid severity");
            }
            break;
    }
    if (abnormalhr == 1 && consciousness == 'U'){
        iscritical = 1;
    }    
    if (bodytemp<36 || bodytemp>38){
        tempalert = 1;
    }
    if (age>=65){
        seniorpriority = 1;
    }
    casenum = (age+heartrate)%4;
    switch(casenum){
        case 0:
            casecategory = 'A';
            break;
        case 1:
            casecategory = 'B';
            break;
        case 2:
            casecategory = 'C';
            break;
        case 3:
            casecategory = 'D';
            break;
        default:
            casecategory = 'X';
            printf("No case category");
    }

    if (iscritical ==1){
        strcpy(decision,"Immediate Attention");
    } else if (departpriority == 1 || seniorpriority == 1 || tempalert == 1){
        strcpy(decision,"Further assessment");
    } else{
        strcpy(decision,"Routine assessment");
    }

    printf("\n================================\n");
    printf("Department: %s\n",departname);
    printf("Age: %d\n", age);
    printf("Heart rate: %d\n", heartrate);
    printf("Temperature: %d\n", bodytemp);
    printf("Consciousness: %c\n", consciousness);
    printf("Severity: %s\n", (severity=='2')?"Yes":"No");
    printf("Critical: %s\n", (iscritical==1)?"Yes":"No");
    printf("Temperature alert: %s\n", (tempalert==1)?"Yes":"No");
    printf("Department Priority: %s\n", (departpriority==1)?"Yes":"No");
    printf("Senior Priority: %s\n", (seniorpriority==1)?"Yes":"No");
    printf("Case Category: %c\n", casecategory);
    printf("Triage: %s\n",decision);
    return 0;

}