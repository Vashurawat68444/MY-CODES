#include<stdio.h>
#include<stdlib.h>
typedef struct vertices
{
    int data,visited;
    struct node* next;
}v;
typedef struct edges
{
    int index;
    struct eddges *next;
}e;
e *create_edge(v* vertices)
{
    e *temp = (e*)malloc(sizeof(e));
    printf("ENTER VALUE OF INDEX CONNCT FROM %d : ",vertices->data);
    scanf("%d",&temp->index);
    temp->next = NULL;
    return temp;
}
e *create_edge_list(int n,v* vertices)
{
    e *temp,*newedge,*head;
    temp = create_edge(vertices);
    head = temp;
    for(int i=1; i<n; i++)
    {
        newedge = create_edge(vertices);
        temp->next = newedge;
        temp = temp->next;
    }
    return head;
}
v *create_vertices()
{
    v *temp;
    temp = (v*)malloc(sizeof(v));
    temp->visited=0;
    printf("ENTER DATA IN VERTICES : ");
    scanf("%d",&temp -> data);
    temp -> next = NULL;
    return temp;
}
int main()
{
    int number,connected_vertices;
    printf("ENTER THE NUMBER OF VERTICES : ");
    scanf("%d",&number);
    v *vertices_array[number];
    e *edges_array[number];
    for(int i=0; i<number; i++)
    {
        vertices_array[i] = create_vertices();
    }
    for(int i=0; i<number; i++)
    {
        printf("ENTER THE NUMBER OF CONNECTED VERTICES FROM %d : ",vertices_array[i]->data);
        scanf("%d",&connected_vertices);
        edges_array[i] = create_edge_list(connected_vertices,vertices_array[i]);
    }
}
