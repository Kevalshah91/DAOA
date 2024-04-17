#include<stdio.h>
#include<string.h>

void main() {
    char a[100], b[100];
    int len_a, len_b;
    int i, j, k;
    int na[100], nb[100];
    int sum = 0;
    int insum;
    
    printf("Keval Shah 60009220061\n");
    printf("Enter larger string\n");
    scanf("%s", a);
    printf("Enter smaller string\n");
    scanf("%s", b);

    len_a = strlen(a);
    len_b = strlen(b);

    // Calculate sum of character values in smaller string
    for(i = 0; i < len_b; i++) {
        nb[i] = ((int)b[i]) - 96;
        sum += nb[i];
    }

    // Calculate sum of character values in substrings of larger string and compare
    for(i = 0; i <= len_a - len_b; i++) {
        insum = 0;
        for(j = i, k = 0; k < len_b; j++, k++) {
            na[j] = ((int)a[j]) - 96;
            insum += na[j];
        }
        if(insum == sum) {
            int flag = 0;
            for(j = i, k = 0; k < len_b; j++, k++) {
                if(a[j] == b[k]) {
                    flag++;
                }
            }
            if(flag == len_b) {
                printf("Match found at position %d\n", i + 1);
                break;
            }
        }
    }
}
