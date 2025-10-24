#include <stdio.h>
#include <string.h>


struct Contact {
    char name[50];
    char phone_number[15];
    char email[50];
};

void add_contact(struct Contact contacts[], int *count) {
    if (*count < 100) {
        struct Contact new_contact;
        printf("Enter name: ");
        fflush(stdin);
        fgets(new_contact.name, sizeof(new_contact.name), stdin);
        new_contact.name[strcspn(new_contact.name, "\n")] = '\0';

        if (strlen(new_contact.name) == 0) {
            printf("Name cannot be empty. Contact not added.\n");
            return;
        }

        printf("Enter phone number: ");
        fgets(new_contact.phone_number, sizeof(new_contact.phone_number), stdin);
        new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = '\0';

        printf("Enter email: ");
        fgets(new_contact.email, sizeof(new_contact.email), stdin);
        new_contact.email[strcspn(new_contact.email, "\n")] = '\0';

        contacts[*count] = new_contact;
        (*count)++;
        printf("Contact added successfully!\n");
    } else {
        printf("Contact list is full!\n");
    }
}



void delete_contact(struct Contact contacts[], int *count, const char *name) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < (*count - 1); j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void update_contact(struct Contact contacts[], int count, const char *name) {
    int choice;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Select field to update:\n");
            printf("1. Phone Number\n");
            printf("2. Email\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new phone number: ");
                    scanf("%s", contacts[i].phone_number);
                    printf("Contact phone number updated successfully!\n");
                    break;
                case 2:
                    printf("Enter new email: ");
                    scanf("%s", contacts[i].email);
                    printf("Contact email updated successfully!\n");
                    break;
                default:
                    printf("Invalid choice. No changes made.\n");
            }
            return;
        }
    }
    printf("Contact not found!\n");
}



void display_all_contacts(struct Contact contacts[], int count) {
    if (count > 0) {
        printf("Contact List:\n");
        printf("--------------------------------------------------\n");
        printf("| %-20s | %-15s | %-30s |\n", "Name", "Phone Number", "Email");
        printf("--------------------------------------------------\n");

        for (int i = 0; i < count; i++) {
            printf("| %-20s | %-15s | %-30s |\n", contacts[i].name, contacts[i].phone_number, contacts[i].email);
        }

        printf("--------------------------------------------------\n");
    } else {
        printf("No contacts found!\n");
    }
}

void search_contact(struct Contact contacts[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone_number, contacts[i].email);
            return;
        }
    }
    printf("Contact not found!\n");
}


int main() {
    struct Contact contacts[100];
    int count = 0;
    int choice;
    char name[50];

    while (1) {
        printf("\nContact Management System\n");
        printf("\nMenu:\n");
        printf("\n1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Update Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Search Contact\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_contact(contacts, &count, name);
                break;
            case 3:
                printf("Enter name to update: ");
                scanf("%s", name);
                update_contact(contacts, count, name);
                break;
            case 4:
                display_all_contacts(contacts, count);
                break;
            case 5:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(contacts, count, name);
                break;
            case 0:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
