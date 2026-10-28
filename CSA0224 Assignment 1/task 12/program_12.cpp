
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define PEAK_START 18
#define PEAK_END 22

int main(void)
{
    uint64_t watt_hours;
    int hour;
    int64_t rate_paise, fixed_paise = 5000;
    int64_t energy_paise;

    FILE *f = fopen("tariff.txt", "r");

    if (f == NULL) {
        printf("Cannot open tariff.txt\n");
        return 1;
    }

    if (fscanf(f, "%" SCNd64, &rate_paise) != 1 ||
        rate_paise < 0) {
        fclose(f);
        printf("Invalid tariff\n");
        return 1;
    }
    fclose(f);

    printf("Enter energy consumed (Wh): ");
    if (scanf("%" SCNu64, &watt_hours) != 1)
        return 1;

    printf("Enter hour (0-23): ");
    if (scanf("%d", &hour) != 1 || hour < 0 || hour > 23)
        return 1;

    /* Convert Wh to kWh and calculate charge in paise. */
    uint64_t numerator = watt_hours * (uint64_t)rate_paise;

    if (hour >= PEAK_START && hour < PEAK_END)
        numerator = numerator * 120 / 100;

    energy_paise = (int64_t)((numerator + 500) / 1000);

    printf("Energy consumed: %" PRIu64 " Wh\n", watt_hours);
    printf("Energy charge: Rs %" PRId64 ".%02" PRId64 "\n",
           energy_paise / 100, energy_paise % 100);
    printf("Fixed charge: Rs 50.00\n");
    printf("Total bill: Rs %" PRId64 ".%02" PRId64 "\n",
           (energy_paise + fixed_paise) / 100,
           (energy_paise + fixed_paise) % 100);

    return 0;
}
