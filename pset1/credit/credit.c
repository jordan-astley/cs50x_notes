#include <cs50.h>
#include <stdio.h>

// Implementation example of Luhn's algorithm
// Determining if a credit card number is syntactically valid

//////function declarations///////
int check_sum(long cardNum);
int get_product(long segment, long modVal);
int get_sumVal(long segment, long modVal);
int break_digits_up(int product);
int sum_of_everyother_digit_doubled(long cardNum);
int sum_of_not_doubled(long cardNum);
void determine_provider(long cardNum);
void compare_final_digits_print_provider(int finalDigit, int penultimateDigit, int count);
int count_digits(long cardNum);
/////////////////////////////////

int main(void)
{
    long cardNum = 0;
    cardNum = get_long("enter your card number: "); // get long rejects hyphens and more
    int checksum = 0;

    checksum = check_sum(cardNum);

    if (checksum == 0)
    {
        printf("INVALID\n");
    }
    else if (checksum == 1)
    {
        // printf("VALID\n");
        determine_provider(cardNum); // determine card provider and print it
    }
    else
    {
        printf("error in checksum calc\n");
    }
}

////////////////////////////////other functions//////////////////////////////////////

// gets the result of the checksum and returns a boolean result for pass or fail
int check_sum(long cardNum) // returns 1 if valid, 0 if not.
{
    int sum1 = 0, sum2 = 0, sum = 0;
    sum1 = sum_of_everyother_digit_doubled(cardNum);
    sum2 = sum_of_not_doubled(cardNum);
    sum = sum1 + sum2;

    // check what final digit of sum is using % 10
    // needs to be zero for passing checksum
    if (sum % 10 == 0)
    {
        // printf("%i\n", sum);
        return 1;
    }
    else
    {
        // printf("%i\n", sum);
        return 0;
    }
}

// Function to multiply every other digit by 2, starting with
// second to last digit. Then sums the products and returns sum1
int sum_of_everyother_digit_doubled(long cardNum)
{
    long modVal = 1;
    int sum1 = 0;
    int product = 0;

    for (;;)
    {
        modVal *= 10; // incr by 1 digit to check for final digit
        long segment = cardNum % modVal;

        if (segment == cardNum) // reached final val, or gone past it
        {
            break;
        }
        else
        {
            modVal *= 10; // not final digit, get everyother digit
            segment = cardNum % modVal;
            product = get_product(segment, modVal);

            if (product > 9) // check if double digits
            {
                int add2sum = break_digits_up(product);
                sum1 += add2sum;
            }
            else
            {
                sum1 += product;
            }
        }
    }
    // printf("sum 1 = %i\n", sum1);
    return sum1;
}

// Function to sum remaining digits that were not multiplied by 2
int sum_of_not_doubled(long cardNum)
{
    long modVal = 1;
    int sum2 = 0;
    int digit = 0;

    for (;;) // execute until reaching break conditions
    {
        long segment = cardNum % modVal;

        if (segment == cardNum) // reached final card digit
        {
            break;
        }
        else
        {
            modVal *= 10;
            segment = cardNum % modVal;
            digit = get_sumVal(segment, modVal);
            sum2 += digit;
            // printf("digit = %i, modval = %li\n", digit, modVal);
        }
        modVal *= 10; // incr modVal for everyother digit
    }
    // printf("sum 2 = %i\n", sum2);
    return sum2;
}


// takes segment and modVal to get product
int get_product(long segment, long modVal)
{
    int product = 0;
    int digit = 0;

    digit = segment / (modVal / 10);
    product = digit * 2;

    return product;
}

int get_sumVal(long segment, long modVal)
{
    int digit = segment / (modVal / 10);
    return digit;
}

// finds the val to add to the sum if product > 10
int break_digits_up(int product)
{
    // highest value a digit can be is 9
    // 9*2 = 18 so two digits to break up
    int n = 0;
    int addToSum = 0;
    n = product % 10;
    addToSum += n;
    n = (product % 100) / 10;
    addToSum += n;

    return addToSum;
}



void determine_provider(long cardNum)
{
    long modVal = 10;
    long segment = 0;
    int penultimateDigit = 0, finalDigit = 0;
    int count = 0;

    for (;;)
    {
        segment = cardNum % modVal;
        // printf("segment = %li, modval = %li\n", segment, modVal);

        if (segment == cardNum) // reached the final value
        {
            finalDigit = get_sumVal(segment, modVal);

            segment = cardNum % (modVal / 10); // step back 1 digit, reset segment
            penultimateDigit = get_sumVal(segment, modVal / 10);

            count = count_digits(cardNum);
            compare_final_digits_print_provider(finalDigit, penultimateDigit, count);
            break;
        }
        else
        {
            modVal *= 10; // going through every single digit
        }
    }
}

void compare_final_digits_print_provider(int finalDigit, int penultimateDigit, int count)
{
    // AMEX starts with 34 or 37
    // MASTERCARD starts with 51,52,53,54,55
    // VISA starts with 4

    if (finalDigit == 4 && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else if (finalDigit == 3 && (count == 15))
    {
        if (penultimateDigit == 4 || penultimateDigit == 7)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (finalDigit == 5 && (count == 16))
    {
        if (penultimateDigit > 0 && penultimateDigit < 6)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int count_digits(long cardNum)
{
    //used to determine if the card number is valid
    int count = 0;
    while (cardNum > 0)
    {
        cardNum /= 10;
        count++;
    }
    return count;
}