#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int h;
    
    do 
    {
        printf("Enter height:");
        h = GetInt();
    }
    while (h < 0 || h > 23);
    
    for (int r = 0; r < h; r++)
    {
        int spaces = 0;
        for (int sp = 1; sp < h - r; sp++) 
        {
            printf(" ");
            spaces++;
        }
        
        printf("#");
        
        for (int hash = 0; hash < h - spaces; hash++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}
