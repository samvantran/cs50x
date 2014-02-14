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

//implement binary search

//---- Continue: last time, was unable to implement binary search due to search parameter constraints (3 args)
//---- can still do it iteratively or write a fn that search calls recursively w/ diff params
bool search(int value, int values[], int max)
{
    //function to find midpoint
    int min = 0;
    int midPoint;
    int findMidPoint(min, max)
    {
        midPoint = (max - min) / 2;
    }
    
    if (min > max)
    {
        return -1;
    }
    else
    {
        findMidPoint(min, max);
        if(values[midPoint] < value)
        {
            search(value, values[], midPoint + 1, max)
        }
        else if(values[midPoint] > value)
        {
            search(value, values[], min, midPoint - 1)
        }
        else
        {
            return values[midPoint];
        }
    }
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
    
    // implement an O(n^2) sorting algorithm
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
   
    printf("\n");
    return;
    
}

