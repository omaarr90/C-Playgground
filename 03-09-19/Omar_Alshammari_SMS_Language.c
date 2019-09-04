#include <stdio.h>
#include <string.h>

#define MAX_SMS_MESSAGE 161
#define MAX_EXPANDED_MESSAGE 1000
#define SIZE 10

typedef struct
{
    const char *acronym;
    const char *full_world;
    int length;

} Acronym;

const char *convertToSMSLang(const char token[]);

Acronym all_acronyms[SIZE] = {
    {"OMG", "Oh My God", 3},
    {"ASAP", "As Soon As Possible", 4},
    {"LOL", "Laugh Out Loud", 3},
    {"OMW", "On My Way", 3},
    {"B/C", "Because", 3},
    {"TIL", "Today I Learnd", 3},
    {"DIY", "Do It Yourself", 3},
    {"TBA", "To Be Announced", 3},
    {"TQ", "Thank You", 2},
    {"YAM", "Yet Another Meeting", 3},
};

int main(void)
{
    char sms_message[MAX_SMS_MESSAGE];
    char exapnded_mssage[MAX_EXPANDED_MESSAGE];
    memset(exapnded_mssage, '\0', MAX_EXPANDED_MESSAGE);

    puts("Please enter SMS message up to 160 characters.");
    fgets(sms_message, MAX_SMS_MESSAGE - 1, stdin);

    char *tokenPtr = strtok(sms_message, " "); // begin tokenizing sentence

    char *replaced_messagge = convertToSMSLang(tokenPtr);

    strcat(exapnded_mssage, replaced_messagge);

    for (size_t i = 0; i < MAX_EXPANDED_MESSAGE; i++)
    {
        if (exapnded_mssage[i] == '\0')
        {
            exapnded_mssage[i] = ' ';
            break;
        }
    }

    while (tokenPtr != NULL)
    {
        tokenPtr = strtok(NULL, " "); // get next token
        char *replaced_messagge = convertToSMSLang(tokenPtr);
        strcat(exapnded_mssage, replaced_messagge);
        for (size_t i = 0; i < MAX_EXPANDED_MESSAGE; i++)
        {
            if (exapnded_mssage[i] == '\0')
            {
                exapnded_mssage[i] = ' ';
                break;
            }
        }
    }

    printf("The full sentence is:%s\n", exapnded_mssage);
}

const char *convertToSMSLang(const char token[])
{
    if (token == NULL)
    {
        return "\0";
    }
    
    for (size_t i = 0; i < SIZE; i++)
    {
        if (strncmp(token, all_acronyms[i].acronym, all_acronyms[i].length) == 0)
        {
            return all_acronyms[i].full_world;
        }
    }
    return token;
}
