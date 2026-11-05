class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        vector<int>count(n,0);
        int l=0,res=0,dif=0;
        for(int r=0;r<n;++r){
            if(count[fruits[r]]==0){
                dif++;
            }
            count[fruits[r]]++;
            while(dif>2){
                count[fruits[l]]--;
                if(count[fruits[l]]==0){
                    dif--;
                }
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
    
};