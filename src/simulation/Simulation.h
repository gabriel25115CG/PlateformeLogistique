#ifndef SIMULATION_H
#define SIMULATION_H

#include "SimulationParams.h"
#include "Warehouse.h"
#include "Transporter.h"
#include "Product.h"
#include <vector>
#include <memory>
#include <chrono>  // Pour gérer le calcul du temps

// Classe Simulation
class Simulation {
private:
    SimulationParams params;  // Paramètres de la simulation
    std::vector<std::shared_ptr<Warehouse>> warehouses;  // Liste des entrepôts
    std::vector<std::shared_ptr<Transporter>> transporters;  // Liste des transporteurs

    // Statistiques de performance
    int totalProductsReceived = 0;  // Total des produits reçus
    int totalProductsDelivered = 0;  // Total des produits livrés
    double totalTimeInStock = 0.0;  // Temps total passé en stock par tous les produits
    double totalSystemTime = 0.0;  // Temps total passé dans le système par tous les produits
    double totalDistanceTraveled = 0.0;  // Distance totale parcourue par les transporteurs
    int totalProductsInStock = 0;  // Nombre total de produits en stock

public:
    // Constructeur
    Simulation(const SimulationParams& params);

    // Ajouter un entrepôt à la simulation
    void addWarehouse(std::shared_ptr<Warehouse> warehouse);

    // Ajouter un transporteur à la simulation
    void addTransporter(std::shared_ptr<Transporter> transporter);

    // Ajouter un produit à un entrepôt
    bool addProductToWarehouse(int warehouseId, std::shared_ptr<Product> product);

    // Démarrer la simulation
    void start();

    // Terminer la simulation
    void end();

    // Afficher l'état de la simulation
    void displayStatus() const;

    // Calculer les performances à la fin de la simulation
    void calculatePerformance();

    // Afficher les performances
    void displayPerformance() const;

    const std::vector<std::shared_ptr<Transporter>>& getTransporters() const;

};

#endif // SIMULATION_H
