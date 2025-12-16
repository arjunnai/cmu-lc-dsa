func maxProfit(prices []int) int {
    minPrice, maxProfit := prices[0], 0
    for i:=0; i<len(prices); i++{
        
        minPrice = min(minPrice, prices[i])
        maxProfit = max(maxProfit, (prices[i]-minPrice))
    }
    return maxProfit
}