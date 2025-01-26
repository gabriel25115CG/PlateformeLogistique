#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include <memory>
#include "Product.h"

class Client {
private:
    int id;                        // Identifiant unique du client
    std::string name;              // Nom du client
    std::vector<int> orders;       // Liste des identifiants des produits commandés
    double distance;               // Distance en km entre le client et l'entrepôt

public:
    // Constructeur
    Client(int id, const std::string& name, double distance = 0.0);

    // Récupérer l'identifiant du client
    int getId() const;

    // Récupérer le nom du client
    std::string getName() const;

    // Getter et setter pour la distance
    double getDistance() const;
    void setDistance(double dist);

    // Ajouter une commande
    void addOrder(int productId);

    // Afficher les commandes du client
    void displayOrders() const;
};

#endif // CLIENT_H
