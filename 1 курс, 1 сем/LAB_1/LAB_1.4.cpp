#include <fstream>
#include <vector>

using namespace std;
ifstream in;
ofstream out;

int main() {
	in.open("smallsort.in");
	int n, temp;
	in >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
	for (int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	out.open("smallsort.out");
	for (int i = 0; i < n; i++) {
		out << a[i] << " ";
	}
	out.close();
	return 0;
}
