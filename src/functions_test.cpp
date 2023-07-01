#include <iostream>
#include <cassert>
#include "functions.cpp" // Include the functions.cpp file

// Test case for the createPatient function
void testCreatePatient() {
    // Create a new patient
    patient_struct* patient = createPatient(1, "John Doe", 3, true, false, nullptr, nullptr);

    // Verify the patient's information
    assert(patient->ID == 1);
    assert(strcmp(patient->name, "John Doe") == 0);
    assert(patient->seatplace == 3);
    assert(patient->priority == true);
    assert(patient->ambulance == false);
    assert(patient->next == nullptr);
    assert(patient->prev == nullptr);

    // Cleanup
    free(patient);
}

// Test case for the trimWhiteSpace function
void testTrimWhiteSpace() {
    // Test trimming leading and trailing white spaces
    char str1[] = "   Hello, World!   ";
    char* trimmedStr1 = trimWhiteSpace(str1);
    assert(strcmp(trimmedStr1, "Hello, World!") == 0);

    // Test trimming when there are no leading or trailing white spaces
    char str2[] = "Hello, World!";
    char* trimmedStr2 = trimWhiteSpace(str2);
    assert(strcmp(trimmedStr2, "Hello, World!") == 0);
}

// Test case for the isSeatFree function
void testIsSeatFree() {
    // Create a linked list of patients
    patient_struct* patient1 = createPatient(1, "John Doe", 1, true, false, nullptr, nullptr);
    patient_struct* patient2 = createPatient(2, "Jane Smith", 2, false, false, nullptr, nullptr);
    patient_struct* patient3 = createPatient(3, "Alice Johnson", 3, true, false, nullptr, nullptr);
    patient1->next = patient2;
    patient2->next = patient3;

    // Test seat availability
    assert(isSeatFree(patient1, 1) == false);  // Seat 1 is occupied
    assert(isSeatFree(patient1, 4) == true);   // Seat 4 is free

    // Cleanup
    free(patient1);
    free(patient2);
    free(patient3);
}

// Test case for the addPatientToList function
void testAddPatientToList() {
    // Create a linked list of patients
    patient_struct* patient1 = createPatient(1, "John Doe", 1, true, false, nullptr, nullptr);
    patient_struct* patient2 = createPatient(2, "Jane Smith", 2, false, false, nullptr, nullptr);
    patient1->next = patient2;

    // Create a new patient and add it to the list
    patient_struct* newPatient = createPatient(3, "Alice Johnson", 3, true, false, nullptr, nullptr);
    addPatientToList(&patient1, newPatient);

    // Verify the patient has been added to the list
    assert(patient2->next == newPatient);
    assert(newPatient->prev == patient2);

    // Cleanup
    free(patient1);
    free(patient2);
    free(newPatient);
}

int main() {
    // Run the unit tests
    testCreatePatient();
    testTrimWhiteSpace();
    testIsSeatFree();
    testAddPatientToList();

    std::cout << "All tests passed successfully!\n";

    return 0;
}
