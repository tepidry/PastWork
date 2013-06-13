#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int f(int a, int b)
{
	return a - b;
}
int g(int c, int d)
{
	return c + d;
}
int higherOrder( *int b, int d, int e)
{
	return b(d,e);
}
int main(){
	cout << higherOrder(f(), 1, 2);
	cout << higherOrder(g(), 1, 2);
}

