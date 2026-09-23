class Solution {
public:
    int reverse(int x) {
        long long count = 0;
        while (x != 0) { 
            int Ldigit = x % 10;
            count = (count * 10) + Ldigit;
            x = x / 10;
        }
        
        if (count > INT_MAX || count < INT_MIN) {
            return 0;
        }
        
        return count;
    }
};