
"""
Author: Ryan Draper
Class: CPSC121 
Assignment Number: 02
"""
def nacci(number):

  fibx = 0
  fiby = 1
  code = fiby + fibx

  if (number <2):
    return number
  
  for i in range (2, number):
    fibx = fiby
    fiby = code
    code = fiby + fibx
  return code


def main():
  for i in range (50):
    print (nacci (i))
  
main()

  
