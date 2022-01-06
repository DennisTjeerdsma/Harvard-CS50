#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// Function prototyping
bool check_key_validity(string key);
string obtain_plaintext_from_user(void);
void generate_ciphertext(string cipher, string plaintext);


int main(int argc, string argv[])
{
    // Check if any command line arguments are given
    if (argc != 2)
    {
        printf("Program takes exactly 1 command line argument, please retry\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);

    // Check key validity return 1 if key does not contain 26 characters or a letter is used twice
    if (key_length != 26)
    {
        printf("Key has to contain 26 characters\n");
        return 1;
    }
    else
    {
        int matches = 0;

        for (char c = 'A'; c <= 'Z'; c++)
        {
            for (int i = 0, n = strlen(key); i < n; i++)
            {
                char temp_character = toupper(key[i]);
                if (temp_character == c)
                {
                    matches++;
                    key[i] = temp_character;
                    break;
                }
            }
        }
        if (matches != 26)
        {
            printf("Characters can each be used once in key\n");
            return 1;
        }
    }

    string plaintext = obtain_plaintext_from_user();
    generate_ciphertext(key, plaintext);

    return 0;
}

// Function requesting input string from user. If input string length < 1, prompts user again. returns user input to main
string obtain_plaintext_from_user(void)
{
    string answer;
    do
    {
        answer = get_string("plaintext: ");
    }
    while (strlen(answer) < 1);

    return answer;
}

// Function generating the ciphertext. Takes 2 inputs, the cipher/key en the plaintext. Prints the encrypted text to screen. Ignores any characters other than alphanumerical
void generate_ciphertext(string cipher, string plaintext)
{
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char temp_character = plaintext[i];

        if (isalpha(temp_character))
        {
            if (isupper(temp_character))
            {
                printf("%c", cipher[temp_character - 65]);
            }
            else
            {
                printf("%c", tolower(cipher[temp_character - 97]));
            }
        }
        else
        {
            printf("%c", temp_character);
        }
    }
    printf("\n");
}