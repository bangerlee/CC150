/*
12.2 Reverse String: Implement a function void reverse(char* str) in C or C++ which reverses a null- terminated string.
*/
class Solution {
public:
    string reverseString(string s) {
        int i=0;
        int j=s.length()-1;
        while(j>i){
            char tmp=s[i];
            s[i]=s[j];
            s[j]=tmp;
            i+=1;
            j-=1;
        }
        return s;
    }
};
