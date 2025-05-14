class Solution {
public:
void solve(string digits,int index,string temp,vector<string> &ans,string map[]){
    //base case 
    if(index >= digits.length()){
        ans.push_back(temp);
        return;
    }
    int num = digits[index] - '0';
    string val = map[num];
    for(int i=0;i<val.length();i++){
        temp.push_back(val[i]);
        solve(digits,index + 1,temp,ans,map);
        temp.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp = "";
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        int index = 0;
        if(digits.length() == 0){
            return ans;
        }
        solve(digits,index,temp,ans,map);

        return ans;
        
    }
};