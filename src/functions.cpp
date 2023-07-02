#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include <stdbool.h>

void displayListIDAndName(patient_struct *headP) {
	printf("This is the current patient list:\n");
	patient_struct *ptr = headP;
	while (ptr != NULL) {
		printf("Patient ID: %d, Patient Name: %s\n", ptr->ID, ptr->name);
		ptr = ptr->next;
	}
	printf("\n");
}

patient_struct* createPatient(int newPatientID, char *newPatientName,
		int seatplace, bool priority, bool ambulance, patient_struct *next,
		patient_struct *prev) {
	patient_struct *tempPtr = (patient_struct*) malloc(sizeof(patient_struct));
	tempPtr->ID = newPatientID;
	strcpy(tempPtr->name, newPatientName);
	tempPtr->seatplace = seatplace;
	tempPtr->priority = priority;
	tempPtr->ambulance = ambulance;
	tempPtr->next = next;
	tempPtr->prev = prev;
	return tempPtr;
}

char* trimWhiteSpace(char *str) {
	// Remove leading and trailing white spaces from a string
	int i = 0;
	while (str[i] == ' ' || str[i] == '\t') {
		i++;
	}
	int j = strlen(str) - 1;
	while (j >= 0
			&& (str[j] == ' ' || str[j] == '\t' || str[j] == '\n'
					|| str[j] == '\r')) {
		j--;
	}
	str[j + 1] = '\0';
	return &str[i];
}

bool isSeatFree(patient_struct* headP, int seatNumber) {
    patient_struct* ptr = headP;
    while (ptr != NULL) {
        if (ptr->seatplace == seatNumber) {
            return false;  // Seat is occupied
        }
        ptr = ptr->next;
    }
    return true;  // Seat is free
}
void FreeSeat(patient_struct* headP, int seatNumber) {
    if (isSeatFree(headP, seatNumber)) {
        printf("Seat %d is free.\n", seatNumber);
    } else {
        printf("Seat %d is occupied.\n", seatNumber);
    }
}
void PrintPatientsInfo(patient_struct* headP) {
    printf("Printing patients' information:\n");
    patient_struct* ptr = headP;
    while (ptr != NULL) {
    	printf("Patient ID: %d\n", ptr->ID);
    	        printf("Name: %s\n", ptr->name);
    	        printf("Seatplace: %d\n", ptr->seatplace);
    	        printf("Priority: %s\n", ptr->priority ? "true" : "false");
    	        printf("Ambulance: %s\n", ptr->ambulance ? "true" : "false");
    	        printf("\n");
    	        ptr = ptr->next;
    	    }
    }
void addPatientToList(patient_struct **headP, patient_struct *newPatient) {
    printf("Adding patient: %s\n", newPatient->name);
    if (*headP == NULL) {
        *headP = newPatient;
        newPatient->prev = NULL;
    } else {
        patient_struct *current = *headP;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPatient;
        newPatient->prev = current;
    }
    printf("Patient added successfully!\n\n");
}

void removePatientFromList(patient_struct **headP, patient_struct *patientToRemove) {
    if (*headP == NULL) {
        printf("Patient list is empty. No patient to remove.\n");
        return;
    }

    patient_struct *current = *headP;
    while (current != NULL) {
        if (current == patientToRemove) {
            if (current->prev == NULL) {
                // Removing the first patient in the list
                *headP = current->next;
                if (current->next != NULL) {
                    current->next->prev = NULL;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            free(current);
            printf("Patient removed successfully!\n");
            return;
        }
        current = current->next;
    }

    printf("Patient not found in the list. No patient removed.\n");
}

// functions from mohamad
// Function to check the neighboring seats for a given seat
//void checkSeatNeighbour(Seat seats[], int totalSeats, int seatNumber) {
//    // If the seatNumber is out of range, print an error and return
//    if(seatNumber < 0 || seatNumber >= totalSeats) {
//        printf("Invalid seat number.\n");
//        return;
//    }
//
//    // Calculate the start and end of the row where the seat is located
//    int row = seatNumber / ROWS;
//    int startOfRow = row * ROWS;
//    int endOfRow = startOfRow + ROWS;
//
//    // Print out a message stating which seat's neighbors we are checking
//    printf("Checking neighbours for seat number %d:\n", seatNumber);
//
//    // If the seat is not at the start of the row, check the seat to the left
//    if (seatNumber > startOfRow) {
//        printf("Left neighbour at seat %d is %s\n",
//               seatNumber - 1,
//               seats[seatNumber - 1].isOccupied ? "occupied" : "free");
//    }
//
//    // If the seat is not at the end of the row, check the seat to the right
//    if (seatNumber < endOfRow - 1) {
//        printf("Right neighbour at seat %d is %s\n",
//               seatNumber + 1,
//               seats[seatNumber + 1].isOccupied ? "occupied" : "free");
//    }
//}
//
//// Function to print out information for all patients
//void PrintPatientsInfo(Patient* head) {
//    // If there are no patients, print a message and return
//    if (head == NULL) {
//        printf("No patients in the queue.\n");
//        return;
//    }
//
//    // Initialize a pointer to traverse the linked list of patients
//    Patient* current = head;
//
//    // Loop through the linked list
//    while (current != NULL) {
//        // Print out the id, name, and priority of the patient
//        printf("Patient ID: %d, Name: %s, Priority: %d\n",
//               current->id,
//               current->name,
//               current->priority);
//
//        // If the patient has a seat, print the seat number
//        // Otherwise, print a message indicating they arrived by ambulance
//        if (current->seatNumber != -1) {
//            printf("Seat number: %d\n", current->seatNumber);
//        } else {
//            printf("No seat assigned (arrived by ambulance)\n");
//        }
//
//        // Move to the next patient in the list
//        current = current->next;
//    }
//}
//
// Function to check the neighboring seats for a given patient
//void QuerySeatPartners(Patient* head, int patientId) {
//    // Initialize a pointer to traverse the linked list of patients
//    Patient* current = head;
//
//    // Loop through the linked list until we find the patient or reach the end
//    while (current != NULL && current->id != patientId) {
//        current = current->next;
//    }
//
//    // If we didn't find the patient, print an error message and return
//    if (current == NULL) {
//        printf("Patient with id %d not found.\n", patientId);
//        return;
//    }
//
//    // If the patient has a seat, call the checkSeatNeighbour function
//    // Otherwise, print a message indicating the patient arrived by ambulance
//    if (current->seatNumber != -1) {
//        checkSeatNeighbour(seats, ROWS * COLS, current->seatNumber);
//    } else {
//        printf("Patient with id %d has no seat assigned (arrived by ambulance).\n", patientId);
//    }
//}
