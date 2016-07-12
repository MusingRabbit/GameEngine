#ifndef GAMETIME_H
#define GAMETIME_H

#include "SDL.h"

using namespace std;

namespace Engine
{
	class __declspec(dllexport) GameTime
	{
	public:
		GameTime();
		~GameTime();

		float GetTotalElapsedTime()const;
		float GetDetlaTime()const;
		float GetFrameRate()const;

		void Reset();
		void Start();
		void Stop();
		bool Tick();

	private:
		Uint64 m_ulBaseTime;
		Uint64 m_ulPausedTime;
		Uint64 m_ulStopTime;
		Uint64 m_ulPrevTime;
		Uint64 m_ulCurrTime;

		Uint64 m_ulFrameCounter;

		double m_frameTime;
		double m_dCountsPerSecond;
		double m_dDeltaTime;
		bool m_bStopped;

		void UpdateTickers();
	};
}
#endif