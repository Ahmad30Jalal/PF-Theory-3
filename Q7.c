#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct content_metadata {
    char title[100];
    float rating;
    int runtime;
    char encoding_format[50];
} content_metadata;

void initialize_engagement_matrix(double** matrix, int num_users, int num_categories) {
    for (int i = 0; i < num_users; i++) {
        matrix[i] = malloc(num_categories * sizeof(double));
        for (int j = 0; j < num_categories; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

void initialize_device_matrix(double** matrix, int num_users, int num_devices) {
    for (int i = 0; i < num_users; i++) {
        matrix[i] = malloc(num_devices * sizeof(double*));
        for (int j = 0; j < num_devices; j++) {
            ((double**)matrix[i])[j] = malloc(3 * sizeof(double));  // Assume 3 preferences
            for (int k = 0; k < 3; k++) {
                ((double**)matrix[i])[j][k] = 0.0;
            }
        }
    }
}

void initialize_content_metadata(content_metadata** matrix, int num_categories, int num_content) {
    for (int i = 0; i < num_categories; i++) {
        matrix[i] = malloc(num_content * sizeof(content_metadata));
    }
}

void free_engagement_matrix(double** matrix, int num_users) {
    for (int i = 0; i < num_users; i++) {
        free(matrix[i]);
    }
}

void free_device_matrix(double** matrix, int num_users, int num_devices) {
    for (int i = 0; i < num_users; i++) {
        for (int j = 0; j < num_devices; j++) {
            free(((double**)matrix[i])[j]);
        }
        free(matrix[i]);
    }
}

void free_content_metadata(content_metadata** matrix, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        free(matrix[i]);
    }
}

int main() {
    int num_users, num_categories, num_devices, num_content;
    double** engagement_matrix;
    double** device_matrix;
    content_metadata** content_matrix;

    printf("Enter number of users: ");
    scanf("%d", &num_users);
    printf("Enter number of categories: ");
    scanf("%d", &num_categories);
    printf("Enter number of devices per user: ");
    scanf("%d", &num_devices);
    printf("Enter number of content items per category: ");
    scanf("%d", &num_content);

    engagement_matrix = malloc(num_users * sizeof(double*));
    device_matrix = malloc(num_users * sizeof(double*));
    content_matrix = malloc(num_categories * sizeof(content_metadata*));

    initialize_engagement_matrix(engagement_matrix, num_users, num_categories);
    initialize_device_matrix(device_matrix, num_users, num_devices);
    initialize_content_metadata(content_matrix, num_categories, num_content);

    free_engagement_matrix(engagement_matrix, num_users);
    free_device_matrix(device_matrix, num_users, num_devices);
    free_content_metadata(content_matrix, num_categories);

    free(engagement_matrix);
    free(device_matrix);
    free(content_matrix);

    return 0;
}
