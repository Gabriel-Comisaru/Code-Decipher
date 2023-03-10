#include "utils.h"
#define INF 10000
void RemovePunctuation(char * str, const char * strRemove) {
    int Remove[256] = { 0 };
    if (NULL == str || NULL == strRemove)
        return;
    while (*strRemove) {
        Remove[*strRemove++] = 1;
    }
    char *strDest = str;
    while (*str) {
        if (!Remove[*str])
            *strDest++ = *str;
        str++;
    }
    *strDest = '\0';
}
void SolveTask3() {
    // TODO(gabriel.comisaru)
    char O[INF] = " ";
    char* S[INF], *F;
    char v[INF] = {" "};
    int aparitii[INF] = {0};
    char *str1, *str2;
    int i = 0, j = 0, k = 0, count = 0, len = 0, contor = 0;
    F = calloc(100, 1);
    scanf("%s", F);
    str1 = calloc(100, 1);
    str2 = calloc(100, 1);
    while (scanf("%s", O) == 1) {
            RemovePunctuation(F, ",.!;");
            RemovePunctuation(O, ",.!;");
            S[i] = calloc(200, 1);
            strncpy(S[i], F, 100);
            strncat(S[i], " ", 1);
            strncat(S[i], O, 100);
            strncpy(F, O, 100);
            i++;
            count++;
    }
    contor = 0;
    for (i = 0; i < count; i++) {
        for (j = 0; j <= i; j++) {
            if (strcmp(S[i], S[j]) == 0) {
                aparitii[j]++;
                break;
            }
        }
        if (i == j)
            contor++;
    }
    printf("%d\n", contor);
    for (i = 0; i < count; i++)
        if (aparitii[i] != 0)
            printf("%s %d\n", S[i], aparitii[i]);
}
