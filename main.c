
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 10
#define MAX_FIELD_LENGTH 100

int main(void)
{
    FILE *csv_file;                         // Dateizeiger für die CSV-Datei
    char line[MAX_FIELD_LENGTH * MAX_COLS]; // puffer für eine Zeile in der CSV-Datei
    char *field;                            // zeigerr auf das aktuelle feld in Zeile
    char fields[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];
    int i = 0, j;

    csv_file = fopen("example.csv", "r");
    // überpruft ob das öffnen CSV
    if (csv_file == NULL)
    {
        printf("Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    // Liest eine Zeile asu CSV
    while (fgets(line, sizeof(line), csv_file) != NULL)
    {
        j = 0;
        field = strtok(line, ";"); // Trennt die Zeile in Felder anhand des Trennzeichens ";"
        while (field != NULL && j < MAX_COLS)
        {
            strcpy(fields[i][j], field);
            j++;
            field = strtok(NULL, ";");
        }
        i++;
    }
    fclose(csv_file);

    // Gibt die Matrix aus, um zu überprüfen, ob sie korrekt befüllt wurde
    for (int row = 0; row < i; row++)
    {
        for (int col = 0; col < j; col++)
        {
            printf("%s ", fields[row][col]);
        }
        printf("\n");
    }

    return 0;
}