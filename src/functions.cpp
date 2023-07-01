
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

