#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "PlatformElement.h"
#include "Product.h"
#include <vector>
#include <memory>
#include <iostream>

class Warehouse : public PlatformElement {
private:
    std::vector<std::shared_ptr<Product>> products;  // Liste des produits stockés dans l'entrepôt
    int capacity;                                    // Capacité maximale de l'entrepôt (nombre de produits)
    double distance;                                 // Distance entre l'entrepôt et le client
    double time;                                     // Temps total pour la gestion des stocks

public:
    // Constructeur
    Warehouse(int id, const std::string& name, int capacity, double distance = 0.0, double time = 0.0);

    // Ajouter un produit à l'entrepôt
    bool addProduct(std::shared_ptr<Product> product);

    // Retirer un produit de l'entrepôt par son ID
    bool removeProduct(int productId);

    // Afficher l'état de l'entrepôt
    void displayWarehouseStatus() const;

    // Implémentation de la méthode pure virtuelle de PlatformElement
    void operate() override;

    // Getter pour la capacité de l'entrepôt
    int getCapacity() const;

    // Getter pour le nombre de produits dans l'entrepôt
    int getProductCount() const;

    // Getter pour la liste des produits dans l'entrepôt
    const std::vector<std::shared_ptr<Product>>& getProducts() const;
};

#endif // WAREHOUSE_H
