class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string ans1,ans2;
        if(length >= 1e4 || width >= 1e4 || height >= 1e4 ||
        (1LL*length*width*height) >= 1e9)
            ans1 = "Bulky";
        if(mass >= 100) ans2 = "Heavy";
        if(ans1 == "Bulky" && ans2 == "Heavy") return "Both";
        if(ans1 == "Bulky" && ans2 != "Heavy") return "Bulky";
        if(ans1 != "Bulky" && ans2 == "Heavy") return "Heavy";
        return "Neither";
    }
};