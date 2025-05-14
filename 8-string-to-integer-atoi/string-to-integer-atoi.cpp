class Solution {
public:
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
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;

            i++;
        }

        return ans * sign;

    }
};