
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <inttypes.h>

#define BILL_PAISE 27500LL

int main(void)
{
    const int household_counts[] = {4000, 60000, 800000};
    const int n = (int)(sizeof household_counts / sizeof household_counts[0]);

    printf("sizeof(int) = %zu, sizeof(long) = %zu, sizeof(long long) = %zu\n",
           sizeof(int), sizeof(long), sizeof(long long));

    for (int i = 0; i < n; i++) {
        int64_t exact = (int64_t)household_counts[i] * BILL_PAISE;
        double rupees = (double)household_counts[i] * 275.00;

        printf("Households: %d\n", household_counts[i]);
        printf("Exact total: %" PRId64 " paise\n", exact);
        printf("Total in rupees: %.2f\n", rupees);
    }

    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);
    printf("FLT_DIG = %d, DBL_DIG = %d\n", FLT_DIG, DBL_DIG);

    return 0;
}
