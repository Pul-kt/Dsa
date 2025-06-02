class Solution {
public:
    int calPoints(vector<string>& arr) {
        stack<int> ans;
        int total = 0;
        for(string c : arr){
            if(c == "C"){
                if(!ans.empty()) ans.pop();
            }
            else if(c == "D") ans.push(ans.top()*2);
            else if(c == "+"){
                int num1 = ans.top();
                ans.pop();
                int num2 = ans.top();
                ans.push(num1);
                ans.push(num1+num2);
            }
            else
                ans.push(stoi(c));
        }
        while(!ans.empty()){
            total += ans.top();
            ans.pop();
        }
        return total;
    }
};