#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

std::ifstream fin("hamiltonian.in");
std::ofstream fout("hamiltonian.out");

enum class Colours{
    WHITE,
    GRAY,
    BLACK
};

std::vector<std::vector<int> > graph;
std::vector<Colours> used;
std::stack<int>top_sort;

void TopSort(int ver){
    used[ver] = Colours::GRAY;
    for(int u:graph[ver]){
        if(used[u] == Colours::WHITE){
            TopSort(u);
        }
    }
    used[ver] = Colours::BLACK;
    top_sort.push(ver);
}

bool HamiltonWay(int n){
    std::vector <int> sorted;
    for(int i = 0; i < n; i++){
        if(used[i] != Colours::BLACK){
            TopSort(i);
        }
    }
    while (!top_sort.empty()){
        sorted.push_back(top_sort.top());
        top_sort.pop();
    }

    for (int i = 1; i < sorted.size(); i++){
        if (std::find(graph[sorted[i-1]].begin(), graph[sorted[i-1]].end(), sorted[i]) == graph[sorted[i-1]].end()) return false;
    }
    return true;
}

int main(){
    int n, m;
    fin >> n >> m;

    graph.resize(n);
    used.resize(n);

    for (int i = 0; i < m; i++){
        int b, e;
        fin >> b >> e;
        b--;e--;
        graph[b].push_back(e);
    }

    if (HamiltonWay(n) == true){
        fout << "YES";
    } else fout << "NO";

    return 0;
}