#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

void playbkmusic(const char* music, bool repeat = false, int voice = -1)
{
	static int i = 0;
	char name[100] = { 0 };

	sprintf(name, "open %s alias bgm%d", music, i);
	MCIERROR ret = mciSendString(name, NULL, 0, NULL);
	if (ret != 0) {
		char err[50];
		mciGetErrorString(ret, err, sizeof(err));
		printf("[open]:%s", err);
	}

	sprintf(name, "play bgm%d %s", i, repeat ? "repeat" : "");
	ret = mciSendString(name, NULL, 0, NULL);
	if (ret != 0) {
		char err[50];
		mciGetErrorString(ret, err, sizeof(err));
		printf("[play]:%s", err);
	}
	if (0 <= voice && voice <= 1000) {
		sprintf(name, "setaudio bgm%d volume to %d", i, voice);
		mciSendString(name, NULL, 0, NULL);
	}
	i++;
}

int main()
{
	//播放音乐
	//mciSendString("open assets/That-Girl.mp3", NULL, 0, NULL);
	//mciSendString("play assets/That-Girl.mp3", NULL, 0, NULL);
	//mciSendString("open assets/鸟之诗.mp3", NULL, 0, NULL);
	//mciSendString("play assets/鸟之诗.mp3", NULL, 0, NULL);
	//MCIERROR ret = mciSendString("open assets/YOU.mp3 alias you", NULL, 0, NULL);
	//if (ret != 0) {
	//	char err[50];
	//	mciGetErrorString(ret, err, sizeof(err));
	//	puts(err);
	//}
	//mciSendString("open assets/video_call.wav", NULL, 0, NULL);
	//mciSendString("play assets/video_call.wav", NULL, 0, NULL);
	//mciSendString("play you", NULL, 0, NULL);
	playbkmusic("assets/YOU.mp3", true, 300);
	//playbkmusic("assets/鸟之诗.mp3",true , 200);
	
	//专门用来播放音效
	//while (1) {
	//	playbkmusic("assets/video_call.wav");
	//	PlaySound("assets/video_call.wav", NULL, SND_FILENAME | SND_ASYNC);
	//	getchar();
	//}

	getchar();

	return 0;
}