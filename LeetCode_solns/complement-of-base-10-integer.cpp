class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int m = n;
        for (int i = 0; i <= 4; i++)
            m |= m >> (1 << i);
        return ~n & m;
    }
};