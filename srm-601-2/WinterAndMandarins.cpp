
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WinterAndMandarins {
public:
    int getNumber(vector <int> bags, int K) {
        int ret = INT_MAX;
        if (K <= 1) {
            return 0;
        }
        sort(bags.begin(), bags.end());
        for (int i = 0; (i + K) <= bags.size(); ++i) {
            ret = min(ret, bags[i+K-1]-bags[i]);
        }
        return ret;
    }
};


int main() {

}
