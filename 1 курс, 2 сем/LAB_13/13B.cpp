#include <fstream>
#include <vector>

std::vector<int> z_func(const std::string &str) {
    std::vector<int> z(str.length(), 0);
    for (int i = 1, l = 0, r = 0; i < str.length(); ++i) {
        if (i <= r)
            z[i] = std::min(z[i - l], r - i + 1);
        while (i + z[i] < str.length()) {
            if (str[i + z[i]] == str[z[i]])
                ++z[i];
            else
                break;
        }

        if (z[i] > 0 && i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    std::ifstream fin("search2.in");
    std::ofstream fout("search2.out");
    std::string p, t;
    fin >> p;
    fin >> t;
    std::vector<int> z = z_func(p + '#' + t);
    std::vector<int> ans;
    int p_length = p.length();

    for (int i = 0; i < t.length(); ++i)
        if (z[p_length + 1 + i] == p_length)
            ans.push_back(i + 1);

    fout << ans.size() << "\n";

    for (int const &position: ans)
        fout << position << " ";

    return 0;
}