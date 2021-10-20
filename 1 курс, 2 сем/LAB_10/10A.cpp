#include <fstream>
#include <vector>


std::ifstream fin("input.txt");
std::ofstream fout("output.txt");


int main() {
    int n, m;
    fin >> n >> m;
    std::vector <int> vertices(1000);

    for (int i = 0; i < m; ++i){
        int b, e;
        fin >> b >> e;

        vertices[b - 1] += 1;
        vertices[e - 1] += 1;
    }

    for (int i = 0; i < n; ++i){
        fout << vertices[i] << " ";
    }
    return 0;
}