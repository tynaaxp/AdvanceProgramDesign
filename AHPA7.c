#include <stdio.h>

int main() {
    char scale;
    float temp, converted_temp;

    // Ask the user which scale they are entering the temperature in
    printf("What type of temperature will you be entering (c/f):\n");
    scanf(" %c", &scale);
    
    printf("What temperature value should be converted?\n");
    scanf("%f", &temp);

    // Check the user's input and proceed with the corresponding conversion
    if (scale == 'F' || scale == 'f') {
        // If the user enters Fahrenheit, ask for the temperature and convert to Celsius
        printf("Given a Fahrenheit temperature of %.2f,\n", temp);
        
        // Fahrenheit to Celsius conversion
        converted_temp = (temp - 32) / 1.8;
        printf("the equivalent Celsius temperature is %.2f\n", converted_temp);
    } else if (scale == 'C' || scale == 'c') {
        // If the user enters Celsius, ask for the temperature and convert to Fahrenheit
        printf("Given a Celsius temperature of %.2f,\n", temp);
        
        // Celsius to Fahrenheit conversion
        converted_temp = (temp * 1.8) + 32;
        printf("the equivalent Fahrenheit temperature is %.2f\n", converted_temp);
    } else {
        // If the user enters an invalid option
        printf("Invalid temperature scale entered. Please enter 'F' for Fahrenheit or 'C' for Celsius.\n");
    }

    return 0;
}
