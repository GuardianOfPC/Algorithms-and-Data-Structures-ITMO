#include <fstream>
#include <vector>

using namespace std;
ifstream in;
ofstream out;

int main() {
	int n;
	float temp;
	in.open("sortland.in");
	in >> n;
	vector <float> a(n);
	vector <float> b(n);
	for (int i = 0; i < n; i++) {
		in >> a[i];
		b[i] = a[i];
	}
	in.close();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (b[i] > b[j]) {
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	out.open("sortland.out");
	for (int i = 0; i < n; i++) {
		if (a[i] == b[0])
			out << i + 1 << ' ';
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == b[n / 2])
			out << i + 1 << ' ';
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == b[n - 1])
			out << i + 1;
	}
	return 0;
}
