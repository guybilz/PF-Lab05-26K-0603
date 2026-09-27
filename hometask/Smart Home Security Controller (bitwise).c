#include <stdio.h>

int main(){
    int MAINDOOR = 1 << 0;      
    int ALARMSYSTEM = 1 << 1;   
    int CCTV = 1 << 2;          
    int SENSOR = 1 << 3;        

    int status = 0;
    int device,operation,mode ;
    char yn;
    printf("========SMART HOME SECURITY CONTROLLER======\n");
    printf("1.Activate Device\n2.Deactivate Device\n3.Check Status\n4.Toggle device\n");
    printf("Select operation:");
    scanf("%d", &operation);
    printf("---------------------------------------------\n");
    printf("1.Main door lock\n2.Alarm System\n3.CCTV camera\n4.Motion Sensor\n");
    printf("Select device:");
    scanf("%d", &device);
    printf("---------------------------------------------\n");
    printf("Do you want to select a mode?(Y/N):");
    scanf(" %c",&yn);
    if (yn == 'Y'){
        printf("1.Home Mode\n2.Away Mode\n3.Night Mode\n");
        printf("Select mode:");
        scanf("%d", &mode);
    }
    printf("---------------------------------------------\n");

    switch(operation){
        case 1:
            switch(device){
                case 1:
                    status = status | MAINDOOR;
                    printf("Main door lock activated\n");
                    break;
                case 2:
                    status = status | ALARMSYSTEM;
                    printf("Alarm system activated\n");
                    break;
                case 3:
                    status = status | CCTV;
                    printf("CCTV Camera activated\n");
                    break;
                case 4:
                    status = status | SENSOR;
                    printf("Motion Sensor activated\n");
                    break;
                default:
                    printf("Invalid Device\n");
            }
            break;
        case 2:
            switch(device){
                case 1:
                    status = status & ~MAINDOOR;
                    printf("Main door lock deactivated\n");
                    break;
                case 2:
                    status = status & ~ALARMSYSTEM;
                    printf("Alarm system Deactivated\n");
                    break;
                case 3:
                    status = status & ~CCTV;
                    printf("CCTV Camera deactivated\n");
                    break;
                case 4:
                    status = status & ~SENSOR;
                    printf("Motion Sensor deactivated\n");
                    break;
                default:
                    printf("Invalid Device\n");
            }
            break;
        case 3:
            switch(device){
                case 1:
                    if (status&MAINDOOR)
                        printf("ACTIVATED\n");
                    else
                        printf("Not activated\n");
                    break;
                case 2:
                    if (status&ALARMSYSTEM)
                        printf("ACTIVATED\n");
                    else
                        printf("Not activated\n");
                    break;
                case 3:
                    if (status&CCTV)
                        printf("ACTIVATED\n");
                    else
                        printf("Not activated\n");
                    break;
                case 4:
                    if (status&SENSOR)
                        printf("ACTIVATED\n");
                    else
                        printf("Not activated\n");
                    break;
                default:
                        printf("Invalid Device\n");
            }    
            break;
        case 4:
            switch(device){
                case 1:
                    status = status ^ MAINDOOR;
                    printf("Deivce toggled\n");
                    break;
                case 2:
                    status = status ^ ALARMSYSTEM;
                    printf("Deivce toggled\n");
                    break;
                case 3:
                    status = status ^ CCTV;
                    printf("Deivce toggled\n");
                    break;
                case 4:
                    status = status ^ SENSOR;
                    printf("Deivce toggled\n");
                    break;
                default:
                    printf("Invalid Device\n");
            }
            break;
        default:
            printf("Invalid operation\n");
    }
    if (yn == 'Y'){
        switch(mode){
            case 1:
                status = status | (MAINDOOR|CCTV);
                printf("Home Mode activated\n");
                break;
            case 2:
                status = status | (MAINDOOR|CCTV|ALARMSYSTEM|SENSOR);
                printf("Away Mode activated\n");
                break;
            case 3:
                status = status | (MAINDOOR|ALARMSYSTEM|SENSOR);
                printf("Night Mode activated\n");
                break;
            default:
                printf("Invalid mode\n");   
        }
    }
    printf("Binary status (Door Alarm CCTV Sensor): ");
    printf("%d%d%d%d ",
        ((status & MAINDOOR) >> 3)&1,
        ((status & MAINDOOR) >> 2)&1,
        ((status & MAINDOOR) >> 1)&1,
        ((status & MAINDOOR))&1);

    printf("%d%d%d%d ",
        ((status & ALARMSYSTEM) >> 3)&1,
        ((status & ALARMSYSTEM) >> 2)&1,
        ((status & ALARMSYSTEM) >> 1)&1,
        ((status & ALARMSYSTEM))&1);

    printf("%d%d%d%d ",
        ((status & CCTV) >> 3)&1,
        ((status & CCTV) >> 2)&1,
        ((status & CCTV) >> 1)&1,
        ((status & CCTV))&1);

    printf("%d%d%d%d\n",
        ((status & SENSOR) >> 3)&1,
        ((status & SENSOR) >> 2)&1,
        ((status & SENSOR) >> 1)&1,
        ((status & SENSOR))&1);

    printf("Door Lock   (bit value 1): %s\n",(status&MAINDOOR) ? "ACTIVE" : "INACTIVE");
    printf("Alarm       (bit value 2): %s\n", (status&ALARMSYSTEM)? "ACTIVE" : "INACTIVE");
    printf("CCTV Camera (bit value 4): %s\n", (status&CCTV)? "ACTIVE" : "INACTIVE");
    printf("Motion Sensor (bit value 8): %s\n", (status&SENSOR) ? "ACTIVE" : "INACTIVE");

   
 
    printf("System Armed Status: %s\n", ((status&MAINDOOR) && (status&ALARMSYSTEM) && (status&CCTV) && (status&SENSOR)) ? "FULLY ARMED" : "NOT FULLY ARMED");

}