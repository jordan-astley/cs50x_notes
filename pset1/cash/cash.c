#include <cs50.h>
#include <stdio.h>

// greedy algorithm

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    printf("quarters %i\n", quarters);
    // printf("cents %i\n", cents);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    printf("dimes %i\n", dimes);

    // // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    printf("nickels %i\n", nickels);

    // // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    printf("pennies %i\n", pennies);

    // // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("enter number of cents: ");
    }
    while (cents < 1);

    return cents;
}

int calculate_quarters(int cents)
{
    int quarters;
    const int QUARTER = 25; // hardcoded value of a quarter
    quarters = cents / QUARTER;

    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes;
    const int DIME = 10;
    dimes = cents / DIME;

    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels;
    const int NICKEL = 5;
    nickels = cents / NICKEL;

    return nickels;
}

int calculate_pennies(int cents)
{
    return cents; // this is by definition of pennies?
}
