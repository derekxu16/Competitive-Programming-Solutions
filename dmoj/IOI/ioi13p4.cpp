#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void exploreCave(int N) {
    int posAns[N], connectAns[N], switches[N];
    bool solved[N];
    memset(posAns, 0, sizeof posAns);
    memset(solved, false, sizeof solved);

    if (tryCombination(posAns) == -1) { // Correct combination is simply all 0s
        for (int i = 0; i < N; i ++) {
            memcpy(switches, posAns, sizeof posAns);
            switches[i] = !switches[i];
            connectAns[i] = tryCombination(switches);
        }
        answer(posAns, connectAns);
    }

    for (int target = 0; target < N; target ++) { // Find correct combination
        bool condition = tryCombination(posAns) != target; // true -> must find way to close, else find way to open 
        int l = 0, r = N - 1;
        while (l < r) {
            memcpy(switches, posAns, sizeof posAns); // Make sure that solved switches stay open
            int mid = (l + r)/2;
            for (int i = l; i <= mid; i ++) {
                if (!solved[i]) {
                    switches[i] = 1;
                }
            }
            if ((tryCombination(switches) == target) == condition) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        posAns[l] = !condition;
        solved[l] = true;
        connectAns[l] = target;
    }
    
    answer(posAns, connectAns);
}
