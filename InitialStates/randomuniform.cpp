#include "randomuniform.h"
#include <iostream>
#include <cassert>
#include <random>
#include "Math/random.h"
#include "../particle.h"
#include "../system.h"

using std::cout;
using std::endl;

RandomUniform::RandomUniform(System*    system,
                             int        numberOfDimensions,
                             int        numberOfParticles)  :
        InitialState(system) {
    assert(numberOfDimensions > 0 && numberOfParticles > 0);
    m_numberOfDimensions = numberOfDimensions;
    m_numberOfParticles  = numberOfParticles;

    /* The Initial State class is in charge of everything to do with the
     * initialization of the system; this includes determining the number of
     * particles and the number of dimensions used. To make sure everything
     * works as intended, this information is passed to the system here.
     */
    m_system->setNumberOfDimensions(numberOfDimensions);
    m_system->setNumberOfParticles(numberOfParticles);
    setupInitialState();
}

void RandomUniform::setupInitialState() {
    for (int i=0; i < m_numberOfParticles; i++) {
        std::vector<double> position = std::vector<double>();

        for (int j=0; j < m_numberOfDimensions; j++) {
            /* This is where you should actually place the particles in
             * some positions, according to some rule. Since this class is
             * called random uniform, they should be placed randomly according
             * to a uniform distribution here. However, later you will write
             * more sub-classes of the InitialState class in which the
             * particles are placed in other configurations.
             *
             * Note: For now, the particles are simply placed in positions
             * according to their index in the particles list (this is
             * obviously NOT a good idea).
             */

            // Mersienne mt19937_64
            // FOUND GOO INFO AT
            // https://diego.assencio.com/?index=6890b8c50169ef45b74db135063c227c
            // ILU RANDOM PERSON OMG

            std::random_device device; // Generate random seed
            std::mt19937 generator(device()); // Initialize w/ random seed.
            std::uniform_int_distribution<double> distribution(-1,1); // Distribution

            //std::cout << distribution(generator) << std::endl;

            //std::mt19937 generator; // add i header and stuff.
            //generator.seed(4);
            //srand(time(0));
            position[j] = distribution(generator);
            position.push_back(i);
        }
        m_particles.push_back(new Particle());
        m_particles.at(i)->setNumberOfDimensions(m_numberOfDimensions);
        m_particles.at(i)->setPosition(position);
    }
}
