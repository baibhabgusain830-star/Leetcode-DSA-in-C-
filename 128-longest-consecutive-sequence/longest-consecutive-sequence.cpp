class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if(nums.empty())
            return 0;
       int longest=1;
       int n=nums.size();
       unordered_set<int>st;
       for(int i=0;i<n;i++){
        st.insert(nums[i]);
       }
        for(int i:st){
            if(st.find(i-1)==st.end()){
                int count=1;
                int x=i;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    count=count+1;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};