/*
8.12 Eight Queens: Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all diagonals, not just the two that bisect the board.
*/
class Solution {
private:
    bool inrow(string& s)
    {
        if(s.find('Q')!=string::npos) return true;
        return false;
    }
    bool incol(vector<string>& v,int j,int n)
    {
        for(int m=0;m<n;m++){
            if(v[m][j]=='Q') return true;
        }
        return false;
    }
    bool indf(vector<string>& v,int i,int j,int n)
    {
        int ti=i,tj=j;
        while(ti<n&&tj<n){
            if(v[ti][tj]=='Q') return true;
            ti+=1;
            tj+=1;
        }
        ti=i;tj=j;
        while(ti>=0&&tj>=0){
            if(v[ti][tj]=='Q') return true;
            ti-=1;
            tj-=1;
        }
        ti=i;
        tj=j;
        while(ti>=0&&tj<n){
            if(v[ti][tj]=='Q') return true;
            ti-=1;
            tj+=1;
        }
        ti=i;
        tj=j;
        while(ti<n&&tj>=0){
            if(v[ti][tj]=='Q') return true;
            ti+=1;
            tj-=1;
        }
        return false;
    }
    bool dfs(vector<vector<string>>& res,vector<string>& v,int n,int d){
        if(d>=n*n){
            res.push_back(v);
            return true;
        }
        int i=d/n;
        int j=d%n;
        for(int k=d;k<(d/n+1)*n;k++){
            int i=k/n;
            int j=k%n;
        if(!inrow(v[i])&&!incol(v,j,n)&&!indf(v,i,j,n)){
            v[i][j]='Q';
            dfs(res,v,n,(d/n+1)*n);
            v[i][j]='.';
        }
        }
        return false;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n,'.');
        vector<string> v(n,s);
        //for(int k=0;k<s.length();k++)
        dfs(res,v,n,0);
        return res;
    }
};
