#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double time_spentv, time_spentd;
// int n1 = 0, m1 = 0;
// int n2 = 0, m2 = 0;
// int a[100][100], b[100][100], c[100][100];

void inputmatrix(int n, int A[n][n])
{
    printf("Enter the elements of the matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the %d, %d element:", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
}

void add(int n, int result[n][n], int A[n][n], int B[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int result[n][n], int A[n][n], int B[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
}

void copy(int dest_count, int dest[dest_count][dest_count], int source_count,
          int source[][source_count], int row_source, int row_end, int col_source, int col_end) {

    for (int i = row_source, k = 0; k < dest_count; i++, k++)
        for (int j = col_source, l = 0; l < dest_count; j++, l++)
            dest[k][l] = source[i][j];
}

void copy_partition(int dest_count, int dest[][dest_count], int row_start,
                    int row_end, int column_start, int column_end, int source_count,
                    int source[][source_count]) {

    for (int i = 0, k = row_start; k <= row_end; i++, k++)
        for (int j = 0, l = column_start; l <= column_end; j++, l++)
            dest[k][l] = source[i][j];
}

void daqmatmul(int n, int result[n][n], int A[n][n], int B[n][n]) {
    if (n == 1) {
        result[0][0] = A[0][0] * B[0][0];
    } else { 

        // Matrices for the partitions
        int A11[n / 2][n / 2];
        int A12[n / 2][n / 2];
        int A21[n / 2][n / 2];
        int A22[n / 2][n / 2];

        int B11[n / 2][n / 2];
        int B12[n / 2][n / 2];
        int B21[n / 2][n / 2];
        int B22[n / 2][n / 2];

        // Partition A

        copy(n / 2, A11, n, A, 0, (n / 2) - 1, 0, (n / 2) - 1);
        copy(n / 2, A12, n, A, 0, (n / 2) - 1, n / 2, n - 1);
        copy(n / 2, A21, n, A, n / 2, n - 1, 0, (n / 2) - 1);
        copy(n / 2, A22, n, A, n / 2, n - 1, n / 2, n - 1);

        // Partition B

        copy(n / 2, B11, n, B, 0, (n / 2) - 1, 0, (n / 2) - 1);
        copy(n / 2, B12, n, B, 0, (n / 2) - 1, n / 2, n - 1);
        copy(n / 2, B21, n, B, n / 2, n - 1, 0, (n / 2) - 1);
        copy(n / 2, B22, n, B, n / 2, n - 1, n / 2, n - 1);

        // block multiplication and addition

        int A11_B11[n / 2][n / 2];
        int A12_B21[n / 2][n / 2];
        int A11_B12[n / 2][n / 2];
        int A12_B22[n / 2][n / 2];
        int A21_B11[n / 2][n / 2];
        int A22_B21[n / 2][n / 2];
        int A21_B12[n / 2][n / 2];
        int A22_B22[n / 2][n / 2];

        daqmatmul(n / 2, A11_B11, A11, B11);
        daqmatmul(n / 2, A12_B21, A12, B21);
        daqmatmul(n / 2, A11_B12, A11, B12);
        daqmatmul(n / 2, A12_B22, A12, B22);
        daqmatmul(n / 2, A21_B11, A21, B11);
        daqmatmul(n / 2, A22_B21, A22, B21);
        daqmatmul(n / 2, A21_B12, A21, B12);
        daqmatmul(n / 2, A22_B22, A22, B22);

        int C11[n / 2][n / 2];
        int C12[n / 2][n / 2];
        int C21[n / 2][n / 2];
        int C22[n / 2][n / 2];

        add(n / 2, C11, A11_B11, A12_B21);
        add(n / 2, C12, A11_B12, A12_B22);
        add(n / 2, C21, A21_B11, A22_B21);
        add(n / 2, C22, A21_B12, A22_B22);

        // joining blocks

        copy_partition(n, result, 0, (n / 2) - 1, 0, (n / 2) - 1, (n / 2), C11);
        copy_partition(n, result, 0, (n / 2) - 1, n / 2, n - 1, (n / 2), C12);
        copy_partition(n, result, n / 2, n - 1, 0, (n / 2) - 1, (n / 2), C21);
        copy_partition(n, result, n / 2, n - 1, n / 2, n - 1, (n / 2), C22);
    }
}

void vsqmatmul(int n, int result[n][n], int A[n][n], int B[n][n])
{
    // clock_t start = clock();

    if (n == 1)
    {
        result[0][0] = A[0][0] * B[0][0];
    }
    else
    {

        // Matrices for the partitions
        int A11[n / 2][n / 2];
        int A12[n / 2][n / 2];
        int A21[n / 2][n / 2];
        int A22[n / 2][n / 2];

        int B11[n / 2][n / 2];
        int B12[n / 2][n / 2];
        int B21[n / 2][n / 2];
        int B22[n / 2][n / 2];

        // Partition A

        copy(n / 2, A11, n, A, 0, (n / 2) - 1, 0, (n / 2) - 1);
        copy(n / 2, A12, n, A, 0, (n / 2) - 1, n / 2, n - 1);
        copy(n / 2, A21, n, A, n / 2, n - 1, 0, (n / 2) - 1);
        copy(n / 2, A22, n, A, n / 2, n - 1, n / 2, n - 1);

        // Partition B

        copy(n / 2, B11, n, B, 0, (n / 2) - 1, 0, (n / 2) - 1);
        copy(n / 2, B12, n, B, 0, (n / 2) - 1, n / 2, n - 1);
        copy(n / 2, B21, n, B, n / 2, n - 1, 0, (n / 2) - 1);
        copy(n / 2, B22, n, B, n / 2, n - 1, n / 2, n - 1);

        // conquer for Strassen's algorithm
        int S1[n / 2][n / 2];
        int S2[n / 2][n / 2];
        int S3[n / 2][n / 2];
        int S4[n / 2][n / 2];
        int S5[n / 2][n / 2];
        int S6[n / 2][n / 2];
        int S7[n / 2][n / 2];
        int S8[n / 2][n / 2];
        int S9[n / 2][n / 2];
        int S10[n / 2][n / 2];

        subtract(n / 2, S1, B12, B22); // S1 = B12 - B22
        add(n / 2, S2, A11, A12);      // S2 = A11 + A12
        add(n / 2, S3, A21, A22);      // S3 = A21 + A22
        subtract(n / 2, S4, B21, B11); // S4 = B21 - B11
        add(n / 2, S5, A11, A22);      // S5 = A11 + A22
        add(n / 2, S6, B11, B22);      // S6 = B11 + B22
        subtract(n / 2, S7, A12, A22); // S7 = A12 - A22
        add(n / 2, S8, B21, B22);      // S8 = B21 + B22
        subtract(n / 2, S9, A11, A21); // S9 = A11 - A21
        add(n / 2, S10, B11, B12);     // S10 = B11 + B12

        int P1[n / 2][n / 2];
        int P2[n / 2][n / 2];
        int P3[n / 2][n / 2];
        int P4[n / 2][n / 2];
        int P5[n / 2][n / 2];
        int P6[n / 2][n / 2];
        int P7[n / 2][n / 2];

        vsqmatmul(n / 2, P1, A11, S1); // P1 = A11 * S1
        vsqmatmul(n / 2, P2, S2, B22); // P2 = S2 * B22
        vsqmatmul(n / 2, P3, S3, B11); // P3 = S3 * B11
        vsqmatmul(n / 2, P4, A22, S4); // P4 = A22 * S4
        vsqmatmul(n / 2, P5, S5, S6);  // P5 = S5 * S6
        vsqmatmul(n / 2, P6, S7, S8);  // P6 = S7 * S8
        vsqmatmul(n / 2, P7, S9, S10); // P7 = S9 * S10

        int C11[n / 2][n / 2];
        int C12[n / 2][n / 2];
        int C21[n / 2][n / 2];
        int C22[n / 2][n / 2];

        int C11_Temp1[n / 2][n / 2];
        int C11_Temp2[n / 2][n / 2];
        int C22_Temp1[n / 2][n / 2];
        int C22_Temp2[n / 2][n / 2];

        add(n / 2, C11_Temp1, P5, P4);
        subtract(n / 2, C11_Temp2, C11_Temp1, P2);
        add(n / 2, C11, C11_Temp2, P6);
        add(n / 2, C12, P1, P2);
        add(n / 2, C21, P3, P4);
        add(n / 2, C22_Temp1, P5, P1);
        subtract(n / 2, C22_Temp2, C22_Temp1, P3);
        subtract(n / 2, C22, C22_Temp2, P7);

        // joining blocks

        copy_partition(n, result, 0, (n / 2) - 1, 0, (n / 2) - 1, (n / 2), C11);
        copy_partition(n, result, 0, (n / 2) - 1, n / 2, n - 1, (n / 2), C12);
        copy_partition(n, result, n / 2, n - 1, 0, (n / 2) - 1, (n / 2), C21);
        copy_partition(n, result, n / 2, n - 1, n / 2, n - 1, (n / 2), C22);
    }
    // clock_t end = clock();
    // time_spentv = (double)((end - start) * 1000.0 / CLOCKS_PER_SEC);
    // printf("Time: %lf", time_spentv);
}

void display_matrix(int n, int out[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", out[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    int A[n][n];
    int B[n][n];
    int C_DAC[n][n];    // Divide and Conquer's result
    int C_SMM[n][n];    // Strassen's result
    int x;
    int ch = 1;
    while (ch < 5)
    {
        printf("+---------------------------------------------------------+\n");
        printf("\t\t\tMENU\n");
        printf("+---------------------------------------------------------+\n");
        printf("Enter 1 for inputing matrix 1 and 2.\n");
        printf("Enter 2 to display matrix.\n");
        printf("Enter 3 for divide and conquer approach.\n");
        printf("Enter 4 for Volker strassen\'s approach.\n");
        printf("+---------------------------------------------------------+\n");

        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            puts("\nMatrix 1:");
            inputmatrix(n, A);
            puts("\nMatrix 2:");
            inputmatrix(n, B);
            break;
        case 2:
            printf("+-------------------------------+\n");
            printf(" Enter 1 to diplay matrix A\n Enter 2 to display matrix B\n Enter 3 to display matrix C: ");
            scanf("%d", &x);
            if(x == 1)
                display_matrix(n, A);
            else if(x == 2)
                display_matrix(n, B);
            else if(x == 3){
                puts("Divide and conquer: \n");
                display_matrix(n, C_DAC);
                puts("Volker and strassen: \n");
                display_matrix(n, C_SMM);
            }
            break;
        case 3:
            daqmatmul(n, C_DAC,A,B);
            break;
        case 4:
            vsqmatmul(n, C_SMM, A, B);
            break;
        }
    }
    return 0;
}