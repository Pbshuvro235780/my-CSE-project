#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX_PLAYERS 30

struct Player {
    char name[50];
    int age;
    char strong_foot;
    int jersey_number;
    char position[50];
    char nationality[50];
    int goals;
    int assists;
};

void add_player(struct Player players[], int *num_players);
void remove_player(struct Player players[], int *num_players);
void update_player_details(struct Player players[], int num_players);
void display_team_details(struct Player players[], int num_players);
void display_player_details(struct Player players[], int num_players, int jersey_number);

int main() {
    struct Player players[MAX_PLAYERS];
    int num_players = 0;
    int choice, jersey_number;

    do {
        printf("\nFootball Team Management System\n");
        printf("\nMenu:\n");
        printf("1. Add player\n");
        printf("2. Remove player\n");
        printf("3. Update player details\n");
        printf("4. Display team details\n");
        printf("5. Display player details\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_player(players, &num_players);
                break;
            case 2:
                remove_player(players, &num_players);
                break;
            case 3:
                update_player_details(players, num_players);
                break;
            case 4:
                display_team_details(players, num_players);
                break;
            case 5:
                printf("Enter the player's jersey number: ");
                scanf("%d", &jersey_number);
                display_player_details(players, num_players, jersey_number);
                break;
            case 6:
                printf("Exiting program. GoodBye and Thank You...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}

void add_player(struct Player players[], int *num_players) {

     if (*num_players >= MAX_PLAYERS) {
        printf("Cannot add more players. Maximum limit reached.\n");
        return;
    }

    struct Player player;
    printf("Enter player name: ");
    scanf("%s", player.name);
    printf("Enter player age: ");
    scanf("%d", &player.age);
    printf("Enter player strong foot (L/R): ");
    scanf(" %c", &player.strong_foot);
    printf("Enter player jersey number: ");
    scanf("%d", &player.jersey_number);
    printf("Enter player position: ");
    scanf("%s", player.position);
    printf("Enter player nationality: ");
    scanf("%s", player.nationality);
    printf("Enter player number of goals: ");
    scanf("%d", &player.goals);
    printf("Enter player number of assists: ");
    scanf("%d", &player.assists);
    players[*num_players] = player;
    *num_players += 1;
    printf("Player added successfully.\n");
}

void remove_player(struct Player players[], int *num_players) {
    int jersey_number, i, j;
    printf("Enter jersey number of player to remove: ");
    scanf("%d", &jersey_number);
    for (i = 0; i < *num_players; i++) {
        if (players[i].jersey_number == jersey_number) {
            for (j = i; j < *num_players - 1; j++) {
                players[j] = players[j+1];
            }
            *num_players -= 1;
            printf("Player removed successfully.\n");
            return;
        }
    }
    printf("Player not found.\n");
}

void update_player_details(struct Player players[], int num_players) {
    int jersey_number, field_choice, i;
    printf("Enter jersey number of player to update: ");
    scanf("%d", &jersey_number);
    for (i = 0; i < num_players; i++) {
        if (players[i].jersey_number == jersey_number) {
            printf("Select field to update:\n");
            printf("1. Jersey number\n");
            printf("2. Position\n");
            printf("3. Nationality\n");
            printf("4. Number of goals\n");
            printf("5. Number of assists\n");
            printf("Enter your choice: ");
            scanf("%d", &field_choice);
            switch (field_choice) {
                case 1:
                    printf("Enter new jersey number: ");
                    scanf("%d", &players[i].jersey_number);
                    break;
                case 2:
                    printf("Enter new position: ");
                    scanf("%s", players[i].position);
                    break;
                case 3:
                    printf("Enter new nationality: ");
                    scanf("%s", players[i].nationality);
                    break;
                case 4:
                    printf("Enter new number of goals: ");
                    scanf("%d", &players[i].goals);
                    break;
                case 5:
                    printf("Enter new number of assists: ");
                    scanf("%d", &players[i].assists);
                    break;
                default:
                    printf("Invalid choice.\n");
                    return;
            }
            printf("Player details updated successfully.\n");
            return;
        }
    }
    printf("Player not found.\n");
}

void display_team_details(struct Player players[], int num_players) {
    int i;
    printf("Team details:\n");
    printf("%-20s %-5s %-10s %-10s %-20s %-10s %-10s %-10s\n", "Name", "Age", "Foot", "Jersey", "Position", "Nationality", "Goals", "Assists");
    for (i = 0; i < num_players; i++) {
        printf("%-20s %-5d %-10c %-10d %-20s %-10s %-10d %-10d\n", players[i].name, players[i].age, players[i].strong_foot, players[i].jersey_number, players[i].position, players[i].nationality, players[i].goals, players[i].assists);
    }
}

void display_player_details(struct Player players[], int num_players, int jersey_number) {
    int i;
    for (i = 0; i < num_players; i++) {
        if (players[i].jersey_number == jersey_number) {
            printf("Player details:\n");
            printf("Name: %s\n", players[i].name);
            printf("Age: %d\n", players[i].age);
            printf("Strong foot: %c\n", players[i].strong_foot);
            printf("Jersey number: %d\n", players[i].jersey_number);
            printf("Position: %s\n", players[i].position);
            printf("Nationality: %s\n", players[i].nationality);
            printf("Goals: %d\n", players[i].goals);
            printf("Assists: %d\n", players[i].assists);
            return;
        }
    }
    printf("Player with jersey number %d not found.\n", jersey_number);
}

