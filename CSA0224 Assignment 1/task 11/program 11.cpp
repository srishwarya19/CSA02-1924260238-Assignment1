
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define FIXED_CHARGE_PAISE 5000LL
#define SLAB1_UNITS 100u
#define SLAB2_UNITS 200u
#define RATE1_PAISE 0LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL

int64_t compute_bill(uint32_t units)
{
    int64_t total = FIXED_CHARGE_PAISE;

    if (units > SLAB2_UNITS)
        total += (int64_t)(units - SLAB2_UNITS) * RATE3_PAISE;

    if (units > SLAB1_UNITS) {
        uint32_t slab2 = units < SLAB2_UNITS
                       ? units - SLAB1_UNITS
                       : SLAB2_UNITS - SLAB1_UNITS;
        total += (int64_t)slab2 * RATE2_PAISE;
    }

    if (units < SLAB1_UNITS)
        total += (int64_t)units * RATE1_PAISE;

    return total;
}

int main(void)
{
    const uint32_t units[] = {0, 100, 150, 200, 350};
    int64_t grand_total = 0;

    for (size_t i = 0; i < sizeof units / sizeof units[0]; i++) {
        int64_t bill = compute_bill(units[i]);
        grand_total += bill;

        printf("%3" PRIu32 " units: Rs %" PRId64 ".%02" PRId64 "\n",
               units[i], bill / 100, bill % 100);
    }

    printf("Five-household total: Rs %" PRId64 ".%02" PRId64 "\n",
           grand_total / 100, grand_total % 100);

    return 0;
}
