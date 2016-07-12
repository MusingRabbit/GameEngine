#include "Display.h"

using namespace Engine;

int main(int argc, char* args[])
{
	Display display(800,600);

	while (!display.isClosing()) {
		SDL_Event e;
		display.Update();

		while (SDL_PollEvent(&e)) {
			switch (e.type)
			{
			case SDL_QUIT:
				display.Close();
				break;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEMOTION:
				break;
			}
		}
	}

    return 0;
}

