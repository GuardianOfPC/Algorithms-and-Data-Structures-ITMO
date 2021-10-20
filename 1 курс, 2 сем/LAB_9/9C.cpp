#include <fstream>
#include <vector>

std::ifstream fin("bipartite.in");
std::ofstream fout("bipartite.out");

enum class Stances{
    NOT_VISITED,
    STANCE_ONE,
    STANCE_TWO
};

std::vector <std::vector<int>>graph;
std::vector <Stances> vec_stances;

Stances reverseStance (Stances s){
    return s == Stances:: STANCE_ONE ? Stances::STANCE_TWO : Stances:: STANCE_ONE;
}

void dfs(int v, Stances st){
    vec_stances[v] = st;
    for (int u:graph[v]){
        if (vec_stances[u] == Stances::NOT_VISITED){
            dfs(u, reverseStance(st));
        } else if (vec_stances[u] == st){
            fout << "NO";
            exit(0);
        }
    }
}

int main(){
    int n, m;
    fin >> n >> m;

    vec_stances.resize(n + 1, Stances::NOT_VISITED);
    graph.resize(n + 1);

    for (int i = 0; i < m; i++){
        int b, e;
        fin >> b >> e;

        graph[b - 1].push_back(e - 1);
        graph[e - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; i++){
        if (vec_stances[i] == Stances::NOT_VISITED){
            dfs(i, Stances:: STANCE_ONE);
        }
    }

    fout << "YES";
    return 0;
}