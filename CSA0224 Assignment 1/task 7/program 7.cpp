
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Integer division: 5 / 2 = %d\n", 5 / 2);
    printf("Floating division: 5.0 / 2 = %.2f\n", 5.0 / 2);
    printf("Cast after division: %.2f\n", (double)(5 / 2));
    printf("Cast before division: %.2f\n", (double)5 / 2);
    printf("Float comparison: %.20f\n", 0.1f + 0.2f);
    printf("Correct paise total: %lld\n", 225LL + 450LL);

    float bill = 0.10f;
    float total = 0.0f;

    for (int i = 0; i < 4000; i++)
        total += bill;

    printf("4000 float bills: %.9f\n", total);
    printf("4000 exact paise bills: %d paise\n", 4000 * 10);

    printf("Rounded float amount: %.2f\n", roundf(total * 100.0f) / 100.0f);

    return 0;
}
