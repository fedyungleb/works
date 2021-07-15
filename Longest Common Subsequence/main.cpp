#include <iostream>

using namespace std;

#include "vector"


void getLongestCommonSubsequence(const string &a, const string &b);


int main() {
    getLongestCommonSubsequence("abecbadceadb", "debaecbc");

    return 0;
}


void getLongestCommonSubsequence(const string &a, const string &b) {
    cout << "First row:\t" << a << endl;
    cout << "Second row:\t" << b << endl;
    vector<vector<int> > max_len;
    max_len.resize(a.size() + 1);
    for (int i = 0; i <= static_cast<int>(a.size()); i++)
        max_len[i].resize(b.size() + 1);
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; i--) {
        for (int j = static_cast<int>(b.size()) - 1; j >= 0; j--) {
            if (a[i] == b[j]) {
                max_len[i][j] = 1 + max_len[i + 1][j + 1];
            } else {
                max_len[i][j] = max(max_len[i + 1][j], max_len[i][j + 1]);
            }
        }
    }
    string res;
    for (int i = 0, j = 0; max_len[i][j] != 0 && i < static_cast<int>(a.size()) && j < static_cast<int>(b.size());) {
        if (a[i] == b[j]) {
            res.push_back(a[i]);
            i++;
            j++;
        } else {
            if (max_len[i][j] == max_len[i + 1][j])
                i++;
            else
                j++;
        }
    }
    cout << "The longest common subsequence:\t" << res << endl;
}