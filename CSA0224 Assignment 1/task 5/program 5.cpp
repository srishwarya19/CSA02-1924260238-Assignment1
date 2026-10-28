
#include <stdio.h>

/* Constants normally stored in billing.h */
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

/* Function prototype */
long long compute_bill(int units);

/* Billing function */
long long compute_bill(int units)
{
    long long energy = 0;

    if (units > SLAB2_UNITS)
        energy += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;

    if (units > SLAB1_UNITS) {
        int n = units < SLAB2_UNITS
              ? units - SLAB1_UNITS
              : SLAB2_UNITS - SLAB1_UNITS;

        energy += (long long)n * RATE2_PAISE;
    }

    if (units < SLAB1_UNITS)
        energy += (long long)units * RATE1_PAISE;

#ifdef DEBUG
    printf("DEBUG: units=%d energy=%lld paise\n", units, energy);
#endif

    return FIXED_CHARGE_PAISE + energy;
}

/* Main function */
int main(void)
{
    int units;

    printf("Enter units consumed: ");

    if (scanf("%d", &units) != 1 || units < 0) {
        printf("Invalid units\n");
        return 1;
    }

    long long total = compute_bill(units);

    printf("Bill: Rs %lld.%02lld\n", total / 100, total % 100);

    return 0;
}
