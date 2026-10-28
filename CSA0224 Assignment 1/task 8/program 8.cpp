
#include <stdio.h>

#define FIXED_CHARGE_PAISE 5000LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200

long long compute_bill(int units)
{
    long long energy = 0;

    if (units > SLAB2_UNITS)
        energy += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;

    if (units > SLAB1_UNITS) {
        int slab2 = units < SLAB2_UNITS
                  ? units - SLAB1_UNITS
                  : SLAB2_UNITS - SLAB1_UNITS;
        energy += (long long)slab2 * RATE2_PAISE;
    }

    return FIXED_CHARGE_PAISE + energy;
}

int main(void)
{
    int units = 150;
    long long total = compute_bill(units);

    printf("Units consumed: %d\n", units);
    printf("Total bill: Rs %lld.%02lld\n",
           total / 100, total % 100);

    return 0;
}
