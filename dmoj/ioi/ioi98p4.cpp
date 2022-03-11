#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, int> vertical, horizontal;

struct Event {
    int pos, rangeStart, rangeEnd, overlap;
    Event(int pos, int rangeStart, int rangeEnd, int overlap) {
        this->pos = pos;
        this->rangeStart = rangeStart;
        this->rangeEnd = rangeEnd;
        this->overlap = overlap;
    }
};

vector<Event> events, events2;

bool comp(Event &a, Event &b) {
    if (a.pos == b.pos) {
        if (a.rangeStart == b.rangeStart) {
            return a.rangeEnd < b.rangeEnd;
        }
        return a.rangeStart < b.rangeStart;
    }
    return a.pos < b.pos;
}

int n;
int main() {
    int x1, x2, rangeStart, rangeEnd;
    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%i %i %i %i", &x1, &rangeStart, &x2, &rangeEnd);
        events.push_back(Event(x1, rangeStart, rangeEnd, 1));
        events.push_back(Event(x2, rangeStart, rangeEnd, -1));
        events2.push_back(Event(rangeStart, x1, x2, 1));
        events2.push_back(Event(rangeEnd, x1, x2, -1));

        vertical[rangeStart] = 0;
        vertical[rangeEnd] = 0;
        horizontal[x1] = 0;
        horizontal[x2] = 0;
    }

    sort(events.begin(), events.end(), comp);
    sort(events2.begin(), events2.end(), comp);

    long long total = 0;
    for (int i = 0; i < events.size(); i ++) {
        Event e = events[i];
        for (auto it = vertical.upper_bound(e.rangeStart); it != vertical.upper_bound(e.rangeEnd); it ++) {
            if ((e.overlap == 1 && it->second == 0) || (e.overlap == -1 && it->second == 1)) {
                total += it->first - prev(it)->first;
            }
            it->second += e.overlap;
        }
    }
    for (int i = 0; i < events2.size(); i ++) {
        Event e = events2[i];
        for (auto it = horizontal.upper_bound(e.rangeStart); it != horizontal.upper_bound(e.rangeEnd); it ++) {
            if ((e.overlap == 1 && it->second == 0) || (e.overlap == -1 && it->second == 1)) {
                total += it->first - prev(it)->first;
            }
            it->second += e.overlap;
        }
    }
    printf("%lli", total);
}
