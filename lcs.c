#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100


void lcs(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;


    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }


    int index = L[m][n]; 
    char lcs[index + 1]; 
    lcs[index] = '\0';


    i = m, j = n;
    while (i > 0 && j > 0) {

        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; 
            i--, j--, index--;
        }

        else if (L[i - 1][j] > L[i][j - 1])
            i--; 
        else
            j--; 
    }

 
    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[MAX_LENGTH], Y[MAX_LENGTH];
    printf("Enter the first sequence: ");
    scanf("%s", X);
    printf("Enter the second sequence: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);


    lcs(X, Y, m, n);

    return 0;
}