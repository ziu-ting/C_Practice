#include<stdio.h>
#include<stdlib.h>
#include<string>

//�إ�linklist
struct _linkmain {
	char *word;
	struct _linkmain *next;
};
typedef struct _linkmain link;

//�W�[linklist�`�I
link *newNode(link *newlink) {
	newlink = (link *)malloc(sizeof(link));

	if (newlink == NULL)
	{
		printf("�O���餣���I\n");
		return NULL;
	}

	newlink->next = NULL;

	return newlink;
}


//�˴��ɮ׶}�ҬO�_���\
FILE *openFile(char fileName[],char mode[]) {
	FILE *data;
	if ((data = fopen(fileName, mode)) == NULL)
	{
		printf("�ɮ׶}�Үɵo�Ϳ��~�I\n");
		data = NULL;
	}
	return data;
}

//�N�ɮ�Ū�Jlinklist
void filetoNode(FILE *origin, link *saving) {
	char data;
	link *allData, *partData;
	while (data = fgetc(origin) != EOF)
	{

		if (data == 32) {

		}
		else
		{
			partData->next
		}
	}
}



void main(int argc, char *argv[]) {
	//��J�榡�G�{��.exe count �ɮ�.txt

	if (argc > 1)
	{
		if (strcmp(argv[1], "count")) {
			if (argc == 3)
			{
				FILE *origin = openFile(argv[2], "rb");
				if (origin != NULL)
				{

					printf("Ū�ɦ��\�I�I\n");
					fclose(origin);
				}
				else
				{
					printf("�ɮ�%s���s�b�I\n", argv[2]);
					exit(1);
				}
			}
		}
		else
		{
			printf("�Ш̥��T�榡��J�I\n\t��J�榡�G�{��.exe count �ɮ�.txt\n");
			exit(1);
		}
	}
}