#include <cmath>
#include <iostream>

using namespace std;

struct Rectangle {
    pair<int, int> bl;
    pair<int, int> tr;
};

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int x_bl, y_bl, x_tr, y_tr;

    scanf("%i %i %i %i", &x_bl, &y_bl, &x_tr, &y_tr);
    Rectangle a = {{x_bl, y_bl}, {x_tr, y_tr}};

    scanf("%i %i %i %i", &x_bl, &y_bl, &x_tr, &y_tr);
    Rectangle b = {{x_bl, y_bl}, {x_tr, y_tr}};

    int width_required = max(a.tr.first, b.tr.first) - min(a.bl.first, b.bl.first);
    int height_required = max(a.tr.second, b.tr.second) - min(a.bl.second, b.bl.second);

    printf("%i\n", (int)pow(max(width_required, height_required), 2));
}
