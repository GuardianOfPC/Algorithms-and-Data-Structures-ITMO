#include <fstream>
#include <vector>
#include <stack>

std::ifstream fin("cond.in");
std::ofstream fout("cond.out");

enum class Colours{
    WHITE,
    GRAY,
    BLACK
};

std::vector<std::vector<int> > graph;
std::vector<Colours> used;
std::stack<int>top_sort;
std::vector<int> sorted;
std::vector<int> components;


void Transposition(int n){
    std::vector<std::vector<int>> temp;
    temp.resize(n);
    for (int ver = 0; ver < n; ver++){
        for (int u:graph[ver]){
            temp[u].push_back(ver);
        }
    }
    graph.clear();
    graph = temp;
}

void TopSort(int ver){
    used[ver] = Colours::GRAY;
    for(int u: graph[ver]){
        if (used[u] == Colours::WHITE){
            TopSort(u);
        }
    }
    used[ver] = Colours::BLACK;
    top_sort.push(ver);
}

void dfs(int ver, int component){
    components[ver] = component;
    for (int u:graph[ver]){
        if (components[u] == 0){
            dfs(u, component);
        }
    }
}

int Condensation(int n){
    for (int i = 0; i < n; i++){
        if (used[i]!=Colours::BLACK){
            TopSort(i);
        }
    }
    for (int i = 0; i < n; i++){
        sorted[i] = top_sort.top();
        top_sort.pop();
    }
    Transposition(n);
    int count = 1;
    for (int i = 0; i < n; i++){
        if (components[sorted[i]] == 0){
            dfs(sorted[i], count);
            count++;
        }
    }
    return count - 1;
}

int main(){
    int n, m;
    fin >> n >> m;

    graph.resize(n);
    used.resize(n);
    sorted.resize(n);
    components.resize(n, 0);

    for (int i = 0; i < m; i++){
        int b, e;
        fin >> b >> e;
        b--;e--;
        graph[b].push_back(e);
    }

    fout << Condensation(n) << "\n";

    for (int u: components){
        fout << u << " ";
    }
    return 0;
}