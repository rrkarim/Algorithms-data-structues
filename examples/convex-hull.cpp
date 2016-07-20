/**
    Convex Hull
    e-olymp
    Rasul Kerimov (CoderINusE) 
*/
#include <bits/stdc++.h>
#define NMAX 1002
using namespace std;
typedef long long ll;
ll mod = 1000000007;

struct point {
    ll x, y;
    point(ll x, ll y) : x(x), y(y) { }
    double len() { return 1.0*(x * x + y * y); }
};

point operator-(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}
point operator+(point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}
vector <point> points;

bool cmp(point left, point right) {
    point a = left - points[0], b = right - left;
    if(a.x * b.y > b.x * a.y) return 1;
    if(a.x * b.y == b.x * a.y)
        return left.len() < right.len();
    return 0;
}

bool left_turn(point a, point b, point c) {
    point l = b - a, r = c - b;
    return  l.x * r.y > r.x * l.y;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    ll x, y;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        points.push_back(point(x, y));
    }
    for(int i = 1; i < points.size(); ++i) {
        if(points[i].x < points[0].x) swap(points[i], points[0]);
        if(points[i].x == points[0].x && points[i].y < points[0].y) swap(points[i], points[0]);
    }
    sort(points.begin() + 1, points.end(), cmp);
    points.push_back(points[0]);
    n += 1;
    int cur = 1;
    for(int i = 2; i < n; ++i) {

        while( (cur > 0) && !(left_turn(points[cur - 1], points[cur], points[i]))) cur -= 1;

        points[++cur] = points[i];

    }

    double p = 0;
    for(int i = 0; i < cur; ++i) {
        p += sqrt( 1.0 * (points[i + 1] - points[i]).len() );
    }
    printf("%.1lf\n", p);

}