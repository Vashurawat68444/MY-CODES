/*
THIS PROGRAME IS CAN RUN FOR BASIC FUNCRION EXPECT INSERTION DELETION
*/
#include<stdio.h>
#include<stdlib.h>
int c=0,count = 0;
struct node{
    int data;
    struct node *left, *right;
};
struct node *create_node()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("ENTER YOUR DATA : ");
    scanf("%d",&ptr->data);
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}
void pre_order(struct node *root)
{
    if(root == NULL){
        return;
    }else{
        printf("%d  ",root->data);
        pre_order(root->left);
        pre_order(root->right);

    }
}
void post_order(struct node *root)
{
    if(root == NULL){
        return;
    }else{
        post_order(root->left);
        post_order(root->right);
        printf("%d  ",root->data);
        c++;
    }
}
int height(struct node *root)
{
    struct node *lh, *rh;
    lh = root;
    rh = root;
    int h1,h2;
    h1=0; h2=0;
    while(lh != NULL)
    {
        lh = lh->left;
        h1++;
    }
    while(rh != NULL)
    {
        rh = rh->right;
        h2++;
    }
    if(h1>h2)
    {
        return h1;
    }else{
        return h2;
    }

}
int number_of_leaf_nodes(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else  if(root->left == NULL && root->right == NULL)
    {
        count++;
    }
    else{
        number_of_leaf_nodes(root->left);
        number_of_leaf_nodes(root->right);
    }

    return count;
}
int single_child_node(struct node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->right != NULL && root->left != NULL)
    {
        single_child_node(root->right);
        single_child_node(root->left);
    }
    else if(root->right == NULL && root->left == NULL)
    {
        return;
    }
    else
    {
        count++;
        single_child_node(root->right);
        single_child_node(root->left);
    }
    return count;
}
int number_internel_node(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->left != NULL || root->right != NULL)
    {
        count++;
        non_leaf_node(root->left);
        non_leaf_node(root->right);
    }else{
        return;
    }
    return count;

}
int left_child_node(struct node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if((root->right == NULL)&&(root->left != NULL))
    {
        count++;
    }
    else{
        left_child_node(root->left);
        left_child_node(root->right);
    }
    return count;
}
int right_child_node(struct node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if((root->left == NULL)&&(root->right != NULL))
    {
        count++;
    }
    else{
        right_child_node(root->left);
        right_child_node(root->right);
    }
    return count;
}
struct node *adding_node(struct node *root)
{
    int choice = -3;
    while(choice != 0)
    {
        printf("ENTER YOUR CHOICE FOR %d : ",root->data);
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("ENTER DATA ON RIGHT SIDE OF %d\n",root->data);
            struct node *ptr;
            root->right = create_node();
            adding_node(root->right);
        }
        if(choice == -1)
        {
        printf("ENTER DATA ON LEFT SIDE OF %d\n",root->data);
        root->left = create_node();
        adding_node(root->left);
        }
    }
    
    return root;
    
}
int main()
{
    printf("\n|--------------------------------------------------------------------------|\n"); 
    printf("                           ENTER YOUR OPTION                 \n");   
    printf("----------------------------------------------------------------------------\n");
    printf("                        A : CREATING TREE                                     \n");
    printf("                        B : RIGHT CHILD NODE                                  \n");
    printf("                        C : LEFT CHILD NODE                                   \n");
    printf("                        D : NUMBER OF LEAF NODE                               \n");
    printf("                        E : SINGLE CHILD NODE                               \n");
    printf("                        F : NON LEAF NODE                               \n");
    printf("                        H : HEIGHT                                \n");
    printf("                        I : POST OREDER                               \n");
    printf("                        J : PRE ORDER                               \n");
    printf("                        L : IN ORDER                               \n");
    printf("                        Z : TO EXIT                               \n");
    printf("____________________________________________________________________________\n");
    // BASIC LAYOUT COMPLETE
    int option;
    printf("                       SELECT YOUR OPTION : ");
    scanf("%d",&option);
    while(option != 'Z')
    {
        switch (option)
        {
        case 'A':
            struct node *root = create_node();
            root = adding_node(root);
            break;
        case 'B':
            right_child_node(root);
            break;
        case 'C':
             
            break;
        case 'D':
            break;
        case 'E':
            break;
        case 'F':
            break;
        case 'G':
            break;
        case 'H':
            break;
        case 'I':
            break;
        case 'J':
            break;
        case 'K':
            break;
        case 'L':
            break;
        }

    }
}