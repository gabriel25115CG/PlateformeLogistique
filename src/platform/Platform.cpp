#include "Platform.h"
#include <iostream>
#include <memory>

// Constructeur de la classe Platform
Platform::Platform() {
    std::cout << "Platform created.\n";
}

// Ajouter un élément à la plateforme (par exemple, un quai, un convoyeur, etc.)
void Platform::addElement(std::shared_ptr<PlatformElement> element) {
    elements.push_back(element);
    std::cout << "Added platform element: " << element->getName() << "\n";
}

// Ajouter un conducteur à la plateforme
void Platform::addDriver(std::shared_ptr<Driver> driver) {
    drivers.push_back(driver);
    std::cout << "Added driver: " << driver->getName() << "\n";
}

// Ajouter un transporteur à la plateforme
void Platform::addTransporter(std::shared_ptr<Transporter> transporter) {
    transporters.push_back(transporter);
    std::cout << "Added transporter with ID: " << transporter->getId() << "\n";
}

// Effectuer les opérations logistiques (par exemple, déplacer un produit)
void Platform::performLogistics() {
    // Chaque conducteur vérifie sa disponibilité et effectue une tâche
    for (auto& driver : drivers) {
        if (driver->checkAvailability()) {
            driver->performTask();  // Le conducteur effectue une tâche (livraison, etc.)
        }
    }

    // Exemple de gestion des convoyeurs (opérations logistiques sur les éléments de la plateforme)
    for (auto& element : elements) {
        // Si l'élément est un convoyeur, on lui demande d'opérer
        if (auto conveyor = std::dynamic_pointer_cast<Conveyor>(element)) {
            conveyor->operate();  // Le convoyeur effectue une opération
        }
    }
}

// Afficher l'état de la plateforme
void Platform::displayPlatformStatus() {
    std::cout << "Platform status:\n";

    // Affichage de l'état de chaque conducteur
    for (auto& driver : drivers) {
        std::cout << "Driver: " << driver->getName() << " (ID: " << driver->getId() << "), "
                  << (driver->checkAvailability() ? "Available" : "Not Available") << "\n";
    }

    // Affichage de l'état de chaque transporteur
    for (auto& transporter : transporters) {
        std::cout << "Transporter with ID: " << transporter->getId() << "\n";
    }

    // Affichage des éléments de la plateforme
    for (auto& element : elements) {
        std::cout << "Platform element: " << element->getName() << "\n";
    }
}
