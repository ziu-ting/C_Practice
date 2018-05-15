#include<stdio.h>
#include<stdlib.h>

#define maxLength 100


//建立一開啟檔案，並檢定檔案是否正常開啟之函式
FILE *fileHandle(char filename[], char mode[]) {
	FILE *object;
	object = fopen(filename, mode);
	if (object == NULL)
	{
		printf("%s","檔案開啟時發生錯誤\n");
		object = NULL;
	}
	
	return object;

}

//建立一函示以將檔案內容逐字寫入字串陣列
void fileToString(FILE* seat,char savingString[maxLength][maxLength],int length){
	int dataword;
	int conti = 0, contj = 0;

	while ((dataword = fgetc(seat)) != EOF)//判斷結束
	{
		//判斷空格 跳入下一列(?)陣列
		if (dataword == 32)
		{
			savingString[conti][contj] = '\0';//補上空 完成陣列
			conti++;//進入下一列
			contj = 0;//從索引值0開始
		}
		else
		{
			if ((conti < length) && (contj < length))//限制檔案大小
			{
				savingString[conti][contj] = dataword;
				contj++;
			}
			else
			{
				printf("檔案過大\t開啟時發生錯誤\n");
				exit(1);//非正常結束
			}
		}
	}
	//檔案結尾補上空
	savingString[conti][contj] = '\0';
	conti++;
	savingString[conti][0] = '\0';

}

//建立一函示以將陣列內容寫入檔案
void stringToFile(FILE* seat, char savdString[maxLength][maxLength], int length) {
	for (int i = 0, j = 0;savdString[i][0] != '\0'; i++)
	{
		for (int j = 0;savdString[i][j] != '\0';j++)
		{
			fputc(savdString[i][j], seat);
		}
		fputc('\n', seat);
	}
}




/*
step1 開啟髒話檔
step2 尋找目的檔中的髒話 以空白取代
step3 取代完成
*/
void main(int argc, char *argv[]) {

	//printf("%s", "=====髒話過濾器=====\n輸入格式：\n\t(存取髒話的檔案) (space) (要過濾的檔案)\n\n");

	char badWordString[maxLength][maxLength];
	FILE *badWord = fileHandle(argv[1], "rb");
	if (badWord != NULL)
	{
		fileToString(badWord, badWordString, maxLength);
		fclose(badWord);
		printf("%s", "檔案讀取成功\n\n...已存取過濾清單\n");
	}
	else
	{
		printf("%s","檔案開啟時發生錯誤\n");
		exit(1);
	}

	
	/*for (int i = 0, j = 0;badWordString[i][0] != '\0'; i++)
	{
		for (int j = 0;badWordString[i][j] != '\0';j++)
		{
			printf(" %c",badWordString[i][j]);
		}
		puts("\n");
	}*/
}

