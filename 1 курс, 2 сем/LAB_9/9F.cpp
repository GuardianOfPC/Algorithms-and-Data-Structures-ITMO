#include <fstream>
#include <vector>


std::ifstream fin("game.in");
std::ofstream fout("game.out");

enum class Colours{
    WHITE,
    GRAY,
    BLACK
};

enum class Player{
    SECOND,
    FIRST

};

std::vector<std::vector<int> > graph;
std::vector<Colours> used;
std::vector<Player>place;

void dfs(int ver){
    used[ver] = Colours::BLACK;
    for (int u:graph[ver]){
        if (used[u] == Colours::WHITE){
            dfs(u);
        }
        if (place[u] == Player::SECOND){
            place[ver] = Player::FIRST;
        }
    }
}

bool The_Game(int s){
    for (int i = 0; i < graph.size(); i++){
        if (used[i] != Colours::BLACK){
            dfs(s - 1);
        }
    }

    if (place[s - 1] == Player::FIRST){
        return true;
    } else return false;
}

int main(){
    int n, m, s;
    fin >> n >> m >> s;

    graph.resize(n+1);
    used.resize(n+1);
    place.resize(n+1);

    for (int i = 0; i < m; i++){
        int b, e;
        fin >> b >> e;
        b--;e--;
        graph[b].push_back(e);
    }

    if (The_Game(s) == true){
        fout << "First player wins";
    } else fout << "Second player wins";

    return 0;
}