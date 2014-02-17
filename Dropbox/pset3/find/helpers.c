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
#include <stdbool.h>

/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int max)
{
    int lowerBound = 0;
    int upperBound = max - 1;
    while (upperBound >= lowerBound)
    {
        int midPoint = (lowerBound + upperBound) / 2;
        if (value == values[midPoint])
        {
            return true;
        }
        else if (value < values[midPoint])
        {
            upperBound = midPoint - 1;
        }
        else
        {
            lowerBound = midPoint + 1;
        }
    }
    return false;
}

void sort(int values[], int n)
{
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
            }
        }
        k++;
    }
}

