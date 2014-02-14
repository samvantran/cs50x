/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // if there are < 2 or > 3 args, end prgm and display instructions
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // change the 2nd arg from string to an integer
    int n = atoi(argv[1]);

    // if there are 3 args, convert 3rd arg to integer (used as seed for rand)
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    // generate pseudorandom numbers argc times
    int genArray[n];
    for (int i = 0; i < n; i++)
    {
        genArray[i] = rand() % LIMIT;
        printf("%i\n", rand() % LIMIT);
    }
    
    // that's all folks
    return 0;
}
