class Solution:
    
    def roman_equivalent(self, roman_number):
        if roman_number=='I':
            return 1
        elif roman_number=='V':
            return 5
        elif roman_number=='X':
            return 10
        elif roman_number=='L':
            return 50
        elif roman_number=='C':
            return 100
        elif roman_number=='D':
            return 500
        elif roman_number=='M':
            return 1000

    def romanToInt(self, s):
            """
            :type s: str
            :rtype: int
            """
            ans = prevous_num = self.roman_equivalent(s[0])
            for pos,char in enumerate(s):
                if pos==0:
                    continue
                current_num = self.roman_equivalent(char) 
                if prevous_num>=current_num:
                    ans += current_num
                elif prevous_num<current_num:
                    ans -= prevous_num
                    ans += abs(prevous_num-current_num)
                prevous_num = current_num
            
            return ans
