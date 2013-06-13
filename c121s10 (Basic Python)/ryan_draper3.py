"""
Author: Ryan Draper
Class: CPSC121 
Assignment Number: 03
"""
import random   
def isPrime(num):

    for i in range(1,num):  
      if num % i == 0:
        return False
      else:
        return True

def main():
    
    for i in range(50):
      num = random.randint(1, 200000)
      if isPrime(num):
        print(num, ': prime')
      else:
        print(num, ': composite')

main()
        
