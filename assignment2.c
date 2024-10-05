#include <stdio.h>
int main()
{
    char flavor1[20], flavor2[20], flavor3[20], flavor4[20];
    
    printf("Enter ice cream flavor #1: ");
    scanf("%19s", flavor1);
    
    printf("Enter ice cream flavor #2: ");
    scanf("%19s", flavor2);
    
    printf("Enter ice cream flavor #3: ");
    scanf("%19s", flavor3);
    
    printf("Enter ice cream flavor #4: ");
    scanf("%19s", flavor4);
    
    float c1_price1, c1_price2, c1_price3, c1_price4;
    printf("Enter corner 1 sales of %s: ", flavor1);
    scanf("%f", &c1_price1);
    
    printf("Enter corner 1 sales of %s: ", flavor2);
    scanf("%f", &c1_price2);
    
    printf("Enter corner 1 sales of %s: ", flavor3);
    scanf("%f", &c1_price3);
    
    printf("Enter corner 1 sales of %s: ", flavor4);
    scanf("%f", &c1_price4);
    
    float c2_price1, c2_price2, c2_price3, c2_price4;
    
    printf("Enter corner 2 sales of %s: ", flavor1);
    scanf("%f", &c2_price1);
    
    printf("Enter corner 2 sales of %s: ", flavor2);
    scanf("%f", &c2_price2);
    
    printf("Enter corner 2 sales of %s: ", flavor3);
    scanf("%f", &c2_price3);
    
    printf("Enter corner 2 sales of %s: ", flavor4);
    scanf("%f", &c2_price4);
    
    float total_f1 = c1_price1 + c2_price1, total_f2 = c1_price2 + c2_price2, total_f3 = c1_price3 + c2_price3, total_f4 = c1_price4 + c2_price4, total = total_f1 + total_f2 + total_f3 + total_f4;
    
    printf("Total %s sales: %.2f\n", flavor1, total_f1);
    printf("Total %s sales: %.2f\n", flavor2, total_f2);
    printf("Total %s sales: %.2f\n", flavor3, total_f3);
    printf("Total %s sales: %.2f\n", flavor4, total_f4);
    
    printf("Bob's Ice Cream total sales: %.2f", total);
    
    return 0;
}