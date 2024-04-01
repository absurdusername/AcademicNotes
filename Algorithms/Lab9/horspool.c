#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* read_string() {
    char buffer[1024];
    fgets(buffer, 1024, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    return strdup(buffer);
}

int *shift_table(char *P) {
    int *table = malloc(128 * sizeof(int));
    int n = strlen(P);
    
    for (int i = 0; i < 128; i++)
        table[i] = n;

    for (int i = 0; i < n - 2; i++)
        table[P[i]] = n - i - 1;

    return table;
}

int horspool_search(char *T, char *P) {
    int *table = shift_table(P);
    int m = strlen(P);
    int n = strlen(T);

    int i = m - 1;
    while (i <= n - 1) {
        int k = 0;
        while (k <= m - 1 && P[m - 1 - k] == T[i - k])
            k++;
        
        if (k == m) 
            return i - m + 1;
        else 
            i += table[T[i]];
    }
    
    return -1;
}

int main() {
    char *T, *P;

    printf("Enter the text: ");
    T = read_string();

    printf("Enter the pattern: ");
    P = read_string();

    int i = horspool_search(T, P);
    if (i != -1) 
        printf("Match found at index %d\n", i);
    else 
        printf("No match found");
}