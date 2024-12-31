#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* add(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int maxLen = len1 > len2 ? len1 : len2;
    
    char* result = (char*)malloc(maxLen + 2);
    memset(result, '0', maxLen + 1);
    result[maxLen + 1] = '\0';

    bool carry = false;

    for (int i = 0; i < maxLen; i++) {
        int temp = carry ? 1 : 0;
        carry = false;

        if (i < len1) temp += s1[len1 - i - 1] - '0';
        if (i < len2) temp += s2[len2 - i - 1] - '0';

        if (temp >= 10) {
            carry = true;
            temp -= 10;
        }
        result[maxLen - i] = temp + '0';
    }

    if (carry) result[0] = '1';
    else memmove(result, result + 1, maxLen + 1);

    return result;
}

char* multiply(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char* result = (char*)malloc(2);
    strcpy(result, "0");

    for (int i = 0; i < len2; i++) {
        char* line = (char*)malloc(len1 + 2);
        strcpy(line, s1);
        int carry = 0;
        for (int j = len1 - 1; j >= 0; j--) {
            int temp = carry;
            carry = 0;
            temp += (s1[j] - '0') * (s2[len2 - i - 1] - '0');
            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
            }
            line[j] = temp + '0';
        }

        if (carry > 0) {
            char* tempLine = (char*)malloc(len1 + 3);
            tempLine[0] = carry + '0';
            strcpy(tempLine + 1, line);
            free(line);
            line = tempLine;
        }

        int lineLen = strlen(line);
        char* paddedLine = (char*)malloc(lineLen + i + 1);
        strcpy(paddedLine, line);
        memset(paddedLine + lineLen, '0', i);
        paddedLine[lineLen + i] = '\0';
        free(line);

        char* tempResult = add(result, paddedLine);
        free(result);
        free(paddedLine);
        result = tempResult;
    }

    return result;
}

char* power(const char* s1, int p) {
    if (p == 1) {
        char* result = (char*)malloc(strlen(s1) + 1);
        strcpy(result, s1);
        return result;
    }

    char* prev = power(s1, p - 1);
    char* result = multiply(prev, s1);
    free(prev);
    return result;
}

int main() {
    char s[101];
    int p;
    scanf("%s %d", s, &p);

    char* dot = strchr(s, '.');
    int idx = 0;

    if (dot) {
        idx = strlen(s) - (dot - s) - 1;
        memmove(dot, dot + 1, strlen(dot));
    }

    idx *= p;

    char* result = power(s, p);

    if (idx > 0) {
        int resultLen = strlen(result);
        char* formattedResult = (char*)malloc(resultLen + 2);
        memmove(formattedResult, result, resultLen - idx);
        formattedResult[resultLen - idx] = '.';
        strcpy(formattedResult + resultLen - idx + 1, result + resultLen - idx);
        free(result);
        result = formattedResult;
    }

    printf("%s\n", result);
    free(result);

    return 0;
}
