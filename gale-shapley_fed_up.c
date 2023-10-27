#include <stdio.h>

#define N 4 // Number of men or women
/*
men:
    r0  r1  r2  r3
m0  w0  w1  w2  w3
m1  w0  w3  w2  w1
m2  w1  w0  w2  w3
m3  w3  w1  w2  w0

women:
    w0  w1  w2  w3
m0  r2  r2  r1  r2
m1  r3  r0  r2  r1
m2  r1  r3  r3  r0
m3  r0  r1  r0  r3
*/
int men[N][N] = {
    {1, 0, 2, 3},
    {3, 0, 1, 2},
    {0, 2, 1, 3},
    {1, 2, 0, 3}};

int women[N][N] = {
    {0, 2, 1, 3},
    {2, 3, 0, 1},
    {3, 1, 2, 0},
    {2, 1, 0, 3}};

int womenPartner[N];
int menFree[N];

void stableMarriage()
{
    for (int i = 0; i < N; i++)
    {
        menFree[i] = 1;       // Initially all men as free.
        womenPartner[i] = -1; // Initially all women as unengaged.
    }

    int freeCount = N;         // No. of unengaged men.
    int maxIterations = N * N; // Max number of iterations

    while (freeCount > 0 && maxIterations > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (menFree[m])
            {
                break;
            }

        // Find the first free man (m) and iterate through his preferences.
        for (int i = 0; i < N && menFree[m]; i++)
        {
            int w = men[m][i]; // Get the woman m prefers at index i.
            if (womenPartner[w] == -1)
            {
                // If the woman w is unengaged, engage them.
                womenPartner[w] = m;
                menFree[m] = 0; // Mark man m as engaged.
                freeCount--;
                printf("Man %d proposes to Woman %d.\n", m, w);
            }
            else
            {
                int m1 = womenPartner[w]; // Get the current partner of w.
                if (women[w][m] < women[w][m1])
                {
                    // If woman w prefers m over m1, engage m and free m1.
                    womenPartner[w] = m;
                    menFree[m] = 0;  // Set man m as engaged.
                    menFree[m1] = 1; // Set man m1 as free.
                    printf("Man %d proposes to Woman %d, and Woman %d prefers him over her current partner Man %d.\n", m, w, w, m1);
                }
                else
                {
                    printf("Man %d proposes to Woman %d, but Woman %d prefers her current partner Man %d over %d.\n", m, w, w, m1, m);
                }
            }
        }

        maxIterations--;
    }

    if (freeCount > 0)
    {
        printf("No stable matching.\n");
    }
    else
    {
        printf("Woman\tMan\n");
        for (int i = 0; i < N; i++)
            printf(" %d\t%d\n", i, womenPartner[i]);
    }
}

int main()
{
    stableMarriage();

    return 0;
}
