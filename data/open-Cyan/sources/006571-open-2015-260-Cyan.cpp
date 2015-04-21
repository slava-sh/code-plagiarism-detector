#include<bits/stdc++.h>

struct point {
    long long x, y;
};

struct moun {
    point * points;
    int n, num;
};

long long ord(point *u1, point *u2, point *v1) {
    return (v1->x - u1->x) * (u2->y - u1->y) - (v1->y - u1->y) * (u2->x - u1->x);
}

long long isUp(point* u1, point* u2, point* v1, point* v2) {
    long long a1 = ord(u1, u2, v1), a2 = ord(u1, u2, v2);
    long long b1 = ord(v1, v2, u1), b2 = ord(v1, v2, u2);
    if((a1 > 0 && a2 < 0) || (a1 < 0 && a2 > 0) ) {
        if((b1 > 0 && b2 < 0) || (b1 < 0 && b2 > 0) ) {
            return -100;
        }
    }
    if(a1 == 0 && v1->x >= u1->x) {
        if(a2 > 0) return 1;
        if(a2 < 0) return -1;
        if(a2 == 0) return 0;
    }
    if(a2 == 0) {
        if(a1 > 0) return 1;
        if(a1 < 0) return -1;
        if(a1 == 0) return 0;
    }
    if(b1 == 0 && v1->x <= u1->x) {
        if(b2 > 0) return -1;
        if(b2 < 0) return 1;
        if(b2 == 0) return 0;
    }
}

int comp(moun* a, moun *b) {
    bool up ,down;
    up = down = false;
    int t1 = 1, t2 = 1;
    while(t1 != a->n || t2 != b->n) {
        if((*a).points[t1].x < (*b).points[t2].x) {
            long long tmp = isUp(&(*b).points[t2 - 1], &(*b).points[t2], &(*a).points[t1 -1], &(*a).points[t1]);
            if(tmp == 1) up = true;
            if(tmp == -1) down = true;
            if(tmp == -100) return -1;
            t1++;
        }
        else {
            long long tmp = isUp(&(*a).points[t1 - 1], &(*a).points[t1], &(*b).points[t2 - 1], &(*b).points[t2]);
            if(tmp == -1) up = true;
            if(tmp == 1) down = true;
            if(tmp == -100) return -1;
            t2++;
        }
    }
    if(up && down) return -1;
    else return 0;
}

int main() {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    int n;
    scanf("%d", &n);
    moun *m = new moun[n];
    for(int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        m[i].n = l;
        m[i].points = new point[l+1];
        m[i].num = i;
        for(int j = 0; j <= l; j++) {
            long long x, y;
            scanf("%lld%lld", &x, &y);
            m[i].points[j].x = x;
            m[i].points[j].y = y;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(comp(&m[i], &m[j]) == -1) {
                printf("No\n%d %d\n", i+1, j+1);
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}
