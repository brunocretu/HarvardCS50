/*
The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by k positions. More formally, if p is some plaintext (i.e., an unencrypted message), pi is the ith character in p, and k is a secret key (i.e., a non-negative integer), then each letter, ci, in the ciphertext, c, is computed as

ci = (pi + k) % 26

wherein % 26 here means “remainder when dividing by 26.” This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely. Indeed, for the sake of discussion, think of A (or a) as 0, B (or b) as 1, …, H (or h) as 7, I (or i) as 8, …, and Z (or z) as 25. Suppose that Caesar just wants to say Hi to someone confidentially using, this time, a key, k, of 3. And so his plaintext, p, is Hi, in which case his plaintext’s first character, p0, is H (aka 7), and his plaintext’s second character, p1, is i (aka 8). His ciphertext’s first character, c0, is thus K, and his ciphertext’s second character, c1, is thus L. Can you see why?

Let’s write a program called caesar that enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc < 2 || atoi(argv[1]) == 0)
    {
        printf("Usage: .\\caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    printf("\n");
    string cyphertext = plaintext;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            if (plaintext[i] + key > 'z') {
                cyphertext[i] =  (char) (plaintext[i] + key - 'z' + 'a' - 1);
            }
            else if (plaintext[i] + key < 'a')
            {
                cyphertext[i] =  (char) (plaintext[i] + key - 'a' + 'z' + 1);
            }
            else
            {
                cyphertext[i] =  (char) (plaintext[i] + key);
            }
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            if (plaintext[i] + key > 'Z') {
                cyphertext[i] =  (char) (plaintext[i] + key - 'Z' + 'A' - 1);
            }
            else if (plaintext[i] + key < 'A')
            {
                cyphertext[i] =  (char) (plaintext[i] + key - 'A' + 'Z' + 1);
            }
            else
            {
                cyphertext[i] =  (char) (plaintext[i] + key);
            }
        }
        else
        {
            cyphertext[i] =  plaintext[i];
        }
    }

    printf("cyphertext: %s\n", cyphertext);

}
