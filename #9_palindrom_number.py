# leetcode question : palindrome numnber
#   problem link : https://leetcode.com/problems/palindrome-number/
 
def isPalindrome(self, x):
    if x < 0 or (x > 0 and x % 10 == 0): return False
    half = 0
    while x > half:
        half, x = half * 10 + x % 10, x / 10
    return x in (half, half / 10)

strin = str(input())
ans = isPalindrome(strin)
 
if ans:
    print("Yes")
else:
    print("No")
