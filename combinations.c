#include <stdlib.h>
#include <string.h>

void backtrack(int start, int n, int k, int* current, int index, int** result, int* returnSize, int* returnColumnSizes) {
    if (index == k) {
        result[*returnSize] = (int*)malloc(k * sizeof(int));
        memcpy(result[*returnSize], current, k * sizeof(int));
        returnColumnSizes[*returnSize] = k;
        (*returnSize)++;
        return;
    }
    
    for (int i = start; i <= n && (n - i + 1 >= k - index); i++) {
        current[index] = i;
        backtrack(i + 1, n, k, current, index + 1, result, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int maxCombinations = 200000; 
    
    int** result = (int**)malloc(maxCombinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCombinations * sizeof(int));
    *returnSize = 0;
    
    int* current = (int*)malloc(k * sizeof(int));
    
    backtrack(1, n, k, current, 0, result, returnSize, *returnColumnSizes);
    
    free(current);
    return result;
}
