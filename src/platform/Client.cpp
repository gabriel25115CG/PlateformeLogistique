#include "Client.h"
#include <iostream>

// Constructeur
Client::Client(int id, const std::string& name, double distance)
    : id(id), name(name), distance(distance) {}

// Récupérer l'identifiant du client
int Client::getId() const {
    return id;
}

// Récupérer le nom du client
std::string Client::getName() const {
    return name;
}

// Getter pour la distance
double Client::getDistance() const {
    return distance;
}

// Setter pour la distance
void Client::setDistance(double dist) {
    distance = dist;
}

// Ajouter une commande
void Client::addOrder(int productId) {
    orders.push_back(productId);
}

// Afficher les commandes du client
void Client::displayOrders() const {
    std::cout << "Client " << name << " (ID: " << id << ") has ordered the following products:\n";
    for (const auto& productId : orders) {
        std::cout << "  - Product ID: " << productId << "\n";
    }
}
