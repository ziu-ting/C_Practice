#include<stdio.h>
#include<stdlib.h>
#include<string>

struct _linklist
{
	char name[100];
	int amount;
	struct _linklist *nextlist;
};
typedef struct _linklist linklist;
typedef linklist *linkPtr;

void purchase(linkPtr *firstPtr, char *name, int amount) {
	linkPtr addPtr, a0Ptr, a1Ptr;

	addPtr = (linkPtr)malloc(sizeof(linklist));
	addPtr->nextlist = NULL;
	strcmp(addPtr->name, name);
	addPtr->amount = amount;

	if (*firstPtr==NULL)
	{
		*firstPtr = addPtr;
	}
	else
	{
		if (addPtr==NULL)
		{

		}
		else
		{
			while (addPtr!=NULL&&strcmp(addPtr->name,name)!=0)
			{
				a1Ptr = a0Ptr;
				a0Ptr = a0Ptr->nextlist;
			}
		}
	}
}