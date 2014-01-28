#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int counter = 0;
    do
    {
        printf("O hai! How much change is owed?\n");
        change = GetFloat();
    }
    while (change <= 0.00 );
      
    int cents = (int) round (change * 100.00);
    
    while (cents >= 25)
    {
        cents -= 25;
        counter++;
    }
    
    while (cents >= 10)
    {
        cents -= 10;
        counter++;
    }
    
    while (cents >= 5)
    {
        cents -= 5;
        counter++;
    }
    
    while (cents > 0)
    {
        cents -= 1;
        counter++;
    }
    
    printf("%d\n", counter);
}
