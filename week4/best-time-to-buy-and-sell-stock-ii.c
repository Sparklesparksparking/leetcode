int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize < 2) {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        if (prices[i + 1] > prices[i]) {
            sum += prices[i + 1] - prices[i];
        }
    }
    return sum;
}