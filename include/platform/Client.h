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

public:
    // Constructeur
    Client(int id, const std::string& name);

    // Récupérer l'identifiant du client
    int getId() const;

    // Récupérer le nom du client
    std::string getName() const;

    // Ajouter une commande
    void addOrder(int productId);

    // Afficher les commandes du client
    void displayOrders() const;
};

#endif // CLIENT_H
