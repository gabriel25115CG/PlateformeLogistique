#include "Conveyor.h"
#include <iostream>
#include <stdexcept>  // Pour std::runtime_error

// Constructeur de la classe Conveyor
Conveyor::Conveyor(int id, const std::string& name)
    : PlatformElement(id, name), isActive(true) {
    std::cout << "Conveyor " << name << " (ID: " << id << ") created and is active.\n";
}

// Méthode pour charger un produit dans le convoyeur
void Conveyor::loadProduct(const std::shared_ptr<Product>& product) {
    productsQueue.push(product);
    std::cout << "Product with ID " << product->getId() << " loaded onto the conveyor.\n";
}

// Méthode pour décharger un produit du convoyeur
std::shared_ptr<Product> Conveyor::unloadProduct() {
    if (!productsQueue.empty()) {
        auto product = productsQueue.front();
        productsQueue.pop();
        std::cout << "Product with ID " << product->getId() << " unloaded from the conveyor.\n";
        return product;
    }
    throw std::runtime_error("No products to unload from the conveyor!");
}

// Méthode pour vérifier si le convoyeur est actif
bool Conveyor::isActiveStatus() const {
    return isActive;
}

// Méthode pour activer/désactiver le convoyeur
void Conveyor::setActive(bool active) {
    isActive = active;
    std::cout << "Conveyor " << getName() << " is now " << (isActive ? "active" : "inactive") << ".\n";
}

// Opération de simulation
void Conveyor::operate() {
    if (isActive && !productsQueue.empty()) {
        std::shared_ptr<Product> product = unloadProduct();
        // Simulation d'un transfert du produit vers la prochaine étape
        std::cout << "Conveyor moving product " << product->getId() << " to next step.\n";
    }
    else {
        std::cout << "Conveyor is inactive or empty.\n";
    }
}
