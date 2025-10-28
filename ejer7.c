#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000
#define vertex int

typedef struct node {
    vertex w;
    struct node *next;
} *link;

typedef struct graph {
    int V;
    int A;
    link *adj;
} *Graph;

static int cnt;
static int pre[MAXV];

typedef struct {
    vertex v;
    link next;
} StackItem;

typedef struct {
    StackItem items[MAXV];
    int top;
} Stack;

link NEW(vertex w, link next) {
    link x = malloc(sizeof *x);
    x->w = w;
    x->next = next;
    return x;
}

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));
    for (int v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w) {
    G->adj[v] = NEW(w, G->adj[v]);
    G->A++;
}

void dfsIterative(Graph G, vertex s) {
    Stack stack;
    stack.top = -1;

    pre[s] = cnt++;
    stack.items[++stack.top].v = s;
    stack.items[stack.top].next = G->adj[s];

    while (stack.top >= 0) {
        vertex v = stack.items[stack.top].v;
        link a = stack.items[stack.top].next;

        if (a == NULL) {
            stack.top--;
            continue;
        }

        stack.items[stack.top].next = a->next;
        vertex w = a->w;

        if (pre[w] == -1) {
            pre[w] = cnt++;
            stack.items[++stack.top].v = w;
            stack.items[stack.top].next = G->adj[w];
        }
    }
}

void GRAPHdfsIterative(Graph G) {
    cnt = 0;
    for (int v = 0; v < G->V; v++)
        pre[v] = -1;

    for (int v = 0; v < G->V; v++)
        if (pre[v] == -1)
            dfsIterative(G, v);
}

void print_pre(Graph G) {
    printf("\npre[v]: ");
    for (int v = 0; v < G->V; v++)
        printf("%3d", pre[v]);
    printf("\n");
}

int main() {
    Graph G = GRAPHinit(7);
    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 2);
    GRAPHinsertArc(G, 1, 3);
    GRAPHinsertArc(G, 1, 4);
    GRAPHinsertArc(G, 2, 5);
    GRAPHinsertArc(G, 5, 6);

    GRAPHdfsIterative(G);
    print_pre(G);
    return 0;
}
