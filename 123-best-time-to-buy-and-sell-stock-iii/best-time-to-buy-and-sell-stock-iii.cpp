class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty())
      return 0;

    int firstBuy = INT_MIN, firstSell = 0;
    int secondBuy = INT_MIN, secondSell = 0;

    for (int price : prices) {
      firstBuy = max(firstBuy, -price);                // First buy
      firstSell = max(firstSell, firstBuy + price);    // First sell
      secondBuy = max(secondBuy, firstSell - price);   // Second buy
      secondSell = max(secondSell, secondBuy + price); // Second sell
    }

    return secondSell; // Max profit after two transactions
  }
};