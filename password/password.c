// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int i = 0;
    int UpperCheck = 0;
    int LowerCheck = 0;
    int NumberCheck = 0;
    int SymbolCheck = 0;
    while (password[i] != 0)
    {
        if (password[i] > 64 && password[i] < 91)
        {
            UpperCheck++;
        }
        else if (password[i] > 96 && password[i] < 123)
        {
            LowerCheck++;
        }
        else if (password[i] > 47 && password[i] < 58)
        {
            NumberCheck++;
        }
        else
        {
            SymbolCheck++;
        }
        i++;
    }

    if (UpperCheck > 0 && LowerCheck > 0 && NumberCheck > 0 && SymbolCheck > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
