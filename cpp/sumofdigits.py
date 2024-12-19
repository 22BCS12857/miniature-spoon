def sumDigits(no):
  if no == 0:
     return 0 
  else:
     return int(no % 10) + sumDigits(int(no/10))

if __name__ == "__main__":
  
    print(sumDigits(111))