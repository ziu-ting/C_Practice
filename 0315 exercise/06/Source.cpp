#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int indentify(int user) {//判斷使用者出拳
	if (user == 0)
	{
		printf("肥宅出的拳為：石頭\n");
		return 0;
	}
	else if (user == 1)
	{
		printf("肥宅出的拳為：布\n");
		return 1;
	}
	else if (user == 2)
	{
		printf("肥宅出的拳為：剪刀\n");
		return 2;
	}
	else
	{
		printf("肥宅腦抽了? 請重新出拳喔 呵呵\n");
		int re_user;//再定義一變數使使用者重新輸入
		printf("肥宅出拳喔~\t");
		scanf("%d", &re_user);
		return indentify(re_user);
	}
}


int main(void) {

	printf("\t=====遊戲規則=====\n出石頭請輸入0\t出布請輸入1\t出剪刀請輸入2\n猜拳贏3次方可結束遊戲\n");
	printf("\t=====遊戲開始=====\n");

	int win = 0, lose = 0, draw = 0;

	for (int i=1; win < 3;i++)//當勝利次數累計至3時自動跳出
	{
		printf("肥宅請出拳:\t");
		int user;
		scanf("%d", &user);
		indentify(user);

		int computer = 0;
		srand(time(NULL));
		computer = rand() % 2;//使電腦出拳範圍為0到2

		switch (computer)
		{
		case 0://電腦石頭
			printf("電腦出的拳為：石頭\n");
			if (user==0)//我方出石頭
			{
				printf("哎呀~居然平手惹\n");
				draw++;
			}
			else if (user==2)//我方出剪刀
			{
				printf("唉嘿~肥宅輸了呵呵\n");
				lose++;
			}
			else//我方出布
			{
				printf("肥宅勝利惹耶\n");
				++win;
			}
			break;
		case 1:
			printf("電腦出的拳為：布\n");
			if (user == 1)
			{
				printf("哎呀~居然平手惹\n");
				draw++;
			}
			else if (user == 0)
			{
				printf("唉嘿~肥宅輸了呵呵\n");
				lose++;
			}
			else
			{
				printf("肥宅勝利惹耶\n");
				++win;
			}
			break;
		case 2:
			printf("電腦出的拳為：剪刀\n");
			if (user == 2)
			{
				printf("哎呀~居然平手惹\n");
				draw++;
			}
			else if (user == 1)
			{
				printf("唉嘿~肥宅輸了呵呵\n");
				lose++;
			}
			else
			{
				printf("肥宅勝利惹耶\n");
				
				++win;
			}
			break;
		default:
			break;
		}
		printf("====肥宅戰績匯報====\n");
		printf("累積至今第%d場，總共勝利了%d場，平手了%d場，輸了%d場QQ\n\n",i,win,draw,lose);
	}
	printf("恭喜肥宅成功脫出~\n");
	system("pause");
}