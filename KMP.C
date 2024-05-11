#include<stdio.h>
#include<string.h>

void main(){
    char text[100];
    char pattern[50];
    printf("Enter Text : ");
    scanf("%s", text);
    printf("Enter Pattern : ");
    scanf("%s", pattern);
    
    int i = 0;
    int j = 0;
    int ptr = -1; 
    
    while (i < strlen(text) && j < strlen(pattern)) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                ptr = i; // Update ptr only when matching starts
            }
            i++;
            j++;
        } 
        else {
            if (ptr != -1) {
                i = ptr + 1; // Reset i to start searching from next character
            } 
            else {
                i++; // Continue searching from the next character
            }
            j = 0; // Reset j to start matching pattern from beginning
            ptr = -1; // Reset ptr
        }
    }
    
    if (j == strlen(pattern)) {
        printf("Pattern found at index %d\n", ptr);
    }
    else {
        printf("Pattern doesn't exist\n");
    }
}
