#ifndef DISPLAY_H
#define DISPLAY_H

#include "SDL.h"
#include <string>

#define DEFAULT_SCREEN_WIDTH 800
#define DEFAULT_SCREEN_HEIGHT 600
#define DEFAULT_SCREEN_TITLE "Game Window"

class Display
{
public:
	Display() { Init(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, DEFAULT_SCREEN_TITLE); }
	
	Display(int width, int height) { Init(width, height, DEFAULT_SCREEN_TITLE); }

	Display(int width, int height, const std::string& title) { Init(width, height, title); }

	inline virtual ~Display() {
		SDL_GL_DeleteContext(m_glContext);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	inline void Init(int width, int height, const std::string& title) {
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		m_iHeight = height;
		m_iWidth = width;
		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_iWidth, m_iHeight, SDL_WINDOW_OPENGL);
		m_glContext = SDL_GL_CreateContext(m_window);

		m_bClose = false;
	}

	inline void Update() {
		//Swap buffers
		SDL_GL_SwapWindow(m_window);
	}

	inline bool isClosing() {
		return m_bClose;
	}

	inline void Close() {
		m_bClose = true;
	}

	inline int GetWidth() {
		return m_iWidth;
	}

	inline int GetHeight(){
		return m_iHeight;
	}
	 
	inline float GetAspectRatiof() {
		return (float)m_iWidth / (float)m_iHeight;
	}

private:
	int m_iWidth, m_iHeight;
	bool m_bClose;
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
};

#endif