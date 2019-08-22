#ifndef _LINK_H
#define _LINK_H
typedef struct _LinkNode{
	char userblack[10];
	char userwhite[10];
	int time[6];
	int offset;
	struct _LinkNode* next;
	
};
typedef struct _LinkNode LinkNode;

 typedef struct _Link{
	LinkNode* head;
	LinkNode* tail;
};
typedef struct _Link Link;
extern Link* link_init();
extern int link_append(Link* link, char* userblack, char*userwhite, int* offset);
extern LinkNode* link_find(Link* link, char* userblack, char* userwhite, int* time);
extern void link_destruct(Link* link);
#endif