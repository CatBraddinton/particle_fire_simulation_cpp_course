/*
 * Swarm.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: busichka
 */

#include "Swarm.h"

namespace kd {

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update() {

	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update();
	}
}

} /* namespace kd */
