/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i]++;
        digits[i] = digits[i] % 10;
        if (digits[i] != 0) {
            *returnSize = digitsSize;
            return digits;
        }
    }
    int* newDigits = (int*)malloc((digitsSize + 1) * sizeof(int));
    for (int i = 0; i < digitsSize + 1; i++) {
         newDigits[i] = 0;
    }
    newDigits[0] = 1;
    *returnSize = digitsSize + 1;
    return newDigits;
}