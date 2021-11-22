#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType 
{
    int element;
    struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;

// Khởi tạo và kiểm tra cây
void MakeNullTree(treetype *T)
{ 
    *T = NULL;
} 
int EmptyTree(treetype T)
{ 
    return T==NULL; 
}

// Tạo node mới
node_Type *create_node(int NewData)
{ 
    node_Type *N;
    N=(node_Type*)malloc(sizeof(node_Type));
    if (N != NULL)
    { 
    N->left = NULL;
    N->right = NULL;
    N->element = NewData;
    }
    return N;
}

// Try cập con trái, phải
treetype LeftChild(treetype n)
{ 
    if (n!=NULL) return n->left; 
    else return NULL;
}
treetype RightChild(treetype n)
{ 
    if (n!=NULL) return n->right;
    else return NULL;
}

// Kiểm tra node có là lá hay không
int IsLeaf(treetype n)
{
    if(n!=NULL) 
    return(LeftChild(n)==NULL)&&(RightChild(n)==NULL); 
    else return -1; 
} 

// Tìm số nút trên cây
int nb_nodes(treetype T)
{ 
    if(EmptyTree(T)) return 0; 
    else return 1+nb_nodes(LeftChild(T))+ nb_nodes(RightChild(T)); 
} 

// Tạo 1 cây từ 2 cây con
treetype createfrom2(int v, treetype l, treetype r)
{ 
    treetype N; 
    N=(node_Type*)malloc(sizeof(node_Type));
    N->element=v;
    N->left=l; 
    N->right=r;
    return N;
}
/*
// Thêm nút vào vị trí trái
treetype Add_Left(treetype *Tree, int NewData)
{ 
    node_Type *NewNode = Create_Node(NewData);
    if (NewNode == NULL) return (NewNode);
    if (*Tree == NULL)   *Tree = NewNode;
    else
    {
        node_Type *Lnode = *Tree;
        while (Lnode->left != NULL)
            Lnode = Lnode->left;
        Lnode->left = NewNode;
    }
    return (NewNode);
}

// Thêm nút vào vị trí phải

treetype Add_Left(treetype *Tree, int NewData)
{ 
    node_Type *NewNode = Create_Node(NewData);
    if (NewNode == NULL) return (NewNode);
    if (*Tree == NULL)
    *Tree = NewNode;
    else
    {
        node_Type *Rnode = *Tree;
        while (Rnode->right != NULL)
            Rnode = Rnode->right;
        Rnode->right = NewNode;
    }
    return (NewNode);
}
*/
void main()
{
    treetype *root;
    MakeNullTree(root);
    root=create_node(1);
    printf("1");
}

