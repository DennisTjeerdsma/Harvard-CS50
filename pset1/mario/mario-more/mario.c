#include <stdio.h>
#include <cs50.h>

// Function prototypes
int get_height(void);
void draw_pyramid(int height);

int main(void)
{
    int height = get_height();
    draw_pyramid(height);

    return 0;
}

// Function asking the user for the height of the pyramid. Input value has to be an integer between 0 and 9
int get_height(void)
{
    int height_input;

    do
    {
        height_input = get_int("Input pyramid height: ");
    }
    while (height_input < 1 || height_input > 8);

    return height_input;
}

// Function drawing the pyramid to command line
void draw_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {

        // spaces before the pyramid
        for (int x = 1; x < height - i; x++)
        {
            printf(" ");
        }

        // draw # at front of pyramid
        for (int x = 0; x <= i ; x++)
        {
            printf("#");
        }

        // spaces between pyramid sides
        printf("  ");

        // draw back of pyramid
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }

        printf("\n");
    }
}