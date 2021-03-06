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

int getW(Node *node) {
    return node ? node->w : 0;
}

void relax(Node *node) {
    if (!node) return;
    node->w = 1 + getW(node->left) + getW(node->right);
}

void split(Node *node, int k, Node *&left, Node *&right) {
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

Node *_merge(Node *left, Node *right) {
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

void _insert(Node *&root, int x) {
    Node *A, *B;
    split(root, x, A, B);
    root = _merge(A, new Node(x));
    root = _merge(root, B);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int allinv = 0;
    vector<int> inv(n);
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] < a[j]) {
                inv[i]++;
            }
        }
        allinv += inv[i];
    }

    if (is_sorted(a.begin(), a.end())) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }

    int best = allinv, ansi = -1, ansj = -1;
    for (int i = 1; i < n; i++) {
        int add = 0;
        Node *root = nullptr;
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] < a[j]) {
                add--;
            } else {
                add++;
            }

            Node *A, *B;
            split(root, a[j], A, B);
            int newadd = getW(B) - getW(A);
            root = _merge(A, B);

            if (allinv + add + newadd < best) {
                best = allinv + add + newadd;
                ansi = j + 1, ansj = i + 1;
            }
            _insert(root, a[j]);
        }
    }

    cout << ansi << ' ' << ansj << endl;
}
