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

// Truy cập con trái,phải
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

// Tạo node mới
node_Type *Create_Node(int NewData)
{ 
    node_Type *N=(node_Type*)malloc(sizeof(node_Type));
    if (N != NULL)
    { 
        N->left = NULL;
        N->right = NULL;
        N->element = NewData;
    }
    return N;
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
    treetype N=(node_Type*)malloc(sizeof(node_Type));
    N->element=v;
    N->left=l; 
    N->right=r;
    return N;
}

// Thêm nút vào vị trí trái nhất
treetype Add_Left(treetype Tree, int NewData){ 
    node_Type *NewNode = Create_Node(NewData);
    if (NewNode == NULL) return (NewNode);
    if (Tree == NULL)
    Tree = NewNode;
    else{
    node_Type *Lnode = Tree;
    while (Lnode->left != NULL)
    Lnode = Lnode->left;
    Lnode->left = NewNode;
    }
    return (NewNode);
}


// Thêm nút vào vị trí phải
treetype Add_Right(treetype Tree, int NewData)
{ 
    node_Type *NewNode = Create_Node(NewData);
    if (NewNode == NULL) return (NewNode);
    if (Tree == NULL)
    Tree = NewNode;
    else
    {
        node_Type *Rnode = Tree;
        while (Rnode->right != NULL)
            Rnode = Rnode->right;
        Rnode->right = NewNode;
    }
    return (NewNode);
}

// Xóa một node khỏi cây
void DeleteNode(int x,treetype Root)
{ 
    if (Root!=NULL) 
    if (x < Root->element) DeleteNode(x, &Root->left); 
    else if (x > Root->element)
    DeleteNode(x, &Root->right); 
    else if  ( Root->left==NULL && Root->right==NULL) 
        Root=NULL; 
    else if (Root->left == NULL)
        Root = Root->right; 
    else if (Root->right==NULL) 
        Root = Root->left ;
    else Root->element = DeleteMin(&Root->right); 
}
// Xóa tất cả node
void freetree(treetype tree)
{
    if (tree!=NULL)
        {
            freetree(tree->left);
            freetree(tree->right);
            free((void *) tree);
            }
}
void main()
{
    treetype root= Create_Node(5);
    root->left=Add_Left(root,3);
    root->right=Add_Right(root,9);
    printf("%d",nb_nodes(root));
}

