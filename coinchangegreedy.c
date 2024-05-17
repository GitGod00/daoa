#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of coins:\n");
    scanf("%d",&n);
    printf("Enter coins:\n");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int value;
    printf("Enter Target:\n");
    scanf("%d",&value);
    int sol[n];
    int i;

    for (int i = 0; i < n; i++)
    {
        sol[i] = 0;
    }
    for (i = n - 1; i >= 0; i--)
    {
        while (arr[i] <= value)
        {
            sol[i] += 1;
            value = value - arr[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", sol[i]);
    }
   
}