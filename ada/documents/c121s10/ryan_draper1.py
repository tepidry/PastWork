"""
   Author: Ryan Draper
   Class: CPSC121 
   Assignment Number: 01
"""
import cTurtle

def drawStar(myStar,L):
  myStar.begin_fill()
  myStar.fillcolor('orange')
  for i in range(5):
     myStar.forward(L)
     myStar.right(144)
  myStar.end_fill()
  
def main():
    myStar = cTurtle.Turtle()
    drawStar(myStar,50)
main()
