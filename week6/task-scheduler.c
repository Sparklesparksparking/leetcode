#define MAX_NUM 26

int Cmp(const void* a, const void* b) 
{
    return (*(int*)b - *(int*)a);
}

int leastInterval(char* tasks, int tasksSize, int n)
{
    if (tasks == NULL || tasksSize == 0) {
        return 0;
    }
    if (n == 0) {
        return tasksSize;
    }
    int nums[MAX_NUM] = {0};
    for (int i = 0; i < tasksSize; i++) {
        nums[tasks[i] - 'A']++;
    }
    qsort(nums, MAX_NUM, sizeof(int), Cmp);
    int cnt = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        if (nums[i] == nums[0]) {
            cnt++;
        }
    }
    int ret = (nums[0] - 1) * (n + 1) + cnt;
    if (ret > tasksSize) {
        return ret;
    }
    return tasksSize;
}