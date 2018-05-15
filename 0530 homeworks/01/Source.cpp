#include<stdio.h>
#include<stdlib.h>
#include<string>

#define length 100

FILE *checkopen(char file[], char mode[]) {
	FILE *origin;
	if ((origin = fopen(file, mode)) == NULL)
	{
		printf("檔案開啟時發生錯誤！\n");
		origin = NULL;
	}
	return origin;
}

void fileToStr(FILE *origin, char saving[length][length], int maximum) {
	int i = 0, j = 0;
	char data;
	while ((data = fgetc(origin)) != EOF)
	{
		if (data == 32)
		{
			saving[i][j] = '\0';
			i++;
			j = 0;
		}
		else if (i < maximum&&j < maximum)
		{
			saving[i][j] = data;
			j++;
		}
		else
		{
			printf("檔案開啟時發生錯誤！\n檔案大小超過限制！！\n");
			exit(1);
		}
	}
	
	saving[i][j] = '\0';
	i++;
	saving[i][0] = '\0';
}

void strPrint(char saving[length][length]) {
	for (int i = 0; saving[i][0] != '\0'; i++)
	{
		for (int j = 0;saving[i][j] != '\0';j++) {
			putchar(saving[i][j]);
		}
		putchar('\n');
	}
}

void strToFile(char saving[length][length], FILE *destination) {
	for (int i = 0; saving[i][0] != '\0'; i++)
	{
		for (int j = 0;saving[i][j] != '\0';j++) {
			fputc(saving[i][j], destination);
		}
		fputc('\n',destination);
	}
}

int wordCounter(char str[length][length]) {
	int wordNum = 0;
	for (int i = 0, j = 0;str[i][0] != '\0'; j++)
	{
		if (str[i][j] = '\0')
		{
			wordNum++;
			i++;
		}
	}
	return (wordNum - 1);
}

//河蟹
void replace(char word[length][length], char literary[length][length]) {
	int times=wordCounter(word)
}

void main(int argc, char *argv[]) {
	FILE *badWord, *document;
	char bwlist[length][length], doclist[length][length];

	if (argc > 1)
	{
		//開檔格式：程式.exe remove 髒話檔.txt in 過濾檔.txt
		if (strcmp(argv[1], "remove") && strcmp(argv[4], "in")) 
		{
			if (argc > 4)
			{
				badWord = checkopen(argv[2], "rb");
				if (badWord != NULL)
				{
					printf("檔案開啟成功！\n");
					fileToStr(badWord, bwlist, length);
					fclose(badWord);
					printf("檔案讀取成功！\n");
					printf("\n=====要屏蔽的字詞為=====\n");
					strPrint(bwlist);
					printf("\n=====字詞數量為為 %d個=====\n", wordCounter(bwlist));
				}
				else
				{
					printf("檔案開啟失敗！！\n");
					exit(1);
				}

				document = checkopen(argv[4], "wb");
				if (document != NULL)
				{
					printf("檔案開啟成功！\n");
					fileToStr(document, doclist, length);
					fclose(document);
					printf("檔案讀取成功！\n");
					
				}
				else
				{
					printf("檔案開啟失敗！！\n");
					exit(1);
				}


			}
			
		}
		else
		{
			printf("請依格式輸入：\n開檔格式：程式.exe remove 髒話檔.txt in 過濾檔.txt\n");
			exit(1);
		}
	}

}