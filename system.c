/*
 ============================================================================
 Name        : System.c
 Author      : Ahmed Mostafa
 Description : Vehicle Control System
 ============================================================================
 */

#include <stdio.h>

#define GREEN 'G'
#define ORANGE 'O'
#define RED 'R'

#define WITH_ENGINE_TEMP_CONTROLLER 1

char setTrafficLight() {
    char color;
    printf("Enter traffic light color (G/O/R): ");
    scanf(" %c", &color);
    return color;
}

int setRoomTemperature() {
    int temperature;
    printf("Enter room temperature: ");
    scanf("%d", &temperature);
    return temperature;
}

int setEngineTemperature() {
    int temperature;
    printf("Enter engine temperature: ");
    scanf("%d", &temperature);
    return temperature;
}

int main() {
    char input;
    char trafficLight;
    int roomTemperature, engineTemperature;
    int vehicleSpeed = 0;
    int acState = 0;  // 0: OFF, 1: ON
    int engineControllerState = 0;  // 0: OFF, 1: ON
    int engineState = 0;  // 0: OFF, 1: ON
    int system = 1;

    while (system != 0) {
        // Display main menu options
        printf("a. Turn on the vehicle engine\n");
        printf("b. Turn off the vehicle engine\n");
        printf("c. Quit the system\n\n");
        printf("Enter your choice: ");
        scanf(" %c", &input);

        if (input == 'c') {
            printf("Quitting the system.\n");
            system = 0;
            break;
        } else if (input == 'a') {
            engineState = 1;
            printf("Engine turned ON.\n");

            while (engineState !=0) {
                printf("\nSensors set menu:\n");
                printf("a. Turn off the engine\n");
                printf("b. Set the traffic light color\n");
                printf("c. Set the room temperature\n");
                printf("d. Set the engine temperature\n");
                printf("Enter your choice: ");
                scanf(" %c", &input);

                if (input == 'a') {
                    engineState = 0;
                    printf("Engine turned OFF.\n");
                    break;
                } else if (input == 'b') {
                    trafficLight = setTrafficLight();
                    if (trafficLight == GREEN) {
                        vehicleSpeed = 100;
                    } else if (trafficLight == ORANGE) {
                        vehicleSpeed = 30;
                    } else if (trafficLight == RED) {
                        vehicleSpeed = 0;
                    }
                } else if (input == 'c') {
                    roomTemperature = setRoomTemperature();
                    if (roomTemperature < 10 || roomTemperature > 30) {
                        acState = 1;
                        roomTemperature = 20;
                    } else {
                        acState = 0;
                    }
                } else if (input == 'd') {
                    engineTemperature = setEngineTemperature();
#if WITH_ENGINE_TEMP_CONTROLLER
                    if (engineTemperature < 100 || engineTemperature > 150) {
                        engineControllerState = 1;
                        engineTemperature = 125;
                    } else {
                        engineControllerState = 0;
                    }
#endif
                }

                if (vehicleSpeed == 30) {
                    if (!acState) {
                        acState = 1;
                        roomTemperature = roomTemperature * (5.0 / 4) + 1;
                    }
#if WITH_ENGINE_TEMP_CONTROLLER
                    if (!engineControllerState) {
                        engineControllerState = 1;
                        engineTemperature = engineTemperature * (5.0 / 4) + 1;
                    }
#endif
                }

                printf("\nCurrent Vehicle State:\n");
                printf("Engine state: %s\n", engineState ? "ON" : "OFF");
                printf("AC: %s\n", acState ? "ON" : "OFF");
                printf("Vehicle Speed: %d km/hr\n", vehicleSpeed);
                printf("Room Temperature: %d\n", roomTemperature);
#if WITH_ENGINE_TEMP_CONTROLLER
                printf("Engine Temperature Controller State: %s\n", engineControllerState ? "ON" : "OFF");
                printf("Engine Temperature: %d\n", engineTemperature);
#endif
            }
        } else if (input == 'b') {
            printf("Cannot turn off the engine when it's already off.\n");
        } else {
            printf("Invalid input. Please choose a valid option.\n");
        }
    }

    return 0;
}
