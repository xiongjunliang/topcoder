
#include <iostream>
#include <vector>

using namespace std;


class TypoCoderDiv1 {
public:
    int getmax(vector<int> D, int X);
private:
    const static int BB = 2200;
};

int TypoCoderDiv1::getmax(vector<int> D, int X) {
    vector<vector<int> > dp(D.size()+1, vector<int>(BB, -1));
    dp[0][X] = 0;
    
    for (int i = 0; i < D.size(); ++i) {
        for (int j = 0; j < BB; ++j) {
            if (dp[i][j] >= 0) {
                int scorea = j + D[i];
                int scoreb = max(j-D[i], 0);
                if (scorea >= BB) {
                    if ((i+1) != D.size() && (scorea - D[i+1]) < BB) {
                        int newscore = max(0, scorea - D[i+1]);
                        dp[i+2][newscore] = max(dp[i+2][newscore], dp[i][j]+2);
                    } else if ((i+1) == D.size()){
                        dp[i+1][j] = max(dp[i+1][j], dp[i][j]+1);
                    }
                } else {
                    dp[i+1][scorea] = 
                        max(dp[i+1][scorea], dp[i][j]);
                }
                dp[i+1][scoreb] = 
                    max(dp[i+1][scoreb], dp[i][j]);
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
    int sz = D.size();
    int ret = 0;
    for (int i = 0; i < BB; ++i) {
        ret = max(ret, dp[sz][i]);
    }
    return ret;
}

int main() {
    int n;
    int m;
    int x;
    cin >> n;
    TypoCoderDiv1 div1;
    while (n--) {
        cin >> m;
        vector<int> in;
        while (m--) {
            cin >> x;
            in.push_back(x);
            cout << x << " ";
        }
        cin >> x;
        cout << x << endl;
        cout << div1.getmax(in, x) << endl;
        
    }
    return 0;
}

