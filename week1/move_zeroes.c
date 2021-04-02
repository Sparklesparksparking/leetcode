void moveZeroes(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) {
        return NULL;
    }
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int tmp = nums[index];
            nums[index++] = nums[i];
            nums[i] = tmp;
        }
    }
}