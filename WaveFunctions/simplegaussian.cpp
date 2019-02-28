#include "simplegaussian.h"
#include <cmath>
#include <cassert>
#include <math.h>
#include "wavefunction.h"
#include "../system.h"
#include "../particle.h"

SimpleGaussian::SimpleGaussian(System* system, double alpha) :
        WaveFunction(system) {
    assert(alpha >= 0);
    m_numberOfParameters = 1;
    m_parameters.reserve(1);
    m_parameters.push_back(alpha);
}

double SimpleGaussian::evaluate(std::vector<class Particle*> particles) {
    /* You need to implement a Gaussian wave function here. The positions of
     * the particles are accessible through the particle[i].getPosition()
     * function.
     *
     * For the actual expression, use exp(-alpha * r^2), with alpha being the
     * (only) variational parameter.
     */

    //particle[0].getPosition() ;
    std::vector<double> r = particles[0]->getPosition();
    double psi = exp(-m_parameters[0] *pow(r[0],2));
    return psi;
}

double SimpleGaussian::computeDoubleDerivative(std::vector<class Particle*> particles) {
    /* All wave functions need to implement this function, so you need to
     * find the double derivative analytically. Note that by double derivative,
     * we actually mean the sum of the Laplacians with respect to the
     * coordinates of each particle.
     *
     * This quantity is needed to compute the (local) energy (consider the
     * Schrödinger equation to see how the two are related).
     */

    // Natural units. hbar=m=...=1
    // Do I need the double derivative times the wavefunction or whaaaat?

    //Try without.
    std::vector<double> r = particles[0]->getPosition();
    double DoubleDerivative = 1/(2*pow(m_parameters[0],2)) + (m_parameters[0]+1)*pow(r[0],2);



    return 0;
}
