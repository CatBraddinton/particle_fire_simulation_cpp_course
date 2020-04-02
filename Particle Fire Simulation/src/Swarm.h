/*
 * Swarm.h
 *
 *  Created on: Apr 3, 2020
 *      Author: busichka
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace kd {

class Swarm {
public:
	const static int NPARTICLES = 5000;

private:
	Particle *m_pParticles;

public:
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticles() { return m_pParticles; };
	void update();
};

} /* namespace kd */

#endif /* SWARM_H_ */
