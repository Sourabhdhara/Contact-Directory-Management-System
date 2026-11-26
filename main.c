#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure for Contact Linked List */
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    struct Contact *next;
};

/* Global head pointer */
struct Contact *head = NULL;

/* Function Declarations */
void addContactMenu();
void insertBeginning(char name[], char phone[], char email[]);
void insertEnd(char name[], char phone[], char email[]);
void insertAtPosition(char name[], char phone[], char email[], int pos);

void deleteMenu();
void deleteByName(char name[]);
void deleteByPhone(char phone[]);
void updateContact();

void searchMenu();
void searchByName(char name[]);
void searchByPhone(char phone[]);
void searchByEmail(char email[]);

void displayContacts();
void countContacts();
void detectDuplicates();
void sortAlphabetical();

int main() {
    int choice;

    do {
        printf("\n===== CONTACT DIRECTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add / Insert Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Update Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Count Total Contacts\n");
        printf("7. Detect Duplicates\n");
        printf("8. Show Contacts Alphabetically\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addContactMenu(); break;
            case 2: deleteMenu(); break;
            case 3: updateContact(); break;
            case 4: searchMenu(); break;
            case 5: displayContacts(); break;
            case 6: countContacts(); break;
            case 7: detectDuplicates(); break;
            case 8: sortAlphabetical(); break;
            case 0: printf("Thank you for using Contact Directory!\n"); break;
            default: printf("Wrong choice! Please enter again.\n");
        }
    } while(choice != 0);

    return 0;
}

/* ========================================================
   MODULE 1: Add and Insert Contact Module
   ======================================================== */

void addContactMenu() {
    char name[50], phone[20], email[50];
    int choice, pos;

    printf("\nEnter Name: ");
    scanf(" %49[^\n]", name);
    printf("Enter Phone: ");
    scanf(" %19[^\n]", phone);
    printf("Enter Email: ");
    scanf(" %49[^\n]", email);

    printf("\nWhere do you want to insert?\n");
    printf("1. At Beginning\n");
    printf("2. At End\n");
    printf("3. At Specific Position\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        insertBeginning(name, phone, email);
    } else if(choice == 2) {
        insertEnd(name, phone, email);
    } else if(choice == 3) {
        printf("Enter position (1, 2, 3...): ");
        scanf("%d", &pos);
        insertAtPosition(name, phone, email, pos);
    } else {
        printf("Wrong choice!\n");
    }
}

/* 1. Insert at Beginning */
void insertBeginning(char name[], char phone[], char email[]) {
    struct Contact *newNode = (struct Contact*)malloc(sizeof(struct Contact));
    
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    strcpy(newNode->email, email);

    newNode->next = head;
    head = newNode;

    printf("Contact inserted at beginning successfully!\n");
}

/* 2. Insert at End */
void insertEnd(char name[], char phone[], char email[]) {
    struct Contact *newNode = (struct Contact*)malloc(sizeof(struct Contact));
    struct Contact *temp;

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Contact inserted at end successfully!\n");
}

/* 3. Insert at Specific Position */
void insertAtPosition(char name[], char phone[], char email[], int pos) {
    int i;
    struct Contact *temp;
    struct Contact *newNode;

    if(pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1) {
        insertBeginning(name, phone, email);
        return;
    }

    temp = head;
    for(i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    newNode = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    strcpy(newNode->email, email);

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Contact inserted at position %d successfully!\n", pos);
}

/* ========================================================
   MODULE 2: Delete and Update Module
   ======================================================== */

void deleteMenu() {
    int choice;
    char name[50], phone[20];

    if(head == NULL) {
        printf("Directory is empty! Nothing to delete.\n");
        return;
    }

    printf("\n1. Delete by Name\n");
    printf("2. Delete by Phone Number\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter name to delete: ");
        scanf(" %49[^\n]", name);
        deleteByName(name);
    } else if(choice == 2) {
        printf("Enter phone number to delete: ");
        scanf(" %19[^\n]", phone);
        deleteByPhone(phone);
    } else {
        printf("Wrong choice!\n");
    }
}

/* 1. Delete contact by Name */
void deleteByName(char name[]) {
    struct Contact *temp = head;
    struct Contact *toDelete;

    // If first contact matches
    if(strcmp(head->name, name) == 0) {
        head = head->next;
        free(temp);
        printf("Contact '%s' deleted successfully!\n", name);
        return;
    }

    // Traverse list
    while(temp->next != NULL && strcmp(temp->next->name, name) != 0) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        printf("Contact with name '%s' not found!\n", name);
    } else {
        toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        printf("Contact '%s' deleted successfully!\n", name);
    }
}

/* 2. Delete contact by Phone */
void deleteByPhone(char phone[]) {
    struct Contact *temp = head;
    struct Contact *toDelete;

    // If first contact matches
    if(strcmp(head->phone, phone) == 0) {
        head = head->next;
        free(temp);
        printf("Contact with phone '%s' deleted successfully!\n", phone);
        return;
    }

    // Traverse list
    while(temp->next != NULL && strcmp(temp->next->phone, phone) != 0) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        printf("Contact with phone '%s' not found!\n", phone);
    } else {
        toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        printf("Contact with phone '%s' deleted successfully!\n", phone);
    }
}

/* 3. Update Contact Details */
void updateContact() {
    char searchKey[50];
    struct Contact *temp = head;
    int found = 0;

    if(head == NULL) {
        printf("Directory is empty!\n");
        return;
    }

    printf("Enter Name or Phone number of contact to update: ");
    scanf(" %49[^\n]", searchKey);

    while(temp != NULL) {
        if(strcmp(temp->name, searchKey) == 0 || strcmp(temp->phone, searchKey) == 0) {
            printf("\nContact found!\n");
            printf("Enter new name: ");
            scanf(" %49[^\n]", temp->name);
            printf("Enter new phone: ");
            scanf(" %19[^\n]", temp->phone);
            printf("Enter new email: ");
            scanf(" %49[^\n]", temp->email);

            printf("Contact details updated successfully!\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if(found == 0) {
        printf("Contact not found!\n");
    }
}

/* ========================================================
   MODULE 3: Search Module (Traversal)
   ======================================================== */

void searchMenu() {
    int choice;
    char key[50];

    if(head == NULL) {
        printf("Directory is empty!\n");
        return;
    }

    printf("\n1. Search by Name\n");
    printf("2. Search by Phone Number\n");
    printf("3. Search by Email\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter name to search: ");
        scanf(" %49[^\n]", key);
        searchByName(key);
    } else if(choice == 2) {
        printf("Enter phone number to search: ");
        scanf(" %19[^\n]", key);
        searchByPhone(key);
    } else if(choice == 3) {
        printf("Enter email to search: ");
        scanf(" %49[^\n]", key);
        searchByEmail(key);
    } else {
        printf("Wrong choice!\n");
    }
}

/* 1. Search by Name */
void searchByName(char name[]) {
    struct Contact *temp = head;
    int found = 0;

    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0) {
            printf("\n--- Contact Found ---\n");
            printf("Name  : %s\n", temp->name);
            printf("Phone : %s\n", temp->phone);
            printf("Email : %s\n", temp->email);
            found = 1;
        }
        temp = temp->next;
    }

    if(found == 0) {
        printf("No contact found with name '%s'!\n", name);
    }
}

/* 2. Search by Phone */
void searchByPhone(char phone[]) {
    struct Contact *temp = head;
    int found = 0;

    while(temp != NULL) {
        if(strcmp(temp->phone, phone) == 0) {
            printf("\n--- Contact Found ---\n");
            printf("Name  : %s\n", temp->name);
            printf("Phone : %s\n", temp->phone);
            printf("Email : %s\n", temp->email);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if(found == 0) {
        printf("No contact found with phone '%s'!\n", phone);
    }
}

/* 3. Search by Email */
void searchByEmail(char email[]) {
    struct Contact *temp = head;
    int found = 0;

    while(temp != NULL) {
        if(strcmp(temp->email, email) == 0) {
            printf("\n--- Contact Found ---\n");
            printf("Name  : %s\n", temp->name);
            printf("Phone : %s\n", temp->phone);
            printf("Email : %s\n", temp->email);
            found = 1;
        }
        temp = temp->next;
    }

    if(found == 0) {
        printf("No contact found with email '%s'!\n", email);
    }
}

/* ========================================================
   MODULE 4: Display and Duplicate Check Module
   ======================================================== */

/* 1. Display All Contacts */
void displayContacts() {
    struct Contact *temp = head;
    int count = 0;

    if(head == NULL) {
        printf("Directory is empty!\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-25s\n", "No.", "Name", "Phone", "Email");
    printf("--------------------------------------------------------------------\n");

    while(temp != NULL) {
        count++;
        printf("%-5d %-20s %-15s %-25s\n", count, temp->name, temp->phone, temp->email);
        temp = temp->next;
    }
    printf("--------------------------------------------------------------------\n");
    printf("Total Contacts: %d\n", count);
}

/* 2. Count Total Contacts */
void countContacts() {
    struct Contact *temp = head;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total contacts in directory: %d\n", count);
}

/* 3. Detect Duplicates */
void detectDuplicates() {
    struct Contact *i, *j;
    int found = 0;

    if(head == NULL || head->next == NULL) {
        printf("Not enough contacts to check for duplicates.\n");
        return;
    }

    printf("\nChecking for duplicates...\n");

    for(i = head; i != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            // Check same phone
            if(strcmp(i->phone, j->phone) == 0) {
                printf("[Duplicate Phone Found]\n");
                printf("  Contact 1: %s (%s)\n", i->name, i->phone);
                printf("  Contact 2: %s (%s)\n", j->name, j->phone);
                found = 1;
            }
            // Check same email
            else if(strcmp(i->email, j->email) == 0) {
                printf("[Duplicate Email Found]\n");
                printf("  Contact 1: %s (%s)\n", i->name, i->email);
                printf("  Contact 2: %s (%s)\n", j->name, j->email);
                found = 1;
            }
        }
    }

    if(found == 0) {
        printf("No duplicate contacts found!\n");
    }
}

/* 4. Show Contacts Alphabetically (Bubble Sort on Linked List) */
void sortAlphabetical() {
    struct Contact *i, *j;
    char tempName[50], tempPhone[20], tempEmail[50];

    if(head == NULL || head->next == NULL) {
        printf("Not enough contacts to sort.\n");
        return;
    }

    // Bubble sort: compare adjacent pairs and swap data
    for(i = head; i->next != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(strcmp(i->name, j->name) > 0) {
                // Swap names
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                // Swap phone numbers
                strcpy(tempPhone, i->phone);
                strcpy(i->phone, j->phone);
                strcpy(j->phone, tempPhone);

                // Swap emails
                strcpy(tempEmail, i->email);
                strcpy(i->email, j->email);
                strcpy(j->email, tempEmail);
            }
        }
    }

    printf("\nContacts sorted in alphabetical order successfully!\n");
    displayContacts();
}
