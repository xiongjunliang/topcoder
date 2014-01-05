
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WinterAndCandies {
public:
    int getNumber(vector<int> type) {   
        vector<int> counter(NUM, 0);
        vector<int> ret(NUM, 0);
        for (int i = 0; i < type.size(); ++i) {
            counter[i] ++;
        }
        int num = 0;
        if (counter[1] == 0) {
            return 0;
        } else {
            ret[1] = counter[1];
            num += ret[1];
        }
        for (int idx = 2; idx < NUM; ++idx) {
            if (counter[idx] == 0) {
                break;
            }
            ret[idx] = ret[idx-1] * counter[idx];
            cout << num << endl;
            num += ret[idx];
        }
        return num;
    }
private:
    static const int NUM = 52;
};


int main() {
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    WinterAndCandies w;
    cout << w.getNumber(t) << endl;
}
