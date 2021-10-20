#include <fstream>
#include <vector>
#include <stack>

std::vector<int> graph[100000];
int colours[100000];
std::stack<int> sorted;

std::ifstream fin("topsort.in");
std::ofstream fout("topsort.out");

enum Colours{
    WHITE,
    GRAY,
    BLACK
};

void TopSort(int ver){
    colours[ver] = GRAY;
    for (int u: graph[ver]){
        if (colours[u] == WHITE){
            TopSort(u);
        }
        else if(colours[u] == GRAY){
            fout << "-1";
            exit(0);
        }
    }
    colours[ver] = BLACK;
    sorted.push(ver+1);
}

int main(){
    int n, m;
    fin >> n >> m;

    for (int i = 0; i < m; i++){
        int b, e;
        fin >> b >> e;
        graph[b - 1].push_back(e - 1);
    }

    for(int i = 0; i < n; i++){
        if (colours[i] != BLACK){
            TopSort(i);
        }
    }

    while(!sorted.empty()){
        fout << sorted.top() << " ";
        sorted.pop();
    }

    return 0;
}