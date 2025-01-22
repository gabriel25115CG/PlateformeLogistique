#ifndef SIMULATIONPLATFORM_H
#define SIMULATIONPLATFORM_H

#include "Warehouse.h"
#include "Transporter.h"
#include "SimulationParams.h"
#include <vector>
#include <memory>

// Interface de la plateforme de simulation
class SimulationPlatform {
public:
    virtual void setupPlatform(const SimulationParams& params) = 0;  // Configurer la plateforme
    virtual void startSimulation() = 0;  // Lancer la simulation
    virtual void stopSimulation() = 0;  // Arrêter la simulation
    virtual void displayPlatformStatus() const = 0;  // Afficher l'état de la plateforme
};

#endif // SIMULATIONPLATFORM_H
