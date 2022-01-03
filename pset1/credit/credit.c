#include <stdio.h>
#include <cs50.h>

// Function prototyping
long get_creditcard(void);
void validate_creditcard(long cc_number);

// main function
int main(void)
{
    long cc_number = get_creditcard();
    validate_creditcard(cc_number);
    return 0;
}

// Obtain credit card info from user ignores negative numbers
long get_creditcard(void)
{
    long credit_number;

    do
    {
        credit_number = get_long("Credit card number: ");
    }
    while (credit_number <= 0);

    return credit_number;
}


// Validate creditcard number by luhn's algorithm. Checks if creditcard is valid and print out  the credit card company associated.
void validate_creditcard(long cc_number)
{
    int sum_digits = 0, sum_digits_mult2 = 0, counter = 0;
    long cc_number_copy =  cc_number;

    // Looping through the credit card number to perform luhn's algorithm
    while (cc_number != 0)
    {
        if (counter % 2 == 0)
        {
            sum_digits += cc_number % 10;
        }
        else
        {
            // Checks if the number is not above 10, if it is, the number is split into its products and added to the sum_of_mult2
            int temp_value = 2 * (cc_number % 10);
            if (temp_value > 9)
            {
                while (temp_value != 0)
                {
                    sum_digits_mult2 += (temp_value % 10);
                    temp_value /= 10;
                }
            }
            else
            {
                sum_digits_mult2 += (temp_value % 10);
            }
        }

        cc_number /= 10;
        counter++;
    }

    sum_digits += sum_digits_mult2;

    // Select the type of creditcard based on starting numbers and the total amount of numbers in the card
    if (sum_digits % 10 != 0 || counter < 13 || counter > 16)
    {
        printf("INVALID\n");
    }
    else if ((counter == 13 || counter == 16) && (cc_number_copy / 1000000000000000 == 4 || cc_number_copy / 1000000000000 == 4))
    {
        printf("VISA\n");
    }
    else if (counter == 15 && (cc_number_copy / 10000000000000 == 34 || cc_number_copy / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if (counter == 16 && (cc_number_copy / 100000000000000 == 51 || cc_number_copy / 100000000000000 == 52
                               || cc_number_copy / 100000000000000 == 53 || cc_number_copy / 100000000000000 == 54 || cc_number_copy / 100000000000000 == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}