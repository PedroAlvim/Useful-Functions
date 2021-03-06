/*
         This program shows the functionality of the menu_v in a compound menu structure

    Compound menu structure in this case, is : when the user enters a menu,
     give the option to go back to the last menu.

     This structure can be replicated, in an 'n' menu cases.

     obs: The explanation of menu_v is in another post. -->
     https://github.com/PedroAlvim/Useful-Functions/blob/master/Vertical%20Menu
*/

#include <iostream>
//to use textcolor();
#include <windows.h>
//to use getch();
#include <conio.h>
using namespace std;

//function thats change the color
void textcolor(int iColor);
//function menu_v
void menu_v(string call, string op_array[], int n, int &op, int icolor);

int main()
{
    //external MENU
    bool keep = true, switch_menu = false;
    int n1 = 3, op1;
    string op_array1[n1] = {"Access Internal Menu 1", "Access Internal Menu 2", "Exit"},
           call1 = "External MENU \nPress [w/s] to change and [Enter] to choose.\n\n";

    //internal MENU 1
    int n2 = 3, op2;
    string op_array2[n2] = {"Option 1", "Option 2", "\nReturn last Menu"},
           call2 = "Internal MENU 1 \nPress [w/s] to change and [Enter] to choose.\n\n";

    //Internal MENU 2
    int n3 = 3, op3;
    string op_array3[n3] = {"Option 1", "Option 2", "\nReturn last Menu"},
           call3 = "Internal MENU 2 \nPress [w/s] to change and [Enter] to choose.\n\n";

    do
    {
        //set the start point of op1 in external menu
        op1 = 0;
        //external menu
        menu_v(call1, op_array1, n1, op1, 6);
        //when exiting the external menu, all internal 'ops' must be reset to be aesthetically better
        op2 = 0;
        op3 = 0;
        switch (op1)
        {

        case 0: //Internal menu 1

            do
            {
                //in the beginning of this loop, we have to reset switch_menu
                switch_menu = 0;
                menu_v(call2, op_array2, n2, op2, 4);

                switch (op2)
                {
                case 0:
                    system("cls");
                    cout << "\nOption 1 of the Internal menu 1.\n\n";
                    system("pause");
                    break;

                case 1:
                    system("cls");
                    cout << "\nOption 2 of the Internal menu 1.\n\n";
                    system("pause");
                    break;

                default:
                    switch_menu = true;
                }
            } while (!switch_menu);
            //this is the switch..case breaker
            break;

        case 1: //Internal menu 2

            do
            {
                switch_menu = 0;
                menu_v(call3, op_array3, n3, op3, 11);

                switch (op3)
                {
                case 0:
                    system("cls");
                    cout << "\nOption 1 of the Internal menu 2.\n\n";
                    system("pause");
                    break;

                case 1:
                    system("cls");
                    cout << "\nOption 2 of the Internal menu 2.\n\n";
                    system("pause");
                    break;

                default:
                    switch_menu = true;
                }
            } while (!switch_menu);
            //this is the switch..case breaker
            break;

        default:
            //to leave the external menu
            keep = false;
        }

    } while (keep);

    return 0;
}

void menu_v(string call, string op_array[], int n, int &op, int icolor)
{
    char key;
    do
    {
        system("cls");
        //you can put what ever you want here, will be showed above the op_array
        cout << call << endl
             << endl;

        for (int i = 0; i < n; i++)
        {
            if (i == op)
            {
                textcolor(icolor);
                cout << op_array[i] << endl;
                //default color is set to 15 white
                textcolor(15);
            }
            else
                cout << op_array[i] << endl;
        }

        //reset key
        key = 'z';
        // trap the user in getch (); until he types, w, s or enter
        while (key != 'w' and key != 'W' and key != 's' and key != 'S' and key != 13)
            key = getch();

        // move to the chosen direction [w/s]
        if (key == 'w' or key == 'W')
        {
            if (op != 0)
                op--;
        }

        else if (key == 's' or key == 'S')
        {
            if (op != n - 1)
                op++;
        }
    }
    // exit the loop if the user presses enter
    while (key != 13);
}

void textcolor(int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= iColor);
}
