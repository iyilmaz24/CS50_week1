#include <stdio.h>


int main(void)
{

    // this variable will store the user specified height
    int height;


    // this do-while loop validates input so that only numeric values between 1 - 8 can be used
    do
    {
        printf("How tall should the pyramids be (height from 1 - 8) ? ");
        scanf("%d", &height);
    }
    while (height <= 0 || height >= 9);


    // remaining_height is an identical value to height, we use it in one of our nested loops and subtract from it
    int remaining_height = height;
    int skip_first_row = 0;
    int row_count = 1;

    // this is the largest loop of this program, this for loop has many nested loops inside of it and if-else statements
    // this large for loop creates the pyramids fully according to user specified input
    for (int i = 0; i <= height; i++)
    {
        // this if-else statement with the nested for loop formats the hashes correctly and provides the correct spacing
        if (skip_first_row == 0)
        {
            skip_first_row++;
        }
        else
        {
            for (int i = 0; remaining_height - i > 0; i++)
            {
                printf(" ");
            }
        }

        // this for loop creates the left side of the pyramid
        for (int i = 1; i < row_count; i++)
        {
            printf("#");
        }
        if (i > 0)
        {
            printf("  ");
        }

        // this for loop creates the right side of the pyramid
        for (int i = 1; i < row_count; i++)
        {
            printf("#");
        }

        if (i > 0)
        {
            printf("\n");
        }

        // these variables get incremented by 1 at the end of every row that is printed
        row_count++;
        remaining_height--;
    }
}


