/*
 * Screen.h
 *
 *  Created on: Apr 2, 2020
 *      Author: Kateryna Dudko
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <SDL2/SDL.h>

namespace kd {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window 		*m_window;
	SDL_Renderer 	*m_renderer;
	SDL_Texture 	*m_texture;
	Uint32 			*m_buffer;

public:
	Screen();
	bool init();
	bool processEvents();
	void close();
};

} /* namespace kd */

#endif /* SCREEN_H_ */
