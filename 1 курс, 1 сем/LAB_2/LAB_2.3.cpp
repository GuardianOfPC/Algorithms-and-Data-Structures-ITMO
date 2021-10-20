#include <fstream>

using namespace std;

long long n, arr[300000], A[300000], ans;
void mergeSort(long left, long right) {
    if (left < right) {
        long mid = (left + right) / 2, invLeft = mid - left + 1;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        long i = 0, j = 0;
        while (left + i <= mid && mid + 1 + j <= right) {
            if (A[left + i] > A[mid + 1 + j]) {
                arr[i + j] = A[mid + 1 + j];
                ans += invLeft - i;
                j++;
            }
            else {
                arr[i + j] = A[left + i];
                i++;
            }
        }
        while (left + i <= mid) {
            arr[i + j] = A[left + i];
            i++;
        }

        while (mid + 1 + j <= right) {
            arr[i + j] = A[mid + 1 + j];
            ans += invLeft - i;
            j++;
        }

        for (i = 0; i < right - left + 1; i++)
            A[left + i] = arr[i];
    }
}

int main() {
    ifstream fin("inversions.in");
    ofstream fout("inversions.out");
    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> A[i];
    mergeSort(0, n - 1);
    fout << ans;
    fin.close();
    fout.close();
}