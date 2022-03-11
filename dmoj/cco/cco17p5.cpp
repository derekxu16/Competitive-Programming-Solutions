#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int,int> iPair;
int visited[200001];

bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main() {
    int n;
    int a,b;
    multiset<int> available;
    vector<iPair> people;

    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%i %i", &a, &b);
        people.push_back(make_pair(a,b));
    }
    sort(people.begin(), people.end(), comp);

    // for (iPair person : people) {
    //     cout << person.first << " " << person.second;
    // }
    // cout << endl;
    int cost = 0;
    int bought = 0, seen = 0;
    for (int seen = 0; seen < people.size(); seen ++) {
        available.insert(people[seen].second);
        while (n - seen + bought - 1 < people[seen].first) {
            bought ++;
            cost += *available.begin();
            available.erase(available.begin());
        }
    }
    cout << cost;
}