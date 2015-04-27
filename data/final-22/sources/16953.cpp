#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <algorithm>

typedef unsigned int uint;

#define BUBEN
#define VERTICES 600010
#define EDGES 1700010
#define MAXCOST 13

#ifdef BUBEN
#define ptrdiff_t int
#define size_t uint
#endif

typedef ptrdiff_t vertex_t;
typedef struct {
    vertex_t start;
    vertex_t end;
    uint length;
} edge_t;

size_t nverts, nedges;
edge_t* fedge[VERTICES];
size_t edgec[VERTICES];
edge_t edges[EDGES];

int compare_edges(const void *aa, const void *bb) {
    const edge_t *a = (const edge_t *)aa,
                 *b = (const edge_t *)bb;
    if ( a->start < b->start )
        return -1;
    else if ( a->start == b->start )
        return 0;
    else
        return 1;
}

bool operator<(const edge_t &e, const edge_t &f) {
    return compare_edges(&e, &f) < 0;
}

void swap(ptrdiff_t a, ptrdiff_t b) {
    edge_t t = edges[a];
    edges[a] = edges[b];
    edges[b] = t;
}

#define NIL (-1)

typedef struct {
    ptrdiff_t start, end;
    vertex_t data[VERTICES];
} queue_t;

void put(queue_t *q, vertex_t v) {
    q->data[q->end++] = v;
    q->end %= VERTICES;
}

vertex_t get(queue_t *q) {
    vertex_t ret;

    assert(q->start != q->end);
    ret = q->data[q->start++];
    q->start %= VERTICES;
   
    return ret;    
}

bool empty(queue_t *q) {
    return q->start == q->end;
}

void clear(queue_t *q) {
    q->start = q->end = 0;
}

#define NQUEUES (MAXCOST+1)
queue_t queues[NQUEUES];

uint distance[VERTICES];
bool seen[VERTICES];

void bfs(vertex_t v) {
    uint i, j, dist, q, pending;
    vertex_t u;
    edge_t *e;

    for ( i = 0; i <= MAXCOST; i++ )
        clear(&queues[i]);
    for ( i = 0; i < nverts; i++ )
        seen[i] = false;

    put(&queues[0], v);
    distance[v] = 0;
    pending = 1;
    for ( dist = 0, q = 0; pending; dist++, q++, q %= NQUEUES ) {
        while ( !empty(&queues[q]) ) {
            u = get(&queues[q]);
            pending--;
            if ( seen[u] )
                continue;
            else
                seen[u] = true;

            for ( j = 0, e = fedge[u]; j < edgec[u]; j++, e++ ) {
                if ( distance[e->end] > dist + e->length ) {
                    distance[e->end] = dist + e->length;
                    put(&queues[(q + e->length) % NQUEUES], e->end);
                    pending++;
                }
            }
        }
    }
}

uint EDGELEN[] = { 12, 6, 4, 3 };

int main(void) {
    uint i;
    uint x, y, z;
//  vertex_t v;

    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);

    scanf("%d", &nverts);
    scanf("%d", &nedges);
    nedges *= 2;
   
    for ( i = 0; i < nedges; ) {
        scanf("%d %d %d", &x, &y, &z);
        edges[i].start    = x - 1;
        edges[i].end      = y - 1;
        edges[i++].length = EDGELEN[z-1];
        edges[i].start    = y - 1;
        edges[i].end      = x - 1;
        edges[i++].length = EDGELEN[z-1];
    }
    
    std::sort(edges, edges + nedges);
    
    for ( i = 0; i < nverts; i++ ) {
        fedge[i] = NULL;
        edgec[i] = 0;
    }

    for ( i = 0; i < nedges; i++ ) {
        if ( !edgec[edges[i].start] )
            fedge[edges[i].start] = &edges[i];
        edgec[edges[i].start]++;
    }

    for ( i = 0; i < nverts; i++ )
        distance[i] = INT_MAX;

    bfs(0);
    for ( i = 1; i < nverts; i++ )
        printf("%.8f\n", ((double) distance[i]) / 12);
    
    return 0;
}

