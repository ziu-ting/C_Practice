#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("�п�J�Z�žǥ��`�H��:");
	int count;//�]�m�Z���`�H��
	scanf("%d", &count);

	int sum = 0;//�]�m�ǥͦ��Z�[�`
	int i = 1;//i++ ����j����榸��
	while (i<=count)//�ϯ�̾ǥ��`�H�ƨM�w��J����
	{
		printf("�п�J�y�� %d�ǥͤ����Z:",i);
		int score;
		scanf("%d", &score);

		sum = sum + score;//�[�`���Z
		i++;
	}
	float average = sum / (float)count;//����=�`���Z/�`�H��
	printf("���Z�`���Z��:\t%.2f\n", average);

	system("pause");
}