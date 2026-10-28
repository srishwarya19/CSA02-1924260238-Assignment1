
#include <stdio.h>

#define RUPEES_TO_PAISE(r) ((long long)(r) * 100LL)
#define SQUARE(x) ((x) * (x))
#define MAX_VALUE(a, b) ((a) > (b) ? (a) : (b))

static inline long long square_value(long long x)
{
    return x * x;
}

static inline int max_value(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int a = 4;
    int b = 7;

    printf("Square of a+1: %d\n", SQUARE(a + 1));
    printf("Maximum: %d\n", MAX_VALUE(a, b));
    printf("Five rupees in paise: %lld\n", RUPEES_TO_PAISE(5));
    printf("Inline square: %lld\n", square_value(a + 1));
    printf("Inline maximum: %d\n", max_value(a, b));

    return 0;
}
