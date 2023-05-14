/*
 * main.c
 *
 *  Created on: May 14, 2023
 *      Author: Gruppe 7 Sam
 */

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int seat_Order[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,1,19,20},{21,22,23,24,25}};

typedef struct patient {
    char name[20];
    int ID;
    int seatplace;
    bool priority;
    bool ambulance;

    struct patient *next;
}patient;



int main(){

	FILE *fp;



    return 0;
}



