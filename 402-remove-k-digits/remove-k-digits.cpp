class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        string ans = "";
        int n = num.size();
        stack<int> st;
        for(char c : num){
            if(st.empty()) st.push(c - '0');
            else{
                while(!st.empty() && k > 0 && st.top() > c - '0'){
                    st.pop();
                    k--;
                }
                st.push(c - '0');
            }
        }
        // If still k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        while(!st.empty()){
            ans.push_back(st.top() + '0');
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};