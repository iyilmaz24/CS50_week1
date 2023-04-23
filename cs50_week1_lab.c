#include <stdio.h>


// This is my submission for the CS50x Week 1 Lab Activity. 
// It is a simple program written in C to calculate the number of years needed to reach an ending population size, for a population that grows by 1/3 it's size every year and sheds 1/4 it's size every year as well.


int main(void)
{

    // a do-while loop intended to validate input for starting size
    int starting_size;
    do
    {
        printf("Please enter a starting population size greater than 9: ");
        scanf("%d", &starting_size);
    }
    while (starting_size < 9);


    // a do-while loop intended to validate input for ending size
    int ending_size;
    do
    {
        printf("Please enter a ending population size: ");
        scanf("%d", &ending_size);
    }
    while (ending_size <= starting_size);


    // variable to store end result
    int years;

    if (starting_size != ending_size)
    {
        int current_size = starting_size;
        do
        {
            current_size = current_size + ((current_size / 3) - (current_size / 4));
            years++;
        }
        while (current_size < ending_size);
    }
    else
    {
        years = 0;
    }

    // outputs end result
    printf("Years: %d", years);
}





