class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; i ++) {
            uint32_t digit = n & mask;
            result = (result << 1);
            if (digit != 0) {
                 result = result + 1;
            }
            mask = (mask << 1);
        }
        return result;
    }
};