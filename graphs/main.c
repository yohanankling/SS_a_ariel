# include <stdio.h>
# include <stdlib.h>
# include "my_graph.h"

int main(void){
    pnode DWG=NULL;
    DWG = (pnode) malloc(sizeof(node));
    char ch;
    int a = 5;
    int flag = 0;
    while(1){
        if (flag == 0){
        a = scanf(" %c", &ch);
        if (a == 0 || a == -1)
            break;}
        flag = 0;
        if (ch == 'A'){
            pnode curr_node=NULL;
            int src;
            char dest;
            int num_of_nodes;
            scanf(" %d", &num_of_nodes);
            char n;
            scanf(" %c", &n);

            DWG = (pnode) malloc(sizeof(node));
            int i=0;
            while(num_of_nodes>i){
                scanf(" %d", &src);

                curr_node = DWG;
                while(curr_node != NULL && curr_node->node_num != src)
                    curr_node = curr_node->next;
                if(curr_node == NULL)
                    insert_node_cmd(&DWG, src);
                for(; ;) {
                    scanf(" %c", &dest);

                    if(dest == 'A' || dest == 'B' || dest == 'D' || dest == 'S' || dest == 'T'){
                        ch = dest; flag =1; break;}
                    if(dest != 'n'){
                        int dest_int= dest - '0';
                        int weight;
                        scanf(" %d", &weight);

                        insert_edge_cmd(&DWG, src, weight, dest_int);}
                    else break;}
                i++;}}
        else if (ch == 'B'){
            pnode curr_node=NULL;
            int src;
            scanf(" %d", &src);
            curr_node = DWG;
            while(curr_node != NULL && curr_node->node_num != src)
                curr_node = curr_node->next;
            if(curr_node == NULL)
                insert_node_cmd(&DWG, src);
            else while (DWG->edges != NULL)
                    DWG->edges = DWG->edges->next;
            DWG->edges = NULL;
            for(; ;){
                char dest;
                scanf(" %c", &dest);
                if(dest == 'A' || dest == 'B' || dest == 'D' || dest == 'S' || dest == 'T' || dest == EOF){
                    ch = dest; flag =1;break;}
                int dest_int= dest - '0';
                int weight;
                scanf(" %d", &weight);
                insert_edge_cmd(&DWG, src,weight, dest_int);}}

        else if (ch == 'D'){
            pnode temp1=DWG;
            pnode temp2 = NULL;
            int node_to_delete;
            scanf(" %d", &node_to_delete);
            delete_node_cmd(&DWG, node_to_delete);
            while (temp1->node_num != node_to_delete)
                temp1 = temp1->next;
            pedge tempEdge = NULL;
            while (temp1->edges != NULL){
                tempEdge = temp1->edges;
                temp1->edges = (temp1->edges)->next;
                free(tempEdge);}
            temp1->edges = NULL;
            temp2 = temp1;
            temp1 = temp1->next;
            free(temp2);
        }

        else if (ch == 'S') {
            int src;
            scanf(" %d", &src);
            int dest;
            scanf(" %d", &dest);
            printf("Dijsktra shortest path: %d \n", shortsPath_cmd(&DWG, src, dest));
        }

        else if (ch == 'T') {
            int num_of_nodes;
            scanf(" %d", &num_of_nodes);
            int arr_ver[num_of_nodes* sizeof(int)];
            int i=0;
            while (num_of_nodes>i){
                int ver;
                scanf(" %d", &ver);

                arr_ver[i] = ver;
                i++;}
            TSP_cmd(&DWG, arr_ver, num_of_nodes);
        }
        else{
            break;
        }
}
//    deleteGraph_cmd(&DWG);
    free (DWG);
    DWG=NULL;
    return 0;}

//A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 S 2 0
//
//
//
// A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 B 5 0 4 2 1 T 4 2 1 3 5 B 6 2 3 1 4 T 3 1 3 6
