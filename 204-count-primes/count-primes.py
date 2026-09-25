class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
            
        s = bytearray([1]) * n
        s[0] = s[1] = 0
        
        for i in range(2, int(n**0.5) + 1):
            if s[i]:
                # Slice length equals the total number of multiples of i in range
                s[i*i:n:i] = b'\x00' * len(s[i*i:n:i])
                
        return sum(s)