#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct patient {
    int ID;
    char name[20];
    int seatplace;
    bool priority;
    bool ambulance;
    struct patient* next;
    struct patient* prev;
};

typedef struct patient patient_struct;

void displayListIDAndName(patient_struct* headP);
patient_struct* createPatient(int newPatientID, char* newPatientName, int seatplace, bool priority, bool ambulance, patient_struct* newPatientNext, patient_struct* newPatientPrev);
void addPatientToList(patient_struct** headP, patient_struct* newPatient);
char* trimWhiteSpace(char* str);
bool isSeatFree(patient_struct* headP, int seatNumber);
void FreeSeat(patient_struct* headP, int seatNumber);

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

    displayListIDAndName(head);
 FreeSeat(head, 3);   // Check if seat number 3 is free or occupied


    fclose(fp);
    return 0;
}

void displayListIDAndName(patient_struct* headP) {
    printf("This is the current patient list:\n");
    patient_struct* ptr = headP;
    while (ptr != NULL) {
        printf("Patient ID: %d, Patient Name: %s\n", ptr->ID, ptr->name);
        ptr = ptr->next;
    }
    printf("\n");
}

patient_struct* createPatient(int newPatientID, char* newPatientName, int seatplace, bool priority, bool ambulance, patient_struct* next, patient_struct* prev) {
    patient_struct* tempPtr = (patient_struct*)malloc(sizeof(patient_struct));
    tempPtr->ID = newPatientID;
    strcpy(tempPtr->name, newPatientName);
    tempPtr->seatplace = seatplace;
    tempPtr->priority = priority;
    tempPtr->ambulance = ambulance;
    tempPtr->next = next;
    tempPtr->prev = prev;
    return tempPtr;
}

void addPatientToList(patient_struct** headP, patient_struct* newPatient) {
    printf("Adding patient: %s\n", newPatient->name);
    if (*headP == NULL) {
        *headP = newPatient;
    } else {
        patient_struct* current = *headP;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPatient;
        newPatient->prev = current;
    }
    printf("Patient added successfully!\n\n");
}

char* trimWhiteSpace(char* str) {
    // Remove leading and trailing white spaces from a string
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    int j = strlen(str) - 1;
    while (j >= 0 && (str[j] == ' ' || str[j] == '\t' || str[j] == '\n' || str[j] == '\r')) {
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

