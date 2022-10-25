def isPalindrome(n):
    return n == n[::-1]
 
 
strin = str(input())
ans = isPalindrome(n)
 
if ans:
    print("Yes")
else:
    print("No")
   
