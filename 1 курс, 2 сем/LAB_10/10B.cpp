#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits.h>

std::ifstream fin("spantree.in");
std::ofstream fout("spantree.out");

class Graph
{
private:
    int n;
    std::vector<int> x;
    std::vector<int> y;
public:
    void MST() {
        fin >> n;
        x.resize(n); y.resize(n);
        for (int i = 0; i < n; i++)
            fin >> x[i] >> y[i];

        std::vector<bool> fMST(n);
        std::vector<int> range(n,INT_MAX);
        double mstRange = 0;
        range[0] = 0;

        for (int i = 0; i < n; i++) {
            int minim = -1;
            for (int j = 0; j < n; j++)
                if (!fMST[j] && (minim == -1 || range[j] < range[minim]))
                    minim = j;

            fMST[minim] = true;

            for (int j = 0; j < n; j++) {
                int dx = x[j] - x[minim];
                int dy = y[j] - y[minim];
                int d = dx * dx + dy * dy;
                if (!fMST[j] && d < range[j] && minim != j) range[j] = d;
            }
        }
        for (int u: range) {
            mstRange += sqrt(u);
        }
        fout << std::setprecision(10) << mstRange;
    }
};

int main() {
    Graph graph;
    graph.MST();
    return 0;
}