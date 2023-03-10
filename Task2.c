#include "utils.h"
#define inf 1000
#define max 10
#define ascii0 48
#define alphaloop 26
#define asciiA 65
#define asciiZ 90
#define asciia 97
#define asciiz 122
int getcharval(const char *s, int idx) {
    if (idx < strlen(s))
        return s[strlen(s) - idx - 1] - ascii0;
    return 0;
}
void SolveTask2() {
    // TODO(gabriel.comisaru)
    char cifru[max] = " ", S[inf] = " ";
    scanf("%s", &cifru);
    if (strcmp(cifru, "caesar") == 0) {
        int K = 0, i = 0;
        scanf("%d", &K);
        scanf("%s", &S);
        while (S[i] != '\0' && S[i] != ' ') {
            if (isdigit(S[i])) {
                if ((S[i] - '0') < (K % max))
                    S[i] = (max + ((S[i]- '0') - (K % max))) + '0';
                else
                    S[i] = ((S[i] - '0') - (K % max)) + '0';
            }
            if (isalpha(S[i])) {
                if (S[i] >= 'A' && S[i] <= 'Z') {
                    if (((int)S[i] % asciiA) < (K % alphaloop))
                        S[i] = (asciiZ + ((int)S[i] % (asciiA - 1) -
                        (K % alphaloop)));
                    else
                        S[i] = ((int)S[i]  - (K % alphaloop));
                }
                if (S[i] >= 'a' && S[i] <= 'z') {
                    if (((int)S[i] % asciia) < (K % alphaloop))
                        S[i] = (asciiz + ((int)S[i] % (asciia - 1) -
                        (K % alphaloop)));
                    else
                        S[i] = ((int)S[i]  - (K % alphaloop));
                }
            }
            i++;
        }
        printf("%s\n", S);
    } else if (strcmp(cifru, "vigenere") == 0) {
        char K[max] = " ";
        int i = 0, size = 0;
        scanf("%s", &K);
        scanf("%s", &S);
        size = strlen(K);
        for (i = 0 ; i < inf; i++) {
            if (isdigit(S[i])) {
                if ((S[i] - '0') < ((((int)K[i%size]) % asciiA) % max)) {
                    if (((int)K[i%size] % asciiA) % max == 0)
                        S[i] = S[i];
                    else
                        S[i] = (max + ((S[i] - '0') -
                        (((int)K[i%size] % asciiA) % max))) + '0';
                } else {
                    if (((int)K[i%size] % asciiA) % max == 0)
                        S[i] = S[i];
                    else
                        S[i] = ((S[i] - '0') -
                        (((int)K[i%size] % asciiA) % max)) + '0';
                }
            }
            if (isalpha(S[i])) {
                if (S[i] >= 'A' && S[i] <= 'Z') {
                    if ((int)S[i] < (int)K[i%size])
                        S[i] = (asciiZ + (((int)S[i] % (asciiA - 1)) -
                        ((int)K[i%size] % asciiA)));
                    else
                        S[i] = (int)S[i] - ((int)K[i%size] % asciiA);
                }
                if (S[i] >= 'a' && S[i] <= 'z') {
                    if ((int)S[i] % asciia < (int)K[i%size] % asciiA)
                        S[i] = (asciiz + (((int)S[i] % (asciia - 1)) -
                        ((int)K[i%size] % asciiA)));
                    else
                        S[i] = (int)S[i] - (int)K[i%size] % asciiA;
                }
            }
        }
        printf("%s\n", S);
    } else if (strcmp(cifru, "addition") == 0) {
        int i = 0, K = 0;
        char N1[inf] = " ", N2[inf] = " ";
        scanf("%d", &K);
        scanf("%s", &N1);
        scanf("%s", &N2);
        int size_N1 = strlen(N1), size_N2 = strlen(N2),
        size = 0, sum = 0, carry = 0;
        size = size_N1 > size_N2 ? size_N1 : size_N2;
        for (i = 0; i < size_N1; i++) {
                if ((N1[i] - '0') < (K % max))
                    N1[i] = (max + ((N1[i]- '0') - (K % max))) + '0';
                else
                    N1[i] = ((N1[i] - '0') - (K % max)) + '0';
        }
        for (i = 0; i < size_N2; i++) {
                if ((N2[i] - '0') < (K % max))
                    N2[i] = (max + ((N2[i]- '0') - (K % max))) + '0';
                else
                    N2[i] = ((N2[i] - '0') - (K % max)) + '0';
        }
        for (i = 0; i < size; i++) {
            char cN1 = getcharval(N1, i);
            char cN2 = getcharval(N2, i);
            sum = cN1 + cN2 + carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum -= max;
            }
            S[i] = sum + ascii0;
        }
        if (carry)
            S[i++] = carry + ascii0;
        S[i] = 0;
        for (i = 0; i < strlen(S) / 2; i++) {
            char t = S[i];
            S[i] = S[strlen(S) - i - 1];
            S[strlen(S) - i -1] = t;
        }
        for (i = 0; i < strlen(S) - 1; ++i)
            if (S[i] != '0')
                break;
        for (; i < strlen(S); i++)
            printf("%c", S[i]);
        printf("\n");
    }
}
