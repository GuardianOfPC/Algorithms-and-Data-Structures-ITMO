#include <fstream>
#include <vector>

std::vector <int> graph[100000];
bool used[100000];
int components[1000000];

void dfs(int v, int component_number){
    used[v] = true;
    components[v] = component_number;

    for (int u: graph[v]){
        if (!used[u]){
            dfs(u, component_number);
        }
    }
}

int main(){
    std::ifstream fin("components.in");
    std::ofstream fout("components.out");
    int n;
    int m;
    fin >> n >> m;
    for (int i = 0; i < m; i++){
        int b, e;
        fin >> b >> e;

        b--;
        e--;

        graph[b].push_back(e);
        graph[e].push_back(b);
    }

    int component_number = 1;

    for (int i = 0; i < n; i++){
        if (!used[i]){
            dfs(i, component_number);
            component_number++;
        }
    }

    fout << component_number - 1 << "\n";

    for (int i = 0; i < n; i++){
        fout << components[i] << " ";
    }
    return 0;
}
