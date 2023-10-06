#pragma once
#include <iostream>
#include <chrono>
namespace CommonUtilities
{
	class Timer
	{
	public: 
		Timer();
		Timer(const Timer& aTimer) = delete;
		Timer& operator= (const Timer & aTimer) = delete;
		void Update();
		float GetDeltaTime() const;
		double GetTotalTime() const;
	private:
		std::chrono::high_resolution_clock::time_point myCurrentTime;
		std::chrono::high_resolution_clock::time_point myPrevTime;
		std::chrono::high_resolution_clock::time_point myStartTime;
		double myTotalTime;
		float myDeltaTime;

	};
}