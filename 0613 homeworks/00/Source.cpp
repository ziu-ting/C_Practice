#include <stdio.h>

typedef struct {
	char color[10];
	double radius;
} Ball;

void foo(Ball);

int main(void) {
	Ball ball = { "red", 5.0 };

	foo(ball);
	printf("ball: %s,\t%.2f\n", ball.color, ball.radius);

	return 0;
}

void foo(Ball ball) { // ball �����ȳQ�ƻs�L�� 
	ball.radius = 100.0;
}


//Result�Gball: red,      5.00
