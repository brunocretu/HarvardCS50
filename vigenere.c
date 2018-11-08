/*
Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using a sequence of keys (or, put another way, a keyword).

In other words, if p is some plaintext and k is a keyword (i.e., an alphabetical string, whereby A (or a) represents 0, B (or b) represents 1, C (or c) represents 2, …, and Z (or z) represents 25), then each letter, ci, in the ciphertext, c, is computed as:

ci = (pi + kj) % 26

Note this cipher’s use of kj as opposed to just k. And if k is shorter than p, then the letters in k must be reused cyclically as many times as it takes to encrypt p.

In other words, if Vigenère himself wanted to say HELLO to someone confidentially, using a keyword of, say, ABC, he would encrypt the H with a key of 0 (i.e., A), the E with a key of 1 (i.e., B), and the first L with a key of 2 (i.e., C), at which point he’d be out of letters in the keyword, and so he’d reuse (part of) it to encrypt the second L with a key of 0 (i.e., A) again, and the O with a key of 1 (i.e., B) again.

Let’s now write a program called vigenere that enables you to encrypt messages using Vigenère’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the keyword should be for the secret message they’ll provide at runtime.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc < 2 || atoi(argv[1]) != 0)
    {
        printf("Usage: .\\vigenere keyword\n");
        return 1;
    }

    string keyword = argv[1];
    string plaintext = get_string("plaintext: ");
    printf("\n");
    string cyphertext = plaintext;
    int counter = 0;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int shift = 0;

        if (keyword[counter] >= 'a' && keyword[counter] <= 'z')
        {
            shift = keyword[counter] - 'a';
        }
        else
        {
            shift = keyword[counter] - 'A';
        }

        if ((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z'))
        {
            if (plaintext[i] + shift > 'z' && (plaintext[i] >= 'a' && plaintext[i] <= 'z'))
            {
                cyphertext[i] =  (char) (plaintext[i] + shift - 'z' + 'a' - 1);
            }
            else if (plaintext[i] + shift > 'Z' && (plaintext[i] >= 'A' && plaintext[i] <= 'Z'))
            {
                cyphertext[i] =  (char) (plaintext[i] + shift - 'Z' + 'A' - 1);
            }
            else
            {
                cyphertext[i] = (char) (plaintext[i] + shift);
            }

            counter ++;
        }
        else
        {
            cyphertext[i] = plaintext[i];
        }

        if (counter >= strlen(keyword))
        {
            counter = 0;
        }

    }

    printf("cyphertext: %s\n", cyphertext);
}
