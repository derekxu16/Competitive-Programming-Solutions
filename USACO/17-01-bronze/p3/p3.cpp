#include <iostream>

using namespace std;

bool isGridClear(int n, char grid[10][10]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                return false;
            }
        }
    }
    return true;
}

/**
 * Flips the rectangle with top-left corner (0, 0) and bottom-right corner (`bottom_right_i`, `bottom_right_j`).
 */
void flipUpperLeftRectangle(char grid[10][10], int bottom_right_i, int bottom_right_j) {
    for (int i = 0; i <= bottom_right_i; ++i) {
        for (int j = 0; j <= bottom_right_j; ++j) {
            grid[i][j] = grid[i][j] == '0' ? '1' : '0';
        }
    }
}

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n;
    scanf("%i", &n);

    char grid[10][10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &grid[i][j]);
        }
    }

    int ans = 0;
    while (true) {
        if (isGridClear(n, grid)) {
            break;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == '1') {
                    flipUpperLeftRectangle(grid, i, j);
                    ans++;
                }
            }
        }
    }

    printf("%i\n", ans);
}
