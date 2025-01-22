#ifndef SIMULATIONPARAMS_H
#define SIMULATIONPARAMS_H

// Classe qui contient les paramètres de la simulation
class SimulationParams {
private:
    int numWarehouses;  // Nombre d'entrepôts
    int numTransporters;  // Nombre de transporteurs

public:
    // Constructeur
    SimulationParams(int numWarehouses, int numTransporters)
        : numWarehouses(numWarehouses), numTransporters(numTransporters) {}

    // Getters
    int getNumWarehouses() const { return numWarehouses; }
    int getNumTransporters() const { return numTransporters; }
};

#endif // SIMULATIONPARAMS_H
