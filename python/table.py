def printTable(n, i=1):

    if (i == 11):  # base case
        return
    print(n, "*", i, "=", n * i)
    i += 1  # increment i
    printTable(n, i)

if __name__ == "__main__":
  n = 5
  printTable(n)