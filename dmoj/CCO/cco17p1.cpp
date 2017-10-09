#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int k;
int n;

typedef pair<int,int> iPair;
#define mp make_pair

int main() {
    vector<iPair> edges;
    int target, max;
    scanf("%i", &k);
    int last = 0;
    bool started = false;
    while (k > 0) {
        if (started)
            edges.push_back(mp(last,last+1));

        last ++;
        target = k * 2;
        //n^2 - n - 2k = 0
        n = (1 + sqrt( 1 - 4 * (-target)))/2;
        for (int i = last; i < last + n - 1; i ++) {
            edges.push_back(mp(i,i+1));
        }
        edges.push_back(mp(last + n - 1, last));
        max = last + n - 1;
        k -= (n * (n-1)/2);
        last = last + n - 1;
        started = true;
    }
    printf("%i %li\n", max, edges.size());
    for (iPair edge : edges) {
        printf("%i %i\n", edge.first, edge.second);
    }
}