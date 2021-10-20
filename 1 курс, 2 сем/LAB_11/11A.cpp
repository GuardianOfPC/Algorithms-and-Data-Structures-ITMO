#include <stdio.h>
#include <vector>
#include <queue>
#include <limits>

typedef std::pair<long long, int> edge;
const long long INF = std::numeric_limits<long long>::max();

class CGraph{
private:
    std::vector<std::vector<edge>> graph;
    std::vector<long long> result;
    int n, s, f;
public:
    void Import(){
        scanf("%d %d %d", &n, &s, &f);
        s--; f--;
        result.resize(n, INF);
        graph.resize(n);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                int w;
                scanf("%d", &w);
                if (i == j || w == -1) continue;
                graph[i].push_back({w, j});
            }
        }
    }

    long long dijkstra(){
        result[s] = 0;

        std::priority_queue<edge, std::vector<edge>, std::greater<>> q;
        q.push({0, s});

        while(!q.empty()){
            edge v = q.top();
            q.pop();
            long long v_range = v.first;
            int v_num = v.second;

            if (result[v_num] < v_range) continue;

            for (edge &u: graph[v_num]){
                int u_range = u.first, u_num = u.second;
                long long n_range = v_range + u_range;
                if (n_range < result[u_num]){
                    result[u_num] = n_range;
                    q.push({n_range, u_num});
                }
            }
        }
        return result[f] == INF ? -1 : result[f];
    }
};

int main(){
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);

    CGraph graph;
    graph.Import();
    printf("%lld", graph.dijkstra());
    return 0;
}