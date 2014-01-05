
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WinterAndReindeers {
public:
    int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
        string a;
        string b;
        string c;
        for (size_t i = 0; i < allA.size(); ++i) {
            a.append(allA[i]);
        }
        for (size_t i = 0; i < allB.size(); ++i) {
            b.append(allB[i]);
        }
        for (size_t i = 0; i < allC.size(); ++i) {
            c.append(allC[i]);
        }
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
        vector<vector<int> > dpr(a.length()+1, vector<int>(b.length()+1, 0));
        for (size_t i = 0; i < a.length(); ++i) {
            for (size_t j = 0; j < b.length(); ++j) {
                if (a[i] == b[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        for (int i = a.length()-1; i >= 0; --i) {
            for (int j = b.length()-1; j >= 0; --j) {
                if (a[i] == b[j]) {
                    dpr[i][j] = dpr[i+1][j+1] + 1;
                } else {
                    dpr[i][j] = max(dpr[i+1][j], dpr[i][j+1]);
                }
            }
        }
        vector<pair<int, int> > ac;
        vector<pair<int, int> > bc;
        findc(a, c, ac);
        findc(b, c, bc);
        int ret = 0;
        for (int i = 0; i < ac.size(); ++i) {
            for (int j = 0; j < bc.size(); ++j) {
                int len = dp[ac[i].first][bc[j].first] + 
                    c.length() + dpr[ac[i].second+1][bc[j].second+1];
                ret = max(len, ret);
            }
        }
        return ret;
    }

    void findc(string& a, string& c, vector<pair<int, int> >& pairs) {
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == c[0]) {
                int j = i + 1;
                int k = 1;
                while (j < a.length() && k < c.length()) {
                    if (a[j] == c[k]) {
                        j ++;
                        k ++;
                    } else {
                        j ++;
                    }
                }
                if (k == c.length()) {
                    pairs.push_back(make_pair(i, j-1));
                } 
            }
        }
    }

};


int main() {
    vector<string> a;
    vector<string> b;
    vector<string> c;
    a.push_back("X");
    b.push_back("X");
    b.push_back("Y");
    c.push_back("X");
    WinterAndReindeers w;
    cout << w.getNumber(a, b, c) << endl;

}
