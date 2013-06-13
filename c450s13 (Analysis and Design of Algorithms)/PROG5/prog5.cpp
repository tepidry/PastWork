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

struct point 
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
//      points must be an array of size 2*numPoints and in4.dat must hold
//      point values satisfying the pre-conditions of the algorithm
//@post: points holds the point values in in4.dat
//@param: int numPoints
//        int* points
//@return: none
//@throw: none
//@usage: GeneratePointArray(numPoints, points);
void GeneratePointArray(int numPoints, point* points);


// ConvexHull performs the bruteforce algorithm to determine the convex hull
//@pre: numPoints must be the nonnegative integer number of points,
//      points must be an array of size 2*numPoints
//@post: the pairs of extreme points making up the convex hull are output
//@param: int numPoints
//        int* points
//@return: none
//@throw: none
//@usage: ConvexHull(numPoints, points);
void QuickHull(int numPoints, point* points);

void UpperHull(int numPoints, point* points, point point1, point pointN);

void LowerHull(int numPoints, point* points, point point1, point pointN);

int UpperPartition(int numPoints, point* points, point* upperPoints, point point1, point pointN);

int LowerPartition(int numPoints, point* points, point* lowerPoints, point point1, point pointN);

point FindPointMax(int numPoints, point* points, point point1, point pointN);

void PrintPoints(point point1, point point2);

int Determinant(point point1, point point2, point point3);



point* ReturnArrayFromTo(int start, int end, point* oldArray);

void ConcatenateArrayTo(int arrayASize, point* arrayA, int totalArraySize, point* totalArray);

void PrintArray(int size, point* Points);

void Copy(int rightFrom, int rightTo, point* rightHS, int leftFrom, int leftTo, point* leftHS);

//void 
//@pre: none
//@post: decimal number inputted, then fibonacci number calculated and returned
//       via several methods
//@param: none
//@return: 0
//@throw: none
int main(){
   int numPoints = 7;
   point* points;
   points = new (nothrow) point[numPoints];
   
   GeneratePointArray(numPoints, points);
   MergeSort(numPoints, points);
   PrintArray(numPoints, points);
   
   //QuickHull(numPoints, points);
	
   //Test
   /*
   point* upperPoints;
   point* lowerPoints;
   upperPoints = new (nothrow) point[numPoints];
	lowerPoints = new (nothrow) point[numPoints];
   int upperCount = UpperPartition(numPoints, points, upperPoints, points[0], points[2]);
   int lowerCount = LowerPartition(numPoints, points, lowerPoints, points[0], points[2]);
   for (int i = 0; i < upperCount; i++)
      cout << upperPoints[i].x << " " << upperPoints[i].y << endl;
   cout << endl;
   for (int j = 0; j < lowerCount; j++)
      cout << lowerPoints[j].x << " " << lowerPoints[j].y << endl << endl;
   
   point pointMaxUpper = FindPointMax(upperCount, upperPoints, points[0], points[2]);
   cout << pointMaxUpper.x << " " << pointMaxUpper.y << endl;
   point pointMaxLower = FindPointMax(lowerCount, lowerPoints, points[0], points[2]);
   cout << pointMaxLower.x << " " << pointMaxLower.y << endl;
   */
   //End Test
     
   
   return 0;
}

void PrintArray(int size, point* Points)
{
	for (int i = 0; i < size; i++)
   {
   	cout << Points[i].x << ", " << Points[i].y << endl;
   }
}

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

void Merge(int bNum, point* bPoints, int cNum, point* cPoints, point* aPoints){
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < bNum && j < cNum)
	{
		if (bPoints[i].x <= cPoints[j].x) {
			
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

void Copy(int rightFrom, int rightTo, point* rightHS, int leftFrom, int leftTo, point* leftHS){
	for(int i = 0; i < (rightTo - rightFrom) && i < (leftTo - leftFrom); i++){
		leftHS[leftFrom + i] = rightHS[rightFrom + i];
	}
}

void ConcatenateArrayTo(int arrayASize, point* arrayA, int totalArraySize, point* totalArray){
	for(int i = 0; i < arrayASize; i++){
		totalArray[totalArraySize] = arrayA[i];
	} 
}

//assuming end is larger than start
point* ReturnArrayFromTo(int start, int end, point* oldArray){
	point* newArray;
   newArray = new (nothrow) point[end - start];
	for(int i = 0; i < (end - start); i++)
	{
		newArray[i] = oldArray[i + start];
	}
	return newArray;
}

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
//      points must be an array of size 2*numPoints and in4.point* pointsdat must hold
//      point values satisfying the pre-conditions of the algorithm
//@post: points holds the point values in in4.dat
//@param: int numPoints
//        int* points
//@return: none
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


// ConvexHull performs the bruteforce algorithm to determine the convex hull
//@pre: numPoints must be the nonnegative integer number of points,
//      points must be an array of size 2*numPoints
//@post: the pairs of extreme points making up the convex hull are output
//@param: int numPoints
//        int* points
//@return: none
//@throw: none
//@usage: ConvexHull(numPoints, points);
void QuickHull(int numPoints, point* points){
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
      LowerHull(lowerCount, lowerPoints, points[0], points[numPoints - 1]);
	}
   
}

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

int Determinant(point point1, point point2, point point3){
   return (point1.x * point2.y + point3.x * point1.y + point2.x * point3.y - point3.x * point2.y - point2.x * point1.y - point1.x * point3.y);
}


