#include<stdio.h>
#include<stdlib.h>

#define maxLength 100


//�إߤ@�}���ɮסA���˩w�ɮ׬O�_���`�}�Ҥ��禡
FILE *fileHandle(char filename[], char mode[]) {
	FILE *object;
	object = fopen(filename, mode);
	if (object == NULL)
	{
		printf("%s","�ɮ׶}�Үɵo�Ϳ��~\n");
		object = NULL;
	}
	
	return object;

}

//�إߤ@��ܥH�N�ɮפ��e�v�r�g�J�r��}�C
void fileToString(FILE* seat,char savingString[maxLength][maxLength],int length){
	int dataword;
	int conti = 0, contj = 0;

	while ((dataword = fgetc(seat)) != EOF)//�P�_����
	{
		//�P�_�Ů� ���J�U�@�C(?)�}�C
		if (dataword == 32)
		{
			savingString[conti][contj] = '\0';//�ɤW�� �����}�C
			conti++;//�i�J�U�@�C
			contj = 0;//�q���ޭ�0�}�l
		}
		else
		{
			if ((conti < length) && (contj < length))//�����ɮפj�p
			{
				savingString[conti][contj] = dataword;
				contj++;
			}
			else
			{
				printf("�ɮ׹L�j\t�}�Үɵo�Ϳ��~\n");
				exit(1);//�D���`����
			}
		}
	}
	//�ɮ׵����ɤW��
	savingString[conti][contj] = '\0';
	conti++;
	savingString[conti][0] = '\0';

}

//�إߤ@��ܥH�N�}�C���e�g�J�ɮ�
void stringToFile(FILE* seat, char savdString[maxLength][maxLength], int length) {
	for (int i = 0, j = 0;savdString[i][0] != '\0'; i++)
	{
		for (int j = 0;savdString[i][j] != '\0';j++)
		{
			fputc(savdString[i][j], seat);
		}
		fputc('\n', seat);
	}
}




/*
step1 �}��ż����
step2 �M��ت��ɤ���ż�� �H�ťը��N
step3 ���N����
*/
void main(int argc, char *argv[]) {

	//printf("%s", "=====ż�ܹL�o��=====\n��J�榡�G\n\t(�s��ż�ܪ��ɮ�) (space) (�n�L�o���ɮ�)\n\n");

	char badWordString[maxLength][maxLength];
	FILE *badWord = fileHandle(argv[1], "rb");
	if (badWord != NULL)
	{
		fileToString(badWord, badWordString, maxLength);
		fclose(badWord);
		printf("%s", "�ɮ�Ū�����\\n\n...�w�s���L�o�M��\n");
	}
	else
	{
		printf("%s","�ɮ׶}�Үɵo�Ϳ��~\n");
		exit(1);
	}

	
	/*for (int i = 0, j = 0;badWordString[i][0] != '\0'; i++)
	{
		for (int j = 0;badWordString[i][j] != '\0';j++)
		{
			printf(" %c",badWordString[i][j]);
		}
		puts("\n");
	}*/
}

