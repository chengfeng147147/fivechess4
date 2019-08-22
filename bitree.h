#include<stdlib.h>
#include<string.h>
#include"link.h"
#ifndef _BITREE_H
#define _BITREE_H
#define NULL 0
typedef struct _biTNode{

	char userblack[10],userwhite[10];
	int offset;
	_biTNode *lchild, *rchild,*mchild;

};
typedef struct _biTNode BiTNode;
typedef struct _biTree{
	
	BiTNode*parentNode;
	BiTNode*curNode;
};
typedef struct _biTree BiTree;
extern BiTree*biTree_init();
extern void curNode_init(BiTree*bitree);
extern int bitree_append(BiTree*bitree, char*userblack, char*userwhite, int*offset);
extern BiTNode* BiNode_find(BiTree*bitree, char*userblack, char*userwhite);
#endif