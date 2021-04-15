int steps(int i, int n, int* memory) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (memory[i] > 0) {
        return memory[i];
    } 
    memory[i] = (steps(i + 1, n, memory) + steps(i + 2, n, memory));
    return memory[i];
}

int climbStairs(int n){
    int* memory = (int*)calloc(n, sizeof(int));
    return(steps(0, n, memory));
}