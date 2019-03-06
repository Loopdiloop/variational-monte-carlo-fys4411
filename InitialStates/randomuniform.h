#pragma once
#include "initialstate.h"

class RandomUniform : public InitialState {
public:
    RandomUniform(System* system, int numberOfDimensions, int numberOfParticles);
    void setupInitialState();
private:
    //std::mt19937 ;
    //void generateRandom(std::vector<double>&);
};

