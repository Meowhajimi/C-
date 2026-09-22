#include "cs50_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char* name = get_string("What's your name? ");
    if (name) {
        printf("Hello, %s!\n", name);
        free(name);
    }

    int age = get_int("How old are you? ");
    printf("You are %d years old.\n", age);

    double price = get_double("Enter price: ");
    printf("Price: %.2f\n", price);

    char grade = get_char("Enter your grade (A/B/C): ");
    printf("Grade: %c\n", grade);

    long big = get_long("Enter a large number: ");
    printf("Number: %ld\n", big);

    return 0;
}