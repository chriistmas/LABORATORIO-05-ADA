#include <stdio.h>
#include <stdlib.h>


typedef int vertex;

// Nodo de la lista de adyacencia (arco v -> w)
typedef struct link {
    vertex w;
    struct link *next;
} *link;

// Estructura del Grafo
typedef struct {
    int V;    // Número de vértices
    int A;    // Número de arcos
    link *adj; // Arreglo de listas de adyacencia (link *adj[V])
} Graph;

// Variables globales para el seguimiento de DFS
static int cnt;      
static int pre[1000];
static int indent;   

// Función para inicializar un nodo (link)
link NEW(vertex w, link next) {
    link x = (link)malloc(sizeof(*x));
    x->w = w;
    x->next = next;
    return x;
}

// Función para crear un grafo con V vértices
Graph *GRAPHinit(int V) {
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->V = V;
    G->A = 0;
    G->adj = (link *)malloc(V * sizeof(link));
    for (vertex v = 0; v < V; v++) {
        G->adj[v] = NULL; // Inicializar todas las listas a NULL
    }
    return G;
}

// Función para insertar un arco (v -> w)
void GRAPHinsertArc(Graph *G, vertex v, vertex w) {
    G->adj[v] = NEW(w, G->adj[v]);
    G->A++;
}

Graph *GRAPHread(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    int V;
    if (fscanf(fp, "%d", &V) != 1) {
        fprintf(stderr, "Error al leer el número de vértices V.\n");
        fclose(fp);
        return NULL;
    }

    Graph *G = GRAPHinit(V);
    vertex v, w;

    // Leer las V líneas de adyacencia
    for (int i = 0; i < V; i++) {
        if (fscanf(fp, "%d", &v) != 1) {
            fprintf(stderr, "Error al leer el vértice v en la línea %d.\n", i + 2);
            fclose(fp);
            return NULL;
        }
        
        // Asumimos que la lista de vecinos sigue inmediatamente después de v
        char line_buffer[1024];
        if (fgets(line_buffer, sizeof(line_buffer), fp) == NULL) {
            break; // Final del archivo inesperado
        }

        fseek(fp, 0, SEEK_SET);
        for(int j=0; j<=i; j++) { // Avanzamos a la línea actual
            if(fscanf(fp, "%d", &v) != 1) break;
            while(fscanf(fp, "%d", &w) == 1) {
                // Si la línea no es la que buscamos (la i-ésima), solo saltamos
                if(j < i) continue;
                
                // Si es la línea i-ésima, insertamos el arco.
                GRAPHinsertArc(G, v, w);
            }
        }
    }
    
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, "%d", &V); // Leer V de nuevo

    for (int i = 0; i < V; i++) {
        if (fscanf(fp, "%d", &v) != 1) break; // Leer el vértice v
        
        // Leer todos los vecinos w hasta el final de la línea o un nuevo vértice
        while (1) {
            long current_pos = ftell(fp);
            if (fscanf(fp, "%d", &w) != 1) break; 
            
            // Si w es el inicio de la siguiente lista de adyacencia (v_siguiente)
            // se asume que las listas están ordenadas 0..V-1
            if (w == i + 1 && i < V - 1) {
                fseek(fp, current_pos, SEEK_SET); // Rebobinar para la siguiente iteración
                break;
            }
            
            GRAPHinsertArc(G, v, w);
        }
    }
    
    fclose(fp);
    return G;
}

// Imprime el espacio de sangría
void printIndent() {
    for (int i = 0; i < indent; ++i) {
        printf(" "); 
    }
}

// Declaración anticipada
static void dfsR(Graph *G, vertex v);

// Función GRAPHdfs modificada
void GRAPHdfs(Graph *G) {
    cnt = 0;
    indent = 0; // Inicializar la sangría
    
    printf("--- Rastreo de GRAPHdfs(G) ---\n");
    
    for (vertex v = 0; v < G->V; ++v) {
        pre[v] = -1;
    }
    
    for (vertex v = 0; v < G->V; ++v) {
        if (pre[v] == -1) {
            // Imprime la invocación inicial (sin sangría, ya que indent=0)
            printf("%d dfsR(G, %d)\n", v, v); 
            dfsR(G, v); // Comienza nueva etapa
        }
    }
    
    // Imprimir el vector pre[] final
    printf("\n--- Estado Final de pre[] ---\n");
    printf("v:  ");
    for (int i = 0; i < G->V; i++) {
        printf("%4d", i);
    }
    printf("\npre[v]:");
    for (int i = 0; i < G->V; i++) {
        printf("%4d", pre[i]);
    }
    printf("\n");
}

// Función dfsR modificada
static void dfsR(Graph *G, vertex v) {
    indent++; // Entra en la función: incrementa sangría
    
    pre[v] = cnt++; 
    
    for (link a = G->adj[v]; a != NULL; a = a->next) {
        vertex w = a->w;
        
        // Imprime el arco v-w recorrido
        printIndent();
        printf("%d-%d", v, w);
        
        if (pre[w] == -1) {
            // Imprime la llamada recursiva y la ejecuta
            printf(" dfsR(G, %d)\n", w);
            dfsR(G, w);
        } else {
            // Solo registra el arco (vecino ya visitado)
            printf("\n"); 
        }
    }
    
    indent--; // Sale de la función: decrementa sangría
    
    // Imprime el vértice v solo, representando el final de la ejecución de dfsR(G, v)
    printIndent();
    printf("%d\n", v); 
}


int main() {

    printf("Iniciando prueba de DFS con rastreo (Ejemplo A: 0-1, 1-2, 1-3, 2-4, 2-5)\n");
    
    Graph *G = GRAPHinit(6); // 6 vértices: 0 a 5

    GRAPHinsertArc(G, 0, 1); 

    GRAPHinsertArc(G, 1, 3);
    GRAPHinsertArc(G, 1, 2);

    GRAPHinsertArc(G, 2, 5);
    GRAPHinsertArc(G, 2, 4); 

    GRAPHdfs(G);

    return 0;
}
