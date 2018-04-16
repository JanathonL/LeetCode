190. Reverse Bits
这题很简单，先取到所有数位，然后从后往前加一下就好了
大佬的写法是n>>i&1取最后一位，倒数第二位，倒数第三位。。。，然后和result加起来，result = (result<<1) +(n>>I  &1)

class Solution {
public:
    uint32_t  reverseBits(uint32_t n) {
        uint32_t result= 0;
        for(int i=0; i<32; i++)
            result = (result<<1) + (n>>i &1);
        
        return result;
    }
};