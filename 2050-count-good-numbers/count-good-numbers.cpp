class Solution {
public:
long long modExp(long long x, long long pow) {
        int Mod = 1e9 + 7;
        long long result = 1;
        while (pow > 0) {
            if (pow % 2 == 1) {
                result = (result * x) % Mod;
            }
            x = (x * x) % Mod;  // Square the base
            pow /= 2;  // Divide the exponent by 2
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {

        int Mod = 1e9 + 7;

        long long evenCount = (n+1)/2;  // Half are even-indexed
        long long oddCount = n - evenCount;  // The rest are odd-indexed

        //(0, 2, 4, 6, 8)
        long long evenChoices = 5;
        //(2, 3, 5, 7)
        long long oddChoices = 4;

        long long result = modExp(evenChoices, evenCount) * 
                            modExp(oddChoices, oddCount) % Mod;
        
        return result;
    }
};