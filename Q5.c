#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_inventory(char*** species_supplies, int* num_species) {
    printf("Enter the number of species: ");
    scanf("%d", num_species);
    *species_supplies = malloc(*num_species * sizeof(char**));
    for (int i = 0; i < *num_species; i++) {
        (*species_supplies)[i] = NULL;
    }
}

void add_supplies(char** species_supplies, int num_supplies) {
    species_supplies = malloc(num_supplies * sizeof(char*));
    for (int i = 0; i < num_supplies; i++) {
        species_supplies[i] = malloc(100 * sizeof(char));
        printf("Enter supply %d: ", i + 1);
        scanf("%s", species_supplies[i]);
    }
}

void update_supply(char** species_supplies, int supply_index, const char* new_supply) {
    strcpy(species_supplies[supply_index], new_supply);
}

void remove_species(char*** species_supplies, int* num_species, int species_index) {
    for (int i = 0; species_supplies[species_index][i] != NULL; i++) {
        free(species_supplies[species_index][i]);
    }
    free(species_supplies[species_index]);
    for (int i = species_index; i < *num_species - 1; i++) {
        species_supplies[i] = species_supplies[i + 1];
    }
    (*num_species)--;
    *species_supplies = realloc(*species_supplies, *num_species * sizeof(char**));
}

void display_inventory(char** species_supplies, int num_species) {
    for (int i = 0; i < num_species; i++) {
        printf("Species %d supplies: ", i + 1);
        for (int j = 0; species_supplies[i][j] != NULL; j++) {
            printf("%s ", species_supplies[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char*** species_supplies;
    int num_species, choice, species_index, num_supplies, supply_index;
    char new_supply[100];

    initialize_inventory(&species_supplies, &num_species);

    do {
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter species index: ");
                scanf("%d", &species_index);
                printf("Enter number of supplies: ");
                scanf("%d", &num_supplies);
                add_supplies(species_supplies[species_index], num_supplies);
                break;
            case 2:
                printf("Enter species index: ");
                scanf("%d", &species_index);
                printf("Enter supply index: ");
                scanf("%d", &supply_index);
                printf("Enter new supply name: ");
                scanf("%s", new_supply);
                update_supply(species_supplies[species_index], supply_index, new_supply);
                break;
            case 3:
                printf("Enter species index to remove: ");
                scanf("%d", &species_index);
                remove_species(&species_supplies, &num_species, species_index);
                break;
            case 4:
                display_inventory(species_supplies, num_species);
                break;
            case 5:
                for (int i = 0; i < num_species; i++) {
                    for (int j = 0; species_supplies[i][j] != NULL; j++) {
                        free(species_supplies[i][j]);
                    }
                    free(species_supplies[i]);
                }
                free(species_supplies);
                break;
        }
    } while (choice != 5);

    return 0;
