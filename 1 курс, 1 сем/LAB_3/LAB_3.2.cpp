#include <fstream>

using namespace std;

void SiftDown(int heap[], int n, int i) {
	int L = 2 * i;
	int R = 2 * i + 1;
	int largest = i;
	if (L < n && heap[L] > heap[largest]) {
		largest = L;
	}
	if (R < n && heap[R] > heap[largest]) {
		largest = R;
	}
	if (largest != i) {
		swap(heap[i], heap[largest]);
		SiftDown(heap, n, largest);
	}
}

void HeapSort(int heap[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		SiftDown(heap, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(heap[0], heap[i]);
		SiftDown(heap, i, 0);
	}
}

int main() {
	ifstream fin("sort.in");
	ofstream fout("sort.out");
	int n;
	fin >> n;
	int heap[100000];
	for (int i = 0; i < n; i++) { 
		fin >> heap[i]; }
	HeapSort(heap, n);
	for (int i = 0; i < n; i++) {
		fout << heap[i] << " "; 
	}
	fin.close();
	fout.close();
	return 0;
}