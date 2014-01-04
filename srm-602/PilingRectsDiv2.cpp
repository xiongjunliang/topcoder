

#include <iostream>
#include <vector>

using namespace std;


class PilingRectsDiv2 {
public:
    int getmax(vector<int> X, vector<int> Y, int limit) {
        int ret = -1;
        for (int i = 1; i <= SZ; ++i) {
            for (int j = 1; j <= SZ; ++j) {
                if (i*j >= limit) {
                    int count = 0;
                    for (int k = 0; k < X.size(); ++k) {
                        if ((X[k]>=i && Y[k]>=j) || 
                                (X[k]>=j && Y[k]>=i)) {
                            count ++;
                        }
                    }
                    if (count > 0) {
                        ret = max(ret, count);
                    }
                }
            }
        }
        return ret;
    }
private:
    const static int SZ = 200;
};

int main() {

}
