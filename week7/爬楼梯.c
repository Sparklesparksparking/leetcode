int memo[1000] = {0};

int help (int n)
{
    int ret;
    if (memo[n] != 0) {
        return memo[n];
    }
    ret = help(n - 1) + help(n - 2);
    memo[n] = ret;
    return ret;
}
int climbStairs(int n){
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    return help(n);
}