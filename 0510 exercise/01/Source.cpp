#include<stdio.h>
#include<stdlib.h>
#include<string>

#define lenght 100

//�إߤ@�˴��ɮ׬O�_���\�}�Ҥ��禡
FILE *successopen(char place[], char mode[]) {
	FILE *origin;
	if ((origin = fopen(place, mode)) == NULL)
	{
		printf("�ɮ׶}�Үɵo�Ϳ��~�I\n");
		origin = NULL;
	}
	return origin;
}

//�إߤ@�禡�A�N�ɮ׸����J�}�C
void filetoStr(FILE *origin, char saving[lenght][lenght],int maximum) {
	int i = 0, j = 0;
	char data;
	while ((data = fgetc(origin)) != EOF)
	{
		if (data == 32) {
			saving[i][j] = '\0';
			i++;
			j = 0;
		}
		else if (i < lenght&&j < lenght)
		{
			saving[i][j] = data;
			j++;
		}
		else
		{
			printf("�ɮ׶}�Үɵo�Ϳ��~�I\n�ɮ׹L�j�AŪ�����~�I\n");
			exit(1);
		}
	}

	//�إߵ���
	saving[i][j] = '\0';
	i++;
	saving[i][0] = '\0';
}

void test(char saving[lenght][lenght]) {
	for (int i = 0;saving[i][0] != '\0'; i++)
	{
		for (int j = 0; saving[i][j] != '\0'; j++)
		{
			putchar(saving[i][j]);
		}
		puts("\n");
	}
}


//�إߤ@�禡�A�N�}�C���e�g�J�ɮ�
void strtoFile(char saving[lenght][lenght], FILE *destination) {
	for (int i = 0;saving[i][0] != '\0'; i++)
	{
		for (int j = 0; saving[i][j] != '\0'; j++)
		{
			fputc(saving[i][j], destination);
		}
		fputc('\n', destination);
	}
}



void main(int argc, char *argv[]) {

	char savingStr[lenght][lenght];

	if (argc>1)
	{
		//�}���ɮפ覡: �{��.exe copy ����.txt to �ت���.txt
		if (!strcmp(argv[1],"copy"))
		{
			if (argc > 3)
			{
				FILE *origin;
				origin = successopen(argv[2], "rb");
				if (origin != NULL)
				{
					filetoStr(origin, savingStr, lenght);
					fclose(origin);
					printf("Ū�ɦ��\�I\n");
				}
				else
				{
					printf("�ɮ�%s���s�b\n", argv[2]);
					exit(1);
				}

				printf("\n=====����󤺮e��=====\n\n");
				test(savingStr);
				printf("\n=====�ɮ׼g�J��=====\n\n");

				FILE *result;
				result = successopen(argv[4], "wb");
				if (origin != NULL)
				{
					strtoFile(savingStr, result);
					fclose(result);
					printf("�g�ɦ��\�I\n");
				}
				else
				{
					printf("�ɮ�%s���s�b\n", argv[4]);
					exit(1);
				}
			}
		}
		else
		{
			printf("�Ш̮榡��J�G\n�{��.exe\tcopy\t����.txt\tto\t�ت���.txt\n");
			exit(1);
		}
	}

	//system("pause");
}