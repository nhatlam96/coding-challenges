/*
	u01a
*/

#include <stdio.h>

int main()
{
    //printf("Hello world\n");
    for (int i = 0; i < 31; i++)
    {
        //printf("Die Z�hlvariable hat den Wert: %i\n", i);
        if (i % 3 == 0)
            printf("Die Zahl %i ist durch 3 teilbar.\n", i);

        if (i % 2 == 0)
            printf("Die %i ist eine gerade Zahl.\n", i);
        else
            printf("Die %i ist eine ungerade Zahl.\n", i);

    }
    return 0;
}
