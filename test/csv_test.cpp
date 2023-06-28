
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <csv.h>
#include <catch2/catch.hpp>

#define MAX_ROWS 1000
#define MAX_COLS 10
#define MAX_FIELD_LENGTH 100

TEST_CASE("Test1") {
	REQUIRE(true);
}
TEST(PatientListTest, FreeSeat) {
    patient_struct* head = NULL;
    head = createPatient(1, "John", 1, true, true, NULL, NULL);
    patient_struct* patient2 = createPatient(2, "Alice", 2, false, false, NULL, NULL);
    head->next = patient2;
    patient2->prev = head;

    // Seat 3 should be free
    ASSERT_TRUE(isSeatFree(head, 3));

    // Seat 1 and 2 are occupied
    ASSERT_FALSE(isSeatFree(head, 1));
    ASSERT_FALSE(isSeatFree(head, 2));
}

