#ifndef GRAPH_
#define GRAPH_
#include <stdbool.h>

typedef struct GRAPH_NODE_ *pnode;;
typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

int get_edge(pnode* graph, int srcNode, int destNode);
void insert_node_cmd(pnode* DWG, int node_id);
void insert_edge_cmd(pnode* DWG, int src,int weight, int dest);
void deleteGraph_cmd(pnode* DWG);
void delete_node_cmd(pnode* DWG, int node_id);
int get_dist(int dist[], bool visited[], int size);
int dijakstra(pnode* graph, int size, int src, int dest);
int shortsPath_cmd(pnode* graph, int s, int d);
void TSP_cmd(pnode* graph, int nodes[], int size);

#endif
