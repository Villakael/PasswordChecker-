#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxPasswds 50

typedef struct {
    char password[50];
} Passwd;

typedef struct Node {
    int pswdIndex;
    struct Node *next;
} Node;

void checker(Passwd passwds[], int *count, Node **head);
void list_passwords(Passwd passwds[], Node *head, int count);
int get_valid_int();

int my_strlen(const char *s);
int has_min_length(const char *pw);
int has_uppercase(const char *pw);
int has_lowercase(const char *pw);
int has_digit(const char *pw);
int has_special_char(const char *pw);

int main(void)
{
    Passwd passwds[maxPasswds];
    int choice, id;
    int count = 0;

    Node *head = NULL;

    FILE *file = fopen("passwords.txt", "r");
    if (file != NULL) {
        while (fgets(passwds[count].password, sizeof(passwds[count].password), file) != NULL && count < maxPasswds) {
            size_t len = strlen(passwds[count].password);
            if (len > 0 && passwds[count].password[len - 1] == '\n') {
                passwds[count].password[len - 1] = '\0';
            }
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->pswdIndex = count;
            newNode->next = head;
            head = newNode;
            count++;
        }
        fclose(file);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Check password\n");
        printf("2. List previous passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        choice = get_valid_int();

        switch (choice) {
            case 1:
                checker(passwds, &count, &head);
                break;
            case 2:
                list_passwords(passwds, head, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

int get_valid_int() {
    char input[10];
    int value;
    while (1) {
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &value) == 1) {
                return value;
            } else {
                printf("Invalid input. Enter a number: ");
            }
        } else {
            printf("Input error. Try again: ");
            clearerr(stdin);
        }
    }
}

void checker(Passwd passwds[], int *count, Node **head) {
    if (*count >= maxPasswds) {
        printf("\nMax number of passwords reached.\n");
        return;
    }

    Passwd *p = &passwds[*count];
    printf("\nEnter strong password: ");
    scanf(" %[^\n]", p->password);
    getchar();

    const char *pw = p->password;
    int strength = 0;

    if (has_min_length(pw)) {
        strength++;
    } else {
        printf("Too short\n");
    }

    if (has_uppercase(pw)) {
        strength++;
    } else {
        printf("Add uppercase\n");
    }

    if (has_lowercase(pw)) {
        strength++;
    } else {
        printf("Add lowercase\n");
    }

    if (has_digit(pw)) {
        strength++;
    } else {
        printf("Add digit\n");
    }

    if (has_special_char(pw)) {
        strength++;
    } else {
        printf("Add special character\n");
    }

    if (strength >= 5) {
        printf("\nStrong password accepted!\n");

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->pswdIndex = *count;
        newNode->next = *head;
        *head = newNode;

        FILE *file = fopen("passwords.txt", "a");
        if (file != NULL) {
            fprintf(file, "%s\n", p->password);
            fclose(file);
        }

        (*count)++;
    } else if (strength >= 4) {
        printf("\nFairly strong, Try again to add a strong password\n");
    } else if (strength >= 3) {
        printf("\nModerate, Try again to add a strong password\n");
    } else if (strength >= 2) {
        printf("\nWeak, Try again to add a strong password\n");
    } else {
        printf("\nPassword too weak. Try again.\n");
    }
}

void list_passwords(Passwd passwds[], Node *head, int count) {
    if (head == NULL) {
        printf("\nNo passwords stored.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    Node *curr = head;
    while (curr != NULL) {
        int idx = curr->pswdIndex;
        if (idx >= 0 && idx < count) {
            printf("- %s\n", passwds[idx].password);
        }
        curr = curr->next;
    }
}

int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int has_min_length(const char *pw) {
    return my_strlen(pw) >= 8;
}

int has_uppercase(const char *pw) {
    int i = 0;
    while (pw[i] != '\0') {
        if (pw[i] >= 'A' && pw[i] <= 'Z') return 1;
        i++;
    }
    return 0;
}

int has_lowercase(const char *pw) {
    int i = 0;
    while (pw[i] != '\0') {
        if (pw[i] >= 'a' && pw[i] <= 'z') return 1;
        i++;
    }
    return 0;
}

int has_digit(const char *pw) {
    int i = 0;
    while (pw[i] != '\0') {
        if (pw[i] >= '0' && pw[i] <= '9') return 1;
        i++;
    }
    return 0;
}

int has_special_char(const char *pw) {
    const char *specials = "!@#$%^&*()-_=+[]{};:'\",.<>?/\\|";
    int i = 0;
    while (pw[i] != '\0') {
        int j = 0;
        while (specials[j] != '\0') {
            if (pw[i] == specials[j]) return 1;
            j++;
        }
        i++;
    }
    return 0;
}