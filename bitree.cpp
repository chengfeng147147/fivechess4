#include"bitree.h"
#include"link.h"
BiTree*biTree_init()
{
	BiTree*bitree;
	bitree = (BiTree*)malloc(sizeof(BiTree));
	bitree->parentNode = NULL;
	bitree->curNode = NULL;
	
	return bitree;
}
void curNode_init(BiTree*bitree)
{
	bitree->curNode = bitree->parentNode;
}
BiTNode* init_bitNode(){

	BiTNode*bitNode;
	bitNode = (BiTNode*)malloc(sizeof(BiTNode));
	//bitNode = NULL;
	bitNode->lchild = NULL;
	bitNode->rchild = NULL;
	return bitNode;
}
int bitree_append(BiTree*bitree, char*userblack, char*userwhite,int*offset)
{
	BiTNode* bitnode,*tempnode;
	int judge;
	bitnode = init_bitNode();
	tempnode = init_bitNode();
	strncpy(bitnode->userblack, userblack, 10);
	strncpy(bitnode->userwhite, userwhite, 10);
	bitnode->offset =*offset;
	if (bitree->curNode==NULL)
	{
		bitree->parentNode = bitnode;
		bitree->curNode = bitnode;
		return 1;
	}
	else
	{
		judge = strcmp(userblack, bitree->curNode->userblack);
	}
	if (judge > 0)
	{
		if (bitree->curNode->lchild == NULL)
		{
			bitree->curNode->lchild = bitnode;
			return 1;
		}
		else
		{
			bitree->curNode = bitree->curNode->lchild;
			bitree_append(bitree, userblack, userwhite,offset);
		}
	}
	else if (judge<0)
	{
		if (bitree->curNode->rchild == NULL)
		{
			bitree->curNode->rchild = bitnode;
			return 1;
		}
		else{
			bitree->curNode = bitree->curNode->rchild;
			bitree_append(bitree, userblack, userwhite,offset);
		}
	}
	else {
		if (judge == 0 && bitree->curNode->mchild != NULL)
		{

			tempnode = bitree->curNode->mchild;
			bitree->curNode->mchild = bitnode;
			bitree->curNode = bitree->curNode->mchild;
			bitree->curNode->mchild = tempnode;
			return 1;
		}
		else
		{
			bitree->curNode->mchild = bitnode;
			return 1;
		}
	} 
	return 1;
}
BiTNode* BiNode_find(BiTree*bitree, char*userblack, char*userwhite)
{
	
	int judge;
	BiTNode*tempNode;
	Link*link;
	link = link_init();
	tempNode = (BiTNode*)malloc(sizeof(BiTNode));
	if (bitree->curNode == NULL)
	{
		
		return bitree->curNode;
	}
	judge = strcmp(userblack, bitree->curNode->userblack);
	if (judge > 0)
	{
		bitree->curNode = bitree->curNode->lchild;
		BiNode_find(bitree,userblack, userwhite);
	}
	else if (judge < 0)
	{
		bitree->curNode = bitree->curNode->rchild;
		BiNode_find(bitree,userblack, userwhite);
	}
	else if(judge==0)
	{
	
		return bitree->curNode;
	}
	
}
