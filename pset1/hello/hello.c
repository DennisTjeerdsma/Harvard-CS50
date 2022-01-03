#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Promps the user for their name and returns the name to screen
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}