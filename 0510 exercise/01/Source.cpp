#include<stdio.h>
#include<stdlib.h>
#include<string>

#define lenght 100

//建立一檢測檔案是否成功開啟之函式
FILE *successopen(char place[], char mode[]) {
	FILE *origin;
	if ((origin = fopen(place, mode)) == NULL)
	{
		printf("檔案開啟時發生錯誤！\n");
		origin = NULL;
	}
	return origin;
}

//建立一函式，將檔案資料轉入陣列
void filetoStr(FILE *origin, char saving[lenght][lenght],int maximum) {
	int i = 0, j = 0;
	char data;
	while ((data = fgetc(origin)) != EOF)
	{
		if (data == 32) {
			saving[i][j] = '\0';
			i++;
			j = 0;
		}
		else if (i < lenght&&j < lenght)
		{
			saving[i][j] = data;
			j++;
		}
		else
		{
			printf("檔案開啟時發生錯誤！\n檔案過大，讀取錯誤！\n");
			exit(1);
		}
	}

	//建立結尾
	saving[i][j] = '\0';
	i++;
	saving[i][0] = '\0';
}

void test(char saving[lenght][lenght]) {
	for (int i = 0;saving[i][0] != '\0'; i++)
	{
		for (int j = 0; saving[i][j] != '\0'; j++)
		{
			putchar(saving[i][j]);
		}
		puts("\n");
	}
}


//建立一函式，將陣列內容寫入檔案
void strtoFile(char saving[lenght][lenght], FILE *destination) {
	for (int i = 0;saving[i][0] != '\0'; i++)
	{
		for (int j = 0; saving[i][j] != '\0'; j++)
		{
			fputc(saving[i][j], destination);
		}
		fputc('\n', destination);
	}
}



void main(int argc, char *argv[]) {

	char savingStr[lenght][lenght];

	if (argc>1)
	{
		//開啟檔案方式: 程式.exe copy 原檔.txt to 目的檔.txt
		if (!strcmp(argv[1],"copy"))
		{
			if (argc > 3)
			{
				FILE *origin;
				origin = successopen(argv[2], "rb");
				if (origin != NULL)
				{
					filetoStr(origin, savingStr, lenght);
					fclose(origin);
					printf("讀檔成功！\n");
				}
				else
				{
					printf("檔案%s不存在\n", argv[2]);
					exit(1);
				}

				printf("\n=====此文件內容為=====\n\n");
				test(savingStr);
				printf("\n=====檔案寫入中=====\n\n");

				FILE *result;
				result = successopen(argv[4], "wb");
				if (origin != NULL)
				{
					strtoFile(savingStr, result);
					fclose(result);
					printf("寫檔成功！\n");
				}
				else
				{
					printf("檔案%s不存在\n", argv[4]);
					exit(1);
				}
			}
		}
		else
		{
			printf("請依格式輸入：\n程式.exe\tcopy\t原檔.txt\tto\t目的檔.txt\n");
			exit(1);
		}
	}

	//system("pause");
}