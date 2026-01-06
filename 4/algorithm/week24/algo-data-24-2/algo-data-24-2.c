#include <stdio.h>

int kmp_match(const char txt[], const char pat[]) {
    int pt = 1;
    int pp = 0;
    int skip[1024];

    skip[pt] = 0;
    while (pat[pt] != '\0') {
        if (pat[pt] == pat[pp]) {
            skip[++pt] = ++pp;
        } else if (pp == 0) {
            skip[++pt] = pp;
        } else {
            pp = skip[pp];
        }
    }

    pt = pp = 0;

    while (txt[pt] != '\0' && pat[pp] != '\0') {
        if (txt[pt] == pat[pp]) {
            pt++; pp++;
        } else if (pp == 0) {
            pt++;
        } else {
            pp = skip[pp];
        }
    }

    if (pat[pp] == '\0') {
        return pt - pp;
    }

    return -1;
}

int main(void) {
    char txt[1024];
    char pat[1024];

    scanf("%s", txt);
    scanf("%s", pat);

    printf("%d\n", kmp_match(txt, pat));
    return 0;
}