#ifndef CSV_H_
#define CSV_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void readPatientsList();
struct patient {
	int ID;
	char name[20];
	int seatplace;
	bool priority;
	bool ambulance;
	struct patient *next;
	struct patient *prev;
};

typedef struct patient patient_struct;
typedef struct seat seat_struct;

void displayListIDAndName(patient_struct *headP);
patient_struct* createPatient(int newPatientID, char *newPatientName,
		int seatplace, bool priority, bool ambulance,
		patient_struct *newPatientNext, patient_struct *newPatientPrev);
void addPatientToList(patient_struct **headP, patient_struct *newPatient);

bool isSeatFree(patient_struct* headP, int seatNumber);
void FreeSeat(patient_struct* headP, int seatNumber);
void PrintPatientsInfo(patient_struct* headP); 


#endif /* CSV_H_ */
