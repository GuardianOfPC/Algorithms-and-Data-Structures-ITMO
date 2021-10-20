#include <stdio.h>
#include <vector>
#include <limits>


const long long INF = std::numeric_limits<long long>::max();

struct Edge{
    int destination;
    long long range;
};

class CGraph{
private:
    std::vector<std::vector<Edge>> edges;
    std::vector<bool> used;
    int v, e, s;
public:
    void Import(){
        scanf("%d %d %d", &v, &e, &s);
        s--;
        used.resize(v);
        edges.resize(v);

        for (int i = 0; i < e; ++i){
            int s, f; long long w;
            scanf("%d %d %lld", &s, &f, &w);
            s--; f--;
            edges[s].push_back({f, w});
        }
    }

    void dfs(int v){
        used[v] = true;
        for(auto &u: edges[v]){
            int dstn = u.destination;
            if(!used[dstn]) dfs(dstn);
        }
    }

    void BFord() {
        std::vector<long long> range(v, INF);
        range[s] = 0;

        for (int i = 0; i < v - 1; ++i){
            for (int j = 0; j < v; ++j){
                for (auto &u: edges[j]){
                    int dstn = u.destination;
                    long long range_u = u.range;
                    if ((range[j] + range_u < range[dstn]) && (range[j] < INF)){
                        range[dstn] = std::max(-INF, range[j] + range_u);
                    }
                }
            }
        }

        for (int i = 0; i < v; ++i){
            for (auto &u: edges[i]){
                int dstn = u.destination;
                long long range_u = u.range;
                if ((range[i] + range_u < range[dstn]) && (range[i] < INF) && (!used[dstn])){
                    dfs(dstn);
                }
            }
        }

        for (int i = 0; i < v; ++i){
            if (range[i] == INF){
                printf("*\n");
            }
            else if (used[i] || range[i] < -5e18){
                printf("-\n");
            }
            else printf("%lld\n", range[i]);
        }
    }
};

int main(){
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);

    CGraph graph;
    graph.Import();
    graph.BFord();
    return 0;
}