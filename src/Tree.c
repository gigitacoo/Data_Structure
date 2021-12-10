#include "Tree.h"
#include <stdio.h>

//前序遍历
void preOrder(BTreeList btl)
{
    if (btl != NULL)
    {
        //visit(btl); 读取结点数据
        printf("node=%d", btl->id);
        preOrder(btl->lchild);
        preOrder(btl->rchild);
    }
}
//中序遍历
void inOrder(BTreeList btl)
{
    if (btl != NULL)
    {
        inOrder(btl->lchild);
        printf("node=%d", btl->id);
        inOrder(btl->rchild);
    }
}
//后序遍历
void postOrder(BTreeList btl)
{
    if (btl != NULL)
    {
        postOrder(btl->lchild);
        postOrder(btl->rchild);
        printf("node=%d", btl->id);
    }
}
/*求二叉树bt中叶结点的数目*/
int leafcount(BTreeList bt)
{
    if (bt == NULL)
        return (0);
    else if (bt->lchild == NULL && bt->rchild == NULL)
        return (1);
    else
    {
        int n = leafcount(bt->lchild); /* 求左子树的叶子数目*/
        int m = leafcount(bt->rchild); /* 求右子树的叶子数目*/
        return (m + n);
    }
}
int onesoncount(BTreeList t)
/*输出二叉树t中度为1的结点值，并求其个数*/
{
    if (t == NULL)
        return (0);
    else if ((t->lchild == NULL && t->rchild != NULL) ||
             (t->lchild != NULL && t->rchild == NULL))
    {
        printf(t->id);
        return (onesoncount(t->lchild) +
                onesoncount(t->rchild) + 1);
    }
    else
        return (onesoncount(t->lchild) +
                onesoncount(t->rchild));
}
int twoson(BTreeList BT)
/*输出二叉树BT中所有度为2的结点的数据域值，并统计其数目*/
{
    if (BT == NULL)
        return (0);
    else if (BT->lchild == NULL || BT->rchild == NULL)
        return (twoson(BT->lchild) +
                twoson(BT->rchild));
    else if (BT->lchild != NULL && BT->rchild != NULL)
    {
        printf(BT->id);
        return (twoson(BT->lchild) +
                twoson(BT->rchild) + 1);
    }
}
int notleafcount(BTreeList bt)
/*求二叉树bt中非叶结点的数目*/
{
    if (bt == NULL)
        return (0);
    else if (bt->lchild == NULL && bt->rchild == NULL)
        return (0); /*无左右子树*/
    else
    {
        printf(bt->id); /* 输出非终端结点值*/
        int n = notleafcount(bt->lchild);
        /* 求左子树的非终端结点数目*/
        int m = notleafcount(bt->rchild);
        return (m + n + 1); /* 返回总的非终端结点数*/
    }
}
int f5(BTreeList bt)
/* 打印出二叉树t中所有结点的值，并统计结点的个数 */
{
    if (bt == NULL)
        return (0);
    else
    {
        printf(bt->id);         /* 输出结点值*/
        int n = f5(bt->lchild); /* 求左子树的结点数目*/
        int m = f5(bt->rchild); /* 求右子树的结点数目*/
        return (m + n + 1);     /* 返回总的结点数*/
    }
}

int f6(BTreeList bt)
/*求二叉树bt结点数据域值为８的结点的数目*/
{
    if (bt == NULL)
        return (0);
    else if (bt->id == 8)
        return (f6(bt->lchild) + f6(bt->rchild) + 1);
    else
        return (f6(bt->lchild) + f6(bt->rchild));
}


// 1、一般树 二叉树
// ▲方法： ⑴ 各兄弟之间加连线；
// ⑵ 对任一结点，除最左孩子外，抹掉该结
// 点与其余孩子的各枝；
// ⑶ 以根为轴心，将连线顺时针转450。()见图TreeToBTree

/*
森林F转换成二叉树的方法如下：
⚫（1）将每棵树转换成相应的二叉树；
⚫（2）将（1）中得到的各棵二叉树的根结点看做是
兄弟连接起来。
*/

/*
设森林F中有三棵树，其结点的个数分别为m1、m2、m3，则与F对应的二叉树根
结点的右子树上的结点数是（m2+m3)。
*/

/*
哈夫曼树
叶结点带权的二叉树：
叶结点ni的带权路径长度：
为结点ni到树根的路径长度(ni的祖先的个数li)×结点ni所带的权（pi）

叶结点带权的二叉树路径长度WPL： a b c d 7 5 2 4 d的路径长度=？ WPL=？ n
WPL=∑(pk×lk)，
k=1
其中：n——叶子数
pk——第k个叶子的权,lk——从根到第k个叶子的路径长度（分支数）
        A
    B       C
  D   E   F   G
  7   5   2   4

D的路径长度：祖先结点的个数2 * 权7 = 14;
                              n
G的叶结点带权的二叉树路径长度WPL：WPL=∑(pk×lk)，
                             k=1
即2*7 + 2*5 + 2*2 + 2*4 = 36
*/


