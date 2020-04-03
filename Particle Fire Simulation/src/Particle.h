/*
 * Particle.h
 *
 *  Created on: Apr 3, 2020
 *      Author: busichka
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace kd {

struct Particle {
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace kd */

#endif /* PARTICLE_H_ */
