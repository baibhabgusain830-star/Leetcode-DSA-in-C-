class Solution {
public:
    bool SearchInRow(vector<vector<int>>& matrix,int target,int row){
        int n=matrix[0].size();
        int st=0,end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(target ==matrix[row][mid]){
                return true;
            }
            else if(target>matrix[row][mid]){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int SR=0,ER=m-1;
        while(SR<=ER){
            int MR=SR+(ER-SR)/2;
            if(target>=matrix[MR][0]&& target<=matrix[MR][n-1]){
                return SearchInRow(matrix,target,MR);
            }
            else if(target>=matrix[MR][n-1]){
                SR=MR+1;
            }
            else{
                ER=MR-1;
            }
        }
    return false;
    }
};