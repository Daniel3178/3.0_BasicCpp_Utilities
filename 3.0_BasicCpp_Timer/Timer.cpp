#include "Timer.h"
#include <chrono>
namespace CommonUtilities
{
	Timer::Timer()
	{
		myDeltaTime = 0;
		myTotalTime = 0;
		myStartTime = std::chrono::high_resolution_clock::now();
		myCurrentTime = std::chrono::high_resolution_clock::now();
		myPrevTime = myStartTime;
	}
	void Timer::Update()
	{
		myCurrentTime = std::chrono::high_resolution_clock::now();
		myDeltaTime = std::chrono::duration_cast<std::chrono::microseconds>(myCurrentTime - myPrevTime).count()/1e6;
		myTotalTime = std::chrono::duration_cast<std::chrono::microseconds>(myCurrentTime - myStartTime).count()/1e6;
		myPrevTime = myCurrentTime;
	}

	float Timer::GetDeltaTime() const
	{
		return myDeltaTime;
	}
	double Timer::GetTotalTime() const
	{
		return myTotalTime;
	}
}