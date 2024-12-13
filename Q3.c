#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int validate(char* email) {
    int atCount = 
    int dotAfterAt = 0; 
    int atPos = -1; 

    int length = strlen(email);

    // Check if the email is empty
    if (length == 0) {
        printf("Invalid email\n");
        return 0;
    }

    // Loop through the email
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atCount++;
            atPos = i; // Store the position of '@'
        }
        if (email[i] == '.' && atPos != -1 && i > atPos) {
            dotAfterAt = 1; // Mark that a '.' is found after '@'
        }
    }

    // Validate email based on criteria
    if (atCount == 1 && dotAfterAt == 1 && atPos > 0 && atPos < length - 1) {
        return 1; // Email is valid
    } else {
        printf("Invalid email\n");
        return 0; // Email is invalid
    }
}

// Function to display the validation result
void display(int found) {
    if (found == 1) {
        printf("Email is valid\n");
    } else {
        printf("Email is not valid\n");
    }
}

int main() {
    char* email; // Pointer for dynamically allocated memory
    int bufferSize = 30; // Initial size for the email buffer

    // Allocate memory for email
    email = (char*)malloc(bufferSize * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    printf("Enter your email: ");
    scanf("%s", email); // Read the email input

    // Validate and display the result
    int result = validate(email);
    display(result);

    // Free dynamically allocated memory
    free(email);

    return 0;
}
