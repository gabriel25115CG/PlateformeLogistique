#include <iostream>
#include "simulation/Simulation.h"
#include "simulation/SimulationParams.h"
#include "platform/Warehouse.h"
#include "platform/Product.h"
#include "platform/Transporter.h"

int main() {
    // Définir les paramètres de la simulation (nombre d'entrepôts et de transporteurs)
    int numWarehouses = 3;
    int numTransporters = 2;
    SimulationParams simParams(numWarehouses, numTransporters);

    // Créer l'instance de la simulation
    Simulation simulation(simParams);

    // Création des entrepôts et ajout à la simulation
    for (int i = 0; i < numWarehouses; ++i) {
        std::shared_ptr<Warehouse> warehouse = std::make_shared<Warehouse>(i, "Warehouse_" + std::to_string(i+1), 10);  // Capacité 10 pour chaque entrepôt
        simulation.addWarehouse(warehouse);
    }

    // Création des transporteurs et ajout à la simulation
    for (int i = 0; i < numTransporters; ++i) {
        std::shared_ptr<Transporter> transporter = std::make_shared<Transporter>(i, "Transporter_" + std::to_string(i+1));
        simulation.addTransporter(transporter);
    }

    // Ajout de produits aux entrepôts
    for (int i = 0; i < numWarehouses; ++i) {
        for (int j = 0; j < 5; ++j) {  // Ajouter 5 produits à chaque entrepôt
            std::shared_ptr<Product> product = std::make_shared<Product>(j, "Product_" + std::to_string(j+1), 2.5, 10);  // Exemple de produit
            if (simulation.addProductToWarehouse(i, product)) {
                std::cout << "Product_" << j+1 << " added to Warehouse_" << i+1 << ".\n";
            }
        }
    }

    // Démarrer la simulation
    simulation.start();

    // Afficher l'état de la simulation après démarrage
    simulation.displayStatus();

    // Exemple d'actions supplémentaires pendant la simulation
    std::cout << "\nStarting mission for Transporter 1...\n";
    simulation.getTransporters()[0]->startMission();
    simulation.displayStatus();

    // Compléter la mission pour Transporter 1
    std::cout << "\nCompleting mission for Transporter 1...\n";
    simulation.getTransporters()[0]->completeMission();
    simulation.displayStatus();

    // Fin de la simulation
    simulation.end();

    return 0;
}