#ifndef GAMETIME_H
#define GAMETIME_H

#include "SDL.h"

using namespace std;

namespace Engine
{
	class GameTime
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


		long m_lBaseTime;
		long m_lPausedTime;
		long m_lStopTime;
		long m_lPrevTime;
		long m_lCurrTime;

		long m_lFrameCounter;
		double m_frameTime;
		double m_dCountsPerSecond;
		double m_dDeltaTime;
		bool m_bStopped;

		void UpdateTickers();
	};
}
#endif