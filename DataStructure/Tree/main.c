#include <stdio.h>
#include <stdlib.h>

//#include "BinarySearchTree.c"

#define bool char
#define true 1
#define false 0


typedef struct Node_ {
    int value;
    struct Node_ *left;
    struct Node_ *right;
}Node;

typedef Node *Tree;


//二叉树排序添加
void add(Tree *root , int value)
{
    Tree f,p;
    p = *root;

    while (p) {
        if (value == p->value)
            return;
        f = p;
        p = (value < p->value) ? p->left : p->right;
    }

    p = (Tree)malloc(sizeof(Node));

    p->value = value;
    p->left = NULL;
    p->right = NULL;

    if (*root == NULL)
        *root = p;
    else
        if (value < f->value)
            f->left = p;
        else
            f->right = p;
}

//创建二叉排序树
Tree create()
{
    Tree root = NULL;
    int value;
    printf("请输入一个以-1为结束标记的结点序列\n");
    scanf("%d",&value);
    while (value != -1) {
        //将value添加到二叉排序树root中
        add(&root,value);
        scanf("%d",&value);
    }
    //返回建立的二叉排序树的根地址
    return root;
}


//二叉树排序的遍历

//中序遍历
void in_order(Tree root)
{
    if (root)
    {
        in_order(root->left);

        printf("%d ",root->value);

        in_order(root->right);
    }
}

//前序遍历
void pre_order(Tree root)
{
    if (root)
    {
        printf("%d ",root->value);

        pre_order(root->left);

        pre_order(root->right);
    }
}

//后序遍历
void post_order(Tree root)
{
    if (root)
    {
        post_order(root->left);

        post_order(root->right);

        printf("%d ",root->value);
    }
}


//二叉排序树的插入
void insert(Tree *root,int value)
{
    Tree oldTree,p;
    p = *root;

    while (p) {
        if (value == p->value)
            return;

        oldTree = p;
        p = (value < p->value) ? p->left : p->right;
    }

    Tree newTree;
    newTree = (Tree)malloc(sizeof(Tree));

    newTree->value = value;
    newTree->left = NULL;
    newTree->right = NULL;

    if (*root == NULL)
        *root = newTree;
    else {
        if (value < oldTree->value)
            oldTree->left = newTree;
        else
            oldTree->right = newTree;
    }

}

bool find(Tree root,int value)
{
    bool flag = false;

    while (root && !flag) {
        if (root->value == value)
            flag = true;
        else if (root->value < value)
            root = root->right;

        else
            root = root->left;
    }
    return flag;
}

void modify(Tree *root,int value,int newValue)
{
    Tree p;
    p = *root;
    if (find(p,value) == true) {
        printf("修改成功！\n");
        bool flag = false;
        while (p && !flag) {
            if (p->value == value){
                //p->value = newValue;//该方法会破坏二叉排序树
                DeleteTree(&p);//把需要修改数据的节点先删除
                add(root,newValue);//然后把修改的数据添加到二叉排序树中
            }
            else if (p->value < value)
                p = p->right;
            else
                p = p->left;
        }
    }
    else
        printf("该数不存在!\n");
}

void delete(Tree *root,int value)
{
    if (find(*root,value) == true) {
        if ((*root)->value == value)
            DeleteTree(root);
        else if ((*root)->value > value)
            return delete(&(*root)->left , value);
        else
            return delete(&(*root)->right , value);
    }
    else
        printf("该数不存在!\n");
}

int DeleteTree(Tree *root)
{
    //从二叉排序树中删除节点p，并重新接它的左或右子树
    Tree q,s;
    if (!(*root)->left && !(*root)->right)//p为叶子节点
        *root = NULL;
    else if ( !(*root)->left )//左子树为空，重接右子树
    {
        q = *root;
        *root = (*root)->right;
        free(q);
    }
    else if( !(*root)->right )//右子树为空，重接左子树
    {
        q = *root;
        *root = (*root)->left;
        free(q);
    }
    else
    {
        q = *root;
        s = (*root)->left;
        while (s->right)
        {
            q = s;
            s = s->right;
        }
        (*root)->value = s->value;
        if ( q != *root)
            q->right = s->left;
        else
            q->left = s->left;

        free(s);
    }
    return true;
}

int main()
{
    Tree root;
    int flag;

    while (1)
    {
        printf("1、输入\n");
        printf("2、显示\n");
        printf("3、插入\n");
        printf("4、修改\n");
        printf("5、删除\n");
        printf("6、退出\n");

        scanf("%d",&flag);

        switch (flag) {
            case 1:
                root = create();
                break;
            case 2:
                printf("In Order:\n");
                in_order(root);
                printf("\n");

                printf("Pre Order:\n");
                pre_order(root);
                printf("\n");

                printf("Post Order:\n");
                post_order(root);
                printf("\n");
                break;
            case 3:
                printf("请输入需要插入的数据:\n");
                int value;
                scanf("%d",&value);
                insert(&root,value);
                break;

            case 4:
                printf("请输入需要修改的数据:\n");
                int value1,temp;
                scanf("%d%d",&value1,&temp);
                //printf("%d %d\n",num1,num2);
                modify(&root,value1,temp);
                break;
            case 5:
                printf("请输入需要删除的数据:\n");
                int value2;
                scanf("%d",&value2);
                delete(&root,value2);
                break;

            case 6:
                exit(0);
                break;
        }
    }
    return 0;
}
