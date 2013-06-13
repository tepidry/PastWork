//@ Specification of
//@ Abstract Data Type BucketsNPebbles
//@    data object: buckets filled with colored pebbles
//@    operations: SetUpBuckets, FillBuckets, GetColor, Swap, TrashBuckets
//@ file buckets.h
//@ date February 7, 2010
//@ author  Dr Y

enum Pebble {RED, WHITE, BLUE};
struct BuckStuff;

class Buckets
{
public:
   //@gets a number of buckets for the robot
   //@pre number is assigned the desired number of buckets
   //@post number buckets are placed in front of the robot
   //@param number is the number of buckets desired
   //@usage  b.SetUpBuckets(5);
   void SetUpBuckets(int number);
   
   //@fills all of the buckets with pebbles
   //@pre buckets are placed in front of the robot
   //@post one colored pebble is placed in each bucket
   //@     according to the user's input
   //@usage   b.FillBuckets();
   void FillBuckets();
   
   //@robot uses its eye to view the color of the pebble
   //@pre i is the position of the bucket
   //@    positions of the buckets are labeled 0, 1, 2, ....
   //@post the color of the pebble is returned
   //@param i
   //@return the color of the pebble
   //@usage  pebble = b.GetColor(2);
   Pebble GetColor(int i);
   
   //@robot swaps the pebbles in two buckets with its arms
   //@pre  i and j are the positions of the two buckets
   //@     buckets are given positions 0, 1, 2, 3,...
   //@post the pebbles in buckets i and j are swapped
   //@param i
   //@param j
   //@usage    b.Swap(i,j);
   void Swap (int i, int j);
   
   //@all of the buckets are thrown in the trash
   //@pre  there are buckets placed before the robot
   //@post there are no buckets placed before the robot
   //@usage   b.TrashBuckets();
   void TrashBuckets();
   
   //@counts the number of buckets placed before the robot
   //@pre   there are buckets
   //@post  returns the number of buckets
   //@usage   num = b.GetNum();
   int GetNumber();
private:
   BuckStuff* buckets;
};
