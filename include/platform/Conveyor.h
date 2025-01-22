#ifndef CONVEYOR_H
#define CONVEYOR_H

#include "PlatformElement.h"
#include "Product.h"
#include <queue>
#include <memory>
#include <iostream>

class Conveyor : public PlatformElement {
private:
    std::queue<std::shared_ptr<Product>> productsQueue; // File pour stocker les produits en transit
    bool isActive; // Statut du convoyeur (actif ou non)

public:
    // Constructeur
    Conveyor(int id, const std::string& name);

    // Méthode pour charger un produit dans le convoyeur
    void loadProduct(const std::shared_ptr<Product>& product);

    // Méthode pour décharger un produit du convoyeur
    std::shared_ptr<Product> unloadProduct();

    // Méthode pour vérifier si le convoyeur est actif
    bool isActiveStatus() const;

    // Méthode pour activer/désactiver le convoyeur
    void setActive(bool active);

    // Opération de simulation
    void operate() override;
};

#endif // CONVEYOR_H
