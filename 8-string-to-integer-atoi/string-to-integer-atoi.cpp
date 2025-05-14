class Solution {
public:
    int ModMax = INT_MAX;
    int ModMin = INT_MIN;
int f(int i,int n,long long ans,string &s,int sign){

    if(i >= n || !isdigit(s[i])) return ans*sign;

    ans = ans*10 + (s[i] - '0');
    long signedNum = sign * ans;
    if (signedNum >= ModMax) return ModMax;
    if (signedNum <= ModMin) return ModMin;

    return f(i+1,n,ans,s,sign);

}
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;// +ive
        long long ans = 0;
        while(i < n && s[i] == ' ') i++;
        if(i >= n) return 0;
        if(s[i] == '-' || s[i] == '+'){
            sign = (s[i] == '+')? 1 : -1;
            i++;
        }

        return f(i,n,ans,s,sign);
    }
};