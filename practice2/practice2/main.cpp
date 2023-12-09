#include <stdio.h>
#include <graphics.h>
#include "tools.hpp"

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

	//掩码图透明贴图
	IMAGE player[2];
	loadimage(player + 0, "assets/planeNormal_1.jpg");
	loadimage(player + 1, "assets/planeNormal_2.jpg");
	putimage(100, 100, player + 0, NOTSRCERASE);//先绘制掩码图
	putimage(100, 100, player + 1, SRCERASE);//在绘制原图

	//PNG透明贴图
	IMAGE img_png;
	loadimage(&img_png, "assets/博丽灵梦（红魔乡自机像素绘）.png");
	//putimage(200, 200, &img_png);
	drawImg(200, 200, &img_png);

	getchar();

	return 0;
}