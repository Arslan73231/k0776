#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    float score;
    int duration;
    char availableFormats[50];
} MediaDetails;

typedef struct {
    float displayResolution;
    int viewedHistory[10];
    float dataUsage;
} DeviceSettings;

typedef struct {
    double* interactionRow;
    DeviceSettings** gadgets;
    int gadgetCount;
} UserStatistics;

void setupInteractionMatrix(double*** interactionData, int totalUsers, int totalCategories) {
    *interactionData = (double**)malloc(totalUsers * sizeof(double*));
    for (int i = 0; i < totalUsers; i++) {
        (*interactionData)[i] = (double*)calloc(totalCategories, sizeof(double));
    }
}

void setupDeviceMatrix(DeviceSettings**** deviceData, int totalUsers, int maxGadgets) {
    *deviceData = (DeviceSettings***)malloc(totalUsers * sizeof(DeviceSettings**));
    for (int i = 0; i < totalUsers; i++) {
        (*deviceData)[i] = (DeviceSettings**)malloc(maxGadgets * sizeof(DeviceSettings*));
        for (int j = 0; j < maxGadgets; j++) {
            (*deviceData)[i][j] = (DeviceSettings*)malloc(sizeof(DeviceSettings));
            (*deviceData)[i][j]->displayResolution = 1080;
            (*deviceData)[i][j]->dataUsage = 0;
            memset((*deviceData)[i][j]->viewedHistory, 0, 10 * sizeof(int));
        }
    }
}

void setupMediaMetadata(MediaDetails*** mediaData, int categoryCount, int contentCount) {
    *mediaData = (MediaDetails**)malloc(categoryCount * sizeof(MediaDetails*));
    for (int i = 0; i < categoryCount; i++) {
        (*mediaData)[i] = (MediaDetails*)malloc(contentCount * sizeof(MediaDetails));
        for (int j = 0; j < contentCount; j++) {
            snprintf((*mediaData)[i][j].name, 100, "Media_%d_%d", i + 1, j + 1);
            (*mediaData)[i][j].score = (rand() % 50) / 10.0 + 5.0;
            (*mediaData)[i][j].duration = (rand() % 60) + 90;
            snprintf((*mediaData)[i][j].availableFormats, 50, "HD, 4K");
        }
    }
}

void modifyInteractionScore(double** interactionData, int userID, int categoryID, double increment) {
    interactionData[userID][categoryID] += increment;
}

void showInteractionMatrix(double** interactionData, int totalUsers, int totalCategories) {
    for (int i = 0; i < totalUsers; i++) {
        printf("User_%d: ", i + 1);
        for (int j = 0; j < totalCategories; j++) {
            printf("%.2f ", interactionData[i][j]);
        }
        printf("\n");
    }
}

void releaseInteractionMatrix(double** interactionData, int totalUsers) {
    for (int i = 0; i < totalUsers; i++) {
        free(interactionData[i]);
    }
    free(interactionData);
}

void releaseDeviceMatrix(DeviceSettings*** deviceData, int totalUsers, int maxGadgets) {
    for (int i = 0; i < totalUsers; i++) {
        for (int j = 0; j < maxGadgets; j++) {
            free(deviceData[i][j]);
        }
        free(deviceData[i]);
    }
    free(deviceData);
}

void releaseMediaMetadata(MediaDetails** mediaData, int categoryCount, int contentCount) {
    for (int i = 0; i < categoryCount; i++) {
        free(mediaData[i]);
    }
    free(mediaData);
}

int main() {
    int userCount = 3, categoryCount = 5, maxGadgets = 2, contentPerCategory = 4;

    double** interactionData;
    setupInteractionMatrix(&interactionData, userCount, categoryCount);

    DeviceSettings*** deviceData;
    setupDeviceMatrix(&deviceData, userCount, maxGadgets);

    MediaDetails** mediaData;
    setupMediaMetadata(&mediaData, categoryCount, contentPerCategory);

    modifyInteractionScore(interactionData, 0, 1, 5.0);
    modifyInteractionScore(interactionData, 1, 3, 3.5);

    showInteractionMatrix(interactionData, userCount, categoryCount);

    releaseInteractionMatrix(interactionData, userCount);
    releaseDeviceMatrix(deviceData, userCount, maxGadgets);
    releaseMediaMetadata(mediaData, categoryCount, contentPerCategory);

    return 0;
}
