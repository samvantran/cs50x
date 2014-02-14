/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n)
{
    if (value < 0)
        return false;
        
    // implement a searching algorithm
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
            return true;
    }
    return false;
}

/**
 * Sorts array of n values.
 */

void sort(int values[], int n)
{
    printf("This is the current array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", values[i]);
    }
    
    printf("\n");
    
    // TODO: implement an O(n^2) sorting algorithm
    // implement bubble sort
    int k = 0;
    bool didntSort = false;
    
    while (k < n)
    {
        for (int i = 0; i < n - 1 - k; i++)
        {
            if (values[i] > values[i + 1])
            {
                int temp = values[i + 1];
                values[i + 1] = values[i];
                values[i] = temp;
                didntSort = false;
                printf("Switched %d with %d\n", values[i+1], values[i]);
            }
        }
        k++;
    }
    
    printf("This is the sorted array: ");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", values[i]);
    }
    
    
    /*
        
    int counter = 0;

    
    do
    {
        for (int i = 0; i < n - 1; i++)
        {

        }  
    }
    while (counter > 0);
    */
    
    printf("\n");
    return;
    
}

