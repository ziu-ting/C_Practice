#include<stdio.h>
#include<stdlib.h>

char toUpperCase(char captial) {//�N�p�g��j�g
	if (captial <= 'z' && captial >= 'a')//�P�_�O�_���p�g
	{
		return captial - 32;//�Q��ASCII������ �N�p�g�ର�j�g
	}
	else if (captial<='Z'&&captial>='A')//�P�_�O�_���j�g
	{
		return captial;
	}
	else//�P�_�Y�D���r��
	{
		return 0;//�۰ʵ���
	}
}

char toLowerCase(char lowercase) {//�N�j�g�ର�p�g
	if (lowercase<='Z'&&lowercase>='A')//�P�_�O�_���j�g
	{
		return lowercase + 32;//�Q��ASCII������ �N�j�g�ର�p�g
	}
	else if (lowercase<='z'&&lowercase>='a')//�P�_�O�_���p�g
	{
		return lowercase;
	}
	else//�P�_�Y���D�r��
	{
		return 0;//�۰ʵ���
	}
}

int main(void) {
	char letter;
	printf("�п�J�r��:");//�ظm�@�ϥΪ̥i�H��J���r��
	scanf(" %c", &letter);
	printf(" %c ���j�g�� %c\n", letter, toUpperCase(letter));
	printf(" %c ���p�g�� %c\n", letter, toLowerCase(letter));
}
