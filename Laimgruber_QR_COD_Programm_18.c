#include <stdio.h>

int main()
{

    // --------------------------------------------------- //
    // --------------------------------------------------- //
    // --------------------------------------------------- //


    // VARIABLES

    // Arrays https://www.geeksforgeeks.org/c-arrays/

    char user_input[255]; // Store in an arry with maximum length 254 + 1 for null terminator

    int valid = 1; // Assume email is valid until proven otherwise (if parameters fail, reduce to 0) at the end check if <1

    int length = 0;

    int at_symbol_index = -1; // start at -1 for not found

    int dot_symbol_index = -1; // start at -1 for not found

    int check_counter = 1;


    // --------------------------------------------------- //
    // --------------------------------------------------- //
    // --------------------------------------------------- //


    // DESCRIPTION OF PROGRAM

    printf("Welcome!\n");
    printf("Here you can enter an email adress and check its validity.\n\n");
    printf("Checking parameters are:\n\n");
    printf("* Max length of the email adress overall are:\n\t254 characters\n\n");
    printf("* Max lenght of the name of the email adress (before the at symbol) are:\n\t64 characters\n\n");
    printf("* Allowed symbols are:\n\tA-Z and\n\ta-z and\n\t0-9 and\n");
    printf("\t. _ - + symbols\n\n");
    printf("* No consecutive dots\n\n");


    // --------------------------------------------------- //
    // --------------------------------------------------- //
    // --------------------------------------------------- //




    // BIG LOOP TO FAST RECHECK EMAIL ADRESSES
    while (1)
    {
        
        // RESET ALL VARIABLES FOR A NEW ENTRY
        user_input[255];
        valid = 1;
        length = 0;
        at_symbol_index = -1;
        dot_symbol_index = -1;


        // USER INPUT AND SCAN

        printf("Please enter an email address you want to check: \n\n\n");
        // Read only up to 255 characters to avoid buffer overflow (scanf_s is only visual studio and if entered chars/string you need to specify length)
        scanf_s("%255s", user_input, 255);



        // --------------------------------------------------- //
        // --------------------------------------------------- //
        // --------------------------------------------------- //



        // PARAMETER CHECK



        // CHECK IF user_input CHARS ARE >254 via length
        // calc - count input chars via the array (Position: 0, 1, 2, 3, ...)
        while (user_input[length] != '\0')
        {
            length++;
        }

        // check if user_input is >254+1 (count starts at 0)
        if (length > 255)
        {
            valid = 0;
        }



        // CHECK CHARACTERS
        // A Z a z 0 9 . _ - + @

        // characters are number values and check if chars in the string are between x and y
        // (https://www.programiz.com/c-programming/examples/alphabet)


        for (int i = 0; i < length; i++)
        {
            char c = user_input[i];
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '.' || c == '_' || c == '-' || c == '+' || c == '@'))
            {
                printf("Bitte keine Sonderzeichen verwenden");
                valid = 0;
                break;
            }
        }



        // CHECK CONSECUTIVE DOTS 
        // .. ... ...
        // loop through user input array and check a dot & if there is another dot
        for (int i = 0; i < length; i++)
        {
            // 
            if (user_input[i] == '.' && user_input[i + 1] == '.')
            {
                valid = 0;
                break;
            }
        }



        // CHECK CONSECUTIVE @@
        // loop through user input array and check an @ & if there is another @
        for (int i = 0; i < length; i++)
        {
            if (user_input[i] == '@' && user_input[i + 1] == '@')
            {
                valid = 0;
                break;
            }
        }



        // CHECK IF THERE IS A DOT AT BEGINNING
        // Check if a dot exists in array
        for (int i = 0; i < length; i++)
        {
            if (user_input[i] == '.')
            {
                dot_symbol_index = i;
                break;
            }
        }



        // Check if the dot is at the start (<1) of user_input
        if (dot_symbol_index == -1 || dot_symbol_index < 1)
        {
            valid = 0;
        }



        // CHECK IF @ is before character 64
        for (int i = 0; i <= length; i++)
        {
            if (user_input[i] == '@')
            {
                at_symbol_index = i;
                break;
            }
        }



        // Check if @ exists and if @ is before the 64 characters mark
        if (at_symbol_index == -1 || at_symbol_index > 64)
        {
            valid = 0;
        }



        // --------------------------------------------------- //
        // --------------------------------------------------- //
        // --------------------------------------------------- //



        // OUTPUT


        
        // valid must be 1 as initialized or the -else statement is printed
        if (valid)
        {
            printf("VALID\n%d checked\n\n\n", check_counter);
        }

        else
        {
            printf("NOT valid\n%d checked\n\n\n", check_counter);
        }

        // check_counter increase every iteration from the big while loop to be able to print out the amount of email adress checks (you've checked X email adresses) 
        check_counter++;
    }

    return 0;
}
