#include <stdio.h>

int main() {
	int b = 10;
	printf("%s\n", b);
	return 0;
}
//把整数当做字符串打印 整数被当做地址 而证书代表的地址不存在或者不可访问

// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     char * c = "hello world";
//     c[1] = 'H';
// }