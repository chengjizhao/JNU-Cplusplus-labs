void methodOne()
{
	//方法一：占满栈空间，造成段错误
	int a[1048575];
}

void methodTwo()
{
	//方法二:对空地址进行写入，造成段错误
	int *a = nullptr;
	*a = 114514;
}
