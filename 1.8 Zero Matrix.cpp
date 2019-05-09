class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=0;
        if(m>0) n=matrix[0].size();
        else return;
        vector<pair<int,int>> v;
        for(int i=0;i<m;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    pair<int,int> tmp(i,j);
                    v.push_back(tmp);
                }
                    
            }
        }
        for(int i=0;i<v.size();i++){
            for(int k=0;k<n;k++)
                matrix[v[i].first][k]=0;
            for(int q=0;q<m;q++)
                matrix[q][v[i].second]=0;
        }
    }
};
