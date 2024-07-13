
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0; // No profit can be made if there's only one or no price
    }
    
    int min_price = prices[0];
    int max_profit = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i]; // Update min_price if a new lower price is found
        } else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price; // Calculate the profit and update max_profit if it's higher
        }
    }
    