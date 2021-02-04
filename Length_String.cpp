#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#define MAX_STR_SIZE 80
#define CASE_DIFFERENCE 32

int string_length(char *in_str)
{
    int str_length = 0;

    // Traverse the string till you find the null character
    for (char *char_indx = in_str; *char_indx != '\0'; char_indx++, str_length++); 
    
    return str_length;
}

char* string_uppercase(char *orig_string, char *upper_string)
{
    char* orig_indx = orig_string;
    char* upper_indx = upper_string;

    for (;*orig_indx != '\0'; orig_indx++, upper_indx++)
    {
        if (*orig_indx >= 'a' && *orig_indx <= 'z')
        {
            // Found a lower case character. Change it.
            *upper_indx = *orig_indx - CASE_DIFFERENCE;
        }
        else
        {
            *upper_indx = *orig_indx;
        }
    }

    return (upper_string);
}

char* string_lowercase(char *orig_string, char *lower_string)
{

    char* orig_indx = orig_string;
    char* lower_indx = lower_string;

    for (;*orig_indx != '\0'; orig_indx++, lower_indx++)
    {
        if (*orig_indx >= 'A' && *orig_indx <= 'Z')
        {
            // Found an upper case character. Change it.
            *lower_indx = *orig_indx + CASE_DIFFERENCE;
        }
        else
        {
            *lower_indx = *orig_indx;
        }
    }

    return (lower_string);
}

int string_vowels (char* orig_str)
{
    uint total_vowels = 0;
    const char vowel_str[] ="AEIOUaeiou";

    for (int indx = 0; indx < strlen(orig_str); indx++)
    {
        if (strchr(vowel_str, orig_str[indx]) != nullptr)
        {
            total_vowels++;
        }
    }
    
    return total_vowels;
}

int string_consonants (char* orig_str)
{   
    uint total_consonants = 0;
    const char vowel_str[] ="AEIOUaeiou";

    for (int indx = 0; indx < strlen(orig_str); indx++)
    {
        // Lets first make sure it is a valid alphabet
        if (!isalpha(orig_str[indx]))
        {
            continue;
        }

        // If it is not in a vowel list - must be a consonant
        if (strchr(vowel_str, orig_str[indx]) == nullptr)
        {
            total_consonants++;
        }
    }
    
    return total_consonants;
}

int string_words (char* orig_str)
{
    uint total_words = 0;
    bool is_word = false;

    // Eat up any spaces at the start
    uint str_indx = 0;
    while (orig_str[str_indx++] == ' ');

    while (str_indx++ < strlen(orig_str))
    {
        // If we are not at a space - just keep going
        if (orig_str[str_indx] != ' ') 
        {
            is_word = true;
            continue;
        }

        // If we are at a space
        // 1. Increment word count
        // 2. Gobble up all the spaces
        total_words++;
        is_word = false;
        while (orig_str[str_indx++] == ' ');
    }
    
    // were we at the last word?
    if (is_word) 
    {
        total_words++;
    }

    return total_words;
}

int main()
{
    char user_str[MAX_STR_SIZE];
    char lower_str[MAX_STR_SIZE];
    char upper_str[MAX_STR_SIZE];

    memset(user_str, 0, sizeof(user_str));
    memset(lower_str, 0, sizeof(lower_str));
    memset(upper_str, 0, sizeof(upper_str));

    cout << "Enter a string: ";
    cin.getline(user_str, MAX_STR_SIZE);
    cout << "You entered string: " << user_str << endl;
    cout << "You entered a string of length: " << string_length(user_str) << endl;
    cout << "Lower Case Version: " << string_lowercase(user_str, lower_str) << endl;
    cout << "Upper Case Version: " << string_uppercase(user_str, upper_str) << endl;
    cout << "Total Vowels: " << string_vowels(user_str) << endl;
    cout << "Total Consonants: " << string_consonants(user_str) << endl;
    cout << "Total Words: " << string_words(user_str) << endl;

}