class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int left=0;
        int maxlen=0;
        for(int right=0;right<s.length();++right){
            while(set.find(s[right])!=set.end()){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};