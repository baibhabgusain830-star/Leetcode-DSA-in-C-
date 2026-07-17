class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        vector<int> ans(n);
        int p=-n;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                p=i;
            }
            ans[i]=i-p;
        }
        p=2*n;
        for(int i=n-1;i>=0;i--){
            if(s[i]==c){
                p=i;
            }
            ans[i]=min(ans[i],p-i);
        }
        return ans;
    }
};