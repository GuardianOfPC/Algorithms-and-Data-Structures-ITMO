#include <fstream>

int main(){
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;
    int graph[100][100];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
           if (graph[i][j] == 1){
               if (!(graph[i][j] == 1 && graph[j][i] == 1)){
                   fout << "NO";
                   return 0;
               }
           }
           if (graph[i][i] == 1) {
               fout << "NO";
               return 0;
           }
        }
    }
    fout << "YES";
    return 0;
    }