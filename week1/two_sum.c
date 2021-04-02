/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if (nums == NULL || numsSize <= 0) {
        return NULL;
    }
    *returnSize = 2;
    int* ret = (int*)malloc(2 * sizeof(int)); 
    for (int i = 1; i < numsSize; i++) {
        ret[0] = i;
        int left = i - 1;
        int right = i + 1;
        int goal = target - nums[i];
        while (left >= 0) {
            if (nums[left] == goal) {
                ret[1] = left;
                return ret;
            } else {
                left--;
            }
        }
        while (right < numsSize) {
            if (nums[right] == goal) {
                ret[1] = right;
                return ret;
            } else {
                right++;
            }
        }
    }
    return NULL;
}