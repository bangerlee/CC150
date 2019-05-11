/*
8.1 Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.
*/
class Solution {
public:
    int climbStairs(int n) {
        int res=0;
        if(n<=0) return 0;
        if(n<=2) return n;
        int one=2,two=1;
        for(int i=2;i<n;i++){
            res=one+two;
            two=one;
            one=res;
        }
        return res;
    }
};
