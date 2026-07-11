class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int p=-1;
       for(int i=nums.size()-2;i>=0;i--) {
        if(nums[i]<nums[i+1]){
            p=i;
            break;
        }
       }
       if(p==-1){
        reverse(nums.begin(),nums.end());
        return;
       }
       for(int i = nums.size()-1;i>p;i--){
        if(nums[i]>nums[p]){
            swap(nums[i],nums[p]);
            break;
        }
       
       }
       int i = p+1,j=nums.size()-1;
       while(i<=j){
        swap(nums[i++],nums[j--]);
       }
    }
};