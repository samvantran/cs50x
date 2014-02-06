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
    
    // iterate through string, encoding by ROTk
    for (int i = 0, n = strlen(p); i < n; i++)
    {
            // formula for caesar's cipher
            // c = (p + k) % 26
            p[i] += (k % 26);
        
            // to wrap letters back around
            /*
            if (p[i] > 90)
            {
                p[i] -= 26;
            }
            */
    }
    printf("%s\n", p);
      
}
