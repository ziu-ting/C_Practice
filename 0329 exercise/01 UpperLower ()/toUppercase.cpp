char toUpperCase(char captial) {//�N�p�g��j�g
	if (captial <= 'z' && captial >= 'a')//�P�_�O�_���p�g
	{
		return captial - 32;//�Q��ASCII������ �N�p�g�ର�j�g
	}
	else if (captial <= 'Z'&&captial >= 'A')//�P�_�O�_���j�g
	{
		return captial;
	}
	else//�P�_�Y�D���r��
	{
		return 0;//�۰ʵ���
	}
}