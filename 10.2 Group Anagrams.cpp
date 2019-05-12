/*
10.2 Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to
each other.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(auto str:strs){
            string tmp=str;
            sort(str.begin(),str.end());
            m[str].push_back(tmp);
        }
        vector<vector<string>> res;
        auto it=m.begin();
        while(it!=m.end()){
            res.push_back(it->second);
            ++it;
        }
        return res;
    }
};
