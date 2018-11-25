#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> iPair;
#define mp make_pair

int grid[301][301];
vector<iPair> first(100001, mp(-1,-1));
vector<iPair> last(100001, mp(-1,-1));
int temp;

int main() {
    int n, m;
    scanf("%i %i", &n, &m);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            scanf("%i", &temp);
            grid[i][j] = temp;
            if (i < first[temp].first || first[temp].first == -1) {
                first[temp].first = i;
            }
            if (j < first[temp].second || first[temp].second == -1) {
                first[temp].second = j;
            }
            if (i > last[temp].first) {
                last[temp].first = i;
            }
            if (j > last[temp].second) {
                last[temp].second = j;
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int curr = grid[i][j];
            if (curr == -100)
                continue;
            if (last[curr].first - first[curr].first != last[curr].second - first[curr].second) {
                printf("0");
                return 0;
            }
            for (int ii = first[curr].first; ii <= last[curr].first; ii ++) {
                for (int jj = first[curr].second; jj <= last[curr].second; jj ++) {
                    if (grid[ii][jj] == curr) {
                        grid[ii][jj] = -100;
                    } else {
                        printf("0");
                        return 0;
                    }
                }
            }
        }
    }
    printf("1");
}