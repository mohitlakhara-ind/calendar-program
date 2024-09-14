#include <stdio.h>

// Function that returns the index of the day for date DD/MM/YYYY
int dayNumber(int day, int month, int year) 
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

// Function that returns the name of the month for the given month Number
const char* getMonthName(int monthNumber) 
{
    static const char* months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    return months[monthNumber];
}

// Function to return the number of days in a month
int numberOfDays(int monthNumber, int year) 
{
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (monthNumber == 1 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) 
        return 29; // Leap year adjustment for February

    return daysInMonth[monthNumber];
}

// Function to print the calendar of the given year
void printCalendar(int year) 
{
    printf("      Calendar - %d\n\n", year);
    int days;
    int current = dayNumber(1, 1, year); // Index of the day from 0 to 6

    for (int i = 0; i < 12; i++) 
    {
        days = numberOfDays(i, year);
        printf("\n ------------ %s -------------\n", getMonthName(i));
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        // Print appropriate spaces
        for (int k = 0; k < current; k++) 
            printf("    ");

        for (int j = 1; j <= days; j++) 
        {
            printf("%4d", j);

            if (++current > 6) 
            {
                current = 0;
                printf("\n");
            }
        }

        if (current) 
            printf("\n");

        // Prepare for the next month
        current = (current % 7);
    }
}

int main() 
{
    int year;

    printf("Enter the year: ");
    if (scanf("%d", &year) != 1 || year <= 0) 
    {
        printf("Invalid input. Please enter a positive integer for the year.\n");
        return 1;
    }

    // Function Call
    // Credits Section
/*
 * Program: Conversion Tool - Binary, Octal, Decimal, and Hexadecimal
 * Author: Mohit Lakhara
 * GitHub: https://github.com/mohitlakhara-ind
 * Description: A simple and interactive tool to perform conversions between 
 *              binary, octal, decimal, and hexadecimal number systems.
 * Date: 2024
 *
 * Acknowledgements:
 * - Open-source community for invaluable guidance and resources.
 * 
 * License: MIT License
 */
    printCalendar(year);
    return 0;
}
