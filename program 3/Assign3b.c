/*************************************************
*   Brent Johnson                                *
*   Operating Systems - Summer 2015              *
*   Assign 3                                     *
*                                                *
*   This is a simple C program that restores     *
*   correct functionality to Assign3a.c (a       *
*   program simulating students receiving a      *
*   scholarship on a first come first serve basis*
*   This version protects shared resources using *
*   a semaphore.                                 *
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>


void *getMoney(char *);
int totalMoney = 4000;
int * moneyPtr = &totalMoney;
pthread_mutex_t mutex1;

int main()
{

    pthread_t stu1, stu2, stu3;
    char a='a',b ='b',c ='c';
    char * charptrA = &a, *charptrB=&b, *charptrC=&c;
    pthread_mutex_init(&mutex1, NULL);

    while (totalMoney > 1)
    {
        pthread_create(&stu1, NULL, getMoney, charptrA);
        pthread_create(&stu2, NULL, *getMoney, charptrB);
        pthread_create(&stu3, NULL, &getMoney, charptrC);
    }

  //  pthread_join(stu1, NULL);
 //   pthread_join(stu2, NULL);
 //   pthread_join(stu3, NULL);
  //  pthread_mutex_destroy(&mutex1);
}

void * getMoney(char  * charPtr)
{


    int amtReceived = 0;
    int amtGiven = 0;
    pthread_mutex_lock(&mutex1);
   // while(totalMoney > 1)
    {
    // Critical Section  //
    amtGiven = ceil(*moneyPtr * .25);
    printf("amtGiven %c: $%i\n",*charPtr, amtGiven );
    *moneyPtr = *moneyPtr - amtGiven;
    amtReceived = amtReceived + amtGiven;
    // end critical section //
    }
    pthread_mutex_unlock(&mutex1);
    sleep(1);
}
