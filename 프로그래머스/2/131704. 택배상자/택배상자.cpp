#include <vector>
using namespace std;

int solution(vector<int> order) {
    int n = order.size();
    vector<int> st;
    int idx = 0;
    int count = 0;

    for (int box = 1; box <= n; ++box) {
        st.push_back(box);
        while (!st.empty() && st.back() == order[idx]) {
            st.pop_back();
            ++idx;
            ++count;
        }
    }
    while (!st.empty() && st.back() == order[idx]) {
        st.pop_back();
        ++idx;
        ++count;
    }
    return count;
}
