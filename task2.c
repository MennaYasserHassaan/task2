#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char username[20];
    char password[20];
    char password2[20];
    bool flag;
} user;

user users[10];
int userNo = 0;

bool isValid(const char* input) {
    return (strcmp(input, "0") == 0 || strcmp(input, "1") == 0 ||
            strcmp(input, "true") == 0 || strcmp(input, "false") == 0);
}

bool convert(const char* input) {
    // Convert the input to a boolean value
    if (strcmp(input, "1") == 0 || strcmp(input, "true") == 0) {
        return true;
    } else {
        return false;
    }
}

void Register() {
    user newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    
    printf("Enter password: ");
    scanf("%s", newUser.password);
    
    printf("Re-enter password: ");
    scanf("%s", newUser.password2);
    
    if (strcmp(newUser.password2, newUser.password) != 0) {
        printf("Passwords do not match. Re-enter password: ");
        scanf("%s", newUser.password2);
    }
    
    char flagInput[10];
    printf("Enter online or not using 1, 0, true, or false: ");
    scanf("%s", flagInput);
    
    if (isValid(flagInput)) {
        newUser.flag = convert(flagInput);
    } else {
        printf("Invalid input. Enter 0, 1, true, or false.\n");
        scanf("%s", flagInput);
    }

    users[userNo] = newUser;
    userNo++;

    printf("User registered successfully.\n");
}

void Login() {
    char username[20];
    char password[20];
    bool flag = false;
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userNo; i++) {
        user currentUser = users[i];
        
        if (strcmp(currentUser.username, username) == 0 && strcmp(currentUser.password, password) == 0 && (currentUser.flag == true)) {
            printf("Login complete.\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    int x;do{
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &x);

    switch (x) {
        case 1:
            Register();
            break;
        case 2:
            Login();
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}while (x != 3);
    return 0;
}
