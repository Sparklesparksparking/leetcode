/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX_SIZE 10000

void generate(int left, int right, int n, int index, char* str, char** result, int* returnSize)
{
    if (left == n && right == n) {
        result[*returnSize] = (char*)calloc(2 * n + 1, sizeof(char*));
        strcpy(result[*returnSize], str);
        (*returnSize)++;
        return;
    }

    if (left < n) {
        str[index] = '(';
        generate(left + 1, right, n, index + 1, str, result, returnSize);
    }
    if (left > right && right < n) {
        str[index] = ')';
        generate(left, right + 1, n, index + 1, str, result, returnSize);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char** result = (char**)malloc(MAX_SIZE * sizeof(char*));
    char* str = (char*)calloc(2 * n + 1, sizeof(char));
    *returnSize = 0;
    generate(0, 0, n, 0, str, result, returnSize);
    return result;
}