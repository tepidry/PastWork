//Example Syntax and style summary for 
//   while, for, if-else, if-else if-else

//   ALLOWED for while
while (i < maxNumber) {
   statement
   statement
}
// or
while (!isFound)
{
   statement
   statement
}

//  STYLE NOT ALLOWED
while (i < 5)
   {
      statement
      statement
   }

//   ALLOWED for for
for (int i = 0; i < 5; i++)
{
   statement
   statement
}
// or
for (int i = 1; i <= numExams; i++) {
   statement
   statement
}

// ALLOWED for if-else
if (exam > 60)
{
   statements
}
else
{
   statements
}

if (isFound) {
   statements
} else {
   statements
}
// or
if (num > value)
{
   statements
} else {
   statements
}

//ALLOWED for  if-else if- else
if (exam >= 90)
{
   statements
} else if (exam >= 80)
{
   statements
} else
{
   statements
}
// or
if (exam >= 90) {
   statements
} else if (exam >= 80) {
   statements
} else {
   statements
}
