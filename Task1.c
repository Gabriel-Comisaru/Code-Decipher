#include "utils.h"
#define inf 50
#define pw 10
void SolveTask1() {
    // TODO(gabriel.comisaru)
    int N = 0, M = 0, i = 0, j = 0, k = 0, savek = 0, n = 0, m = 0,
    max = 0, poz = 0, count = 2, nr = 2, S = 0, n1 = 0;
    char O[inf] = " ";
    scanf("%d", &N);
    scanf("%d", &M);
    int matrix[inf][inf] = {0};
    while (scanf("%s", &O) == 1) {
        if (O[0] == 'a') {
            for (j = 1; j <= 4; j++)
                if (O[j] >= max)
                    max = O[j];
            if (max == O[1])
                poz = 1;
            if (max == O[2])
                poz = 2;
            if (max == O[3])
                poz = 3;
            if (max == O[4])
                poz = 4;
            matrix[0][0] = 1;
            switch (poz) {
                case 1:
                    matrix[n][m+1] = nr;
                    m++;
                    break;
                case 2:
                    matrix[n-1][m] = nr;
                    n--;
                    break;
                case 3:
                    matrix[n][m-1] = nr;
                    m--;
                    break;
                case 4:
                    matrix[n+1][m] = nr;
                    n++;
                    break;
                default:
                    printf("eroare");
            }
            max = 0;
            poz = 0;
            nr++;
        }
        int K = 0, ysave = 0, palindrom = 0, y = 0, X = 0,
        countsave = 0, flag = 0;
        if (O[0] == 'b') {
            count = 0;
            for (i = 1; i <= inf; i++) {
                if (O[i] == '\0' || O[i] == ' ')
                    break;
                count++;
            }
            countsave = count;
            for (i = 1; i <= countsave; i++) {
                y = y + (O[i] - '0') * (pow(pw, count-1));
                count--;
            }
            K = y;
            while (y != 0) {
                ysave = y % pw;
                palindrom = palindrom * pw + ysave;
                y /= pw;
            }
            X = (O[countsave-1] - '0') * pw + (O[countsave] - '0');
            for (i = 2; i <= X/2; ++i)
                if (X % i == 0) {
                    flag = 1;
                    break;
                }
            if (K == palindrom && flag == 0) {
                matrix[n][m-1] = nr;
                m--;
            }
            if (K == palindrom && flag != 0) {
                matrix[n][m+1] = nr;
                m++;
            }
            if (K != palindrom && flag == 0) {
                matrix[n-1][m] = nr;
                n--;
            }
            if (K != palindrom && flag != 0) {
                matrix[n+1][m] = nr;
                n++;
            }
            nr++;
        }
        if (O[0] == 'c') {
            count = 0;
            n1 = O[1] - '0';
            k = O[2] - '0';
            savek = k;
            for (i = 0; k > 0; i = i + savek) {
                S = S + (O[(i%n1)+3] - '0');
                k--;
            }
            if ((S % 4) == 0) {
                matrix[n][m-1] = nr;
                m--;
            }
            if ((S % 4) == 1) {
                matrix[n-1][m] = nr;
                n--;
            }
            if ((S % 4) == 2) {
                matrix[n][m+1] = nr;
                m++;
            }
            if ((S % 4) == 3) {
                matrix[n+1][m] = nr;
                n++;
            }
            nr++;
        }
        n1 = 0; k = 0; savek = 0; S = 0; count = 0; poz++;
    }
    matrix[0][0] = 1;
    for (n = 0; n < N; n++) {
        for (m = 0; m < M; m++)
            printf("%d ", matrix[n][m]);
        printf("\n");
    }
}
