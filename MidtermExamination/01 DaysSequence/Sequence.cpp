//ミ耞逼ぇㄧ计  //all done
//ミ穦が传ぇㄧ计
void change(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//ミ耞逼ぇㄧ计
//ミ穦ど经逼皚兜ぇㄧ计
void sequence(int arrange[],int x[],int y[],int z[], int number) {
	for (int i = number - 1; i >= 0; i--)//パ程兜玡浪代
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
