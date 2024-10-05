/*
 * COP 3515 – Fall Semester 2024
 *
 * Homework #1: Password Strength Meter
 *
 * Phuong Thai
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
bool check_min_length(const char *password, int min_length);
bool check_max_length(const char *password, int max_length);
bool check_no_repeats(const char *password);
bool check_contains_required(const char *password);
bool check_optional_tests(const char *password, int required_tests, int min_required);
int count_digits(const char *password);
int count_special_chars(const char *password);
bool is_passphrase(const char *password);

int main() {
    char *file_names[] = { "Proposed passwords #1.txt", "Proposed passwords #2.txt", "Proposed passwords #3.txt" };
    int num_files = 3;

    // Process each file
    for (int file_idx = 0; file_idx < num_files; file_idx++) {
        FILE *file = fopen(file_names[file_idx], "r");
        if (file == NULL) {
            printf("Could not open file %s\n", file_names[file_idx]);
            return 1;
        }

        // Read the configuration flags from the file
        int max_length, min_length, allow_pass_phrases, min_phrase_length, optional_tests_required, min_optional_tests;
        fscanf(file, "%d %d %d", &max_length, &min_length, &allow_pass_phrases);
        
        if (allow_pass_phrases) {
            fscanf(file, "%d", &min_phrase_length);
        }

        fscanf(file, "%d", &optional_tests_required);

        if (optional_tests_required) {
            fscanf(file, "%d", &min_optional_tests);
        }

        printf("\nProcessing password file #%d\n\n", file_idx + 1);
        printf("Maximum password length: %d\n", max_length);
        printf("Minimum password length: %d\n", min_length);
        printf("Pass phrases are %sallowed\n", allow_pass_phrases ? "" : "NOT ");
        if (allow_pass_phrases) {
            printf("Minimum pass phrase length: %d\n", min_phrase_length);
        }
        printf("Optional tests are %srequired\n", optional_tests_required ? "" : "NOT ");

        char password[101]; // Assuming max password length of 100
        while (fscanf(file, " %100[^\n]", password) == 1) {
            printf("\nPotential password: %s\n", password);

            bool is_strong = true;

            // Check required tests
            if (!check_min_length(password, min_length)) {
                printf("The password must be at least %d characters long.\n", min_length);
                is_strong = false;
            }
            if (!check_max_length(password, max_length)) {
                printf("The password must be fewer than %d characters.\n", max_length);
                is_strong = false;
            }
            if (!check_no_repeats(password)) {
                printf("The password may not contain sequences of three or more repeated characters.\n");
                is_strong = false;
            }
            if (!check_contains_required(password)) {
                printf("The password must contain letters, numbers, AND symbols.\n");
                is_strong = false;
            }

            // Check optional tests
            if (optional_tests_required && is_strong) {
                if (!check_optional_tests(password, optional_tests_required, min_optional_tests)) {
                    printf("The password failed the optional tests.\n");
                    is_strong = false;
                }
            }

            if (is_strong) {
                printf("Password is strong.\n");
            } else {
                printf("Password failed - it cannot be used.\n");
            }
        }

        fclose(file);
    }

    return 0;
}

// Function definitions
bool check_min_length(const char *password, int min_length) {
    return strlen(password) >= min_length;
}

bool check_max_length(const char *password, int max_length) {
    return strlen(password) <= max_length;
}

bool check_no_repeats(const char *password) {
    int length = strlen(password);
    for (int i = 0; i < length - 2; i++) {
        if (password[i] == password[i + 1] && password[i] == password[i + 2]) {
            return false;
        }
    }
    return true;
}

bool check_contains_required(const char *password) {
    bool has_letter = false, has_digit = false, has_special = false;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isalpha(password[i])) {
            has_letter = true;
        } else if (isdigit(password[i])) {
            has_digit = true;
        } else {
            has_special = true;
        }
    }

    return has_letter && has_digit && has_special;
}

bool check_optional_tests(const char *password, int required_tests, int min_required) {
    int passed_tests = 0;

    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) passed_tests++;
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) passed_tests++;
    if (count_digits(password) >= 2) passed_tests++;
    if (count_special_chars(password) >= 2) passed_tests++;

    return passed_tests >= min_required;
}

int count_digits(const char *password) {
    int count = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) count++;
    }
    return count;
}

int count_special_chars(const char *password) {
    int count = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (!isalnum(password[i])) count++;
    }
    return count;
}
