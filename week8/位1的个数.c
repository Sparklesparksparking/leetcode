//移位
/*
int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1u << i)) {
            cnt++;
        }
    }
    return cnt;
}
*/

//n&(n-1)
int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n != 0) {
        n &= n - 1;
        cnt++;
    }
    return cnt;
}