char toUpperCase(char captial) {//將小寫轉大寫
	if (captial <= 'z' && captial >= 'a')//判斷是否為小寫
	{
		return captial - 32;//利用ASCII的概念 將小寫轉為大寫
	}
	else if (captial <= 'Z'&&captial >= 'A')//判斷是否為大寫
	{
		return captial;
	}
	else//判斷若非為字母
	{
		return 0;//自動結束
	}
}