#ifndef PLATFORM_H
#define PLATFORM_H

#include "PlatformElement.h"
#include "Conveyor.h"
#include "Storage.h"
#include "Driver.h"
#include "Transporter.h"
#include "Product.h"
#include <vector>
#include <memory>
#include <iostream>

class Platform {
private:
    std::vector<std::shared_ptr<PlatformElement>> elements;  // Liste des éléments de la plateforme (quais, entrepôts, convoyeurs, etc.)
    std::vector<std::shared_ptr<Driver>> drivers;           // Liste des conducteurs
    std::vector<std::shared_ptr<Transporter>> transporters; // Liste des transporteurs

public:
    // Constructeur
    Platform();

    // Ajouter un élément à la plateforme (par exemple, un quai, un convoyeur, etc.)
    void addElement(std::shared_ptr<PlatformElement> element);

    // Ajouter un conducteur à la plateforme
    void addDriver(std::shared_ptr<Driver> driver);

    // Ajouter un transporteur à la plateforme
    void addTransporter(std::shared_ptr<Transporter> transporter);

    // Effectuer les opérations logistiques (par exemple, déplacer un produit)
    void performLogistics();

    // Afficher l'état de la plateforme
    void displayPlatformStatus();
};

#endif // PLATFORM_H
