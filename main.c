#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void insertSort(int a[ ], size_t length) {
    int i, j, value;
    for(i = 1; i < length; i++) {
        value = a[i];
        for (j = i - 1; (j >= 0) && (value< a[j]); j--) {
            a[j + 1] = a[j];
        }
        a[j+1] = value;
    }
}

void printArray(int arr[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int     N, M, p;
    int A[100][100];
    int B[10000];
    printf("Input length of a two-dimensional array: \n");
    printf("n = ");
    scanf("%i", &N);
    printf("m = ");
    scanf("%i", &M);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rand() % 90 + 10;
        }
    }
    p = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            B[p] = A[i][j];
            p++;
        }
    }
    insertSort(B, (N*M));
    printf("\n!Sorted array\n");
    printArray(A, N, M);

    int Ibeg = 0, Ifin = 0, Jbeg = 0, Jfin = 0;
    int k = 0;
    int i = 0;
    int j = 0;
    printf("Filling a two-dimensional matrix in a spiral");
    while (k < N * M){
        A[i][j] = B[k];
        if (i == Ibeg && j < M - Jfin - 1)
            ++j;
        else if (j == M - Jfin - 1 && i < N - Ifin - 1)
            ++i;
        else if (i == N - Ifin - 1 && j > Jbeg)
            --j;
        else
            --i;

        if ((i == Ibeg + 1) && (j == Jbeg) && (Jbeg != M - Jfin - 1)){
            ++Ibeg;
            ++Ifin;
            ++Jbeg;
            ++Jfin;
        }
        ++k;
    }
    printf("\nSorted array\n");
    printArray(A, N, M);
	getch();
    return 0;
}