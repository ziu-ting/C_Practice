char toLowerCase(char lowercase) {//�N�j�g�ର�p�g
	if (lowercase <= 'Z'&&lowercase >= 'A')//�P�_�O�_���j�g
	{
		return lowercase + 32;//�Q��ASCII������ �N�j�g�ର�p�g
	}
	else if (lowercase <= 'z'&&lowercase >= 'a')//�P�_�O�_���p�g
	{
		return lowercase;
	}
	else//�P�_�Y���D�r��
	{
		return 0;//�۰ʵ���
	}


}