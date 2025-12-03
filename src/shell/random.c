#include "../include/random.h"

void srand(void)
{
    seed = current_seconds();
}

double rand(void)
{
    return (seed = (seed * 1103515245 + 12345) & RAND_MAX) * NORM;
}
