
#include <iostream>
#include <vector>

using namespace std;


class TypoCoderDiv2 {
public:
    int count(vector<int> rating);
private:
    const static int BB = 1200;
};

int TypoCoderDiv2::count(vector<int> rating) {
    int last = 500;
    int ret = 0;
    for (int i = 0; i < rating.size(); ++i) {
        if (last < BB && rating[i] >= BB) {
            ret ++;
        }
        if (last >= BB && rating[i] < BB) {
            ret ++;
        }
        last = rating[i];
    }
    return ret;
}


int main() {
    int n;
    int m;
    int x;
    cin >> n;
    TypoCoderDiv2 typo;
    while (n--) {
        cin >> m;
        vector<int> r;
        while (m--) {
            cin >> x;  
            r.push_back(x);
        }
        cout << typo.count(r) << endl;
    }

}
