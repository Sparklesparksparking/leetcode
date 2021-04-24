int Cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    if (g == NULL || gSize == 0 || s == NULL || sSize == 0) {
        return 0;
    }
    qsort(g, gSize, sizeof(int), Cmp);
    qsort(s, sSize, sizeof(int), Cmp);
    int index = sSize - 1;
    int cnt = 0;
    for (int i = gSize - 1; i >= 0; i--) {
        if (index >= 0 && g[i] <= s[index]) {
            cnt++;
            index--;
        }
    }
    return cnt;
}