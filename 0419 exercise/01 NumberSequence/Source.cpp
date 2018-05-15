#include<stdio.h>
#include<stdlib.h>

#define length 10

//交換兩變數之位置
void change(int &m, int &n) {
	int temp;
	temp = m;
	m = n;
	n = temp;
}

//檢測是否升冪排序
void sequence(int a[], int n) {//陣列為a,當時最高項為n
	
	for (int i = n-1; i>=0 ; i--)
	{
		while (a[n] < a[i])
		{
			change(a[n], a[i]);
			n--;//使檢查項數向前移至小於後項   重要!!!
		}
	}
	
}

int main(void) {
	/*
	//測試函式change()是否可執行
	int x = 1;
	int y = 2;
	change(x,y);
	printf("%d,%d", x, y);
	*/

	int a[length] = { 0 };//初始設定陣列長度為length=10，且各項初始直接為0
	printf("欲排序一長度為%d之陣列\n", length);

	for (int i = 0; i < length; i++)
	{
		printf("請輸入第%d項之值\t",i);

		scanf("%d", &a[i]);//輸入此陣列第i項之值	
		sequence(a, i);//排列陣列

		while (i==length-1)//當輸入完成時，印出陣列
		{
			printf("此陣列總長為%d，其升冪排序為：\n",length);
			for (int j = 0; j <= i; j++)
			{
				printf("%d\t", a[j]);
			}
			break;
		}
		
	}
	system("pause");
}