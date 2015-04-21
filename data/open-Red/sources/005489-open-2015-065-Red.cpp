#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

//#define nullptr NULL

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int inf = 1000000000;

struct edge
{
    int from, to, t, id;
};

vector <edge> E;

struct node
{
    node *left, *right;
    int key, priority, id;
    node(int new_id)
    {
        left = right = nullptr;
        id = new_id;
        key = E[new_id].t;
        priority = rand();
    }
};

pair <node*, node*> split(node *root, int key)
{
    if (root == nullptr) return mp(nullptr, nullptr);
    if (root->key < key)
    {
        pair <node*, node*> splitted = split(root->right, key);
        root->right = splitted.first;
        return mp(root, splitted.second);
    }
    else
    {
        pair <node*, node*> splitted = split(root->left, key);
        root->left = splitted.second;
        return mp(splitted.first, root);
    }
}

node* merge(node *left, node *right)
{
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    if (left->priority > right->priority)
    {
        left->right = merge(left->right, right);
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        return right;
    }
}

vector <int> help;

void out(node *root)
{
    if (root == nullptr) return;
    help.pb(root->id);
    out(root->left);
    out(root->right);
}

int main()
{

    srand(time(NULL));

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);

    E.resize(2 * m);

    for (int i = 0; i < m; i++)
    {
        edge tmp;
        scanf("%d%d%d", &tmp.from, &tmp.to, &tmp.t);
        --tmp.from, --tmp.to;
        tmp.id = i * 2;
        E[i * 2] = tmp;
        swap(tmp.from, tmp.to);
        ++tmp.id;
        E[i * 2 + 1] = tmp;
    }

    int q;
    scanf("%d", &q);

    while (q--)
    {
        vector <node*> v(n, nullptr);
        for (int i = 0; i < 2 * m; i++)
            v[E[i].from] = merge(v[E[i].from], new node(i));
        queue <int> edge_id;
        vector <int> dist(n, inf);
        int start, finish;
        scanf("%d%d", &start, &finish);
        --start, --finish;
        dist[start] = 0;
        help.clear();
        out(v[start]);
        for (int i = 0; i < sz(help); i++)
        {
            edge_id.push(help[i]);
            dist[E[help[i]].to] = 1;
        }
        v[start] = nullptr;
        int t = 1;
        queue <int> edge_id_next;
        while (!edge_id.empty())
        {
            edge e = E[edge_id.front()];
            edge_id.pop();
            pair <node*, node*> spl1 = split(v[e.to], e.t - d);
            node *left = spl1.first;
            pair <node*, node*> spl2 = split(spl1.second, e.t + d + 1);
            node *middle = spl2.first;
            node *right = spl2.second;
            v[e.to] = merge(left, right);
            help.clear();
            out(middle);
            for (int i = 0; i < sz(help); i++)
            {
                edge e_next = E[help[i]];
                dist[e_next.to] = min(dist[e_next.to], t + 1);
                edge_id_next.push(e_next.id);
            }
            if (edge_id.empty())
            {
                ++t;
                edge_id = edge_id_next;
                while (!edge_id_next.empty())
                    edge_id_next.pop();
            }
        }
        int ans = (dist[finish] == inf ? -1 : dist[finish]);
        printf("%d\n", ans);
    }

}

