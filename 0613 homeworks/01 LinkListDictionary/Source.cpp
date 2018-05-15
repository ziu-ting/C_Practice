#include<stdio.h>
#include<stdlib.h>
#include<string>

//建立linklist
struct _linkmain {
	char *word;
	struct _linkmain *next;
};
typedef struct _linkmain link;

//增加linklist節點
link *newNode(link *newlink) {
	newlink = (link *)malloc(sizeof(link));

	if (newlink == NULL)
	{
		printf("記憶體不足！\n");
		return NULL;
	}

	newlink->next = NULL;

	return newlink;
}


//檢測檔案開啟是否成功
FILE *openFile(char fileName[],char mode[]) {
	FILE *data;
	if ((data = fopen(fileName, mode)) == NULL)
	{
		printf("檔案開啟時發生錯誤！\n");
		data = NULL;
	}
	return data;
}

//將檔案讀入linklist
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
	//輸入格式：程式.exe count 檔案.txt

	if (argc > 1)
	{
		if (strcmp(argv[1], "count")) {
			if (argc == 3)
			{
				FILE *origin = openFile(argv[2], "rb");
				if (origin != NULL)
				{

					printf("讀檔成功！！\n");
					fclose(origin);
				}
				else
				{
					printf("檔案%s不存在！\n", argv[2]);
					exit(1);
				}
			}
		}
		else
		{
			printf("請依正確格式輸入！\n\t輸入格式：程式.exe count 檔案.txt\n");
			exit(1);
		}
	}
}