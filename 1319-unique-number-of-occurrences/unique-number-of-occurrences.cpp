class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int num : arr) {
            counts[num]++;
        }
        unordered_set<int> uniqueCounts;
        for (auto& pair : counts) {
            uniqueCounts.insert(pair.second);
        }
        return counts.size() == uniqueCounts.size();
    }
};