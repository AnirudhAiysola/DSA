#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st; // {stock price, count}
    StockSpanner()
    {
    }

    /**
     * Return the number of days until the next higher price.
     * @param price the current price of the stock
     * @return the number of days until the next higher price
     */
    int next(int price)
    {
        int days = 1;
        while (!st.empty() && st.top().first <= price)
        {
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */