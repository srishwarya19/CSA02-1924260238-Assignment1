
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    unsigned int household;
    unsigned int previous, current;
    char category;

    printf("Enter household number, category, previous reading, current reading: ");

    if (scanf("%u %c %u %u",
              &household, &category, &previous, &current) != 4) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (previous > 65535 || current > 65535) {
        fprintf(stderr, "Meter readings must be between 0 and 65535\n");
        return 1;
    }

    uint16_t p = (uint16_t)previous;
    uint16_t c = (uint16_t)current;
    uint32_t units = (uint16_t)(c - p);

    printf("Household: %u\n", household);
    printf("Category: %c\n", category);
    printf("Units consumed: %" PRIu32 "\n", units);

    return 0;
}
