/*******************************************************
    Name: Ariessa

    Date: 07/11/2017

    Assignment Title: Grocery Shop Profit Calculator

    Objective: To calculate profit for a grocery shop
********************************************************/

#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    char itemName[30] = {}, itemCode[30] = {};
    int stockNumber = 0, userChoice = 0, userOption = 0;
    double buyingPrice = 0.00, sellingPrice = 0.00, expectedProfit = 0.00, totalExpectedProfit = 0.00;
    bool goodStock = true;
    struct tm expiryDate;
    SYSTEMTIME st;
    GetLocalTime(&st);

    mainMenu:
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
        printf("$$$$\tWelcome to Grocery Shop Profit Calculator\t$$$$\n\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
        printf("\t\tWhat Would You Like To Do?\n\n");
        printf("\t\t1. Add Stock(s)\n");
        printf("\t\t2. See Expected Profit\n\n");
        printf("\t\tEnter your choice (1 or 2): ");
        scanf("%d", &userChoice);
        fflush(stdin);
        printf("\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");

    switch (userChoice)
    {
        case 1:
            printf("\nEnter Item Name: ");
            gets(itemName);

            do
            {
                printf("\nEnter Expiry Date [dd mm yy]: ");
                scanf("%d %d %d", &expiryDate.tm_mday, &expiryDate.tm_mon, &expiryDate.tm_year);
                fflush(stdin);

                if (expiryDate.tm_year < st.wYear)
                {
                    printf("The expiry date has passed! Please reenter a valid date.\n");
                    goodStock = false;
                }

                else if (expiryDate.tm_year == st.wYear)
                {
                    if (expiryDate.tm_mon < st.wMonth)
                    {
                        printf("The expiry date has passed! Please reenter a valid date.\n");
                        goodStock = false;
                    }

                    else if (expiryDate.tm_mon == st.wMonth && expiryDate.tm_mday < st.wDay)
                    {
                        printf("The expiry date has passed! Please reenter a valid date.\n");
                        goodStock = false;
                    }

                    else
                        goodStock = true;
                }

                else
                    goodStock = true;

            } while (goodStock != true);

            printf("\nEnter Item Code: ");
            scanf("%d", &itemCode);
            fflush(stdin);

            while (buyingPrice <= 0.00)
            {
                printf("\nEnter Buying Price: RM ");
                scanf("%lf", &buyingPrice);

                if (buyingPrice <= 0.00)
                    printf("Buying Price cannot be zero or negative number! Please reenter Buying Price.\n");
            }

            while (stockNumber <= 0)
            {
                printf("\nEnter Number of Stock(s): ");
                scanf("%d", &stockNumber);
                fflush(stdin);

                if (stockNumber <= 0)
                    printf("Number of Stock(s) cannot be zero or negative number! Please reenter Number of Stock(s).\n");
            }

            sellingPrice = 0.3 * buyingPrice; // Calculates the selling price which should be 30% increment of the buying price.

            expectedProfit = sellingPrice * stockNumber; // Generates the expected profit for the particular stock.

            totalExpectedProfit += expectedProfit; // Calculates the total expected profit based on all the stocks owned.

            printf("\n\nSelling price: RM %.2lf\n", sellingPrice);
            printf("Expected Profit: RM %.2lf\n\n", expectedProfit);

            option:
                printf("\n\n************************************************************\n\n");
                printf("\n\n************************************************************\n\n");
                printf("What Would You Like to Do?\n\n");
                printf("1\tGo to Main Menu(s)\n");
                printf("2\tExit Grocery Shop Profit Calculator\n\n");
                printf("Enter Your Choice (1 or 2): ");
                scanf("%d", &userOption);
                fflush(stdin);

                if (userOption == 1)
                {
                    system("cls");
                    goto mainMenu;
                }
                else if (userOption == 2)
                    printf("Thank You for Using Grocery Shop Profit Calculator ^-^\n\n");
                else
                {
                    printf("\nInvalid input entered! Choose either 1 or 2 ONLY.");
                    goto option;
                }

            break;

        case 2:

            if (totalExpectedProfit == 0.00)
            {
                printf("\nWARNING! No prior stocks have been recorded!");
                printf("\nTotal Expected Profit: RM %.2lf\n", totalExpectedProfit);
            }
            else
                printf("Total Expected Profit: RM %.2lf\n", totalExpectedProfit);

            break;

        default:
            printf("\nInvalid input entered! Choose either 1 or 2 ONLY.");
            Sleep(1000);
            system("cls");
            goto mainMenu;
    }

    return 0;
 }

