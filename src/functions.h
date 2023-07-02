#include <stdbool.h>

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
void PrintPatientsInfo(patient_struct* headP); // Funktion zum Drucken der Patienteninformationen hinzugefügt

//functions mohammad
//void checkSeatNeighbour(Seat seats[], int totalSeats, int seatNumber);
