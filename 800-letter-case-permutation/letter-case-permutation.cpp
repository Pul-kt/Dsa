class Solution {
public:
void f(int i,string &s,string &temp,vector<string> &ans){

    if(temp.size() == s.size()){
            ans.push_back(temp);
            return;
    }   
    if(isdigit(s[i])){
        temp.push_back(s[i]);
        f(i+1,s,temp,ans);
        temp.pop_back();
    }
    else{
        temp.push_back(tolower(s[i]));
        f(i+1,s,temp,ans);
        temp.pop_back();
        temp.push_back(toupper(s[i]));
        f(i+1,s,temp,ans);
        temp.pop_back();
    }

}
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp = "";
        f(0,s,temp,ans);
        return ans;
    }
};