#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <csv.h>
#include <catch2/catch.hpp>

TEST_CASE("Test1") {
	REQUIRE(true);
}

TEST_CASE("Check if seat is free") {
    patient_struct* head = NULL;
    patient_struct* patient1 = (patient_struct*)malloc(sizeof(patient_struct));
    patient1->seatplace = 1;
    patient1->next = NULL;
    head = patient1;

    SECTION("Occupied seat") {
        bool result = isSeatFree(head, 1);
        REQUIRE(result == false);
    }

    SECTION("Free seat") {
        bool result = isSeatFree(head, 2);
        REQUIRE(result == true);
    }
}

TEST_CASE("Check if seat is free or occupied") {
    patient_struct* head = NULL;
    patient_struct* patient1 = (patient_struct*)malloc(sizeof(patient_struct));
    patient1->seatplace = 1;   // Set the seatplace member of patient1 to 1
    patient1->next = NULL;
    head = patient1;

    SECTION("Occupied seat") {
        // Redirect stdout to a buffer
        FILE* buffer;
        buffer = freopen("output.txt", "w", stdout);

        FreeSeat(head, 1);
        fclose(buffer);
		// Read the buffer and check the output
        buffer = fopen("output.txt", "r");
        char output[100];
        fgets(output, sizeof(output), buffer);
        fclose(buffer);

        REQUIRE(strcmp(output, "Seat 1 is occupied.\n") == 0);
    }

    SECTION("Free seat") {
        FILE* buffer;
        buffer = freopen("output.txt", "w", stdout);

        FreeSeat(head, 2);
        fclose(buffer);

        buffer = fopen("output.txt", "r");
        char output[100];
        fgets(output, sizeof(output), buffer);
        fclose(buffer);

        REQUIRE(strcmp(output, "Seat 2 is free.\n") == 0);
    }
}
