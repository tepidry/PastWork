//@ authors:  Ryan Draper (rdraper)  Patrick Mosca (pmosca)
//@ date March 8, 2013
//@ file prog4.cpp
//@ Implementation of
//@ Abstract Data Type coordiate
//@    data object: an x and y coordinate
//@    data structures: a struct that has two integers in is a x and a y that
//@                     is used to fill a vector.
//@                     Also a Vector is used to store these coordintaes
//@                     which is a sequence container representing
//@                     an array that can change insize. Just like arrays, vectors
//@                     use contiguous storage locations for their elements
//@    operations: (bool operator <)


#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


struct coordinate
    {
        int x, y;
    };

//@this inline-expands a function call to lhs < rhs, the function's code gets inserted into the caller's code stream
//@pre lhs and rhs are coordinates
//@post True or false is returned depending if the the lhs coordinates is less than the rhs
//@return Bool value
//@param lhs
//@      rhs
//@usage while (sameSign && iteratorForOtherPoints < numberOfPoints) {
inline bool operator<(const coordinate& lhs, const coordinate& rhs);

//@Reads the set of 10 coordinates that are in the 'in4.dat' file
//@pre the infile 'in4.dat' has 10 coordinates
//@post the points are returned in the vector of coordinates
//@return a vector of coordinates
//@usage filePoints = readFilePoints();
vector<coordinate> readFilePoints();

//@Prints the extreme points that are within the vector of points that make up the outside points of the convex Hull
//@pre points are a vector of extreme points from the set of points that make up the convex hull
//@post the extreme points are output
//@param points
//@usage printExtremePoints(extremePoints);
void printExtremePoints(set<coordinate> points);

//@opens an external file for reading and loads
//@post if the external file "in4.dat" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@Finds the extreme points that are within the vector of points that make up the outside points of the convex hull
//@pre the vector of coordinates contains ten points
//@post the vecotr hulls extreme points are found and returned in a set of coordinates
//@returns a set of coordinates that are the points that make up the extrememe points of the convex hull
//@param points
//@usage extremePoints = findExtremePoints(filePoints);
set<coordinate> findExtremePoints(vector<coordinate> points);

//@MAIN
int main(int argc, const char * argv[])
{
    vector<coordinate> filePoints;
    set<coordinate> extremePoints;
    
    filePoints = readFilePoints();
    extremePoints = findExtremePoints(filePoints);
    printExtremePoints(extremePoints);
    
    return 0;
}

//@this inline-expands a function call to lhs < rhs, the function's code gets inserted into the caller's code stream 
//@pre lhs and rhs are coordinates
//@post True or false is returned depending if the the lhs coordinates is less than the rhs
//@return Bool value
//@param lhs
//@      rhs
//@usage while (sameSign && iteratorForOtherPoints < numberOfPoints) 
inline bool operator<(const coordinate& lhs, const coordinate& rhs)
{
    return (lhs.x,lhs.y) < (rhs.x,rhs.y);
}

//@Reads the set of 10 coordinates that are in the 'in4.dat' file
//@pre the infile 'in4.dat' has 10 coordinates
//@post the points are returned in the vector of coordinates
//@return a vector of coordinates
//@usage filePoints = readFilePoints();
vector<coordinate> readFilePoints()
{
    ifstream infile;
    bool fileOk;
    vector<coordinate> points;
    OpenInputFile(infile, fileOk);
    coordinate coord;
    
    for (int i = 0; i < 10; i++)
    {
        infile >> coord.x;
        infile >> coord.y;
        points.push_back(coord);
    }
    return points;
}

//@Prints the extreme points that are within the vector of points that make up the outside points of the convex Hull
//@pre points are a vector of extreme points from the set of points that make up the convex hull
//@post the extreme points are output
//@param points
//@usage printExtremePoints(extremePoints);
void printExtremePoints(set<coordinate> points)
{
    set<coordinate>::iterator iter;
    cout << endl << "Extreme points:" << endl;
	for (iter = points.begin(); iter != points.end(); ++iter) {
        cout << "(" << iter->x << "," << iter->y << ")" << endl;
    }
    cout << endl;
}

//@opens an external file for reading and loads
//@post if the external file "in4.dat" exists, then it is associated with infile, its
//@     pointer is at the beginning, and fileOk is true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk)
{
    infile.open("in4.dat");
    if (infile.fail())
    {
        fileOk = false;
        cout << "Error: file does not exist" << endl;
    } else {
        fileOk = true;
    }
}

//@Finds the extreme points that are within the vector of points that make up the outside points of the convex hull
//@pre the vector of coordinates contains ten points
//@post the vecotr hulls extreme points are found and returned in a set of coordinates
//@returns a set of coordinates that are the points that make up the extrememe points of the convex hull
//@param points
//@usage extremePoints = findExtremePoints(filePoints);
set<coordinate> findExtremePoints(vector<coordinate> points)
{
    set<coordinate> extremePoints;
    int xi, yi;
    int xj, yj;
    int xK, yK;
    int a, b, c;
    const int numberOfPoints = (int)points.size();
    int signOfPoint;
    bool signSet;
    bool sameSign;
    int lastSign;
    int iteratorForOtherPoints;
    
    //Must have at least three points
    if (numberOfPoints > 2) {
        //Permute every point to every other point
        for (int i = 0; i < (numberOfPoints - 1); i++) {
            for (int j = i + 1; j < numberOfPoints; j++) {
                xi = points.at(i).x;
                yi = points.at(i).y;
                
                xj = points.at(j).x;
                yj = points.at(j).y;
                
                a = yj - yi;
                b = xi - xj;
                
                c = (xi * yj) - (yi * xj);
                
                signSet = false;
                sameSign = true;
                lastSign = 0;
                //Check all other points
                iteratorForOtherPoints = 0;
                while (sameSign && iteratorForOtherPoints < numberOfPoints)
                {
                    //Ignore the current two points
                    if (iteratorForOtherPoints != i && iteratorForOtherPoints != j)
                    {
                        xK = points.at(iteratorForOtherPoints).x;
                        yK = points.at(iteratorForOtherPoints).y;
                        
                        signOfPoint = (a * xK) + (b * yK) - c;
                        if (signSet) {
                            sameSign = (signOfPoint < 0) == (lastSign < 0);
                        }
                        else {
                            signSet = true;
                        }
                        lastSign = signOfPoint;
                    }
                    iteratorForOtherPoints++;
                }
                
               if (sameSign) {
                   extremePoints.insert(points.at(i));
                   extremePoints.insert(points.at(j));
                }
            }
        }
    }
    return extremePoints;
}

