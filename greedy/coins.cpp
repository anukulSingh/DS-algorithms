// find min coins required to pay an amount (10, 5, 2 , 1 paise coins)
// greedy fails for (18, 10, 1), why ?

int minCoins (int *coins, int n, int amount) {
    sort(coins, coins + n, greater<int>());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (coins[i] <= amount) {
            int c = (amount / coins[i]);
            ans += c;
            amount -= c*coins[i];
        }
        if (amount == 0) break;
    }
    return ans;
}