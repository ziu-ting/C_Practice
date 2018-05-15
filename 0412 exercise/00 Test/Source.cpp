#include<stdio.h>
#include<stdlib.h>
void test_1(void) {
	static int x = 100;
	printf("x=%d\n", x++);
	printf("x=%d\n", x);
}

void test_2(void) {
	static int x = 100;
	printf("x=%d\n", ++x);
	printf("x=%d\n", x);
}


int main(void) {
	test_1();
	test_1();
	test_2();
	test_2();
	system("pause");
}