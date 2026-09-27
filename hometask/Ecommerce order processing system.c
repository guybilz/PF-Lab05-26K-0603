#include <stdio.h>
int main(){
    int product,customer,discount,prioritycharges,ispriority, ordernum;
    float orderamount, distance,deliverycharge,discountamount,finalamount,totalamount;

    printf("Enter Order Number:");
    scanf("%d",&ordernum);
    printf("1.Electronics\n2.Clothing\n3.Books\n4.Household\n");
    printf("Select Product Category:");
    scanf("%d",&product);
    printf("1.Regular\n2.Premium\n3.Corporate\n");
    printf("Select Customer Category:");
    scanf("%d",&customer);
    printf("Enter order amount:");
    scanf("%f",&orderamount);
    printf("Enter delivery distance:");
    scanf("%f",&distance);

    printf("====ORDER DETAILS====\n");
    switch(product){
        case 1:
        printf("Product Category: Electronics\n");
            switch(customer){
                case 1:
                    printf("Customer Category: Regular\n");
                    discount = 5;
                    break;
                case 2: 
                    printf("Customer Category: Premium\n");
                    discount = 10;
                    break;
                case 3:
                    printf("Customer Category: Corporate\n");
                    discount = 15;
                    break;
                default:
                    printf("Invalid customer category.");
                    return 0; 
            }
            break;
        case 2:
            printf("Product Category: Clothing\n");
            switch(customer){
                case 1:
                    printf("Customer Category: Regular\n");
                    discount = 10;
                    break;
                case 2:
                    printf("Customer Category: Premium\n"); 
                    discount = 15;
                    break;
                case 3:
                    printf("Customer Category: Corporate\n");
                    discount = 20;
                    break;
                default:
                    printf("Invalid customer category.");
                    return 0;
            }
            break;
        case 3:
                printf("Product Category: Books\n");
                switch(customer){
                    case 1:
                        printf("Customer Category: Regular\n");
                        discount = 8;
                        break;
                    case 2: 
                        printf("Customer Category: Premium\n");
                        discount = 12;
                        break;
                    case 3:
                        printf("Customer Category: Corporate\n");
                        discount = 18;
                        break;
                    default:
                        printf("Invalid customer category.");
                        return 0;
                }
                break;
        case 4:
                printf("Product Category: Household\n");
                switch(customer){
                    case 1:
                    printf("Customer Category: Regular\n");
                        discount = 7;
                        break;
                    case 2: 
                        printf("Customer Category: Premium\n");
                        discount = 14;
                        break;
                    case 3:
                        printf("Customer Category: Corporate\n");
                        discount = 20;
                        break;
                    default:
                        printf("Invalid customer category.");
                        return 0;
                }
                break;
        default:
                printf("Invalid product category.");
                return 0;
    }
    
    
    ((customer == 2 ||customer == 3)&&(orderamount>=10000)) ? 
    (ispriority = 1,prioritycharges = 500):
    (ispriority = 0,prioritycharges = 0);



    discountamount = orderamount * (discount/100.0);
    finalamount = orderamount - discountamount;
    ((customer == 2 ||customer == 3 || finalamount>=5000)? (deliverycharge = 0):(deliverycharge = distance) );
    totalamount = finalamount + prioritycharges + deliverycharge ; 

    printf("Original order amount: %.2f\n",orderamount);
    printf("Applicable discount: %d%%\n",discount);
    printf("Discount amount: %.2f\n",discountamount);
    printf("Final amount:%.2f\n",finalamount);
    printf("Delivery distance: %.2f\n",distance);
    printf("Shipping Status: %s\n",(deliverycharge == 0)? "FREE":"PAID");
    printf("Delivery Charges: %.2f\n",deliverycharge);
    printf("Delivery Status: %s\n",(ispriority==1)? "PRIORITY":"NORMAL");
    printf("Priority Charges: %d\n",prioritycharges);

    if (ordernum%4 == 0){
        printf("Processing Group: A\n");
    } else if(ordernum%4 == 1){
        printf("Processing Group: B\n");
    } else if(ordernum%4 == 2){
        printf("Processing Group: C\n");
    } else if(ordernum%4 == 3){
        printf("Processing Group: D\n");
    }

    printf("TOTAL AMOUNT PAYABLE: %.2f",totalamount);
    return 0;
}