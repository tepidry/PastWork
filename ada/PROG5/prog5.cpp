//@file: prog5.cpp
//@author: Jamie Haddock (jhaddock2) and Ryan Draper (rdraper)
//@date: 3/26/13
//@description: Finds the pairs of extreme points that are to be connected 
//              to find the convex hull of a set of points.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct point //holds the info for a point in the cartesian plan
{
	int x; 
	int y;
};

// PrintLines prints num lines
//@pre: num must be a nonnegative integer
//@post: num lines are printed
//@param: int num
//@return: none
//@throw: none
//@usage: PrintLines(2);
void PrintLines(int num);

// GeneratePointArray reads point values into an array from an input file
//@pre: numPoints must be the nonnegative integer number of points,
//      points must be an array of size 2*numPoints and in5.dat must hold
//      point values satisfying the pre-conditions of the algorithm
//@post: points holds the point values in in5.dat
//@param: int numPoints
//        point* points
//@return: none
//@throw: none
//@usage: GeneratePointArray(numPoints, points);
void GeneratePointArray(int numPoints, point* points);

// ClockwiseQuickHull begins an algorithm to determine the convex hull in
// clockwise order
//@pre: numPoints must be the nonnegative integer number of points,
//      points must be an array of size numPoints
//@post: the pairs of extreme points making up the convex hull are output
//@param: int numPoints
//        points* points
//@return: none
//@throw: none
//@usage: ClockwiseQuickHull(numPoints, points);
void ClockwiseQuickHull(int numPoints, point* points);

// CounterClockwiseQuickHull begins an algorithm to determine the convex hull
// in counter-clockwise order
//@pre: numPoints must be the nonnegative integer number of points,
//      points must be an array of size numPoints
//@post: the pairs of extreme points making up the convex hull are output
//@param: int numPoints
//        points* points
//@return: none
//@throw: none
//@usage: CounterClockwiseQuickHull(numPoints, points);
void CounterClockwiseQuickHull(int numPoints, point* points);

// UpperHull is a recursive algorithm that determines the convex hull of the upper division
//@pre: numPoints must be the nonnegative integer number of points,
//      points is an array of size numPoints, point1 and pointN are assigned
//@post: the pairs of extreme points making up the upper convex hull are output
//@param: int numPoints
//        point* points
//        point point1
//        point pointN
//@return: none
//@throw: none
//@usage: UpperHull(numPoints, points, point1, pointN);
void UpperHull(int numPoints, point* points, point point1, point pointN);

// LowerHull is a recursive algorithm that determines the convex hull of the upper division
//@pre: numPoints must be the nonnegative integer number of points,
//      points is an array of size numPoints, point1 and pointN are assigned
//@post: the pairs of extreme points making up the lower convex hull are output
//@param: int numPoints
//        point* points
//        point point1
//        point pointN
//@return: none
//@throw: none
//@usage: LowerHull(numPoints, points, point1, pointN); 
void LowerHull(int numPoints, point* points, point point1, point pointN);

// UpperPartition places the points from "points" into upperPoints that are above the line from
// point1 to pointN
//@pre: numPoints is nonnegative integer number of points, points is array of size numPoints
//      upperPoints is created, point1 and pointN are assigned
//@post: upperPoints holds the points in "points" that are above the line between point1 and
//       pointN
//@param: int numPoints
//        point* points
//        point* upperPoints
//        point point1
//        point pointN
//@return: number of points contained in upperPoints
//@throw: none
//@usage: upperCount = UpperPartition(numPoints, points, upperPoints, point1, pointN);
int UpperPartition(int numPoints, point* points, point* upperPoints, point point1, point pointN);

// LowerPartition places the points from "points" into lowerPoints that are below the line from
// point1 to pointN
//@pre: numPoints is nonnegative integer number of points, points is array of size numPoints
//      lowerPoints is created, point1 and pointN are assigned
//@post: lowerPoints holds the points in "points" that are below the line between point1 and
//       pointN
//@param: int numPoints
//        point* points
//        point* lowerPoints
//        point point1
//        point pointN
//@return: number of points contained in lowerPoints
//@throw: none
//@usage: lowerCount = LowerPartition(numPoints, points, lowerPoints, point1, pointN);
int LowerPartition(int numPoints, point* points, point* lowerPoints, point point1, point pointN);

// FindPointMax finds the point that is the maximum distance from the line between
// point1 and pointN
//@pre: numPoints is number of points, points is array of this size and point1 and
//      pointN have been assigned
//@post: returns the point that is the maximum distance from the line between point1
//       and pointN
//@param: int numPoints
//        point* points
//        point point1
//        point pointN
//@return: point that is max distance from line between point1 and pointN
//@throw: none
//@usage: pointMax = FindPointMax(numPoints, points, point1, pointN);
point FindPointMax(int numPoints, point* points, point point1, point pointN);

// PrintPoints prints the points in a readable manner
//@pre: point1 and point2 must be assigned
//@post: points are printed
//@param: point point1
//        point point2
//@return: none
//@throw: none
//@usage: PrintPoints(point1, pointN);
void PrintPoints(point point1, point point2);

// Determinant determines the determinant |x1 y1 1|
//                                        |x2 y2 1|
//                                        |x3 y3 1|
//@pre: point1, point2 and point3 must be assigned
//@post: determinant is returned
//@param: point point1
//        point point2
//        point point3
//@return: determinant of points
//@throw: none
//@usage: det = Determinant(point1, point2, point3);
int Determinant(point point1, point point2, point point3);

//Preforms mergesorts recursive call to divide and conquer the list of x and y points
//@pre: pointsA is filled with x and y coordinates and numPoints is the size of that array
//@post: pointsA is sorted in ascending order with x coordinate taking precedents over the y coordinate
//@param: numPoints
//@		  pointsA
//@return: 0
//@throw: none
//@usage: MergeSort(numPoints, points);
void MergeSort(int numPoints, point* points);

//Merges two lists "bPoints and cPoints" into the array aPoints in order
//@pre: aPoints, bPoints, and cPoints are all arrays of the struct point and bNum and cNum are the size of the cooresponding array
//@post: aPoints is a single array of struct point that is made up of bPoints and cPoints and in order
//@param: bNum
//@		  bPoints
//@		  cNum
//@		  cPoints
//@		  aPoints
//@return: 0
//@throw: none
//@usage: Merge(floor , pointsB, ceiling, pointsC, pointsA);
void Merge(int aNum, point* aPoints, int bNum, point* bPoints, point* aPlusBPoints);

//Copies the rightHS array of the struct point into the leftHS
//@pre: rightFrom and rightTo are the begining and end of the rightHS that is to copied to the leftHS's leftFrom to leftTo elements
//@post: the rightHS array elements that are between rightFrom to rightTo has been copied to the leftHS leftFrom to the leftTo positions
//@param: rightFrom
//@       rightTo
//@       leftFrom
//@       leftTo
//@       rightHS
//@       leftHS
//@return: 0
//@throw: none
//@usage: Copy(j, cNum, cPoints, k, bNum + cNum,  aPoints);
void Copy(int rightFrom, int rightTo, point* rightHS, int leftFrom, int leftTo, point* leftHS);

//Warns user of the sorting process mergesort
//@pre: none
//@post: warning is displayed
//@param: none
//@return: 0
//@throw: none
//@usage: WarnMergeSortUse();
void WarnMergeSortUse();

//@pre: none
//@post: convex hull of points in in5.dat are output
//@param: none
//@return: 0
//@throw: none
int main(){
   int numPoints = 16;
   
   point* points;
   points = new (nothrow) point[numPoints];

   GeneratePointArray(numPoints, points);
   WarnMergeSortUse();
   MergeSort(numPoints, points);
   ClockwiseQuickHull(numPoints, points);
   PrintLines(1);
   CounterClockwiseQuickHull(numPoints, points);
     
   return 0;
}

//Warns user of the sorting process mergesort
//@pre: none
//@post: warning is displayed
//@param: none
//@return: 0
//@throw: none
//@usage: WarnMergeSortUse();
void WarnMergeSortUse(){
	PrintLines(2);
	cout << "*********USED MERGESORT ON POINTS*********";
	PrintLines(2);
}

//Preforms mergesorts recursive call to divide and conquer the list of x and y points
//This is a version of the algorithm found in page 126 in "the Design and Analysis of Algorithm's" by Anany Levitin
//@pre: pointsA is filled with x and y coordinates and numPoints is the size of that array
//@post: pointsA is sorted in ascending order with x coordinate taking precedents over the y coordinate
//@param: numPoints
//@		  pointsA
//@return: 0
//@throw: none
//@usage: MergeSort(numPoints, points);
void MergeSort(int numPoints, point* pointsA){
	if(numPoints > 1)
	{
		int ceiling = (int)(ceil(numPoints/2.0));
		int floor = numPoints/2;
		point* pointsB = new (nothrow) point[floor];
		point* pointsC = new (nothrow) point[ceiling];
		Copy(0, floor, pointsA, 0, floor,  pointsB);
		Copy(floor, numPoints, pointsA, 0, ceiling, pointsC); 
		MergeSort(floor, pointsB);
		MergeSort(ceiling, pointsC);
		Merge(floor , pointsB, ceiling, pointsC, pointsA);
	}
}

//Merges two lists "bPoints and cPoints" into the array aPoints in order
//@pre: aPoints, bPoints, and cPoints are all arrays of the struct point and bNum and cNum are the size of the cooresponding array
//@post: aPoints is a single array of struct point that is made up of bPoints and cPoints and in order
//@param: bNum
//@		  bPoints
//@		  cNum
//@		  cPoints
//@		  aPoints
//@return: 0
//@throw: none
//@usage: Merge(floor , pointsB, ceiling, pointsC, pointsA);
void Merge(int bNum, point* bPoints, int cNum, point* cPoints, point* aPoints){
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < bNum && j < cNum)
	{
		if (bPoints[i].x < cPoints[j].x) {
			aPoints[k] = bPoints[i];
			i++;
		} else if (bPoints[i].x == cPoints[j].x && bPoints[i].y < cPoints[j].y){
			aPoints[k] = bPoints[i];
			i++;
		} else {
			aPoints[k] = cPoints[j];
			j++;
		}
		k++;
	} 
	if(i == bNum)
	{
		Copy(j, cNum, cPoints, k, bNum + cNum,  aPoints);
	} else {
		Copy(i, bNum, bPoints, k, bNum + cNum,  aPoints);
	}
	
}

//Copies the rightHS array of the struct point into the leftHS
//@pre: rightFrom and rightTo are the begining and end of the rightHS that is to copied to the leftHS's leftFrom to leftTo elements
//@post: the rightHS array elements that are between rightFrom to rightTo has been copied to the leftHS leftFrom to the leftTo positions
//@param: rightFrom
//@       rightTo
//@       leftFrom
//@       leftTo
//@       rightHS
//@       leftHS
//@return: 0
//@throw: none
//@usage: Copy(j, cNum, cPoints, k, bNum + cNum,  aPoints);
void Copy(int rightFrom, int rightTo, point* rightHS, int leftFrom, int leftTo, point* leftHS){
	for(int i = 0; i < (rightTo - rightFrom) && i < (leftTo - leftFrom); i++){
		leftHS[leftFrom + i] = rightHS[rightFrom + i];
	}
}

// PrintLines prints num lines
//@pre: num must be a nonnegative integer
//@post: num lines are printed
//@param: int num
//@return: none
//@throw: none
//@usage: PrintLines(2);
void PrintLines(int num){
	for (int i = 0; i < num; i++)
      cout << endl;
}

// GeneratePointArray reads point values into an array from an input file
//@pre: numPoints must be the nonnegative integer number of points,
//      points must be an array of size 2*numPoints and in4.dat must hold
//      point values satisfying the pre-conditions of the algorithm
//@post: points holds the point values in in4.dat
//@param: int numPoints
//        int* points
//@return: none// LowerHull is a recursive algorithm that determines the convex hull of the upper division
//@pre: numPoints must be the nonnegative integer number of points,
//      points is an array of size numPoints, point1 and pointN are assigned
//@post: the pairs of extreme points making up the lower convex hull are output
//@param: int numPoints
//        point* points
//        point point1
//        point pointN
//@return: none
//@throw: none
//@usage: LowerHull(numPoints, points, point1, pointN); 
//@throw: none
//@usage: GeneratePointArray(numPoints, points);
void GeneratePointArray(int numPoints, point* points){
   ifstream pointsFile ("in5.dat");
   string line;
   if (pointsFile.is_open())
   {
      for (int i = 0; i < numPoints; i++){
         pointsFile >> points[i].x;
         pointsFile >> points[i].y;
      }
      pointsFile.close();
   }
   else cout << "Unable to open file.";
}


// ClockwiseQuickHull begins an algorithm to determine the convex hull in
// clockwise order
//@pre: numPoints must be the nonnegative integer number of points,
//      points must be an array of size numPoints
//@post: the pairs of extreme points making up the convex hull are output
//@param: int numPoints
//        points* points
//@return: none
//@throw: none
//@usage: ClockwiseQuickHull(numPoints, points);
void ClockwiseQuickHull(int numPoints, point* points){
    cout << "Convex Hull in Clockwise Order: " << endl;  
    if(numPoints == 2){
        PrintPoints(points[0], points[1]);
    } else {
        point* upperPoints;
	point* lowerPoints;
   	upperPoints = new (nothrow) point[numPoints];
	lowerPoints = new (nothrow) point[numPoints];
        int upperCount = UpperPartition(numPoints, points, upperPoints, points[0], points[numPoints - 1]);
        int lowerCount = LowerPartition(numPoints, points, lowerPoints, points[0], points[numPoints - 1]);
        UpperHull(upperCount, upperPoints, points[0], points[numPoints - 1]);
        UpperHull(lowerCount, lowerPoints, points[numPoints - 1], points[0]);
    }
}

// CounterClockwiseQuickHull begins an algorithm to determine the convex hull
// in counter-clockwise order
//@pre: numPoints must be the nonnegative integer number of points,
//      points must be an array of size numPoints
//@post: the pairs of extreme points making up the convex hull are output
//@param: int numPoints
//        points* points
//@return: none
//@throw: none
//@usage: CounterClockwiseQuickHull(numPoints, points);
void CounterClockwiseQuickHull(int numPoints, point* points){
    cout << "Convex Hull in Counter-Clockwise Order: " << endl;
    if(numPoints == 2){
        PrintPoints(points[0], points[1]);
    } else {
	point* upperPoints;
	point* lowerPoints;
   	upperPoints = new (nothrow) point[numPoints];
	lowerPoints = new (nothrow) point[numPoints];
        int upperCount = UpperPartition(numPoints, points, upperPoints, points[0], points[numPoints - 1]);
        int lowerCount = LowerPartition(numPoints, points, lowerPoints, points[0], points[numPoints - 1]);
        LowerHull(lowerCount, lowerPoints, points[0], points[numPoints - 1]);
        LowerHull(upperCount, upperPoints, points[numPoints - 1], points[0]);
    }
}

// UpperHull is a recursive algorithm that determines the convex hull of the upper division
//@pre: numPoints must be the nonnegative integer number of points,
//      points is an array of size numPoints, point1 and pointN are assigned
//@post: the pairs of extreme points making up the upper convex hull are output
//@param: int numPoints
//        point* points
//        point point1
//        point pointN
//@return: none
//@throw: none
//@usage: UpperHull(numPoints, points, point1, pointN);
void UpperHull(int numPoints, point* points, point point1, point pointN){
   if (numPoints == 0)
      PrintPoints(point1, pointN);
   else{
      point pointMax = FindPointMax(numPoints, points, point1, pointN);
      point* S1;
      point* S2;
      S1 = new (nothrow) point[numPoints];
      S2 = new (nothrow) point[numPoints];
      
      int countS1 = UpperPartition(numPoints, points, S1, point1, pointMax);
      int countS2 = UpperPartition(numPoints, points, S2, pointMax, pointN);
      UpperHull(countS1, S1, point1, pointMax);
      UpperHull(countS2, S2, pointMax, pointN);
   }
}

// LowerHull is a recursive algorithm that determines the convex hull of the upper division
//@pre: numPoints must be the nonnegative integer number of points,
//      points is an array of size numPoints, point1 and pointN are assigned
//@post: the pairs of extreme points making up the lower convex hull are output
//@param: int numPoints
//        point* points
//        point point1
//        point pointN
//@return: none
//@throw: none
//@usage: LowerHull(numPoints, points, point1, pointN); 
void LowerHull(int numPoints, point* points, point point1, point pointN){
   if (numPoints == 0)
      PrintPoints(point1, pointN);
   else{
      point pointMax = FindPointMax(numPoints, points, point1, pointN);
      point* S1;
      point* S2;
      S1 = new (nothrow) point[numPoints];
      S2 = new (nothrow) point[numPoints];
      
      int countS1 = LowerPartition(numPoints, points, S1, point1, pointMax);
      int countS2 = LowerPartition(numPoints, points, S2, pointMax, pointN);
      LowerHull(countS1, S1, point1, pointMax);
      LowerHull(countS2, S2, pointMax, pointN);
   }
}

// UpperPartition places the points from "points" into upperPoints that are above the line from
// point1 to pointN
//@pre: numPoints is nonnegative integer number of points, points is array of size numPoints
//      upperPoints is created, point1 and pointN are assigned
//@post: upperPoints holds the points in "points" that are above the line between point1 and
//       pointN
//@param: int numPoints
//        point* points
//        point* upperPoints
//        point point1
//        point pointN
//@return: number of points contained in upperPoints
//@throw: none
//@usage: upperCount = UpperPartition(numPoints, points, upperPoints, point1, pointN);
int UpperPartition(int numPoints, point* points, point* upperPoints, point point1, point pointN){
   int upperCount = 0;
   for (int i = 0; i < numPoints; i++){
      if (Determinant(point1, pointN, points[i]) > 0){
         upperPoints[upperCount] = points[i];
         upperCount++;
      }
   }
   return upperCount;
}

// LowerPartition places the points from "points" into lowerPoints that are below the line from
// point1 to pointN
//@pre: numPoints is nonnegative integer number of points, points is array of size numPoints
//      lowerPoints is created, point1 and pointN are assigned
//@post: lowerPoints holds the points in "points" that are below the line between point1 and
//       pointN
//@param: int numPoints
//        point* points
//        point* lowerPoints
//        point point1
//        point pointN
//@return: number of points contained in lowerPoints
//@throw: none
//@usage: lowerCount = LowerPartition(numPoints, points, lowerPoints, point1, pointN);
int LowerPartition(int numPoints, point* points, point* lowerPoints, point point1, point pointN){
   int lowerCount = 0;
   for (int i = 0; i < numPoints; i++){
      if (Determinant(point1, pointN, points[i]) < 0){
         lowerPoints[lowerCount] = points[i];
         lowerCount++;
      }
   }
   return lowerCount;
}

// FindPointMax finds the point that is the maximum distance from the line between
// point1 and pointN
//@pre: numPoints is number of points, points is array of this size and point1 and
//      pointN have been assigned
//@post: returns the point that is the maximum distance from the line between point1
//       and pointN
//@param: int numPoints
//        point* points
//        point point1
//        point pointN
//@return: point that is max distance from line between point1 and pointN
//@throw: none
//@usage: pointMax = FindPointMax(numPoints, points, point1, pointN);
point FindPointMax(int numPoints, point* points, point point1, point pointN){
   int DMax = abs(Determinant(point1, pointN, points[0]));
   point pointMax = points[0];
   
   for (int i = 0; i < numPoints; i++){
      int newD = abs(Determinant(point1, pointN, points[i]));
      if (newD > DMax){
         DMax = newD;
         pointMax = points[i];
      }
   }
   return pointMax;
}

// PrintPoints prints the points in a readable manner
//@pre: point1 and point2 must be assigned
//@post: points are printed
//@param: point point1
//        point point2
//@return: none
//@throw: none
//@usage: PrintPoints(point1, pointN);
void PrintPoints(point point1, point point2){
   cout << "{";
   if (point1.x < 0){
      cout << point1.x;
   } else {
      cout << " " << point1.x;
   }
   cout << ", ";
   if (point1.y < 0){
      cout << point1.y;
   } else {
      cout << " " << point1.y;
   }
   cout << "} and {";
   if (point2.x < 0){
      cout << point2.x;
   } else {
   cout << " " << point2.x;
   }
   cout << ", ";
   if (point2.y < 0){
      cout << point2.y;
   } else {
      cout << " " << point2.y;
   }
   cout << "}" << endl;
}

// Determinant determines the determinant |x1 y1 1|
//                                        |x2 y2 1|
//                                        |x3 y3 1|
//@pre: point1, point2 and point3 must be assigned
//@post: determinant is returned
//@param: point point1
//        point point2
//        point point3
//@return: determinant of points
//@throw: none
//@usage: det = Determinant(point1, point2, point3);
int Determinant(point point1, point point2, point point3){
   return (point1.x * point2.y + point3.x * point1.y + point2.x * point3.y - point3.x * point2.y - point2.x * point1.y - point1.x * point3.y);
}


