#include <stdio.h>

int main()
{

    // --------------------------------------------------- //
    // --------------------------------------------------- //
    // --------------------------------------------------- //


    // VARIABLES
    
    // Arrays https://www.geeksforgeeks.org/c-arrays/
    char user_input[255]; // Store in an arry with maximum length 254 + 1 for null terminator
    int valid = 1; // Assume email is valid until proven otherwise (if parameters fail reduce to 0) at the end check if <1

    int length = 0;
    int at_index = -1; // start at -1 for not found
    int dot_index = -1; // start at -1 for not found

    int again;


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


    // DO WHILE TO RE ENTER HERE (want to check another email adress Y or N ( - 1 or 2 )
    // weird do while bug - if user input was flagged as false valid variable will never be resetted to 1


   // do
   // {


            // why cant i re initialize valid to 1 here ?!?!?


            //int valid = 1;

            //if (valid = 0)
            //{
            //    valid = 1;
            //}


        // USER INPUT AND SCAN

        printf("Please enter an email address you want to check: \n");
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
                valid = 0;
                break;
            }
        }



        // CHECK CONSECUTIVE DOTS .. ... ...
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
                dot_index = i;
                break;
            }
        }

        // Check if the dot is at the start (<1) of user_input
        if (dot_index == -1 || dot_index < 1)
        {
            valid = 0;
        }



        // CHECK IF @ is before character 64


        for (int i = 0; i <= length; i++)
        {
            if (user_input[i] == '@')
            {
                at_index = i;
                break;
            }
        }

        // Check if @ exists and if @ is before the 64 characters mark
        if (at_index == -1 || at_index > 64)
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
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

            printf("The email adress you have entered is VALID\n\n");
            printf(" %d \n\n", valid);

            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        }

        else
        {
            printf("--------------------------------------------------------------------------\n\n");

            printf("The email adress you have entered is NOT VALID\n\n");
            printf(" %d \n\n", valid);

            printf("--------------------------------------------------------------------------\n\n");
        }



        // ----------------------------------------------------------------------------//
        // ----------------------------------------------------------------------------//
        // ----------------------------------------------------------------------------//
        // ----------------------------------------------------------------------------//

        /*

        // ASK FOR ANOTHER ROUND AND LOOP TO EMAIL ADRESS ENTRY POINT (Press 1 for re entry or everything else for farewell)
        printf("*****************************************************************************\n");
        printf("Check another email adress?\n");
        printf("Press (1) if you want to check another email adress or (2) to exit program.\n\n");
        printf("(1) - YES - check another email adress\n");
        printf("(2) - NO - do not check another email adress\n");
        printf("*****************************************************************************\n");

        scanf_s("\n\n %d", &again);

        */

    //} while (again == 1);


    // ----------------------------------------------------------------------------//
    // ----------------------------------------------------------------------------//
    // ----------------------------------------------------------------------------//
    // ----------------------------------------------------------------------------//

    // FAREWELL

    /*
    printf("--------------------------------------------------------------------------\n\n");
    printf("Thank you for checking your email adresses.\n\n");
    printf("--------------------------------------------------------------------------\n\n");
    */



    return 0;
}