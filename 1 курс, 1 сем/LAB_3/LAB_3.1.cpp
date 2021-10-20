#include <fstream>
using namespace std;

int main() {
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");
    int n;
    fin >> n;
    int heap[100000];

    for (int i = 1; i <= n; i++) {
        fin >> heap[i];
    }
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (i >= 1 && i <= n) {
            if (2 * i <= n) {
                if (heap[i] <= heap[2 * i]) {
                    count += 1;
                }
            }
            if (2 * i + 1 <= n) {
                if (heap[i] <= heap[2 * i + 1]) {
                    count += 1;
                }
            }
        }
    }

    if (count == n - 1) {
        fout << "YES";
    }
    else fout << "NO";
    fin.close();
    fout.close();
    return 0;
}