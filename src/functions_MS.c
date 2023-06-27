// Function to check the neighboring seats for a given seat
void checkSeatNeighbour(Seat seats[], int totalSeats, int seatNumber) {
    // If the seatNumber is out of range, print an error and return
    if(seatNumber < 0 || seatNumber >= totalSeats) {
        printf("Invalid seat number.\n");
        return;
    }

    // Calculate the start and end of the row where the seat is located
    int row = seatNumber / ROWS;
    int startOfRow = row * ROWS;
    int endOfRow = startOfRow + ROWS;

    // Print out a message stating which seat's neighbors we are checking
    printf("Checking neighbours for seat number %d:\n", seatNumber);

    // If the seat is not at the start of the row, check the seat to the left
    if (seatNumber > startOfRow) {
        printf("Left neighbour at seat %d is %s\n",
               seatNumber - 1,
               seats[seatNumber - 1].isOccupied ? "occupied" : "free");
    }

    // If the seat is not at the end of the row, check the seat to the right
    if (seatNumber < endOfRow - 1) {
        printf("Right neighbour at seat %d is %s\n",
               seatNumber + 1,
               seats[seatNumber + 1].isOccupied ? "occupied" : "free");
    }
}

// Function to print out information for all patients
void PrintPatientsInfo(Patient* head) {
    // If there are no patients, print a message and return
    if (head == NULL) {
        printf("No patients in the queue.\n");
        return;
    }

    // Initialize a pointer to traverse the linked list of patients
    Patient* current = head;

    // Loop through the linked list
    while (current != NULL) {
        // Print out the id, name, and priority of the patient
        printf("Patient ID: %d, Name: %s, Priority: %d\n", 
               current->id, 
               current->name, 
               current->priority);

        // If the patient has a seat, print the seat number
        // Otherwise, print a message indicating they arrived by ambulance
        if (current->seatNumber != -1) {
            printf("Seat number: %d\n", current->seatNumber);
        } else {
            printf("No seat assigned (arrived by ambulance)\n");
        }

        // Move to the next patient in the list
        current = current->next;
    }
}

// Function to check the neighboring seats for a given patient
void QuerySeatPartners(Patient* head, int patientId) {
    // Initialize a pointer to traverse the linked list of patients
    Patient* current = head;
    
    // Loop through the linked list until we find the patient or reach the end
    while (current != NULL && current->id != patientId) {
        current = current->next;
    }

    // If we didn't find the patient, print an error message and return
    if (current == NULL) {
        printf("Patient with id %d not found.\n", patientId);
        return;
    }

    // If the patient has a seat, call the checkSeatNeighbour function
    // Otherwise, print a message indicating the patient arrived by ambulance
    if (current->seatNumber != -1) {
        checkSeatNeighbour(seats, ROWS * COLS, current->seatNumber);
    } else {
        printf("Patient with id %d has no seat assigned (arrived by ambulance).\n", patientId);
    }
}
