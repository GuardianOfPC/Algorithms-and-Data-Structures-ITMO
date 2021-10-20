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
    int v, e;
public:
    void Import(){
        scanf("%d %d", &v, &e);
        result.resize(v, INF);
        graph.resize(v);

        for (int i = 0; i < e; ++i){
            int s, f, w;
            scanf("%d %d %d", &s, &f, &w);
            s--; f--;
            graph[s].push_back({w, f});
        }
    }

    void dijkstra() {
        for (int i = 0; i < v; ++i) {
            result[i] = 0;

            std::priority_queue<edge, std::vector<edge>, std::greater<>> q;
            q.push({0, i});

            while (!q.empty()) {
                edge v = q.top();
                q.pop();
                long long v_range = v.first;
                int v_num = v.second;

                if (result[v_num] < v_range) continue;

                for (edge &u: graph[v_num]) {
                    int u_range = u.first, u_num = u.second;
                    long long n_range = v_range + u_range;
                    if (n_range < result[u_num]) {
                        result[u_num] = n_range;
                        q.push({n_range, u_num});
                    }
                }
            }
            for (long long u: result){
                printf("%d ", u);
            }
            printf("\n");
            result.assign(v, INF);
        }
    }
};

int main(){
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);

    CGraph graph;
    graph.Import();
    graph.dijkstra();
    return 0;
}