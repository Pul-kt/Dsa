class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2) return true;
        int s = 0;
        int e = num/2;
        while(s<=e){
            long long mid = s+(e-s)/2;
            if((long long)mid*mid == num) return true;
            else if((long long)mid*mid > num) e = mid-1;
            else s = mid+1;
        }
        return false;
    }
};