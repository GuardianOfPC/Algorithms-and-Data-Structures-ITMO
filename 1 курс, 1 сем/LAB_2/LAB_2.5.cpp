#include <fstream>
#include <vector>

using namespace std;

void quicksort(vector<int>& a, int left, int right, int k)
{
	int i, j, middle;
	i = left;
	j = right;
	middle = a[(left +right) / 2];
	while (i <= j){
		while (a[i] < middle){
			++i;
		}
		while (a[j] > middle){
			--j;
		}
		if (i <= j){
			swap(a[i++], a[j--]);
		}
	}
	if ((left < j) && (k <= j)){
		quicksort(a, left, j, k);
	}
	if ((i < right) && (k >= i)){
		quicksort(a, i, right, k);
	}
}

int main(){
	ifstream fin("kth.in");
	ofstream fout("kth.out");
	int n, k, A, B, C;
	fin >> n >> k;
	vector<int> arr(n);
	fin >> A >> B >> C >> arr[0] >> arr[1];
	for (int i = 2; i < n; i++){
		arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
	}
	quicksort(arr, 0, arr.size() - 1, k - 1);
	fout << arr[k - 1];
	fin.close();
	fout.close();
	return 0;
}