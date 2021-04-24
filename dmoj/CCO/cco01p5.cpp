#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int GRID_WIDTH = 300;

int ans[50];
int x[50];
int y[50];

int main() {
    int grid[GRID_WIDTH + 1][GRID_WIDTH + 1];
    int n;

    while (true) {
        scanf("%i", &n);
        if (n == 0) {
            return 0;
        }

        memset(grid, 0, sizeof grid);

        for (int i = 0; i < n; i ++) {
            scanf("%i %i", x+i, y+i);
            x[i] *= GRID_WIDTH / 10;
            y[i] *= GRID_WIDTH / 10;
        }

        for (int r = 1; r < n; r ++) {
            for (int i = 1; i <= GRID_WIDTH; i ++) {
                for (int j = 1; j <= GRID_WIDTH; j ++) {
                    double curr_dist = sqrt(pow(x[grid[i][j]] - j, 2) + pow(y[grid[i][j]] - i, 2));
                    double potential_dist = sqrt(pow(x[r] - j, 2) + pow(y[r] - i, 2));
                    if (potential_dist < curr_dist) {
                        grid[i][j] = r;
                    }
                }
            }
        }

        memset(ans, 0, sizeof ans);
        for (int i = 1; i <= GRID_WIDTH; i ++) {
            for (int j = 1; j <= GRID_WIDTH; j ++) {
                ans[grid[i][j]] ++;
            }
        }

        for (int r = 0; r < n; r ++) {
            printf(
                "Restaurant at (%i,%i) serves %i%% of the population.\n",
                10 * x[r] / GRID_WIDTH,
                10 * y[r] / GRID_WIDTH,
                (int)(round((double)ans[r]*100/(GRID_WIDTH * GRID_WIDTH)))
            );
        }
        printf("\n");
    }
}
