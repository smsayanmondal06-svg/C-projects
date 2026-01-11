#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
   int random,guess,no_of_guess=0;
   srand(time(NULL));

   printf("welcome to the world of guessing numbers \n");
   random=rand()%100 +1; //generating between 0 to 100
   do
   {
    printf("please enter your guess between (1 to 100):\n");
    scanf("%d",&guess);
    no_of_guess++;
    if (guess<random)
    {
        printf("guess larger number \n");
    }
    else if (guess>random)
    {
       printf("guess smaller number \n");
    }
    else{
        printf("you have successfully guessed the number in %d attempts",no_of_guess);
    }
    
   } while (guess != random);
   
    return 0;
}