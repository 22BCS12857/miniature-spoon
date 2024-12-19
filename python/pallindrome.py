def checkPalindrome(n):
    reverse = 0
    
    # Copy of the original number so that the original
    # number remains unchanged while finding the reverse
    temp = n
    while temp != 0:
        reverse = reverse * 10 + temp % 10
        temp = temp // 10
        
    # If reverse is equal to the original number, the
    # number is palindrome
    return reverse == n

if __name__ == "__main__":
  n = 12325
  if checkPalindrome(n):
    print("true")
  else:
    print("false")