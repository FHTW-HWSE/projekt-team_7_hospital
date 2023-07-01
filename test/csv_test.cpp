#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <csv.h>
#include <catch2/catch.hpp>

#define MAX_ROWS 1000
#define MAX_COLS 10
#define MAX_FIELD_LENGTH 100

TEST_CASE("Test1") {
	REQUIRE(true);
}
     
TEST_CASE("Read patients list from CSV", "[readPatientsList]"){

    // Create the fields array
    char fields[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];

    SECTION("Valid CSV file")
    {
        // Create a sample CSV file
        FILE* fp = fopen("PatientsList.csv", "w");
        fprintf(fp, "ID,name,seatplace,priority,ambulance,leftNeighbour,rightNeighbour,\n");
        fprintf(fp, "1,Rama Ammoshah,1,FALSE,FALSE,NULL,NULL,\n");
        fprintf(fp, "2,Isabella John,2,FALSE,FALSE,NULL,NULL,\n");
        fprintf(fp, "3,Emilly Miller,3,TRUE,TRUE,NULL,NULL,\n");
        fprintf(fp, "4,Sarah Mayer,4,FALSE,FALSE,NULL,NULL,\n");
        fprintf(fp, "5,Markus Beckerei,5,TRUE,TRUE,NULL,NULL,\n");
        fclose(fp);

        // Call the function
        readPatientsList();

        // Assertions
        REQUIRE(strcmp(fields[0][0], "ID") == 0);
        REQUIRE(strcmp(fields[1][1], "Rama Ammoshah") == 0);
        REQUIRE(strcmp(fields[2][2], "2") == 0);
        REQUIRE(strcmp(fields[3][3], "FALSE") == 0);
        REQUIRE(strcmp(fields[4][4], "FALSE") == 0);
        REQUIRE(strcmp(fields[5][5], "NULL") == 0);
        REQUIRE(strcmp(fields[6][6], "NULL") == 0);
    }
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
