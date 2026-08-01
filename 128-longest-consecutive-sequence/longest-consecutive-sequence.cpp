class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if(nums.empty())
            return 0;

       sort(nums.begin(),nums.end());
       int longest=1,count =0,ls=INT_MIN;
       int n=nums.size();
       for(int i=0;i<n;i++){
        if(nums[i]-1==ls){
            count=count+1;
            ls=nums[i];
        }
        else if(nums[i]!=ls){
            count=1;
            ls=nums[i];
        }
        longest=max(longest,count);

       }
       return longest;

    }
};