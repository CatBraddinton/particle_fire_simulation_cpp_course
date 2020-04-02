/*
 * Particle.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: busichka
 */

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace kd {

Particle::Particle() : m_x(0), m_y(0) {
	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.001 * rand()) / RAND_MAX;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update() {
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed;
	m_y += yspeed;
}
} /* namespace kd */