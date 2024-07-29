#include <stdio.h>

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

double kelvin_to_fahrenheit(double kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

int main() {
    double temperature, converted_temperature;
    char input_scale, output_scale;

    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    printf("Enter input scale (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &input_scale);

    printf("Enter output scale (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &output_scale);

    switch(input_scale) {
        case 'C':
        case 'c':
            if (output_scale == 'F' || output_scale == 'f') {
                converted_temperature = celsius_to_fahrenheit(temperature);
            } else if (output_scale == 'K' || output_scale == 'k') {
                converted_temperature = celsius_to_kelvin(temperature);
            } else {
                converted_temperature = temperature;
            }
            break;

        case 'F':
        case 'f':
            if (output_scale == 'C' || output_scale == 'c') {
                converted_temperature = fahrenheit_to_celsius(temperature);
            } else if (output_scale == 'K' || output_scale == 'k') {
                converted_temperature = fahrenheit_to_kelvin(temperature);
            } else {
                converted_temperature = temperature;
            }
            break;

        case 'K':
        case 'k':
            if (output_scale == 'C' || output_scale == 'c') {
                converted_temperature = kelvin_to_celsius(temperature);
            } else if (output_scale == 'F' || output_scale == 'f') {
                converted_temperature = kelvin_to_fahrenheit(temperature);
            } else {
                converted_temperature = temperature;
            }
            break;

        default:
            printf("Invalid input scale.\n");
            return 1;
    }

    printf("Converted temperature: %.2f %c\n", converted_temperature, output_scale);
    return 0;
}
