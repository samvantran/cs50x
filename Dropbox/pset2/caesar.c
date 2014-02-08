#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{
    // checking for only 2 cmd line args
    if (argc != 2 || argv[1] < 0) 
    {
        printf("Program is yelling at you! asdf!\n");
        return 1;
    }
    
    // casting string k to an int
    int k = atoi(argv[1]);
    
    printf("Hand me a string, good sir or madam!\n");
    string p = GetString();
    
    // iterate through string, encode by ROTk
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (islower(p[i]))
        {
            // formula for caesar's cipher: c = (p + k) % 26
            int new = p[i] + (k % 26);
            
            // to wrap letters back around
            if (new > 122)
            {
                new = new - 26;
            }
            printf("%c", new);
        }
            
        else if (isupper(p[i]))
        {
            //apply cipher and wrap letters
            int new = p[i] + (k % 26);
            
            if (new > 90)
            {
                new = new - 26;
            }
            printf("%c", new);
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}
