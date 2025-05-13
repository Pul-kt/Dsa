class Solution {
public:
    const int Mod = 1e9 + 7;

    // Recursive modular exponentiation
    long long Pow(long long x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x % Mod;

        long long half = Pow(x, n / 2);
        long long result = (half * half) % Mod;

        if (n % 2 == 1) {
            result = (result * x) % Mod;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // Even positions (0, 2, 4, ...)
        long long oddCount = n / 2;         // Odd positions (1, 3, 5, ...)

        long long evenPart = Pow(5, evenCount);  // 5 choices: 0, 2, 4, 6, 8
        long long oddPart = Pow(4, oddCount);    // 4 choices: 2, 3, 5, 7

        return (evenPart * oddPart) % Mod;
    }
};
