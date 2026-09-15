#include <stdio.h>
#include <string.h>
int main(){
    char category, flight, document, verificationc;
    int weight, age, permittedbaggage;
    char priority[50];
    char boardingstatus[50];
    char passangercategory[50];
    char type[50];

    printf("Select category\n");
    printf("1.Adult \n2.Student \n3.Senior Citizen \n");
    printf("Enter 1,2,3 or 4:");
    scanf(" %c", &category);
    printf("Select flight type");
    printf("\n1.Domestic \n2.International\n");
    printf("Enter 1/2:");
    scanf(" %c", &flight);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter baggage weight: ");
    scanf("%d", &weight);
    printf("Are documents valid(Y/N):");
    scanf(" %c", &document); 

    strcpy(boardingstatus,"Denied");
    strcpy(priority,"Not Available");
    strcpy(type,"X");
    strcpy(passangercategory,"X");

    permittedbaggage = 0;
    verificationc = 'X';
    if (document == 'Y'){  
        switch(category){
            case '1':
                strcpy(passangercategory,"Adult");
                switch(flight){
                    case '1':
                        strcpy(type,"Domestic");
                        permittedbaggage = 20;
                        if (weight> 20) {
                            printf("Overweight! Advance to enhanced scanning");
                            strcpy(boardingstatus,"Denied");
                        } else{
                            strcpy(boardingstatus,"Accepted");
                        }
                        break;
                    case '2':
                        strcpy(type,"International");
                        permittedbaggage = 30;
                        if (weight> 30) {
                            printf("Overweight! Advance to enhanced scanning");
                            strcpy(boardingstatus,"Denied");
                        } else{
                            strcpy(boardingstatus,"Accepted");
                        }
                        break; 
                    default:
                        printf("Invalid choice.");
                }   
                break;
            case '2':
            strcpy(passangercategory,"Student");
                switch(flight){
                    case '1':
                    strcpy(type,"Domestic");
                    
                        permittedbaggage = 25;
                        if (weight> 25) {
                            printf("Overweight! Advance to enhanced scanning");
                            strcpy(boardingstatus,"Denied");
                        } else{
                            strcpy(boardingstatus,"Accepted");

                        }
                        break;
                    case '2':
                    strcpy(type,"International");
                        permittedbaggage = 35;
                        strcpy(priority,"Available");
                        if (weight> 35) {
                            printf("Overweight! Advance to enhanced scanning");
                            strcpy(boardingstatus,"Denied");
                        } else{
                            strcpy(boardingstatus,"Accepted");
                        }
                        break; 
                    default:
                        printf("Invalid choice.");       
                }   
                break;
            case '3':
            strcpy(passangercategory,"Senior citizen");
                switch(flight){
                        case '1':
                        strcpy(type,"Domestic");
                        permittedbaggage = 30;
                        strcpy(priority,"Available");
                            if (weight> 30) {
                                printf("Overweight! Advance to enhanced scanning");
                                strcpy(boardingstatus,"Denied");
                            } else{
                                strcpy(boardingstatus,"Accepted");

                            }
                            break;
                        case '2':
                            strcpy(type,"International");
                            permittedbaggage = 40;
                            strcpy(priority,"Available");
                            if (weight> 40) {
                                printf("Overweight! Advance to enhanced scanning");
                                strcpy(boardingstatus,"Denied");
                            } else{
                                strcpy(boardingstatus,"Accepted");
                            }
                            break;
                        default:
                            printf("Invalid choice.");        
                    }   
                    break;
                
                default:
                    printf("Invalid choice");             
        }
    } else{
        printf("Invalid documents");
        strcpy(boardingstatus,"Denied");
    }
    
    if (age%5 == 0){
        verificationc = 'A';
    } else if (age%5 == 1){
        verificationc = 'B';
    } else if (age%5 == 2){
        verificationc = 'C';
    }else if (age%5 == 3){
        verificationc = 'D';
    } else if (age%5 == 4){
        verificationc = 'E';
    }


    printf("\n========================\n");
    printf("Passenger Category: %s\n", passangercategory);
    printf("Destination type: %s\n", type);
    printf("Permitted baggage allowance: %d\n", permittedbaggage);
    printf("Actual baggage: %d\n", weight);
    printf("Document: %c\n", document);
    printf("Verification category: %c\n", verificationc);
    printf("Priority assistance: %s\n",priority);
    printf("Boarding decision: %s\n", boardingstatus);

    return 0;



    

}