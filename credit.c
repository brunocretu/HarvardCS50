/*Luhn’s Algorithm*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Number: ");
        printf("\n");
    }
    while (card < 0);

    bool valid = false;

    int counter = 0;
    int sumOne = 0;
    int sumTwo = 0;
    long digit = card;
    do
    {
        if(counter % 2 == 0)
        {
            sumTwo += digit % 10;
            digit /= 10;
            counter++;
        }
        else
        {
            int single = (digit % 10) * 2;
            for (int i = 0; i < 2; i++)
            {
              sumOne += single % 10;
              single /= 10;
            }
            digit /= 10;
            counter++;
        }
    }
    while(digit >= 1);

    if((sumOne + sumTwo) % 10 == 0)
    {
      valid = true;
    }
    else
    {
      valid = false;
    }

    long digits = card;
    int length = 0;
    while(digits >= 100)
    {
        digits /= 10;
        length += 1;
    }
    if((digits == 34 || digits == 37) && length + 2 == 15 && valid)
    {
      printf("AMEX\n");
    }
    else if ((digits == 51 || digits == 52 || digits == 53 || digits == 54 || digits == 55) && length + 2 == 16 && valid)
    {
      printf("MASTERCARD\n");
    }
    else if (digits >= 40 && digits < 50 && (length + 2 == 13 || length + 2 == 16) && valid)
    {
      printf("VISA\n");
    }
    else
    {
      printf("INVALID\n");
    }

}
