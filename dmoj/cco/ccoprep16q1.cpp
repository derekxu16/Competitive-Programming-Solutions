#include <vector>
#include <iostream>

using namespace std;


int main() {
    int h, w;
    char temp;
    int free[1001][1001];
    int cases;
    scanf("%i", &cases);
    for (int zzz = 0; zzz < cases; zzz ++) {
        scanf("%i %i", &h, &w);
        for (int j = 0; j < w; j ++) {
            scanf(" %c", &temp);
            if (temp == 'F')
                free[0][j] = 1;
            else
                free[0][j] = 0;
        }
        for (int j = 1; j < h; j ++) {
            for (int i = 0; i < w; i ++) {
                scanf(" %c", &temp);
                if (temp == 'F') {
                    free[j][i] = free[j-1][i] + 1;
                } else {
                    free[j][i] = 0;
                }
            }
        }

        // for (int y = 0; y < h; y ++) {
        //     for (int x = 0; x < w; x ++) {
        //         printf("%i ", free[y][x]);
        //     }
        //     cout << endl;
        // }

        int max = 0, hold, left, right;

        for (int y = 0; y < h; y ++) {
            for (int x = 0; x < w; x ++) {
                hold = free[y][x];
                left = -1;
                right = w;
                //find the two boundaries of the building's width
                for (int i = x; i >= 0; i --) {
                    if (free[y][i] < hold) {
                        left = i;
                        break;
                    }
                }
                for (int i = x; i < w; i ++) {
                    if (free[y][i] < hold) {
                        right = i;
                        break;
                    }
                }
                max = hold * (right - left - 1) > max ? hold * (right - left - 1) : max;
            }
        }
        printf("%i\n", max * 3);
    }
}