#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // CreditCard needs 64 bits //
    long CreditCard = get_long("Number: ");

    // Checks whether digit is even //
    int even = 0;

    // Keeps track of total sum
    int counter = 0;

    // For loop that splits all digits and adds/multiplies them to a sum based on even/uneven

    // Modulo can be used to splice digits  --> (123 % 10) / 10 = 3
    //                                      --> (123 % 100) / 10 = 2
    //                                      --> (123 % 1000) / 1000 = 1

    // 100000000000000000 --> Checks up to 16 digits
    for (long i = 10; i < 100000000000000000; i += 0)
    {
        int Check = (CreditCard % i) / (i / 10);
        i = i * 10;

        // if digit is even, multiply and add to sum
        if (even == 1)
        {
            Check *= 2;
            for (int j = 10; j < 1000; j += 0)
            {
                int Split = (Check % j) / (j / 10);
                j = j * 10;
                counter += Split;
            }

            even = 0;
        }

        // if digit is uneven, simply add to sum
        else if (even == 0)
        {
            counter += Check;
            even ++;
        }

    }
    // Visa Check //
    // 13 or 16 digit, starting with 4
    if (counter % 10 == false && ((CreditCard % 10000000000000000 / 1000000000000000 == 4)
                                  || (CreditCard % 10000000000000 / 1000000000000 == 4)))
    {
        printf("VISA\n");
    }
    // MasterCard Check //
    // 16 digit, starting with 51, 52, 53, 54 or 55
    else if (counter % 10 == false && ((CreditCard % 10000000000000000 / 100000000000000 == 51)
                                       || (CreditCard % 10000000000000000 / 100000000000000 == 52)
                                       || (CreditCard % 10000000000000000 / 100000000000000 == 53)
                                       || (CreditCard % 10000000000000000 / 100000000000000 == 54)
                                       || (CreditCard % 10000000000000000 / 100000000000000 == 55)))
    {
        printf("MASTERCARD\n");
    }
    // Amex Check //
    // 15 digit, starting with 34 or 37
    else if (counter % 10 == false && ((CreditCard % 1000000000000000 / 10000000000000 == 34)
                                       || (CreditCard % 1000000000000000 / 10000000000000 == 37)))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

