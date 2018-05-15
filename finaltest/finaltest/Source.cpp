#include<stdio.h>
#include<stdlib.h>
#include<string>

#define length 100

//建立linklist
struct _bssSystem
{
	char name[length];
	int amount;
	struct _bssSystem *nextPtr;
};
typedef struct _bssSystem bssList;//以別名方式縮短宣告
typedef bssList *bssPtr;//指標

//建立進貨函式
void purchase(char *name, int amount, bssPtr *sysPtr) {
	
	/*
	addPtr -> 擴充linklist
	a0Ptr -> 當前運作位置
	a1Ptr -> 預判運作位置
	*/
	bssPtr a0Ptr, a1Ptr, addPtr;

	//將資料建立成單一表單
	addPtr = (bssPtr)malloc(sizeof(bssList));
	strcpy(addPtr->name, name);
	addPtr->amount = amount;
	addPtr->nextPtr = NULL;

	if (*sysPtr == NULL)//若linklist未建立，表單直接建立linklist
	{
		*sysPtr = addPtr;
	}
	else
	{
		a0Ptr = *sysPtr;

		while (a0Ptr != NULL&&strcmp(a0Ptr->name, addPtr->name) != 0)//當貨品名稱不符合，自動向下一項跳尋
		{
			a1Ptr = a0Ptr;
			a0Ptr = a0Ptr->nextPtr;
		}

		//未有此貨品
		if (a0Ptr == NULL)
		{
			a1Ptr->nextPtr = addPtr;
		}
		//已有此貨品
		else
		{
			a0Ptr->amount = a0Ptr->amount + addPtr->amount;
		}
	}
}

//建立銷貨函式
void sell(bssPtr *sysPtr, char *name, int amount) {

	bssPtr a0Ptr, a1Ptr = NULL;

	if (*sysPtr == NULL)//linklist未建立
	{
		printf("所輸入庫存位置錯誤！\n");
	}
	else
	{
		a0Ptr = *sysPtr;

		while (a0Ptr != NULL&&strcmp(a0Ptr->name, name) != 0)//當貨品名稱不符合，自動向下一項跳尋
		{
			a1Ptr = a0Ptr;
			a0Ptr = a0Ptr->nextPtr;
		}
		if (a0Ptr == NULL)
		{
			printf("此商品暫無庫存！\n");
		}
		else
		{
			//庫存不足
			if (a0Ptr->amount < amount)
			{
				printf("商品目前庫存數不足！\n目前商品僅存...\t%d 單位\n", (a0Ptr->amount));
			}
			//庫存足夠
			//剛好賣光，需刪除空白的linklist
			else if (a0Ptr->amount == amount)
			{
				a0Ptr->amount = a0Ptr->amount - amount;
				
				//刪除空白的linklist
				//存放於linklist首(先進)
				if (a0Ptr = *sysPtr)
				{
					*sysPtr = a0Ptr->nextPtr;
				}
				//存放於linklist中、尾(後進)
				else
				{
					a1Ptr->nextPtr = a0Ptr->nextPtr;
				}
			}
			//有剩餘
			else
			{
				a0Ptr->amount = a0Ptr->amount - amount;
			}
		}
	}
}

//建立查詢單項庫存函式
void specific(char *name, bssPtr sysPtr) {
	
	while (sysPtr != NULL&&strcmp(sysPtr->name, name) != 0)//當貨品名稱不符合，自動向下一項跳尋
	{
		sysPtr = sysPtr->nextPtr;
	}

	if (sysPtr == NULL)
	{
		printf("此商品暫無庫存！\n");
	}
	else
	{
		printf("目前商品數量為...\t%d 單位\n", sysPtr->amount);
	}
}

//建立查詢所有庫存函式
void all(bssPtr sysPtr) {

	int counter = 1;
	while (sysPtr != NULL)
	{
		printf("[%d]\n商品名稱：\t%s\n商品數量：\t%d\n\n", counter, sysPtr->name, sysPtr->amount);
		sysPtr = sysPtr->nextPtr;
		counter++;
	}
	printf("庫存共%d項商品\n", counter-1);
}

//建立儲存系統資料函式
void save(char *place, bssPtr sysPtr) {
	FILE *origin = fopen(place, "w");
	//若開檔發生錯誤
	if (origin == NULL)
	{
		printf("檔案開啟時發生錯誤！\n");
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
			printf("檔案開啟時發生錯誤！\n");
			exit(1);
		}

		bssPtr sysPtr = NULL;

		int amount;
		char name[length];
		//將檔案內容導入,期初存貨視同進貨
		while (fscanf(origin, "%s\t%d", name, &amount) != EOF)
		{
			purchase(name, amount, &sysPtr);
		}

		fclose(origin);

		int choose;
	
		printf("=====進銷存系統=====\n\n");

		do {
			printf("[1]進貨\n");
			printf("[2]銷貨\n");
			printf("[3]查詢單一商品庫存\n");
			printf("[4]查詢所有商品庫存\n");
			printf("[5]儲存\n");
			printf("[6]儲存並離開\n");
			printf("[7]不儲存就離開\n");

			printf("\n請選擇服務項目（輸入項目數字）：\n");
			scanf("%d", &choose);

			switch (choose)
			{
			case 1:
				printf("請輸入商品名稱：");
				scanf("%s", name);
				printf("請輸入欲進貨之數量：");
				scanf("%d", &amount);
				printf("此次進貨：%s\t共%d單位\n\n", name, amount);
				purchase(name, amount, &sysPtr);
				specific(name, sysPtr);
				//menu(choose, sysPtr, place);
				break;
			case 2:
				printf("請輸入商品名稱：");
				scanf("%s", name);
				printf("請輸入欲銷貨之數量：");
				scanf("%d", &amount);
				printf("此次銷貨：%s\t共%d單位\n\n", name, amount);
				sell(&sysPtr, name, amount);
				specific(name, sysPtr);
				//menu(choose, sysPtr, place);
				break;
			case 3:
				printf("請輸入商品名稱：");
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
				printf("檔案儲存完成！\n");
				//menu(choose, sysPtr, place);
				break;
			case 6:
				save(argv[1], sysPtr);
				printf("檔案儲存完成！\n");
				printf("即將離開本系統！\n");
				break;
			case 7:
				printf("即將離開本系統！\n");
				break;
			default:
				printf("請輸入1~7之選項數字！\n");
				//menu(choose, sysPtr, place);
				break;
			}
		} while (choose <= 5);

	}
	else
	{
		printf("請輸入正確格式以開啟資料庫！\n輸入格式：程式.exe 進銷存資料檔.txt\n\n");
		exit(1);
	}
}