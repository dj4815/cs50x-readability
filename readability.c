#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text.
    string text_input = get_string("Enter text: ");

    // Store text in array? Or something.
    char text_array[1000];
    strcpy(text_array, text_input);

    // Count the number of letters, words, and sentences in the text array.
    // Initialize counter.
    int counter = 0;

    // Iterate over text input string and count all characters.
    for (int i = 0; i < strlen(text_input); i++)
    {
        counter++;
    }
    // Testing output
    // printf("Total: ");
    // printf("%i", counter);
    // printf("\n");

    // Initialize letter counter.
    float letter_count = 0;

    // Iterate over text array and
    for (int j = 0; j < counter; j++)
    {
        // Check if character is a letter.
        if (isalpha(text_array[j]))
        {
            // If yes, increment counter.
            letter_count++;
        }
    }
    // Testing output
    // printf("Letters: ");
    // printf("%i", letter_count);
    // printf("\n");

    // Initialize word counter
    float word_count = 0;

    // Iterate over text array and
    for (int k = 0; k < counter; k++)
    {
        // Check if character is a space.
        if (isblank(text_array[k]))
        {
            // If yes, increment word counter.
            word_count++;
        }
    }
    // Add + 1 to the counter to catch the word after the last space.
    word_count += 1;

    // Testing output
    // printf("Words: ");
    // printf("%i", word_count);
    // printf("\n");

    // Initialize sentence counter.
    float sentence_count = 0;

    // Iterate over text array and
    for (int l = 0; l < counter; l++)
    {
        // Check if character is punctuation.
        if (text_array[l] == '.' || text_array[l] == '!' || text_array[l] == '?')
        {
            // If yes, increment sentence counter.
            sentence_count++;
        }
    }
    // Testing output
    // printf("Sentences: ");
    // printf("%i", sentence_count);
    // printf("\n");

    // Compute the Coleman-Liau index and
    double coleman_liau_index = 0.0588 * ((letter_count / word_count) * 100) - 0.296 * ((sentence_count / word_count) * 100) - 15.8;

    // Round it
    int rounded_cli = (int) round(coleman_liau_index);

    // Print the grade level
    if (rounded_cli <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_cli >= 2 && rounded_cli <= 16)
    {
        printf("Grade %i\n", rounded_cli);
    }
    else
    {
        printf("Grade 16+\n");
    }
    // Testing output
    // printf("%f\n", coleman_liau_index);
    // printf("%f\n", round(coleman_liau_index));
}
