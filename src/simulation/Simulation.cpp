#include "Simulation.h"
#include "Warehouse.h"
#include "Transporter.h"
#include "Product.h"
#include <iostream>
#include <algorithm>

// Codes ANSI pour les couleurs
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// Constructeur de la classe Simulation
Simulation::Simulation(const SimulationParams& params)
    : params(params), totalProductsReceived(0), totalProductsDelivered(0),
      totalTimeInStock(0), totalSystemTime(0), totalDistanceTraveled(0), totalProductsInStock(0) {
    std::cout << CYAN << BOLD << "Simulation initialized with " 
              << params.getNumWarehouses() << " warehouses and "
              << params.getNumTransporters() << " transporters." << RESET << "\n";
}

// Ajouter un entrepôt à la simulation
void Simulation::addWarehouse(std::shared_ptr<Warehouse> warehouse) {
    warehouses.push_back(warehouse);
}

// Ajouter un transporteur à la simulation
void Simulation::addTransporter(std::shared_ptr<Transporter> transporter) {
    transporters.push_back(transporter);
}

// Ajouter un produit à un entrepôt
bool Simulation::addProductToWarehouse(int warehouseId, std::shared_ptr<Product> product) {
    for (auto& warehouse : warehouses) {
        if (warehouse->getId() == warehouseId) {
            totalProductsReceived++;  // On incrémente le nombre de produits reçus
            return warehouse->addProduct(product);
        }
    }
    std::cout << RED << "Error: Warehouse with ID " << warehouseId << " not found." << RESET << "\n";
    return false;
}

// Démarrer la simulation
void Simulation::start() {
    std::cout << GREEN << BOLD << "\n=== Starting Simulation ===\n" << RESET;
    for (auto& transporter : transporters) {
        transporter->startMission();
    }
}

// Terminer la simulation
void Simulation::end() {
    std::cout << YELLOW << BOLD << "\n=== Ending Simulation ===\n" << RESET;
    for (auto& transporter : transporters) {
        transporter->completeMission();
    }

    // Calculer les performances à la fin de la simulation
    calculatePerformance();
}

// Afficher l'état de la simulation
void Simulation::displayStatus() const {
    std::cout << MAGENTA << BOLD << "\n=== Simulation Status ===\n" << RESET;

    std::cout << BLUE << BOLD << "Warehouses:\n" << RESET;
    for (const auto& warehouse : warehouses) {
        warehouse->displayWarehouseStatus();
    }

    std::cout << BLUE << BOLD << "\nTransporters:\n" << RESET;
    for (const auto& transporter : transporters) {
        std::cout << "Transporter " << transporter->getName() 
                  << " (ID: " << transporter->getId() << ") ";
        if (transporter->isMissionInProgress()) {
            std::cout << GREEN << "is currently on a mission." << RESET << "\n";
        } else {
            std::cout << RED << "is idle." << RESET << "\n";
        }
    }
}

// Calculer les performances de la simulation
void Simulation::calculatePerformance() {
    for (const auto& warehouse : warehouses) {
        for (const auto& product : warehouse->getProducts()) {
            totalTimeInStock += product->getTimeInStock();
            totalSystemTime += product->getTotalTime();
        }
    }

    for (const auto& transporter : transporters) {
        totalDistanceTraveled += transporter->getDistanceTraveled();
        totalProductsDelivered += transporter->getProductsDelivered();
    }

    for (const auto& warehouse : warehouses) {
        totalProductsInStock += warehouse->getProducts().size();
    }
}

// Afficher les performances de la simulation
void Simulation::displayPerformance() const {
    std::cout << CYAN << BOLD << "\n=== Simulation Performance ===\n" << RESET;

    std::cout << YELLOW << "Total Products Received: " << WHITE << totalProductsReceived << RESET << "\n";
    std::cout << YELLOW << "Total Products Delivered: " << WHITE << totalProductsDelivered << RESET << "\n";
    std::cout << YELLOW << "Average Time in Stock: " 
              << WHITE << (totalProductsReceived > 0 ? totalTimeInStock / totalProductsReceived : 0)
              << " hours" << RESET << "\n";
    std::cout << YELLOW << "Total System Time: " << WHITE << totalSystemTime << " hours" << RESET << "\n";
    std::cout << YELLOW << "Total Distance Traveled: " << WHITE << totalDistanceTraveled << " km" << RESET << "\n";
    std::cout << YELLOW << "Total Products in Stock: " << WHITE << totalProductsInStock << RESET << "\n";
}

// Récupérer la liste des transporteurs
const std::vector<std::shared_ptr<Transporter>>& Simulation::getTransporters() const {
    return transporters;
}
