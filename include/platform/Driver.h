#ifndef DRIVER_H
#define DRIVER_H

#include "Transporter.h"
#include <memory>
#include <string>
#include <iostream>

class Driver {
private:
    int id;                         // Identifiant unique du conducteur
    std::string name;               // Nom du conducteur
    std::shared_ptr<Transporter> transporter; // Pointeur vers le transporteur qu'il conduit
    bool isAvailable;               // Statut de disponibilité du conducteur (disponible ou non)

public:
    // Constructeur
    Driver(int id, const std::string& name)
        : id(id), name(name), isAvailable(true) {}

    // Getter pour l'ID du conducteur
    int getId() const { return id; }

    // Getter pour le nom du conducteur
    std::string getName() const { return name; }

    // Méthode pour affecter un transporteur au conducteur
    void assignTransporter(std::shared_ptr<Transporter> trans) {
        transporter = trans;
        std::cout << "Driver " << name << " is now assigned to transporter " << transporter->getId() << ".\n";
    }

    // Méthode pour vérifier si le conducteur est disponible
    bool checkAvailability() const {
        return isAvailable;
    }

    // Driver.h
    void performTask() {
    std::cout << "Driver " << name << " is performing a task.\n";
        }

    // Méthode pour changer la disponibilité du conducteur
    void setAvailability(bool available) {
        isAvailable = available;
        std::cout << "Driver " << name << " is now " << (isAvailable ? "available" : "not available") << ".\n";
    }

    // Méthode pour commencer une mission de livraison
    void startDelivery() {
        if (transporter != nullptr && isAvailable) {
            std::cout << "Driver " << name << " is starting delivery with transporter " << transporter->getId() << ".\n";
            // Ici, la logique pour commencer la livraison peut être ajoutée
            transporter->startMission();
            setAvailability(false);  // Le conducteur n'est plus disponible pendant la mission
        }
        else {
            std::cout << "Driver " << name << " cannot start delivery. " 
                      << (transporter == nullptr ? "No transporter assigned." : "Driver is not available.") << "\n";
        }
    }

    // Méthode pour finir la mission et rendre le conducteur disponible
    void completeDelivery() {
        if (transporter != nullptr) {
            std::cout << "Driver " << name << " has completed the delivery with transporter " << transporter->getId() << ".\n";
            transporter->completeMission();
            setAvailability(true);  // Le conducteur devient disponible après la mission
        }
    }
};

#endif // DRIVER_H
