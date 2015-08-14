/*************************************************
*   Brent Johnson                                *
*   Operating Systems - Summer 2015              *
*   Assign 3                                     *
*                                                *
*   This is a simple C program creates three     *
*   threads and sends them to a function that    *
*   simulates students receiving a scholarship   *
*   on a first come first serve basis.  It is a  *
*   demonstration of the danger of sharing       *
*   resources without using a semaphore.         *
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>


void *getMoney(char *);
int totalMoney = 4000;
int * moneyPtr = &totalMoney;

int main()
{

    pthread_t stu1, stu2, stu3;
    char a='a',b ='b',c ='c';
    char * charptrA = &a, *charptrB=&b, *charptrC=&c;

    while (totalMoney > 1)
    {
        pthread_create(&stu1, NULL, getMoney, charptrA);
        pthread_create(&stu2, NULL, getMoney, charptrB);
        pthread_create(&stu3, NULL, getMoney, charptrC);
    }

    pthread_join(stu1, NULL);
    pthread_join(stu2, NULL);
    pthread_join(stu3, NULL);
}

void * getMoney(char * charPtr)
{

    int amtReceived = 0;
    int amtGiven = 0;

    amtGiven = ceil(*moneyPtr * .25);
    printf("amtGiven %c: $%i\n",*charPtr, amtGiven );
    *moneyPtr = *moneyPtr - amtGiven;
    amtReceived = amtReceived + amtGiven;
   // sleep(1);

}
