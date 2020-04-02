//============================================================================
// Name        : Particle.cpp
// Author      : Kateryna Dudko
// Version     :
// Copyright   : Your copyright notice
// Description : Particle Fire Simulation in C++, Ansi-style
//============================================================================

#include "Screen.h"

using namespace std;
using namespace kd;

int main() {

	Screen screen;

	if (screen.init() == false) {
		cout << "Initializing failed." << endl;
	}

	while (true) {
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	return 0;
}
