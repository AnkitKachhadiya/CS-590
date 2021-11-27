#include <cstring>
#include <iostream>
#include <limits.h>
#include <algorithm>

#include "dynprog.h"

using namespace std;

/*
 * Bottom up implementation of Smith-Waterman algorithm
 */
void SW_bottomUp(char *X, char *Y, char **P, int **H, int n, int m)
{
    int p1, p2, p3;

    for (int i = 0; i <= n; i++)
    {
        H[i][0] = P[i][0] = 0;
    }

    for (int j = 0; j <= m; j++)
    {
        H[0][j] = P[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {
            if (X[i] == Y[j])
            {
                p1 = H[i - 1][j - 1] + 2;
            }
            else
            {
                p1 = H[i - 1][j - 1] - 1;
            }

            p2 = H[i - 1][j] - 1;
            p3 = H[i][j - 1] - 1;

            H[i][j] = max({p1, p2, p3});

            if (H[i][j] == p1)
            {
                // 'd' <=> ↖
                P[i][j] = 'd';
            }
            else
            {
                if (H[i][j] == p2)
                {
                    // 'u' <=> ↑
                    P[i][j] = 'u';
                }
                else
                {
                    // 'l' <=> ←
                    P[i][j] = 'l';
                }
            }
        }
    }
}

/*
 * Top-down with memoization implementation of Smith-Waterman algorithm
 */
void memoized_SW(char *X, char *Y, char **P, int **H, int n, int m)
{
}

/*
 * Auxilary recursive function of top-down with memoization implementation of Smith-Waterman algorithm
 */
void memoized_SW_AUX(char *X, char *Y, char **P, int **H, int n, int m)
{
}

/*
 * Print X'
 */
void print_Seq_Align_X(char *X, char **P, int n, int m)
{
}

/*
 * Print Y'
 */
void print_Seq_Align_Y(char *Y, char **P, int n, int m)
{
}
