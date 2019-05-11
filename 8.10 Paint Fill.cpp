/*
8.10 Paint Fill: Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original color.
*/
class Solution {
private:
     void fill(vector<vector<int>>& res,int sr,int sc,int color,int newColor){
         if(sr<0||sc<0||sr>=res.size()||sc>=res[0].size()) return;
         if(res[sr][sc]!=color) return;
         res[sr][sc]=newColor;
         fill(res,sr-1,sc,color,newColor);
         fill(res,sr,sc-1,color,newColor);
         fill(res,sr+1,sc,color,newColor);
         fill(res,sr,sc+1,color,newColor);
     }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        fill(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};
