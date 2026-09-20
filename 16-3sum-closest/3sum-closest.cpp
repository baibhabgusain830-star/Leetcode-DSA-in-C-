class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Step 1: Sort the array to use the two-pointer approach
        sort(nums.begin(), nums.end());
        
        // Initialize closest_sum with the sum of the first three elements
        int closest_sum = nums[0] + nums[1] + nums[2];
        
        // Step 2: Iterate through the array
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                // If the current sum is closer to the target, update closest_sum
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                // Move pointers based on comparison with the target
                if (current_sum < target) {
                    ++left; // We need a larger sum, move the left pointer right
                } else if (current_sum > target) {
                    --right; // We need a smaller sum, move the right pointer left
                } else {
                    // Exact match found (distance is 0), which is the absolute closest
                    return current_sum;
                }
            }
        }
        
        return closest_sum;
    }
};