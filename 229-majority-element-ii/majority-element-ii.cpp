class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int>ls;
       unordered_map<int,int>mp;

       int n=nums.size();
       int m=n/3+1;
       for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==m)ls.push_back(nums[i]);
       }
       return ls;
    }
};