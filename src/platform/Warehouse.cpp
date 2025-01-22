#include "Warehouse.h"
#include <iostream>
#include <algorithm>

// Constructeur de la classe Warehouse
Warehouse::Warehouse(int id, const std::string& name, int capacity)
    : PlatformElement(id, name), capacity(capacity) {  // Appel au constructeur de PlatformElement
    std::cout << "Warehouse " << name << " created with capacity " << capacity << ".\n";
}

// Ajouter un produit à l'entrepôt
bool Warehouse::addProduct(std::shared_ptr<Product> product) {
    if (products.size() < capacity) {
        products.push_back(product);
        std::cout << "Product " << product->getId() << " added to warehouse " << getName() << ".\n";
        return true;
    } else {
        std::cout << "Warehouse " << getName() << " is full. Cannot add product " << product->getId() << ".\n";
        return false;
    }
}

// Retirer un produit de l'entrepôt
bool Warehouse::removeProduct(int productId) {
    auto it = std::find_if(products.begin(), products.end(),
        [productId](const std::shared_ptr<Product>& product) {
            return product->getId() == productId;
        });

    if (it != products.end()) {
        products.erase(it);
        std::cout << "Product " << productId << " removed from warehouse " << getName() << ".\n";
        return true;
    } else {
        std::cout << "Product " << productId << " not found in warehouse " << getName() << ".\n";
        return false;
    }
}

// Afficher l'état de l'entrepôt
void Warehouse::displayWarehouseStatus() const {
    std::cout << "Warehouse " << getName() << " has " << products.size() << " products stored.\n";
}

// Implémentation de la méthode pure virtuelle `operate`
void Warehouse::operate() {
    std::cout << "Warehouse " << getName() << " is operational.\n";
}

// Getter pour la capacité de l'entrepôt
int Warehouse::getCapacity() const {
    return capacity;
}

// Getter pour le nombre de produits dans l'entrepôt
int Warehouse::getProductCount() const {
    return products.size();
}

// Getter pour la liste des produits dans l'entrepôt
const std::vector<std::shared_ptr<Product>>& Warehouse::getProducts() const {
    return products;
}
