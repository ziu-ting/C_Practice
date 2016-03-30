#include<stdio.h>
#include<stdlib.h>

char toUpperCase(char captial) {//將小寫轉大寫
	if (captial <= 'z' && captial >= 'a')//判斷是否為小寫
	{
		return captial - 32;//利用ASCII的概念 將小寫轉為大寫
	}
	else if (captial<='Z'&&captial>='A')//判斷是否為大寫
	{
		return captial;
	}
	else//判斷若非為字母
	{
		return 0;//自動結束
	}
}

char toLowerCase(char lowercase) {//將大寫轉為小寫
	if (lowercase<='Z'&&lowercase>='A')//判斷是否為大寫
	{
		return lowercase + 32;//利用ASCII的概念 將大寫轉為小寫
	}
	else if (lowercase<='z'&&lowercase>='a')//判斷是否為小寫
	{
		return lowercase;
	}
	else//判斷若為非字母
	{
		return 0;//自動結束
	}
}

int main(void) {
	char letter;
	printf("請輸入字母:");//建置一使用者可以輸入之字母
	scanf(" %c", &letter);
	printf(" %c 的大寫為 %c\n", letter, toUpperCase(letter));
	printf(" %c 的小寫為 %c\n", letter, toLowerCase(letter));
}
