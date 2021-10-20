#include <fstream>
#include <vector>

std::ifstream fin("cycle.in");
std::ofstream fout("cycle.out");

std::vector<std::vector<int>> graph;
std::vector<int> colours;
std::vector<int> traversals;

int n, m;
bool flag;

enum Colours {
    WHITE,
    GRAY,
    BLACK
};

void DFS (int ver) {
    if (flag) return;
    else {
        colours[ver] = GRAY;
        traversals.push_back(ver);
        for (int u: graph[ver]) {
            if (colours[u] == GRAY) {
                traversals.push_back(u);
                flag = true;
                return;
            }
            else if (colours[u] == WHITE){
                DFS(u);
            }
            if (flag) return;
        }
        colours[ver] = BLACK;
        traversals.pop_back();
    }
}

void search() {
    for (int i = 1; i <= n; i++){
        if (colours[i] == WHITE) {
            DFS(i);
            if (flag) return;
        }
    }
}

int main() {
    fin >> n >> m;

    graph.resize(n + 1);
    colours.resize(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int begin, end;
        fin >> begin >> end;

        graph[begin].push_back(end);
    }

    search();

    if (flag) {
        fout << "YES" << std::endl;
        int i = traversals.size() - 2;
        int cycled = traversals.back();
        while (traversals[i] != cycled)
            i--;
        while (i < traversals.size() - 1){
            fout << traversals[i] << " ";
            i++;
        }
    } else
        fout << "NO";

    return 0;
}