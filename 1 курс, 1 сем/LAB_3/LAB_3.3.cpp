#include <fstream>

using namespace std;

string a[1000], b[1000];
int n, m, k;

void RadixSort(int place) {
    char help = 'a';
    int t = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j][place] == help) {
                b[t] = a[j];
                t++;
            }
        }
        help++;
    }
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main() {
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");
    fin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    for (int i = m - 1; i >= m - k; i--) {
        RadixSort(i);
    }
    for (int i = 0; i < n; i++) {
        fout << a[i] << '\n';
    }    
    return 0;
}