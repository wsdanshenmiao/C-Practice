#include <stdio.h>
#include <graphics.h>

int main()
{
	initgraph(1920, 1280, EX_SHOWCONSOLE);
	setbkcolor(RGB(138, 138, 138));
	cleardevice();

	//定义图片变量
	IMAGE picture;
	//加载图片
	//绝对路径：带盘符的路径    相对路径：
	loadimage(&picture, "assets/key.jpg");
	//输出图片
	putimage(0, 0, &picture);

	getchar();

	return 0;
}