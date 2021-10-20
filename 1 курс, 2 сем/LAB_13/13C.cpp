#include <fstream>
#include <vector>

std::ifstream fin("prefix.in");
std::ofstream fout("prefix.out");

void prefix_f(std::string const &str) {
    int n = str.length();
    std::vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && str[i] != str[j])
            j = p[j - 1];

        if (str[i] == str[j])
            ++j;
        p[i] = j;
    }

    for (auto const &ans: p) {
        fout << ans << " ";
    }
}


int main() {
    std::string t;
    fin >> t;
    prefix_f(t);
    return 0;
}