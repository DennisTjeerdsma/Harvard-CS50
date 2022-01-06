#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Defining return struct for text characteristics
struct text_char
{
    int l;
    int s;
    int w;
};

// Function prototyping
struct text_char count_text_characteristics(string);
int coleman_liau(int l, int w, int s);

int main(void)
{
    string text = get_string("Text: ");
    struct text_char text_characteristics = count_text_characteristics(text);
    int grade_result = coleman_liau(text_characteristics.l, text_characteristics.w, text_characteristics.s);

    if (grade_result >= 1 && grade_result < 16)
    {
        printf("Grade %i\n", grade_result);
    }
    else if (grade_result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
    return 0;
}

// Function examining the text characteristics of a string/text. Counts the number of letters, sentences and words. Word is counted after every blank space, sentences are counted after . - ? or !
// The isalpha function is used to check if a character is alphabetical
struct text_char count_text_characteristics(string t)
{
    int l = 0, s = 0, w = 1;

    for (int i = 0, n = strlen(t); i < n; i++)
    {
        char temp_character = t[i];

        if (temp_character == '!' || temp_character == '?' || temp_character == '.')
        {
            s += 1;
        }
        else if (temp_character == ' ' && i > 0)
        {
            w += 1;
        }
        else if (isalpha(temp_character))
        {
            l += 1;
        }
    }
    struct text_char r = {l, s, w};
    return r;
}

// Function returning the grade based on the determined text characteristics according to Coleman-liau index
int coleman_liau(int l, int w, int s)
{
    int cl_index = round((0.0588 * (100 * ((float)l / w))) - (0.296 * (100 * (float)s / w)) - 15.8);
    return cl_index;
}