#ifndef WORKER_H
#define WORKER_H

#include "Person.h"
#include "Product.h"
#include <memory>
#include <iostream>

class Worker : public Person {
private:
    std::string role;  // Rôle ou tâche spécifique du travailleur (ex: manutentionnaire, gestionnaire de stock)
    bool isAvailable;  // Statut de disponibilité du travailleur

public:
    // Constructeur
    Worker(int id, const std::string& name, const std::string& role)
        : Person(id, name), role(role), isAvailable(true) {}

    // Obtenir le rôle du travailleur
    std::string getRole() const {
        return role;
    }

    // Vérifier la disponibilité du travailleur
    bool checkAvailability() const {
        return isAvailable;
    }

    // Effectuer une tâche (par exemple, déplacer un produit)
    void performTask(std::shared_ptr<Product> product) {
        if (isAvailable) {
            isAvailable = false;  // Le travailleur devient occupé
            std::cout << "Worker " << getName() << " is performing task with product " << product->getId() << ".\n";
            // Exemple de tâche effectuée : déplacer le produit
            moveProduct(product);
        } else {
            std::cout << "Worker " << getName() << " is not available.\n";
        }
    }

    // Libérer le travailleur après une tâche
    void completeTask() {
        isAvailable = true;
        std::cout << "Worker " << getName() << " has completed the task.\n";
    }

    // Déplacer un produit (exemple de tâche)
    void moveProduct(std::shared_ptr<Product> product) {
        std::cout << "Worker " << getName() << " is moving product " << product->getId() << ".\n";
        // Exemple de code pour déplacer le produit dans l'entrepôt ou vers le convoyeur
    }

    // Afficher l'état du travailleur
    void displayWorkerStatus() const {
        std::cout << "Worker " << getName() << " (ID: " << getId() << "), Role: " << role
                  << ", Availability: " << (isAvailable ? "Available" : "Not Available") << "\n";
    }
};

#endif // WORKER_H
