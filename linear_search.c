#include <stdio.h>

int main()
{
    int DATA[10] = {22, 65, 1, 99, 32, 17, 74, 49, 33, 2};
    int ITEM = 17;
    int N = 10;
    int LOC = -1;
    int K = 0;

    while (LOC == -1 && K < N)
    {
        if (ITEM == DATA[K])
        {
            LOC = K;
        }

        K++;
    }

    if (LOC == -1)
    {
        printf("ITEM is not in the array DATA.");
    }
    else
    {
        printf("%d is the location of ITEM.", LOC);
    }

    return 0;
}