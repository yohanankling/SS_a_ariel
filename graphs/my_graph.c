#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_graph.h"
# define INF  999999

//Detail

int get_edge(pnode* graph, int srcNode, int destNode){
    int dest, temp = 0;
    pnode src = *graph;
    pnode tempDest = *graph;
    while(temp<srcNode || temp<destNode){
        if(temp<srcNode){
            src = src->next;}
        if(temp<destNode){
            tempDest = tempDest->next;}
        temp++;}
    dest = tempDest->node_num;
    pedge edge = src->edges;
    while(edge != NULL){
        if(edge->endpoint->node_num == dest)
            return edge->weight;
        else
            edge = edge->next;}
    return INF;}
    
// Insertions

void insert_node_cmd(pnode* DWG, int node_id){
    pnode node;
    node = (pnode)malloc(sizeof(node));
    node->node_num = node_id;
    node->next = *DWG; 
    *DWG = node;}

void insert_edge_cmd(pnode* DWG, int src,int weight, int dest){
    pnode src_node, dest_node;
    src_node = *DWG, dest_node = *DWG;
    while(src_node != NULL){
        if(src_node->node_num != src) 
            src_node = src_node->next;
        else break;}
    while(dest_node != NULL){
        if(dest_node->node_num != dest)
            dest_node = dest_node->next;
        else break;}
    if(src_node == NULL){
        insert_node_cmd(DWG, src);
        src = *DWG;}
    if(dest_node == NULL){
        insert_node_cmd(DWG, dest);
        dest_node = *DWG;}
    pedge edge;
    edge = (pedge)malloc(sizeof(edge));
    edge->weight = weight;
    edge->endpoint = dest_node; 
    edge->next = src_node->edges;
    src_node->edges=edge;}

//Deletions

void deleteGraph_cmd(pnode* DWG){
	pnode p1;
    p1 = *DWG;
	while (p1 != NULL) {
		pedge p2;
        p2 = p1->edges;
		while (p2 != NULL) {
			pedge p3;
            p3 = p2->next;
			free(p2);
			p2 = p3;}
        pedge p4;
        p4 = p1->next;
			free(p1);
			p1 = p4;}
	DWG = NULL;}

void delete_node_cmd(pnode* DWG, int node_id) {
    pnode curr_node = *DWG; pedge curr_edge;
    while (curr_node != NULL){
        if( curr_node->node_num == node_id)
            curr_node = curr_node->next;
        else if(curr_node->edges == NULL)
                curr_node = curr_node->next;
        int if_equal= curr_node->edges->endpoint->node_num;
        if(if_equal == node_id){
            for(; ;){
            curr_node->edges = curr_node->edges->next;
            curr_edge = curr_node->edges;
            curr_node = curr_node->next;
            free(curr_edge);
            break;}}
        curr_edge = curr_node->edges;
        pedge delete;
        while (curr_edge->next != NULL) {
            int if_equal=curr_edge->next->endpoint->node_num;
            if(if_equal == node_id){
                delete = curr_edge->next;
                curr_edge->next = curr_edge->next->next;
                free(delete); break;}
            else
                curr_edge = curr_edge->next;}
        curr_node = curr_node->next;}}

//Algorithms - shortest path and TSP_cmd

int get_dist(int dist[], bool visited[], int size){
    int min = INF, id;
    for (int i = 0; i < size; i++)
        if (visited[i] == false)
            if (dist[i] <= min){
            min = dist[i];
            id = i;}
    return id;}

int dijakstra(pnode* graph, int size, int src, int dest){
    int weight;
    int dist [size];
    bool *visited = (bool*)malloc(size * sizeof(bool));
    int i = 0;
    while (i<size){
       int distance = get_edge(graph, src, i);
        if (distance == -1)
            distance = INF;
        if (i == src)
            distance = 0;
        dist[i] = distance;
        visited[i] = false;
        i++; }
    int currNode;
    for (int i = 0; i < size; i++){
        currNode = get_dist(dist, visited, size);
        visited[currNode] = true;
        for (int j = 0; j < size; j++){
            weight = get_edge(graph, currNode, j);
            int oldCost = dist[j];
            int newCost = dist[currNode] + weight;
            if (visited[j] == false && dist[currNode] != INF)
                if (newCost < oldCost)
                dist[j] = newCost;}}
    weight = dist[dest];
    free(visited);
    if(weight == INF)
        return -1;
    return weight;}

int shortsPath_cmd(pnode* graph, int s, int d){
    pnode temp = *graph;
    int size = 0;
    int src = 0, dest = 0;
    while (temp != NULL){
        if (temp->node_num == s)
            src = size;
        if (temp->node_num == d)
            dest = size;
        temp = temp->next;
        size++;}
    return (dijakstra(graph, size, src, dest));}

void TSP_cmd(pnode* graph, int nodes[], int size){
    int distance = INF;
    int nextSrc, srcID = 0;
    bool *visited = (bool*)malloc(size * sizeof(bool));
    for(int i=0; i<size; i++){
        int src = nodes[i];
        int srcWeight = 0;
        visited[i] = true;
        for(int j=0; j<size; j++){
            if (i != j){
                visited[j] = false;}}
        for(int j=0; j<size-1; j++){
            int minWeight = INF;
            for (int k=0; k<size; k++){
                if(visited[k] == false){
                    int weight = shortsPath_cmd(graph, src, nodes[k]);
                    if(weight == -1)
                        break;
                    if(weight <= minWeight){
                        minWeight = weight;
                        nextSrc = nodes[k];
                        srcID = k;}}}
            srcWeight = srcWeight + minWeight;
            src = nextSrc;
            visited[srcID] = true;}
        if(srcWeight < distance)
            distance = srcWeight;}
    free(visited);
    if(distance == INF || distance == -1)
        printf("TSP shortest path: -1 \n");
    else
        printf("TSP shortest path: %d \n",distance);}
