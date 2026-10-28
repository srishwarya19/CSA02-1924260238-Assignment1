
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define SLAB1_UNITS 100u
#define SLAB2_UNITS 200u
#define RATE1_PAISE 0LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

typedef uint16_t meter_t;

typedef struct {
    unsigned int household_no;
    char category;
    meter_t previous;
    meter_t current;
    uint32_t units;
    int64_t energy_charge_paise;
    int64_t fixed_charge_paise;
    int64_t total_paise;
} Bill;

uint32_t consumption(meter_t previous, meter_t current)
{
    return (uint16_t)(current - previous);
}

int64_t compute_energy_charge(uint32_t units)
{
    int64_t charge = 0;

    if (units > SLAB2_UNITS)
        charge += (int64_t)(units - SLAB2_UNITS) * RATE3_PAISE;

    if (units > SLAB1_UNITS) {
        uint32_t slab2 = units < SLAB2_UNITS
                       ? units - SLAB1_UNITS
                       : SLAB2_UNITS - SLAB1_UNITS;
        charge += (int64_t)slab2 * RATE2_PAISE;
    }

    if (units < SLAB1_UNITS)
        charge += (int64_t)units * RATE1_PAISE;

    return charge;
}

void print_money(int64_t paise)
{
    printf("Rs %" PRId64 ".%02" PRId64 "\n",
           paise / 100, paise % 100);
}

int main(void)
{
    Bill b = {1001, 'D', 1200, 1530, 0, 0, 0, 0};

    b.units = consumption(b.previous, b.current);
    b.energy_charge_paise = compute_energy_charge(b.units);
    b.fixed_charge_paise = FIXED_CHARGE_PAISE;
    b.total_paise = b.energy_charge_paise + b.fixed_charge_paise;

    printf("Household: %u\n", b.household_no);
    printf("Category: %c\n", b.category);
    printf("Units: %" PRIu32 "\n", b.units);
    printf("Energy charge: ");
    print_money(b.energy_charge_paise);
    printf("Fixed charge: ");
    print_money(b.fixed_charge_paise);
    printf("Total bill: ");
    print_money(b.total_paise);

    return 0;
}
