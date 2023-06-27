void readPatientsList() {
	FILE *fp;

	fp = fopen("PatientsList.csv", "r");
	if (!fp) {
		printf("can't open the file");
	}

	char line[MAX_FIELD_LENGTH * MAX_COLS];                     // Puffer für eine Zeile in der CSV-Datei
	    char *field;                                            // Zeiger auf das aktuelle Feld in einer Zeile
	    char fields[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];     // Array zur Speicherung der CSV-Daten
	    int i = 0, j;                                         // Zähler für die Zeilen und Spalten

	    while (fgets(line, sizeof(line), cdr) != NULL) {        // Liest eine Zeile aus der CSV-Datei
	            j = 0;                                        // Setzt den Spaltenzähler zurück
	            field = strtok(line, ";");                  // Trennt die Zeile in Felder anhand des Trennzeichens ";"
	            while (field != NULL && j < MAX_COLS) {         // Verarbeitet jedes Feld in der Zeile
	                strcpy(fields[i][j], field);            // Kopiert das Feld in das Array
	                j++;                               // Erhöht den Spaltenzähler
	                field = strtok(NULL, ";");           // Geht zum nächsten Feld über
	                        }
	                        i++;                  // Erhöht den Zeilenzähler
	                    }
	fclose(fp);

	 // Gibt die Matrix aus, um zu überprüfen, ob sie korrekt befüllt wurde
	    for (int row = 0; row < i; row++) {
	        for (int col = 0; col < j; col++) {
	            printf("%s", fields[row][col]);
	        }
	        printf("\n");
	    }

}

bool isSeatFree(patient_struct* headP, int seatNumber);
void FreeSeat(patient_struct* headP, int seatNumber);
void PrintPatientsInfo(patient_struct* headP);

// Function to check if a seat is free or occupied
void FreeSeat(patient_struct* headP, int seatNumber) {
    // Check if the seat is free or occupied
    if (isSeatFree(headP, seatNumber)) {
        // Print that the seat is free
        printf("Seat %d is free.\n", seatNumber);
    } else {
        // Print that the seat is occupied
        printf("Seat %d is occupied.\n", seatNumber);
    }
}
// Function to print patients' information
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




