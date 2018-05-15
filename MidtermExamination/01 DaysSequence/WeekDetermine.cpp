//�إߤ@�i�P�_�P������� //all done
//�إߤ@�P�_�|�~�����
//�O�|�~�^�ǵ��G2;�D�|�~�^�ǵ��G3
int leapyears(int y) {
	if (y % 4 == 0)
	{
		if (y % 400 == 0)
		{
			return 2;
		}
		else if (y % 100 == 0)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 3;
	}
}

//�إߤ@�i�P�_�P�������
//�إߤ@�i�P�_�Ӥ�P�褸���~�@��@��ۮt��Ƥ����
int days_differ(int y, int m, int d) {
	int days_total = 0;//�إ��`���

				   //�N�~���ഫ�����
	int y_last = y - 1;
	for (y_last; y_last > 0;y_last--)
	{
		switch (leapyears(y_last))//�P�_�O�_���|�~
		{
		case 2:
			days_total += 366;
			break;
		case 3:
			days_total += 365;
			break;
		default:
			break;
		}
	}

	//�N����ର���
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	switch (leapyears(y))//�P�_�O�_���|�~
	{
	case 2:
		month[1] = 29;
		break;
	case 3:
		month[1] = 28;
		break;
	default:
		break;
	}
	int m_last = m - 1;
	for (m_last; m_last > 0; m_last--)
	{
		days_total += month[m_last];
	}

	//�N����[�`

	days_total = days_total + d;

	return days_total;
}

//�إߤ@�i�P�_�P�������
//�]�wdays���`�H��
int week_determine(int y, int m, int d) {
	int days = days_differ(y, m, d) % 7;//�]�wdays���`�H��

	switch (days)
	{
	case 0:
		return 2;
		break;
	case 1:
		return 3;
		break;
	case 2:
		return 4;
		break;
	case 3:
		return 5;
		break;
	case 4:
		return 6;
		break;
	case 5:
		return 7;
		break;
	case 6:
		return 1;
		break;

	default:
		break;
	}
}
