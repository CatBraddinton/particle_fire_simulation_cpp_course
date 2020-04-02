//============================================================================
// Name        : Particle.cpp
// Author      : Kateryna Dudko
// Version     :
// Copyright   : Your copyright notice
// Description : Particle Fire Simulation in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed" << endl;
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		SDL_Quit();
		cout << "Error: " << SDL_GetError() << endl;
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL) {
			cout << "Rendeder wasn't created." << endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			return 3;
		}

	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH, SCREEN_HEIGHT);

	if (texture == NULL) {
		cout << "Texture wasn't created." << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;

	SDL_Event event;

	while (!quit) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	delete [] buffer;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
