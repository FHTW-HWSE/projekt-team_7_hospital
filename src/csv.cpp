#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include <stdbool.h>


#define MAX_ROWS 1000
#define MAX_COLS 10
#define MAX_FIELD_LENGTH 100

void readPatientsList() {

    FILE *cdr;

    cdr = fopen("cdr.csv", "r");
    if (!cdr)
    {
        printf("can't open the file");
    }

    char line[MAX_FIELD_LENGTH * MAX_COLS];            // Puffer für eine Zeile in der CSV-Datei
    char *field;                                       // Zeiger auf das aktuelle Feld in einer Zeile
    char fields[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH]; // Array zur Speicherung der CSV-Daten
    int i = 0, j;                                      // Zähler für die Zeilen und Spalten

    while (fgets(line, sizeof(line), cdr) != NULL)
    {                              // Liest eine Zeile aus der CSV-Datei
        j = 0;                     // Setzt den Spaltenzähler zurück
        field = strtok(line, ";"); // Trennt die Zeile in Felder anhand des Trennzeichens ";"
        while (field != NULL && j < MAX_COLS)
        {                                // Verarbeitet jedes Feld in der Zeile
            strcpy(fields[i][j], field); // Kopiert das Feld in das Array
            j++;                         // Erhöht den Spaltenzähler
            field = strtok(NULL, ";");   // Geht zum nächsten Feld über
        }
        i++; // Erhöht den Zeilenzähler
    }
    fclose(cdr);

    // Gibt die Matrix aus, um zu überprüfen, ob sie korrekt befüllt wurde
    for (int row = 0; row < i; row++){
    
        for (int col = 0; col < j; col++){
        
            printf("%s ", fields[row][col]);
        }
        printf("\n");
    }
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