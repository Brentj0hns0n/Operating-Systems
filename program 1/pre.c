/*************************************************
*   Brent Johnson                                *
*   Operating Systems - Summer 2015              *
*   Lab 1 - Part 1                               *
*                                                *
* This is a simple C program that reads in a     *
* list of students from a file "students.txt"    *
* and displays the names of students with        *
* a gpa above 3.5 to to a file (outputfile).     *
*************************************************/
//include appropriate libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{
    FILE * file; // for input file
    FILE * outputFile; // output
    char * nameString[60]; // array of char to store name
    float grade; // to store grade as GPA

//open input file
    file = fopen("students.txt", "r+");

//This is error checking to ensure validity
    if(file == 0)
    {
        perror("Unable to open the file.");
        return -1;
    }
    outputFile = fopen("outputFile.txt","w");

//this loops prints to file
    while (!(feof(file)))
    {
        fscanf(file,"%s %f", nameString, &grade);
        if (grade > 3.5)
            fprintf(outputFile, "%s\n", nameString);
    }
//close IO files
    fclose(outputFile);
    fclose(file);
}
