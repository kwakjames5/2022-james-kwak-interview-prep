class Solution {
public:
    int minOperationsMaxProfit(vector<int>& cust, int boardingCost, int runningCost) {
    int wait = 0, prof = 0, max_prof = 0, max_i = -1;
    for (int i = 0; i < cust.size() || wait > 0; ++i) {
        if (i < cust.size())
            wait += cust[i];
        prof += min(4, wait) * boardingCost - runningCost;
        wait -= min(4, wait);
        if (max_prof < prof) {
            max_prof = prof;
            max_i = i + 1;
        }
    }
    return max_i;
}
};