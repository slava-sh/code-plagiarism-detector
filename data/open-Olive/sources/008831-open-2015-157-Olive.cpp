#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1234567890;


struct Node {
    Node *left, *right;
    int x, y, w;

    Node() : left(nullptr), right(nullptr) {};
    Node(int x) : left(nullptr), right(nullptr), x(x) {
        y = rand();
        w = 1;
    }
};

inline int getW(Node *node) {
    return node ? node->w : 0;
}

inline void relax(Node *node) {
    if (!node) return;
    node->w = 1 + getW(node->left) + getW(node->right);
}

inline void split(Node *node, int k, Node *&left, Node *&right) {
    if (!node) {
        left = right = nullptr;
        return;
    }

    if (node->x <= k) {
        split(node->right, k, node->right, right);
        left = node;
        relax(left);
    } else {
        split(node->left, k, left, node->left);
        right = node;
        relax(right);
    }
}

inline Node *_merge(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;

    if (left->y > right->y) {
        left->right = _merge(left->right, right);
        relax(left);
        return left;
    } else {
        right->left = _merge(left, right->left);
        relax(right);
        return right;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (is_sorted(a.begin(), a.end())) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }

    int best = INF, ansi = -1, ansj = -1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
                int cur = 0;
                Node *root = nullptr;
                for (int ii = 0; ii < n; ii++) {
                    Node *A, *B;
                    split(root, a[ii], A, B);
                    cur += getW(B);
                    root = _merge(A, new Node(a[ii]));
                    root = _merge(root, B);
                }
                if (cur < best) {
                    best = cur;
                    ansi = i + 1;
                    ansj = j + 1;
                }
                swap(a[i], a[j]);
            }
        }
    }

    printf("%d %d\n", ansi, ansj);
}
