#include <vector>
#include <iostream>

using namespace std;

int n;
int bit[1026][1026];

void update(int,int,int);
int query(int,int,int,int);
int sum(int,int);

int main() {
    int temp, a, b, c, d;
    while (true) {
        scanf("%i", &temp);
        if (temp == 0) {
            scanf("%i", &n);
        }
        else if (temp == 1) {
            scanf("%i %i %i", &a, &b, &c);
            a++; b++;
            update(b,a,c);
        }
        else if (temp == 2) {
            scanf("%i %i %i %i", &a, &b, &c, &d);
            c++;
            d++;
            printf("%i\n", query(a,b,c,d));
        } else {
            break;
        }
    }
}

void update(int a, int b, int c) {
    int x = b;
    while (a <= n) {
        x = b;
        while (x <= n) {
            bit[a][x] += c;
            x += (x & -x);
        }
        a += (a & -a);
    }
}

int sum(int x, int y) {
    int hold = x;
    int ans = 0;
    while (y > 0) {
        x = hold;
        while (x > 0) {
            ans += bit[y][x];
            x -= (x & - x);
        }
        y -= (y & -y);
    }
    return ans;
}

int query(int a, int b, int c, int d) {
    int ans = 0;
    ans = sum(c,d) - sum(c,b) - sum(a,d) + sum(a,b);
    return ans;
}