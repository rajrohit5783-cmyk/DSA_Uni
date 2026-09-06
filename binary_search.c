#include <stdio.h>

int main()
{
    int DATA[] = {11, 22, 30, 39, 44, 55, 60, 66, 77, 80, 88, 99};
    int ITEM;
    int BEG, END, MID, LOC;

    printf("Enter the item to search: ");
    scanf("%d", &ITEM);

    BEG = 0;
    END = 11;
    LOC = -1;

    while (BEG <= END)
    {
        MID = (BEG + END) / 2;

        if (ITEM == DATA[MID])
        {
            LOC = MID;
            break;
        }
        else if (ITEM < DATA[MID])
        {
            END = MID - 1;
        }
        else
        {
            BEG = MID + 1;
        }
    }

    if (LOC != -1)
        printf("Item found at position %d\n", LOC + 1);
    else
        printf("Item not found\n");

    return 0;
}