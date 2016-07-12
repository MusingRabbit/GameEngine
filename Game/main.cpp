#include <Util\Display.h>
#include <Util\GameTime.h>
#include <iostream>

using namespace Engine;

int main(int argc, char* args[]){

	Display display(800,600);
	GameTime gameTimer;

	gameTimer.Start();
	while (!display.isClosing()) {
		SDL_Event e;
		display.Update();
	
		if (gameTimer.Tick())
			std::cout << "TICK!" << std::endl;

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

