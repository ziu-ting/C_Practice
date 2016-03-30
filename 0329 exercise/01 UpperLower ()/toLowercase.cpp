char toLowerCase(char lowercase) {//將大寫轉為小寫
	if (lowercase <= 'Z'&&lowercase >= 'A')//判斷是否為大寫
	{
		return lowercase + 32;//利用ASCII的概念 將大寫轉為小寫
	}
	else if (lowercase <= 'z'&&lowercase >= 'a')//判斷是否為小寫
	{
		return lowercase;
	}
	else//判斷若為非字母
	{
		return 0;//自動結束
	}


}