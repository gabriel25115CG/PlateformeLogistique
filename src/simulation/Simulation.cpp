#include "Simulation.h"
#include "Warehouse.h"
#include "Transporter.h"
#include "Product.h"
#include <iostream>
#include <algorithm>
#include "Client.h"
#include <cmath> // Pour utiliser std::sqrt

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

// Ajouter un client à la simulation
void Simulation::addClient(std::shared_ptr<Client> client) {
    clients.push_back(client);
}

// Afficher les informations des clients
void Simulation::displayClients() const {
    std::cout << BLUE << BOLD << "\n=== Clients Information ===\n" << RESET;
    for (const auto& client : clients) {
        std::cout << "Client ID: " << client->getId() 
                  << ", Name: " << client->getName() << "\n";
        client->displayOrders();
    }
}

// Passer une commande pour un client
void Simulation::placeOrder(int clientId, int productId) {
    auto it = std::find_if(clients.begin(), clients.end(), 
        [clientId](const std::shared_ptr<Client>& client) { return client->getId() == clientId; });

    if (it != clients.end()) {
        (*it)->addOrder(productId);
        std::cout << GREEN << "Order placed: Client " << (*it)->getName() 
                  << " ordered Product ID " << productId << RESET << "\n";
    } else {
        std::cout << RED << "Error: Client with ID " << clientId << " not found." << RESET << "\n";
    }
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

    // Calculer et afficher l'impact carbone total
    displayCarbonImpact();
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

// Calculer l'impact carbone entre un client et un entrepôt
double Simulation::calculateCarbonImpact(const std::shared_ptr<Client>& client, const std::shared_ptr<Warehouse>& warehouse) const {
    // Utiliser la distance déjà stockée dans le client
    double distance = client->getDistance();  // Distance en km
    double co2EmissionRate = 0.25; // Exemple d'émission de CO₂ par km (peut être modifié selon le transporteur)

    return distance * co2EmissionRate; // Calcul de l'impact carbone
}

// Calculer l'impact carbone total pour tous les transporteurs
double Simulation::calculateTotalCarbonImpact() const {
    double totalCarbonImpact = 0.0;

    // Calculer l'impact carbone pour chaque transporteur
    for (const auto& transporter : transporters) {
        totalCarbonImpact += transporter->calculateCarbonImpact();
    }

    return totalCarbonImpact;
}

// Afficher l'impact carbone total
void Simulation::displayCarbonImpact() const {
    double totalCarbonImpact = calculateTotalCarbonImpact();  // Calculer l'impact carbone total

    std::cout << GREEN << BOLD << "\n=== Carbon Impact Report ===\n" << RESET;
    std::cout << YELLOW << "Total Carbon Emissions: " << WHITE 
              << totalCarbonImpact << " kg CO₂" << RESET << "\n";
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
