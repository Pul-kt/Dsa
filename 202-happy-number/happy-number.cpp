class Solution {
public:
int square(int x){
    int ans = 0;
    while(x > 0){
        int num = x%10;
        x = x/10;
        ans += num*num;
    }
    return ans;
}
    bool isHappy(int n) {
        int slow = square(n);
        int fast = square(square(n));
        while(slow != fast){
            if(slow == 1 || fast == 1) return true;
            slow = square(slow);
            fast = square(square(fast));
        }
        return slow == 1;
    }
};