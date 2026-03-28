/*
 * Problem  : 3613. Maximize Amount After Two Days of Conversions
 * Difficulty: Medium
 * Topics   : Array, String, Depth-First Search, Breadth-First Search, Graph Theory
 * URL      : https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/
 */

class Solution {
public:
void computeMaxCurrency(const vector<vector<string>>& pairs, const vector<double>& rates,
                        unordered_map<string, double>& currencyMap) {
    for (int i = 0; i < pairs.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            const string& start = pairs[j][0];
            const string& target = pairs[j][1];
            double rate = rates[j];
            
            if (currencyMap[start] > 0) {
                currencyMap[target] = max(currencyMap[target], currencyMap[start] * rate);
            }

            if (currencyMap[target] > 0) {
                currencyMap[start] = max(currencyMap[start], currencyMap[target] / rate);
            }
        }
    }
}
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
       unordered_map<string, double> day1Map;
    day1Map[initialCurrency] = 1.0;

    computeMaxCurrency(pairs1, rates1, day1Map);

    unordered_map<string, double> day2Map = day1Map;

    computeMaxCurrency(pairs2, rates2, day2Map);

    return day2Map[initialCurrency];
    }
};