class Solution {
public:
    double myPow(double x, int n) {
        //base case
        long long m = n;
        if(m==0){
            return 1;
        }
        if(m==1){
            return x;
        }
        if(m<0){
            x = 1/x;
            m = -m;
        }

        //recursion
        double ans = myPow(x,m/2);
        if(m%2 == 0){
            return ans*ans;
        }
        return ans*ans*x;
    }
};