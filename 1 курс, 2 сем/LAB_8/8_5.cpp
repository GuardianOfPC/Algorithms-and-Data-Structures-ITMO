#include <fstream>
#include <vector>
#include <queue>

std::vector <int> graph[100000];
bool used[100000];
int range[1000000];


int main(){
    std::ifstream fin("pathbge1.in");
    std::ofstream fout("pathbge1.out");
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

    std::queue <int> q;
    used[0] = true;
    q.push(0);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int u: graph[current]){
            if (!used[u]){
                used[u] = true;
                q.push(u);
                range[u] = range[current] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++){
        fout << range[i] << " ";
    }

    return 0;
}
