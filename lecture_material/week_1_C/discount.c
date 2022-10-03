# include <cs50.h>
# include <stdio.h>

float discount (float price, int percentageOff);

int main(void)
{
    float regularPrice = get_float("Regular Price: £");
    int percentageOff = get_int("Percentage deduction: ");
    float sale = discount(regularPrice, percentageOff);
    printf("Sale price: £%.2f\n", sale); // %.2f float 2 d.p
}

// function to do discount
float discount(float regularPrice, int percentageOff)
{
    return regularPrice * (100 - percentageOff)/100;
    // e.g. 15% reduction price*0.85
}