#include <fstream>

int main() {
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int n, m;
	fin >> n >> m;
	int graph[100][100] = { 0 };

	for (int i = 0; i < m; i++) {
		int u, v;
		fin >> u >> v;
		u--;
		v--;
		graph[u][v] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fout << graph[i][j] << " ";
		}
		fout << std::endl;
	}

	return 0;
}