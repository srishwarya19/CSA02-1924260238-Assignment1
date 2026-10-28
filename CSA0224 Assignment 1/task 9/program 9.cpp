
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#define SLAB1_UNITS 100u
#define SLAB2_UNITS 200u
#define RATE1_PAISE 0LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

typedef uint16_t meter_t;

int64_t compute_bill(uint32_t units)
{
    int64_t energy = 0;

    if (units > SLAB2_UNITS)
        energy += (int64_t)(units - SLAB2_UNITS) * RATE3_PAISE;

    if (units > SLAB1_UNITS) {
        uint32_t n = units < SLAB2_UNITS
                   ? units - SLAB1_UNITS
                   : SLAB2_UNITS - SLAB1_UNITS;
        energy += (int64_t)n * RATE2_PAISE;
    }

    if (units < SLAB1_UNITS)
        energy += (int64_t)units * RATE1_PAISE;

    return FIXED_CHARGE_PAISE + energy;
}

uint32_t consumption(meter_t previous, meter_t current)
{
    return (uint16_t)(current - previous);
}

bool read_meter(const char *prompt, unsigned int *reading)
{
    printf("%s", prompt);

    if (scanf("%u", reading) != 1)
        return false;

    if (*reading > UINT16_MAX)
        return false;

    return true;
}

int main(void)
{
    unsigned int previous_input, current_input;
    unsigned int household;
    char category;

    printf("Household number: ");
    if (scanf("%u", &household) != 1) {
        fprintf(stderr, "Invalid household number\n");
        return 1;
    }

    printf("Category (D/A): ");
    if (scanf(" %c", &category) != 1) {
        fprintf(stderr, "Invalid category\n");
        return 1;
    }

    if (!read_meter("Previous reading: ", &previous_input) ||
        !read_meter("Current reading: ", &current_input)) {
        fprintf(stderr, "Invalid meter reading\n");
        return 1;
    }

    meter_t previous = (meter_t)previous_input;
    meter_t current = (meter_t)current_input;

    uint32_t units = consumption(previous, current);
    int64_t total = compute_bill(units);

    printf("\nHousehold: %u\n", household);
    printf("Category: %c\n", category);
    printf("Previous: %u\n", (unsigned)previous);
    printf("Current: %u\n", (unsigned)current);
    printf("Units: %" PRIu32 "\n", units);
    printf("Bill: Rs %" PRId64 ".%02" PRId64 "\n",
           total / 100, total % 100);

    return 0;
}
