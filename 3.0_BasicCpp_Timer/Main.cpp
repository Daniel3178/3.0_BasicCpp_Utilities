#include "Timer.h"
#include <iostream>
#include <Windows.h>
#include <cstdio>
int main()
{
	CommonUtilities::Timer timer;
	while(true)
	{
		Sleep(100);
		timer.Update();
		printf("Delta Time : %.7f \tTotal Time : %.7f\n", timer.GetDeltaTime(), timer.GetTotalTime());

	}

	return 0;
}