#include<stdio.h>
#include<stdlib.h>

int NFactorial(int x) {//計算階乘
	
	int ans = 1;
	for (x; x>0; x--)//使(x)*(x-1)*....*1
	{
		ans *= x;
	}

	return ans;
}

int NPower(int n, int m) {//計算指數...........跑不出來QWQQQ
	
	double ans = n;
	for (m; m >=1; m--)
	{
		ans *= n;
	}
	return ans;
}

int NFibonacci(int x) {//計算費式數列，運用遞回函數
	
	if (x==0)//F(0)=0
	{
		return 0;
	}
	else if (x==1)//F(1)=1
	{
		return 1;
	}
	else//F(x)，x>=2
	{
		return NFibonacci(x - 1) + NFibonacci(x - 2);
	}

}

int main(void) {
	printf("===歡迎使用函數計算機===\n\n此計算機能計算之函數為：\n1\t階乘\n2\t指數函數\n3\t費式數列\n\n請選擇欲求之函數：\t");

	int chooce;//建立一變數使使用者選擇所要運用之函數
	scanf("%d", &chooce);
	switch (chooce)//依所輸入之值，選擇進行之函數
	{

	case 1://進行階乘運算
		printf("所選擇之函數為\t階乘\n\n");
		printf("請輸入欲求取之階乘數\nＮ！\t Ｎ=");
		int x_1;
		scanf("%d", &x_1);
		printf("%d！=%d", x_1, NFactorial(x_1));
		break;
	case 2://進行指數運算
		printf("所選擇之函數為\t指數函數\n\n");
		printf("請輸入欲求之底數與次方數\nＮ^m\t(Ｎ,m)=");
		int n, m;
		scanf("(%d,%d)", &n, &m);
		printf("%d^%d=%d", n, m, NPower(n, m));
		break;
	case 3://進行費式數列
		printf("所選擇之函數為\t費式數列\n\n");
		printf("請輸入欲求費式數列之項數\nＦ（n）\tn=");
		int x_3;
		scanf("%d", &x_3);
		printf("F(%d)=%d", x_3, NFibonacci(x_3));
		break;
	default:
		break;
	}
	system("pause");
}

