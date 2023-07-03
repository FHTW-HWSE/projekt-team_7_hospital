#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../include/functions.h"


//struct patient {
//    int ID;
//    char name[20];
//    int seatplace;
//    bool priority;
//    bool ambulance;
//    struct patient* next;
//    struct patient* prev;
//};
//
//typedef struct patient patient_struct;
//
//void displayListIDAndName(patient_struct* headP);
//patient_struct* createPatient(int newPatientID, char* newPatientName, int seatplace, bool priority, bool ambulance, patient_struct* newPatientNext, patient_struct* newPatientPrev);
//void addPatientToList(patient_struct** headP, patient_struct* newPatient);
//char* trimWhiteSpace(char* str);
//bool isSeatFree(patient_struct* headP, int seatNumber);
//void FreeSeat(patient_struct* headP, int seatNumber);
//void PrintPatientsInfo(patient_struct* headP); // Funktion zum Drucken der Patienteninformationen hinzugefügt


int main() {
    patient_struct* head = NULL;

    FILE* fp = fopen("PatientsList.csv", "r");

    if (!fp) {
        perror("Can't open file\n"); // Error in file opening
        exit(1);
    }

    char line[300];

    // Skip the header line
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp)) {
        char* token;
        token = strtok(line, ",");
        int id = atoi(token);

        token = strtok(NULL, ",");
        char name[20];
        strcpy(name, trimWhiteSpace(token));

        token = strtok(NULL, ",");
        int seatplace = atoi(token);

        token = strtok(NULL, ",");
        bool priority = strcmp(trimWhiteSpace(token), "TRUE") == 0;

        token = strtok(NULL, ",");
        bool ambulance = strcmp(trimWhiteSpace(token), "TRUE") == 0;

        token = strtok(NULL, ",");
        patient_struct* next = NULL;

        token = strtok(NULL, ",");
        patient_struct* prev = NULL;

        patient_struct* newPatient = createPatient(id, name, seatplace, priority, ambulance, next, prev);

        if (head == NULL) {
            head = newPatient;
            newPatient->prev = NULL;
        } else {
            patient_struct* temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newPatient;
            newPatient->prev = temp;
        }
    }

 PrintPatientsInfo(head); // Aufruf der Funktion zum Drucken der Patienteninformationen
 FreeSeat(head, 3);   // Check if seat number 3 is free or occupied
 patient_struct *patient11 = createPatient(11,"Marvin Travis",11,false,false,NULL,NULL);
	 patient_struct *patient12 = createPatient(12,"Susi Baum",12,false,false,NULL,NULL);
	 addPatientToList(&head, patient11);
	 addPatientToList(&head, patient12);
	 displayListIDAndName(head);
	 


    fclose(fp);
    return 0;
}
