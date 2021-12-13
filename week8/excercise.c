#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
typedef struct nodeType 
{
    int key;
    struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *TreeType;

void prettyprint(TreeType tree,char *prefix)
{
    char *prefixend=prefix+strlen(prefix);
    if (tree!=NULL){
    printf("%04d",tree->key);
    if (tree->left!=NULL) if (tree->right==NULL){
    printf("\304");strcat(prefix," ");
    }
    else {
    printf("\302");strcat(prefix,"\263 ");
    }
    prettyprint(tree->left,prefix);
    *prefixend='\0';
    if (tree->right!=NULL) if (tree->left!=NULL){
    printf("\n%s",prefix);printf("\300");
    } else printf("\304");
    strcat(prefix," ");
    prettyprint(tree->right,prefix);
    }
}

void InsertNode(int x,TreeType Root )
{ 
    if (Root == NULL)
    {
        /* Create a new node for key x */ 
        Root=(node_Type*)malloc(sizeof(node_Type)); 
        Root->key = x; 
        Root->left = NULL; 
        Root->right = NULL; 
    } 
    else if (x < Root->key) InsertNode(x, &(Root)->left);
    else if (x> Root->key) InsertNode(x, &(Root)->right); 
} 

TreeType Search(int x,TreeType Root)
{ 
    if (Root == NULL) return NULL; // not found
    else if (Root->key == x) /* found x */ 
    return Root; 
    else if (Root->key < x)
    //continue searching in the right sub tree 
    return Search(x,Root->right); 
    else {
    // continue searching in the left sub tree 
    return Search(x,Root->left); 
    }
}

int main()
{
    TreeType p, tree = NULL;
    int i, n = 0;
    char prefix[10];
    srand(time(NULL));
    for ( i = 0; i < 10; i++ ) 
        InsertNode (rand() % 100, tree ); 
    printf("pretty print:\n");
    strcpy(prefix," ");
    prettyprint(tree,prefix);
    printf("\n");
    do 
    {
        printf("Enter key to search (-1 to quit):");
        scanf("%d", &n);
        p= Search(n, tree);
        if (p!=NULL) printf("Key %d found on the tree",n);
        else InsertNode(n, tree);
    }   while (n!=-1);
    return 0;
}
