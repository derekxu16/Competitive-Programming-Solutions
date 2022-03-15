#include <iostream>

using namespace std;

struct Rectangle {
    pair<int, int> bl;
    pair<int, int> tr;

    int area() { return (tr.first - bl.first) * (tr.second - bl.second); }

    static int intersectionArea(const Rectangle& a, const Rectangle& b) {
        return max(0, min(a.tr.first, b.tr.first) - max(a.bl.first, b.bl.first)) *
               max(0, min(a.tr.second, b.tr.second) - max(a.bl.second, b.bl.second));
    }
};

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x_bl, y_bl, x_tr, y_tr;

    scanf("%i %i %i %i", &x_bl, &y_bl, &x_tr, &y_tr);
    Rectangle a = {{x_bl, y_bl}, {x_tr, y_tr}};

    scanf("%i %i %i %i", &x_bl, &y_bl, &x_tr, &y_tr);
    Rectangle b = {{x_bl, y_bl}, {x_tr, y_tr}};

    scanf("%i %i %i %i", &x_bl, &y_bl, &x_tr, &y_tr);
    Rectangle t = {{x_bl, y_bl}, {x_tr, y_tr}};

    int ans = a.area() + b.area() - Rectangle::intersectionArea(a, t) - Rectangle::intersectionArea(b, t);
    printf("%i\n", ans);
}
