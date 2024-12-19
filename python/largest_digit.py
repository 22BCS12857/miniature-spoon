def Digits(n): 
    largest = 0
    smallest = 9
  
    while (n): 
        r = n % 10
        # Find the largest digit 
        largest = max(r, largest)  
        n = n // 10
  
    print(largest)   
n = 2346
Digits(n) 