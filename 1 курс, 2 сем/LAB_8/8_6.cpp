#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::pair <int, int> Point;

int main(){
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, m;
    fin >> m >> n;

    Point start;
    Point finish;

    std::vector <std::vector<char>> labyrinth(1 + m + 1, std::vector<char> (1 + n + 1));
    std::vector <std::vector<std::vector<Point>>> graph (1 + m + 1, std::vector<std::vector<Point>>(1+n+1,std::vector<Point>()));
    std::vector <std::vector<bool>> used (1 + m + 1, std::vector<bool>(1 + n + 1));
    std::vector <std::vector<int>> range (1 + m + 1, std::vector<int>(1 + n +1));
    std::vector <std::vector<Point>> previous_vertices (1 + m + 1, std::vector<Point>(1 + n + 1));

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            fin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'S'){
                start = std::make_pair(i, j);
                labyrinth[i][j] = '.';
            }
            else if (labyrinth[i][j] == 'T'){
                finish = std::make_pair(i,j);
                labyrinth[i][j] = '.';
            }
        }
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (labyrinth[i][j] == '.' && labyrinth[i][j + 1] == '.' && labyrinth[i][j + 1] != '\0') {
                graph[i][j].emplace_back(i, j + 1);
            }
            if (labyrinth[i][j] == '.' && labyrinth[i][j - 1] == '.' && labyrinth[i][j - 1] != '\0') {
                graph[i][j].emplace_back(i, j - 1);
            }
            if (labyrinth[i][j] == '.' && labyrinth[i + 1][j] == '.' && labyrinth[i + 1][j] != '\0') {
                graph[i][j].emplace_back(i + 1, j);
            }
            if (labyrinth[i][j] == '.' && labyrinth[i - 1][j] == '.' && labyrinth[i - 1][j] != '\0') {
                graph[i][j].emplace_back(i - 1, j);
            }
        }
    }

    std::queue<Point> q;
    q.push(start);
    used[start.first][start.second] = true;
    range[start.first][start.second] = 0;
    previous_vertices[start.first][start.second] = std::make_pair(-1, -1);

    while (!q.empty()){
        Point current = q.front();
        q.pop();

        for (Point u: graph[current.first][current.second]){
            if (!used[u.first][u.second]){
                q.push(u);
                used[u.first][u.second] = true;
                range[u.first][u.second] = range[current.first][current.second] + 1;
                previous_vertices[u.first][u.second] = current;
            }
        }
    }

    if (used[finish.first][finish.second] == true){
        fout << range[finish.first][finish.second] << "\n";
    }
    else {
        fout << "-1" << "\n";
        return 0;
    }

    std::vector<Point> route;
    Point current = finish;
    route.push_back(current);

    while (previous_vertices[current.first][current.second].first != -1){
        current = previous_vertices[current.first][current.second];
        route.push_back(current);
    }

    std::reverse(route.begin(),route.end());

    for (int i = 1; i < route.size(); i++){
        if (route[i].second - route[i - 1].second == 1){
            fout << "R";
        }
        else if (route[i].second - route[i - 1].second == -1){
            fout << "L";
        }
        else if (route[i].first - route[i - 1].first == 1){
            fout << "D";
        }
        else if (route[i].first - route[i - 1].first == -1){
            fout << "U";
        }
    }
    return 0;
}