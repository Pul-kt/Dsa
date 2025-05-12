class Solution {
public: 
int solve(int n, bool leftToRight) {
    if (n == 1) return 1;

    if (leftToRight) {
        return 2 * solve(n/2, false);
    }

    else {
        //if n even, we eliminate n, n-2, n-4
        // If n odd, we eliminate position n, n-2, n-4, ..., 1
        if (n % 2 == 0) {
            return 2 * solve(n/2, true) - 1;
        } 
        else {
            return 2 * solve(n/2, true);
        }
    }
}
    int lastRemaining(int n) {

        return solve(n, true);
    }
};
// Approach2
