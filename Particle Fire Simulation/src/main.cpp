//============================================================================
// Name        : Particle.cpp
// Author      : Kateryna Dudko
// Version     :
// Copyright   : Your copyright notice
// Description : Particle Fire Simulation in C++, Ansi-style
//============================================================================

#include "Screen.h"
#include <math.h>
#include "Swarm.h"

using namespace std;
using namespace kd;

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Initializing failed." << endl;
	}

	Swarm swarm;

	while (true) {

		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char red =(unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green =(unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue =(unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const nParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = nParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y  * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	return 0;
}
