#include "FrameTimer.h"

using namespace std::chrono;

FrameTimer::FrameTimer()
{
	last = high_resolution_clock::now();
}

double FrameTimer::Mark()
{
	const auto old = last;
	last = high_resolution_clock::now();
	const duration<double> frameTime = last - old;
	return frameTime.count();
}
