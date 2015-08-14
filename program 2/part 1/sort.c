/*****************************************************
*   Brent Johnson                                    *
*   Operating Systems - Summer 2015                  *
*   Assignment 1 - Program 2                         *
*                                                    *
*   This simple C program is intended to read in a   *
*   list of names from stdin and puts them in        *
*   alphabetical order and outputs to the console.   *
*                                                    *
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nameArray[20][40];
    char tempArray[20];
    FILE * inputFile;
    int x = 0;  //these are indexes for loops
    int y = 0;  //later in the program

    // Open file
    inputFile = fopen("students.txt", "r");

    //check validity
    if(inputFile == 0)
    {
        perror("Unable to open the file.");
        return -1;
    }

    //input file
    for (x = 0; (!feof(inputFile)); ++x)    //while not at eof, keep going
        fscanf( inputFile, "%s", nameArray [x]);

    // close file
    fclose (inputFile);

    int ultimate = x - 1;   // final char in array

    //compare and copy
    for (x = ultimate; x > 0; --x)
        for (y = 1; y <= x; ++y)
            if (strcmp(nameArray[y], nameArray [y-1]) < 0 )
            {
                strcpy(tempArray, nameArray[y]);
                strcpy(nameArray[y], nameArray[y - 1]);
                strcpy(nameArray[y-1], tempArray);
            }
    //print to console
    for (x = 0; x <= ultimate; ++x)
        printf( "%s\n", nameArray[x]);
}
