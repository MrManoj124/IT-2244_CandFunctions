#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char name[MAX_LEN];
    char reg_no[MAX_LEN];
    char age[MAX_LEN];

    printf("========================================\n");
    printf("        Enter Your Details\n");
    printf("========================================\n");

    printf("Name: ");
    fflush(stdout);
    if (fgets(name, sizeof(name), stdin) == NULL) {
        perror("Failed to read name");
        return 1;
    }
    // Remove trailing newline
    name[strcspn(name, "\n")] = 0;

    printf("Reg No: ");
    fflush(stdout);
    if (fgets(reg_no, sizeof(reg_no), stdin) == NULL) {
        perror("Failed to read reg no");
        return 1;
    }
    reg_no[strcspn(reg_no, "\n")] = 0;

    printf("Age: ");
    fflush(stdout);
    if (fgets(age, sizeof(age), stdin) == NULL) {
        perror("Failed to read age");
        return 1;
    }
    age[strcspn(age, "\n")] = 0;

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process: print the received arguments
        printf("\n----------------------------------------\n");
        printf("            Child Process Output\n");
        printf("----------------------------------------\n");
        printf("Name    : %s\n", name);
        printf("Reg No  : %s\n", reg_no);
        printf("Age     : %s\n", age);
        printf("----------------------------------------\n");
        return 0;  // Exit child
    } else {
        // Parent process: wait for child to finish
        wait(NULL);
        printf("\nParent process: Child has finished printing the inputs.\n");
    }

    return 0;
}