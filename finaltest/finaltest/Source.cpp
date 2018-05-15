#include<stdio.h>
#include<stdlib.h>
#include<string>

#define length 100

//�إ�linklist
struct _bssSystem
{
	char name[length];
	int amount;
	struct _bssSystem *nextPtr;
};
typedef struct _bssSystem bssList;//�H�O�W�覡�Y�u�ŧi
typedef bssList *bssPtr;//����

//�إ߶i�f�禡
void purchase(char *name, int amount, bssPtr *sysPtr) {
	
	/*
	addPtr -> �X�Rlinklist
	a0Ptr -> ��e�B�@��m
	a1Ptr -> �w�P�B�@��m
	*/
	bssPtr a0Ptr, a1Ptr, addPtr;

	//�N��ƫإߦ���@���
	addPtr = (bssPtr)malloc(sizeof(bssList));
	strcpy(addPtr->name, name);
	addPtr->amount = amount;
	addPtr->nextPtr = NULL;

	if (*sysPtr == NULL)//�Ylinklist���إߡA��檽���إ�linklist
	{
		*sysPtr = addPtr;
	}
	else
	{
		a0Ptr = *sysPtr;

		while (a0Ptr != NULL&&strcmp(a0Ptr->name, addPtr->name) != 0)//��f�~�W�٤��ŦX�A�۰ʦV�U�@�����M
		{
			a1Ptr = a0Ptr;
			a0Ptr = a0Ptr->nextPtr;
		}

		//�������f�~
		if (a0Ptr == NULL)
		{
			a1Ptr->nextPtr = addPtr;
		}
		//�w�����f�~
		else
		{
			a0Ptr->amount = a0Ptr->amount + addPtr->amount;
		}
	}
}

//�إ߾P�f�禡
void sell(bssPtr *sysPtr, char *name, int amount) {

	bssPtr a0Ptr, a1Ptr = NULL;

	if (*sysPtr == NULL)//linklist���إ�
	{
		printf("�ҿ�J�w�s��m���~�I\n");
	}
	else
	{
		a0Ptr = *sysPtr;

		while (a0Ptr != NULL&&strcmp(a0Ptr->name, name) != 0)//��f�~�W�٤��ŦX�A�۰ʦV�U�@�����M
		{
			a1Ptr = a0Ptr;
			a0Ptr = a0Ptr->nextPtr;
		}
		if (a0Ptr == NULL)
		{
			printf("���ӫ~�ȵL�w�s�I\n");
		}
		else
		{
			//�w�s����
			if (a0Ptr->amount < amount)
			{
				printf("�ӫ~�ثe�w�s�Ƥ����I\n�ثe�ӫ~�Ȧs...\t%d ���\n", (a0Ptr->amount));
			}
			//�w�s����
			//��n����A�ݧR���ťժ�linklist
			else if (a0Ptr->amount == amount)
			{
				a0Ptr->amount = a0Ptr->amount - amount;
				
				//�R���ťժ�linklist
				//�s���linklist��(���i)
				if (a0Ptr = *sysPtr)
				{
					*sysPtr = a0Ptr->nextPtr;
				}
				//�s���linklist���B��(��i)
				else
				{
					a1Ptr->nextPtr = a0Ptr->nextPtr;
				}
			}
			//���Ѿl
			else
			{
				a0Ptr->amount = a0Ptr->amount - amount;
			}
		}
	}
}

//�إ߬d�߳涵�w�s�禡
void specific(char *name, bssPtr sysPtr) {
	
	while (sysPtr != NULL&&strcmp(sysPtr->name, name) != 0)//��f�~�W�٤��ŦX�A�۰ʦV�U�@�����M
	{
		sysPtr = sysPtr->nextPtr;
	}

	if (sysPtr == NULL)
	{
		printf("���ӫ~�ȵL�w�s�I\n");
	}
	else
	{
		printf("�ثe�ӫ~�ƶq��...\t%d ���\n", sysPtr->amount);
	}
}

//�إ߬d�ߩҦ��w�s�禡
void all(bssPtr sysPtr) {

	int counter = 1;
	while (sysPtr != NULL)
	{
		printf("[%d]\n�ӫ~�W�١G\t%s\n�ӫ~�ƶq�G\t%d\n\n", counter, sysPtr->name, sysPtr->amount);
		sysPtr = sysPtr->nextPtr;
		counter++;
	}
	printf("�w�s�@%d���ӫ~\n", counter-1);
}

//�إ��x�s�t�θ�ƨ禡
void save(char *place, bssPtr sysPtr) {
	FILE *origin = fopen(place, "w");
	//�Y�}�ɵo�Ϳ��~
	if (origin == NULL)
	{
		printf("�ɮ׶}�Үɵo�Ϳ��~�I\n");
		exit(1);
	}
	while (sysPtr != NULL)
	{
		fprintf(origin, "%s\t%d\n", sysPtr->name, sysPtr->amount);
		sysPtr = sysPtr->nextPtr;
	}
	fclose(origin);
}

void main(int argc, char *argv[]) {
	if (argc==2)
	{
		FILE *origin = fopen(argv[1], "r");
		if (origin == NULL)
		{
			printf("�ɮ׶}�Үɵo�Ϳ��~�I\n");
			exit(1);
		}

		bssPtr sysPtr = NULL;

		int amount;
		char name[length];
		//�N�ɮפ��e�ɤJ,����s�f���P�i�f
		while (fscanf(origin, "%s\t%d", name, &amount) != EOF)
		{
			purchase(name, amount, &sysPtr);
		}

		fclose(origin);

		int choose;
	
		printf("=====�i�P�s�t��=====\n\n");

		do {
			printf("[1]�i�f\n");
			printf("[2]�P�f\n");
			printf("[3]�d�߳�@�ӫ~�w�s\n");
			printf("[4]�d�ߩҦ��ӫ~�w�s\n");
			printf("[5]�x�s\n");
			printf("[6]�x�s�����}\n");
			printf("[7]���x�s�N���}\n");

			printf("\n�п�ܪA�ȶ��ء]��J���ؼƦr�^�G\n");
			scanf("%d", &choose);

			switch (choose)
			{
			case 1:
				printf("�п�J�ӫ~�W�١G");
				scanf("%s", name);
				printf("�п�J���i�f���ƶq�G");
				scanf("%d", &amount);
				printf("�����i�f�G%s\t�@%d���\n\n", name, amount);
				purchase(name, amount, &sysPtr);
				specific(name, sysPtr);
				//menu(choose, sysPtr, place);
				break;
			case 2:
				printf("�п�J�ӫ~�W�١G");
				scanf("%s", name);
				printf("�п�J���P�f���ƶq�G");
				scanf("%d", &amount);
				printf("�����P�f�G%s\t�@%d���\n\n", name, amount);
				sell(&sysPtr, name, amount);
				specific(name, sysPtr);
				//menu(choose, sysPtr, place);
				break;
			case 3:
				printf("�п�J�ӫ~�W�١G");
				scanf("%s", name);
				specific(name, sysPtr);
				//menu(choose, sysPtr, place);
				break;
			case 4:
				all(sysPtr);
				//menu(choose, sysPtr, place);
				break;
			case 5:
				save(argv[1], sysPtr);
				printf("�ɮ��x�s�����I\n");
				//menu(choose, sysPtr, place);
				break;
			case 6:
				save(argv[1], sysPtr);
				printf("�ɮ��x�s�����I\n");
				printf("�Y�N���}���t�ΡI\n");
				break;
			case 7:
				printf("�Y�N���}���t�ΡI\n");
				break;
			default:
				printf("�п�J1~7���ﶵ�Ʀr�I\n");
				//menu(choose, sysPtr, place);
				break;
			}
		} while (choose <= 5);

	}
	else
	{
		printf("�п�J���T�榡�H�}�Ҹ�Ʈw�I\n��J�榡�G�{��.exe �i�P�s�����.txt\n\n");
		exit(1);
	}
}