class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> w;
        
        for (int i = 0; i < nums.size(); i++) {
            if (w.count(nums[i])) {
                return true;
            }
            
            w.insert(nums[i]);
            
            if (w.size() > k) {
                w.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
