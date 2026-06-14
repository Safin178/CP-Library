#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

const ld EPS = 1e-9;
const ld PI  = acos((ld)-1);  // 3.14159...

// ─── HELPERS ──────────────────────────────────────────────────────────────────

ld toRad(ld deg) { return deg * PI / 180.0; }
ld toDeg(ld rad) { return rad * 180.0 / PI; }

// ─── POINT ────────────────────────────────────────────────────────────────────
// Use: represent 2D coordinates, vectors, directions

struct P {
    ld x, y;
    P(ld x=0, ld y=0): x(x), y(y) {}
    P operator+(P b) const { return {x+b.x, y+b.y}; }
    P operator-(P b) const { return {x-b.x, y-b.y}; }
    P operator*(ld t) const { return {x*t, y*t}; }
    bool operator<(P b) const { return x<b.x || (x==b.x && y<b.y); }
};

// DOT PRODUCT: a·b = |a||b|cos θ
// Use: angle between vectors, check if perpendicular (dot==0), projection
ld dot(P a, P b) { return a.x*b.x + a.y*b.y; }

// CROSS PRODUCT: a×b = |a||b|sin θ
// Use: orientation (CCW/CW), area of triangle, collinearity check
// +ve = CCW, -ve = CW, 0 = collinear
ld cross(P a, P b) { return a.x*b.y - a.y*b.x; }

// DISTANCE between two points: √((x2-x1)² + (y2-y1)²)
ld dist(P a, P b) { return hypot(b.x-a.x, b.y-a.y); }

// ROTATE point p by angle t (radians) around origin
// Use: rotating vectors/shapes
P rotate(P p, ld t) {
    return {p.x*cos(t) - p.y*sin(t),
            p.x*sin(t) + p.y*cos(t)};
}

// ─── ORIENTATION ──────────────────────────────────────────────────────────────
// Use: check if 3 points turn left (CCW), right (CW), or are collinear
// Formula: cross(B-A, C-A)
// Returns: +1=CCW, -1=CW, 0=collinear

int orient(P a, P b, P c) {
    ld v = cross(b-a, c-a);
    if (v >  EPS) return  1;
    if (v < -EPS) return -1;
    return 0;
}

// ─── SEGMENT ──────────────────────────────────────────────────────────────────

// Is point p on segment [a,b]?
// Use: boundary check in point-in-polygon
bool onSeg(P a, P b, P p) {
    return abs(cross(b-a, p-a)) < EPS && dot(a-p, b-p) <= EPS;
}

// Do segments [a,b] and [c,d] intersect?
// Use: any intersection problem between line segments
bool segIntersect(P a, P b, P c, P d) {
    int d1=orient(c,d,a), d2=orient(c,d,b);
    int d3=orient(a,b,c), d4=orient(a,b,d);
    if (d1*d2<0 && d3*d4<0) return true;
    if (!d1 && onSeg(c,d,a)) return true;
    if (!d2 && onSeg(c,d,b)) return true;
    if (!d3 && onSeg(a,b,c)) return true;
    if (!d4 && onSeg(a,b,d)) return true;
    return false;
}

// Intersection point of two LINES (a,b) and (c,d)
// Use: geometry problems needing exact crossing point
// Formula: parametric line equation solved via cross products
P lineIntersect(P a, P b, P c, P d) {
    ld A1 = cross(b-a, c-a);
    ld A2 = cross(b-a, d-a);
    return {(c.x*A2 - d.x*A1)/(A2-A1),
            (c.y*A2 - d.y*A1)/(A2-A1)};
}

// Distance from point p to segment [a,b]
// Use: closest point on a road/wall to a query point
ld distToSeg(P a, P b, P p) {
    if (dot(p-a, b-a) <= 0) return dist(p, a);
    if (dot(p-b, a-b) <= 0) return dist(p, b);
    return abs(cross(b-a, p-a)) / dist(a, b);
}

// ─── AREA ─────────────────────────────────────────────────────────────────────

// POLYGON AREA — Shoelace formula: ½|Σ(xᵢyᵢ₊₁ - xᵢ₊₁yᵢ)|
// Use: area of any simple (non-self-intersecting) polygon
// Note: vertices must be in order (CW or CCW)
ld polyArea(vector<P>& v) {
    ld s = 0; int n = v.size();
    for (int i = 0; i < n; i++)
        s += cross(v[i], v[(i+1)%n]);
    return abs(s) / 2.0;
}

// TRIANGLE AREA from 3 points: ½|cross(B-A, C-A)|
ld triArea(P a, P b, P c) { return abs(cross(b-a, c-a)) / 2.0; }

// TRIANGLE AREA from sides — Heron's: √(s(s-a)(s-b)(s-c)), s=(a+b+c)/2
ld heronArea(ld a, ld b, ld c) {
    ld s = (a+b+c) / 2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// ─── POINT IN POLYGON — Ray Casting O(n) ──────────────────────────────────────
// Use: check if a point is inside a polygon (e.g. query point inside a region)
// Returns: 1=inside, 0=boundary, -1=outside

int pointInPoly(vector<P>& poly, P p) {
    int n = poly.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
        P a = poly[i], b = poly[(i+1)%n];
        if (onSeg(a, b, p)) return 0;
        if ((a.y <= p.y) != (b.y <= p.y) &&
            cross(b-a, p-a) * (b.y > p.y ? 1 : -1) > 0)
            cnt++;
    }
    return cnt%2 ? 1 : -1;
}

// ─── CONVEX HULL — Andrew's Monotone Chain O(n log n) ─────────────────────────
// Use: smallest convex polygon containing all points
// Common in: diameter of point set, collision detection, visibility problems

vector<P> convexHull(vector<P> pts) {
    int n = pts.size(), k = 0;
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end(), [](P a, P b){
        return abs(a.x-b.x)<1e-12 && abs(a.y-b.y)<1e-12;
    }), pts.end());
    n = pts.size();
    if (n < 2) return pts;
    vector<P> h(2*n);
    for (int i=0; i<n; i++) {         // lower
        while (k>=2 && cross(h[k-1]-h[k-2], pts[i]-h[k-2])<=0) k--;
        h[k++] = pts[i];
    }
    for (int i=n-2,t=k+1; i>=0; i--) { // upper
        while (k>=t && cross(h[k-1]-h[k-2], pts[i]-h[k-2])<=0) k--;
        h[k++] = pts[i];
    }
    h.resize(k-1); return h;
}

// ─── TRIGONOMETRY ─────────────────────────────────────────────────────────────
// All angles in RADIANS. Use toRad() to convert from degrees.
//
// sin(t)   — opposite / hypotenuse
// cos(t)   — adjacent / hypotenuse
// tan(t)   — opposite / adjacent  [= sin/cos]
// asin(x)  — returns angle in [-π/2, π/2]
// acos(x)  — returns angle in [0, π]
// atan2(y,x)— returns angle in (-π, π], USE THIS over atan for full quadrant
//
// Key identities:
//   sin²t + cos²t = 1
//   sin(2t) = 2 sin t cos t
//   cos(2t) = cos²t - sin²t
//   sin(A±B) = sinA cosB ± cosA sinB
//   cos(A±B) = cosA cosB ∓ sinA sinB

// LAW OF COSINES: c² = a² + b² - 2ab·cos(C)
// Use: find side when 2 sides + included angle known, or angle when all 3 sides known
ld cosRule_side(ld a, ld b, ld C)      { return sqrt(a*a + b*b - 2*a*b*cos(C)); }
ld cosRule_angle(ld a, ld b, ld c)     { return acos((a*a+b*b-c*c)/(2*a*b)); } // angle at C

// LAW OF SINES: a/sin(A) = b/sin(B) = 2R
// Use: find side/angle when you have a side-angle pair + one more thing
ld sinRule_side(ld a, ld A, ld B)      { return a*sin(B)/sin(A); }
ld sinRule_angle(ld a, ld b, ld A)     { return asin(b*sin(A)/a); }

// ─── 2D SHAPE FORMULAS ────────────────────────────────────────────────────────

// TRIANGLE (sides a,b,c; height h to base b)
// Area    = ½ × base × height
// Area    = ½ × a × b × sin(C)     [two sides + included angle]
// Area    = √(s(s-a)(s-b)(s-c))    [Heron, s = (a+b+c)/2]
// Perimeter = a + b + c
// Circumradius R = abc / (4×Area)
// Inradius  r = Area / s
ld tri_circumR(ld a, ld b, ld c) { ld S=heronArea(a,b,c); return a*b*c/(4*S); }
ld tri_inR    (ld a, ld b, ld c) { ld S=heronArea(a,b,c); return S/((a+b+c)/2); }

// RECTANGLE (width w, height h)
// Area = w × h       Perimeter = 2(w+h)     Diagonal = √(w²+h²)
ld rect_area (ld w, ld h) { return w*h; }
ld rect_diag (ld w, ld h) { return hypot(w,h); }

// RHOMBUS (side a, diagonals d1 d2, angle A)
// Area = ½ × d1 × d2   OR   a² × sin(A)
// Perimeter = 4a
// Side from diagonals: a = √((d1/2)² + (d2/2)²)
ld rhombus_area(ld d1, ld d2) { return 0.5*d1*d2; }
ld rhombus_side(ld d1, ld d2) { return hypot(d1/2, d2/2); }

// CIRCLE (radius r, central angle θ in radians)
// Area = π r²           Circumference = 2πr
// Arc length = r × θ    Sector area = ½ r² θ
// Chord = 2r sin(θ/2)   Segment area = ½r²(θ - sinθ)
ld circle_area   (ld r)          { return PI*r*r; }
ld circle_circ   (ld r)          { return 2*PI*r; }
ld circle_arc    (ld r, ld t)    { return r*t; }
ld circle_sector (ld r, ld t)    { return 0.5*r*r*t; }
ld circle_chord  (ld r, ld t)    { return 2*r*sin(t/2); }
ld circle_segment(ld r, ld t)    { return 0.5*r*r*(t-sin(t)); }

// TRAPEZOID (parallel sides a,b; height h)
// Area = ½(a+b)×h
ld trap_area(ld a, ld b, ld h) { return 0.5*(a+b)*h; }

// ─── 3D SHAPE FORMULAS ────────────────────────────────────────────────────────

// SPHERE (radius r)
// Volume = (4/3)πr³    Surface = 4πr²
ld sphere_vol (ld r) { return (4.0/3.0)*PI*r*r*r; }
ld sphere_surf(ld r) { return 4*PI*r*r; }

// CYLINDER (radius r, height h)
// Volume = πr²h    Surface = 2πr(r+h)
ld cyl_vol (ld r, ld h) { return PI*r*r*h; }
ld cyl_surf(ld r, ld h) { return 2*PI*r*(r+h); }

// CONE (radius r, height h, slant l=√(r²+h²))
// Volume = (1/3)πr²h    Surface = πr(r+l)
ld cone_vol (ld r, ld h) { return PI*r*r*h/3.0; }
ld cone_surf(ld r, ld h) { return PI*r*(r+hypot(r,h)); }

// CUBOID (l × w × h)
// Volume = lwh    Surface = 2(lw+wh+hl)    Diagonal = √(l²+w²+h²)
ld box_vol (ld l,ld w,ld h){ return l*w*h; }
ld box_surf(ld l,ld w,ld h){ return 2*(l*w+w*h+h*l); }
ld box_diag(ld l,ld w,ld h){ return sqrt(l*l+w*w+h*h); }

// ─── HOW TO USE ───────────────────────────────────────────────────────────────
/*
  TYPICAL WORKFLOW:
  1. Read points as P{x, y}
  2. Use orient() before anything else to check CCW/CW/collinear
  3. Use cross() for area, dot() for angles/projections
  4. Use polyArea() with shoelace for polygon area
  5. Use convexHull() when problem mentions "convex"
  6. Use pointInPoly() to test if a query point is inside a region
  7. All trig in radians — wrap degrees with toRad()

  WHEN TO USE WHAT:
  ┌─────────────────────────────────┬──────────────────────────────┐
  │ Situation                       │ Use                          │
  ├─────────────────────────────────┼──────────────────────────────┤
  │ 3 points turn left/right?       │ orient()                     │
  │ Area of triangle/polygon?       │ triArea() / polyArea()       │
  │ Two segments cross?             │ segIntersect()               │
  │ Where do two lines meet?        │ lineIntersect()              │
  │ Closest point on segment?       │ distToSeg()                  │
  │ Point inside polygon?           │ pointInPoly()                │
  │ Smallest bounding polygon?      │ convexHull()                 │
  │ Find angle from sides?          │ cosRule_angle()              │
  │ Find side from angle?           │ cosRule_side() / sinRule     │
  │ Circle area/arc/chord?          │ circle_* functions           │
  │ 3D volume/surface?              │ sphere/cyl/cone/box_*        │
  └─────────────────────────────────┴──────────────────────────────┘

  COMMON PITFALLS:
  - Use EPS (1e-9) for float comparisons, not ==
  - atan2(y, x) not atan(y/x) — handles all quadrants
  - Shoelace requires vertices in order (CW or CCW), not random
  - convexHull with <= removes collinear points on hull edges
    change to < if you want to KEEP collinear boundary points
  - Law of sines has ambiguous case: asin returns [-π/2, π/2]
    check if the triangle is valid before using
*/

int main() {
    // ── Example 1: polygon area
    vector<P> poly = {{0,0},{4,0},{4,3},{0,3}};
    cout << polyArea(poly) << "\n";           // 12

    // ── Example 2: do diagonals of above rect intersect?
    cout << segIntersect({0,0},{4,3},{4,0},{0,3}) << "\n";  // 1

    // ── Example 3: triangle sides 3,4,5
    cout << heronArea(3,4,5) << "\n";         // 6
    cout << tri_circumR(3,4,5) << "\n";       // 2.5
    cout << tri_inR(3,4,5) << "\n";           // 1

    // ── Example 4: convex hull
    vector<P> pts = {{0,0},{2,0},{1,1},{2,2},{0,2}};
    auto hull = convexHull(pts);
    cout << hull.size() << "\n";              // 4

    // ── Example 5: angle from sides via cos rule
    ld ang = toDeg(cosRule_angle(3, 4, 5));
    cout << ang << "\n";                      // 90 degrees (right angle at C)

    // ── Example 6: circle sector area, central angle 60°
    cout << circle_sector(5, toRad(60)) << "\n";   // 13.089...
}