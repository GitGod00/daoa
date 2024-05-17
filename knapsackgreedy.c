#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(double a[], double b[])
{
    double temp[4];
    memcpy(temp, a, sizeof(double) * 4);
    memcpy(a, b, sizeof(double) * 4);
    memcpy(b, temp, sizeof(double) * 4);
}

int main()
{
    int n;
    int weight;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double (*arr)[4] = malloc(n * sizeof(double[4]));
    float sol[n];
    char solc[n];

    printf("Enter the elements (profit weight 0 index):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%lf %lf %lf %lf", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
        arr[i][3] = i; // Store the original index
    }

    printf("Enter the maximum weight: ");
    scanf("%d", &weight);

    for (int i = 0; i < n; i++)
    {
        solc[i] = 'x';
        sol[i] = 1.0;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i][2] = arr[i][0] / arr[i][1]; // Calculate profit/weight ratio
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][2] < arr[j][2])
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    float profit = 0.0;
    float frac = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] <= weight)
        {
            sol[i] = 1.0;
            solc[i] = (char)((int)arr[i][3] + 65);
            profit = profit + arr[i][0];
            weight = weight - arr[i][1];
        }
        else
        {
            frac = (float)weight / arr[i][1];
            sol[i] = frac;
            solc[i] = (char)((int)arr[i][3] + 65);
            profit = profit + arr[i][0] * frac;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("[%c %.2f] ", solc[i], sol[i]);
    }
    printf("\nProfit: %.2f\n", profit);

    free(arr);
    return 0;
}
