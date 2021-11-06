#pragma once
#include <chrono>

class FrameTimer
{
public:
	FrameTimer();
	double Mark();
private:
	std::chrono::high_resolution_clock::time_point last;
};