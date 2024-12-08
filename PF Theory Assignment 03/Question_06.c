#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float tempValue;
    float rainData;
    float windSpeed;
} Climate;

typedef struct {
    char cropName[50];
    char currentStage[50];
    float yieldEstimate;
    Climate* forecastData; 
    int forecastCount;
} Plantation;

typedef struct {
    char machineName[50];
    char status[20];
    float fuelPercentage;
    char operationPlan[100];
} Machinery;

typedef struct {
    float nutrientLevel;
    float soilAcidity;
    float pestConcentration;
} Monitor;

typedef struct {
    float coordLat;
    float coordLong;
    float healthMetric;
    float waterContent;
    Plantation* plantations;           
    Machinery* devices;  
    Monitor* monitors;  
    int plantationCount;
    int deviceCount;
    int monitorCount;
} Area;

typedef struct {
    char zoneTitle[50];
    Area* areas;         
    int areaCount;
    float outputProjection;
    float resourceAllocation;
    char disasterResponse[200];
} AgroHub;

void setupArea(Area* area, int plantationCount, int deviceCount, int monitorCount);
void setupAgroHub(AgroHub* hub, const char* title, int areaCount);
void addPlantation(Area* area, const char* cropName, const char* stage, float yield, int forecastCount);
void addMachinery(Area* area, const char* machineName, const char* status, float fuel, const char* plan);
void addMonitor(Area* area, float nutrients, float acidity, float pests);
void showAgroHub(const AgroHub* hub);
void releaseArea(Area* area);
void releaseAgroHub(AgroHub* hub);

int main() {
    AgroHub hub;
    setupAgroHub(&hub, "Northern Agro Zone", 2);

    setupArea(&hub.areas[0], 2, 2, 2);
    addPlantation(&hub.areas[0], "Wheat", "Flowering", 1200.5, 3);
    addPlantation(&hub.areas[0], "Barley", "Mature", 900.8, 2);
    addMachinery(&hub.areas[0], "Self-driving Tractor", "Operational", 80.0, "Daily Tillage");
    addMonitor(&hub.areas[0], 6.5, 7.0, 0.3);

    setupArea(&hub.areas[1], 1, 1, 1);
    addPlantation(&hub.areas[1], "Corn", "Seeding", 1500.3, 2);
    addMachinery(&hub.areas[1], "Sprinkler System", "Not Active", 0.0, "Repair Scheduled");
    addMonitor(&hub.areas[1], 7.8, 6.2, 0.1);
    showAgroHub(&hub);
    releaseAgroHub(&hub);

    return 0;
}

void setupArea(Area* area, int plantationCount, int deviceCount, int monitorCount) {
    area->coordLat = area->coordLong = 0.0;
    area->healthMetric = area->waterContent = 0.0;
    area->plantationCount = plantationCount;
    area->deviceCount = deviceCount;
    area->monitorCount = monitorCount;
    area->plantations = (Plantation*)malloc(plantationCount * sizeof(Plantation));
    area->devices = (Machinery*)malloc(deviceCount * sizeof(Machinery));
    area->monitors = (Monitor*)malloc(monitorCount * sizeof(Monitor));
}

void setupAgroHub(AgroHub* hub, const char* title, int areaCount) {
    strcpy(hub->zoneTitle, title);
    hub->areaCount = areaCount;
    hub->areas = (Area*)malloc(areaCount * sizeof(Area));
    hub->outputProjection = hub->resourceAllocation = 0.0;
    strcpy(hub->disasterResponse, "No disaster response plan defined.");
}

void addPlantation(Area* area, const char* cropName, const char* stage, float yield, int forecastCount) {
    static int plantationIndex = 0;
    if (plantationIndex >= area->plantationCount) return;
    Plantation* plantation = &area->plantations[plantationIndex++];
    strcpy(plantation->cropName, cropName);
    strcpy(plantation->currentStage, stage);
    plantation->yieldEstimate = yield;
    plantation->forecastCount = forecastCount;
    plantation->forecastData = (Climate*)malloc(forecastCount * sizeof(Climate));
}

void addMachinery(Area* area, const char* machineName, const char* status, float fuel, const char* plan) {
    static int deviceIndex = 0;
    if (deviceIndex >= area->deviceCount) return;
    Machinery* device = &area->devices[deviceIndex++];
    strcpy(device->machineName, machineName);
    strcpy(device->status, status);
    device->fuelPercentage = fuel;
    strcpy(device->operationPlan, plan);
}

void addMonitor(Area* area, float nutrients, float acidity, float pests) {
    static int monitorIndex = 0;
    if (monitorIndex >= area->monitorCount) return;
    Monitor* monitor = &area->monitors[monitorIndex++];
    monitor->nutrientLevel = nutrients;
    monitor->soilAcidity = acidity;
    monitor->pestConcentration = pests;
}

void showAgroHub(const AgroHub* hub) {
    printf("Agro Zone: %s\n", hub->zoneTitle);
    printf("Projected Output: %.2f\n", hub->outputProjection);
    printf("Allocated Resources: %.2f\n", hub->resourceAllocation);
    printf("Disaster Response Plan: %s\n\n", hub->disasterResponse);
    for (int i = 0; i < hub->areaCount; ++i) {
        printf("Area %d:\n", i + 1);
        printf("  Coordinates: (%.2f, %.2f)\n", hub->areas[i].coordLat, hub->areas[i].coordLong);
        printf("  Health: %.2f, Water Content: %.2f\n", hub->areas[i].healthMetric, hub->areas[i].waterContent);
        printf("  Plantations:\n");
        for (int j = 0; j < hub->areas[i].plantationCount; ++j) {
            printf("    %s (%s), Estimated Yield: %.2f\n", hub->areas[i].plantations[j].cropName, hub->areas[i].plantations[j].currentStage, hub->areas[i].plantations[j].yieldEstimate);
        }
        printf("  Machinery:\n");
        for (int j = 0; j < hub->areas[i].deviceCount; ++j) {
            printf("    %s (%s), Fuel Level: %.2f\n", hub->areas[i].devices[j].machineName, hub->areas[i].devices[j].status, hub->areas[i].devices[j].fuelPercentage);
        }
        printf("  Monitors:\n");
        for (int j = 0; j < hub->areas[i].monitorCount; ++j) {
            printf("    Nutrients: %.2f, Acidity: %.2f, Pests: %.2f\n", hub->areas[i].monitors[j].nutrientLevel, hub->areas[i].monitors[j].soilAcidity, hub->areas[i].monitors[j].pestConcentration);
        }
        printf("\n");
    }
}

void releaseArea(Area* area) {
    for (int i = 0; i < area->plantationCount; ++i) {
        free(area->plantations[i].forecastData);
    }
    free(area->plantations);
    free(area->devices);
    free(area->monitors);
}

void releaseAgroHub(AgroHub* hub) {
    for (int i = 0; i < hub->areaCount; ++i) {
        releaseArea(&hub->areas[i]);
    }
    free(hub->areas);
}
