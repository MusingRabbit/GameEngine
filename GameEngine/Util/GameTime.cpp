#include "GameTime.h"

namespace Engine
{
	GameTime::GameTime()
	{
		Reset();
	}

	GameTime::~GameTime()
	{

	}

	float GameTime::GetDetlaTime() const {
		return (float)m_dDeltaTime;
	}

	float GameTime::GetTotalElapsedTime() const {
		return (float)(SDL_GetPerformanceCounter() / m_dCountsPerSecond);
	}

	float GameTime::GetFrameRate()const {
		/*m_lFrameCounter / m_dDeltaTime;*/
		return 0.0f;
	}


	void GameTime::Reset()
	{
		m_lCurrTime = SDL_GetPerformanceCounter();
		m_dCountsPerSecond = SDL_GetPerformanceFrequency();
		m_lBaseTime = m_lCurrTime;
		m_dDeltaTime = -1;
		m_lPausedTime = 0;
		m_lPrevTime = 0;
		m_lFrameCounter = 0;

		m_frameTime = 1.0 / m_dCountsPerSecond;

		m_bStopped = false;
	}

	bool GameTime::Tick()
	{
		if (m_bStopped)
		{
			m_dDeltaTime = 0;
			return false;
		}

		UpdateTickers();

		bool result = m_dDeltaTime >= 0;

		return result;
	}

	void GameTime::Start()
	{
		m_lCurrTime = SDL_GetPerformanceCounter();

		if (m_bStopped)
		{
			m_lPausedTime += m_lCurrTime - m_lStopTime;
			m_lPrevTime = m_lCurrTime;
			m_lStopTime = 0;
			m_bStopped = false;
		}
	}

	void GameTime::Stop()
	{
		if (m_bStopped) {
			m_dDeltaTime = 0.0;
			return;
		}

		UpdateTickers();

		m_lStopTime = m_lCurrTime;
		m_bStopped = true;
	}

	void GameTime::UpdateTickers()
	{
		m_lCurrTime = SDL_GetPerformanceCounter();
		m_dDeltaTime = (m_lCurrTime - m_lPrevTime);
		m_dDeltaTime = m_bStopped ? m_dDeltaTime * m_dCountsPerSecond : m_dDeltaTime / m_dCountsPerSecond;
		m_dDeltaTime = m_dDeltaTime < 0.0 ? 0.0 : m_dDeltaTime;
		m_lPrevTime = m_lCurrTime;
	}
}