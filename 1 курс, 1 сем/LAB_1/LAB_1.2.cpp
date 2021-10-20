#include <iostream>
#include <fstream>

using namespace std;
ifstream in;
ofstream out;

int main() 
{
	in.open("aplusbb.in");
	long long a, b;
	in >> a >> b;
	in.close();
	out.open("aplusbb.out");
	out << a + b * b << endl;
	return 0;
}