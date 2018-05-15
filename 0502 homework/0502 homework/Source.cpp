#include<stdio.h>
#include<stdlib.h>

#define PleaseDontImputTheNumberLargeThan1000 1000

void change(int &a, int &b);
//void P(int a[], int startpoint, int maximum);
	//概念參考：http://programming.im.ncnu.edu.tw/Chapter10.htm		「列出整數陣列的所有排列」
void Permutation(int a[], int startpoint, int chooce_n, int maximum);


int main(void) {
	int m, n;
	int numberarray[PleaseDontImputTheNumberLargeThan1000] = { 0 };
	//為能存取使用者輸入而判斷陣列大小，預先將陣列大小設為1000，即最多只能做1000項之排列
	//不過輸入這麼多會當很久吧...QWQQQ  助教手下留情

	printf("=====排列組合	P（m,n）====\n\n");

	printf("請輸入總數m：");
	scanf("%d", &m);
	while (m <= 0)//限制m範圍為正整數
	{
		printf("請輸入有效數字！\n");
		printf("請輸入總數m：");
		scanf("%d", &m);
	}
	printf("其中，欲選取排列n項：");
	scanf("%d", &n);
	while (n <= 0 || n > m)//限制n之範圍為正整數，且不可以大於m
	{
		printf("請輸入有效數字！\n");
		printf("欲選取排列n項：");
		scanf("%d", &n);
	}


	while (m<0)
	{
		printf("請輸入有效數字！");
	}

	for (int i = 0; i < m; i++)
	{
		numberarray[i] = i + 1;
	}

	printf("=====即將印出P（%d,%d）之所有排列結果=====\n\n", m, n);

	Permutation(numberarray, 0,  n, m);
	system("pause");
}


//建立一組合之函數
//概念類似於排列，擷取片段後印出

void  Permutation(int a[], int startpoint,  int chooce_n, int maximum) {
	if (startpoint == chooce_n)//從陣列尾端開始執行，當排序至chooce_n(=n)時，印出結果
	{
			for (int i = 0;i < chooce_n;i++) {//印出結果範圍：索引值0 ~ chooce_n - 1
			printf("%d  ", a[i]);
		}
		putchar('\n');
		return;
	}
	for (int i = startpoint; i < maximum; i++)
	{
		change(a[i], a[startpoint]);
		Permutation(a, startpoint + 1, chooce_n, maximum);
		change(a[i], a[startpoint]);
	}

}

//建立一可互換數之函數
void change(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//概念延伸基準：排列之函數
/*
a[]：預定排列之陣列
startpoint：
	每次遞迴的起始索引值(第一個執行為maximum，從陣列尾端進行排列
	進行排列組合時應帶入０
maximum：
	此陣列共maximum項作排列
	C m取n的情況下應帶入n
*/
void P(int a[], int startpoint, int maximum) {
	if (startpoint==maximum)//當遞迴執行起始點在陣列最後，印出陣列
	{
		for (int i = 0;i < maximum;i++) {
			printf("%d", a[i]);	
		}
		putchar('\n');//每次印出間要換行
		return;
	}

	/*
	交換概念示意圖
	A	B	C	D	E
				￣１￣
			￣２　　￣
			￣３￣
		￣４		￣
		￣５	￣
		￣６￣
		ETC.
	*/
	for (int i = startpoint; i < maximum; i++)
	{
		change(a[i], a[startpoint]);
		P(a, startpoint + 1, maximum);//使陣列排序從陣列末端開始遞迴進行
		change(a[i], a[startpoint]);
	}
}