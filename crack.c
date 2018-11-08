/*
On most systems running Linux these days is a file called /etc/shadow that contains usernames and passwords. Fortunately, the passwords therein aren’t stored “in the clear” but are instead encrypted using a “one-way hash function.” When a user logs into these systems by typing a username and password, the latter is encrypted with the very same hash function, and the result is compared against the username’s entry in /etc/shadow. If the two hashes match, the user is allowed in. If you’ve ever forgotten some password, you might have been told that tech support can’t look up your password but can change it for you. Odds are that’s because tech support can only see, if anything at all, a hash of your password, not your password itself. But they can create a new hash for you.

Even though passwords in /etc/shadow are hashed, the hash function is not always that strong. Quite often are adversaries, upon obtaining that file somehow, able to guess (and check) users’ passwords or crack them using brute force (i.e., trying all possible passwords). Below is what /etc/shadow might look like, albeit simplified, wherein each line is formatted as username:hash.

Your task is to design and implement a program, crack, that cracks passwords. We’re not going to give too many hints on this one, but to get started you may want to read up on how the crypt function works on Unix/Linux systems, such as this lab environment.

Specification

    Your program should accept one and only one command-line argument: a hashed password.
    If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).
    Otherwise, your program must proceed to crack the given password, ideally as quickly as possible, ultimately printing the password in the clear followed by \n, nothing more, nothing less, with main returning 0.
    Assume that each password has been hashed with C’s DES-based (not MD5-based) crypt function.
    Assume that each password is no longer than five (5) characters. Gasp!
    Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase).

*/

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "unistd.h"





int main(int argc, string argv[])
{
    if(argc < 2 || strlen(argv[1]) != 13)
    {
        printf("Usage: .\\crack hash\n");
        return 1;
    }

    string hash = argv[1];
    char salt[2];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];

    char generated_password[6] = {};
    char test_password[5] = {};

    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //Pass with len 1
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        generated_password[0] = alphabet[i];

        if(strcmp(crypt(generated_password, salt), argv[1]) == 0)
        {
            printf("Password found!\n%s\n", generated_password);
            return 0;
        }
    }

    //Pass with len 2
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        for (int j = 0, n = strlen(alphabet); j < n; j++)
        {
            generated_password[0] = alphabet[i];
            generated_password[1] = alphabet[j];

            if(strcmp(crypt(generated_password, salt), argv[1]) == 0)
            {
                printf("Password found!\n%s\n", generated_password);
                return 0;
            }
        }
    }

    //Pass with len 3
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        for (int j = 0, n = strlen(alphabet); j < n; j++)
        {
            for (int k = 0, n = strlen(alphabet); k < n; k++)
            {
                generated_password[0] = alphabet[i];
                generated_password[1] = alphabet[j];
                generated_password[2] = alphabet[k];

                if(strcmp(crypt(generated_password, salt), argv[1]) == 0)
                {
                    printf("Password found!\n%s\n", generated_password);
                    return 0;
                }
            }
        }
    }

    //Pass with len 4
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        for (int j = 0, n = strlen(alphabet); j < n; j++)
        {
            for (int k = 0, n = strlen(alphabet); k < n; k++)
            {
                for (int l = 0, n = strlen(alphabet); l < n; l++)
                {
                    generated_password[0] = alphabet[i];
                    generated_password[1] = alphabet[j];
                    generated_password[2] = alphabet[k];
                    generated_password[3] = alphabet[l];

                    if(strcmp(crypt(generated_password, salt), argv[1]) == 0)
                    {
                        printf("Password found!\n%s\n", generated_password);
                        return 0;
                    }
                }
            }
        }
    }

    //Pass with len 5
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        for (int j = 0, n = strlen(alphabet); j < n; j++)
        {
            for (int k = 0, n = strlen(alphabet); k < n; k++)
            {
                for (int l = 0, n = strlen(alphabet); l < n; l++)
                {
                    for (int m = 0, n = strlen(alphabet); m < n; m++)
                    {
                        generated_password[0] = alphabet[i];
                        generated_password[1] = alphabet[j];
                        generated_password[2] = alphabet[k];
                        generated_password[3] = alphabet[l];
                        generated_password[4] = alphabet[m];
                        generated_password[5] = '\0';

                        printf("%s\n", generated_password);

                        if(strcmp(crypt(generated_password, salt), argv[1]) == 0)
                        {
                            printf("Password found!\n%s\n", generated_password);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("Nothing found\n");

    return 0;

}
