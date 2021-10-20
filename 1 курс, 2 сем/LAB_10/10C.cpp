#include <vector>
#include <stdio.h>
#include <algorithm>

struct Edge{
    int b, e, w;
};

bool comparator(const Edge &left, const Edge &right){
    return left.w < right.w;
}

class Graph{
private:
    std::vector<int> z;
    std::vector<Edge> edges;
    int n = 0, m = 0;
public:
    void GraphInput(){
        scanf("%d %d", &n, &m);
        z.assign(n + 1, -1);

        for (int i = 0; i < m; i++){
            int b, e, w;
            scanf("%d %d %d", &b, &e, &w);
            edges.push_back(Edge{b, e, w});
        }
    }

    int Root(int e){
        if (z[e] < 0){
            return e;
        } else{
            int root = Root(z[e]);
            z[e] = root;
            return root;
        }
    }

    bool unite(int b, int e){ //система непересекающихся множеств
        b = Root(b);
        e = Root(e);

        if (b == e)
            return false;

        if (z[b] < z[e]){
            z[b] += z[e];
            z[e] = b;
        } else {
            z[e] += z[b];
            z[b] = e;
        }
        return true;
    }

    void kMST(){
        GraphInput();
        std::sort(edges.begin(), edges.end(), comparator);
        long long count = 0;
        for (const Edge &u: edges){
            if (unite(u.b, u.e))
                count += u.w;
        }
        printf("%lld", count);
    }
};

int main(){
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    Graph graph;
    graph.kMST();
    return 0;
}