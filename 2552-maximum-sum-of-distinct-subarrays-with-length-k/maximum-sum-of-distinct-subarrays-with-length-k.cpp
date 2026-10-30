class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxsum=0,curr=0;
        unordered_map<int,int>count;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            count[nums[i]]++;
            if(i>=k){
                int l=nums[i-k];
                curr-=l;
                count[l]--;
                if(count[l]==0){
                    count.erase(l);
                }
                
            }
            if(i>=k-1&&count.size()==k){
                maxsum=max(maxsum,curr);
            }
        }
        return maxsum;
    }
};