//�إߤ@�i�P�_�j�p�ƧǤ����  //all done
//�إߤ@�|�����Ȥ����
void change(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//�إߤ@�i�P�_�j�p�ƧǤ����
//�إߤ@�|�ɾ��ư}�C�U���Ȥ����
void sequence(int arrange[],int x[],int y[],int z[], int number) {
	for (int i = number - 1; i >= 0; i--)//�ѳ̫ᶵ�V�e�˴�
	{
		while (arrange[number] < arrange[i]) {
			change(arrange[number], arrange[i]);
			change(x[number], x[i]);
			change(y[number], y[i]);
			change(z[number], z[i]);

			number--;
		}
	}
}
