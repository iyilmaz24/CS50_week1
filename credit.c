#include <stdio.h>
#include <string.h>


// A program that prompts the user for a credit card number and then reports back whether it is a valid American Express, MasterCard, or Visa card number.


int main(void)
{

    // we will use this array to store the user inputted credit card number for our validation later on
    char a[20];

    printf("Please provide a valid credit card number: ");
    scanf("%s", a);

    // this integer type variable will store the amount of digits in the inputted credit card number as a integer for future use in our loops
    int num_len;    
    num_len = strlen(a);


    // we need the loop count variable since we have a "formula" to follow (Luhn's Algorithm) that uses it in order to validate the credit card input
    // we use multiplied nums to create an array to store the multiplied numbers after they are multiplied by 2, and we use added num count to store the sum of the added numbers.
    // loop count represents which place the credit card digit is in, 1 = 1st, 2 = 2nd, ...
    int loop_count;
    int multiplied_num_array[20];
    int added_num_sum = 0, multiplied_num_sum = 0, total_sum = 0;


    // we will use the two variables below to store the first two digits of the card number, we will need this at the end of the program to output what type of card was provided if the credit card number was deemed valid
    int first_digit = a[0] - '0';
    int second_digit = a[1] - '0';


    // if the length of the credit card number is even, this for loop will run and process the inputted credit card number
    if ((num_len % 2) == 0)
    {
        for (int i = 1; i <= num_len; i++)
        {
            loop_count = i;

            if ((loop_count % 2) > 0)
            {
                int multiplied_num = a[loop_count - 1] - '0';
                multiplied_num_array[i] = 2 * multiplied_num;
            }
            else
            {
                int added_num = a[loop_count - 1] - '0';
                added_num_sum += added_num;
                multiplied_num_array[i] = 0;
            }
        }
    }
    // if the length of the credit card number is odd this for loop will run
    // this else part of the if-else code block is written exactly the same as it's if counterpart. The only difference being the logic of our addition and multiplication is just flipped since the the length of the credit card numbers is odd.
    else 
    {
        for (int i = 1; i <= num_len; i++)
        {
            loop_count = i;

            if ((loop_count % 2) == 0)
            {
                int multiplied_num = a[loop_count - 1] - '0';
                multiplied_num_array[i] = 2 * multiplied_num;
            }
            else
            {
                int added_num = a[loop_count - 1] - '0';
                added_num_sum += added_num;
                multiplied_num_array[i] = 0;
            }
        }
    }

    // this for loop will calculate the sum of the multiplied nums array, with each value split by their digits and added together
    for (int i = 1; i <= num_len; i++)
    {
        int first_digit = 1;
        int second_digit = 0;

        if (multiplied_num_array[i] <= 9)
        {
            multiplied_num_sum += multiplied_num_array[i];
        }
        else
        {   
            second_digit = multiplied_num_array[i] % 10;
            multiplied_num_sum += (second_digit + first_digit);
        }
    }

    // this last part of the program will add up both the sums and do the final step for credit card number validation
    total_sum = multiplied_num_sum + added_num_sum;

    // if the last digit of the total sum is 0, we know it is a valid credit card number so we will proceed
    if (total_sum % 10 == 0)
    {
        //  VISA card numbers always start with 4, and have a length of 13 or 16
        if (first_digit == 4)
        {
            if (num_len == 13 || num_len == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // AMEX card numbers always start with a 34 or 37, and have a length of 15
        else if (first_digit == 3)
        {
            if (second_digit == 4 && num_len == 15 || second_digit == 7 && num_len == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // MASTERCARD card numbers always start with 51 - 55, and have a length of 16
        else if (first_digit == 5)
        {
            if (second_digit >= 1 && second_digit <= 5 && num_len == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }

}



