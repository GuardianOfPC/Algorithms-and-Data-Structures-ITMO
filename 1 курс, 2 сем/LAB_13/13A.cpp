#include <fstream>
#include <vector>
 
 
std::vector<int> Matcher(std::string const& t, std::string const& p){
    int n = t.length();
    int m = p.length();
    std::vector<int> ans;
    char buffer[10000] = " ";
    for (int i = 0; i <= n - m; ++i) {
        t.copy(buffer, m, i);
        buffer[m] = '\0';
        if (buffer == p){
            ans.push_back(i + 1);
        }
    }
    return ans;
}
 
int main(){
    std::ifstream fin("search1.in");
    std::ofstream fout("search1.out");
    std::string p, t;
    fin >> p;
    fin >> t;
    std::vector<int> match = Matcher(t, p);
    fout << match.size() << "\n";
    for (auto const& symbol: match){
        fout << symbol << " ";
    }
    return 0;
 
}