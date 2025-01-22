#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <memory>
#include <iostream>
#include "Product.h"  // Assurez-vous que Product est inclus si nécessaire

class Storage {
private:
    std::vector<std::shared_ptr<Product>> storage; // Liste des produits stockés

public:
    // Ajouter un produit au stockage
    void addProduct(const std::shared_ptr<Product>& product) {
        storage.push_back(product);
        std::cout << "Product with ID " << product->getId() << " added to storage.\n";
    }

    // Retirer un produit du stockage
    bool removeProduct(int productId) {
        for (auto it = storage.begin(); it != storage.end(); ++it) {
            if ((*it)->getId() == productId) {
                storage.erase(it);
                std::cout << "Product with ID " << productId << " removed from storage.\n";
                return true;
            }
        }
        std::cout << "Product with ID " << productId << " not found in storage.\n";
        return false;
    }

    // Afficher l'état du stockage
    void displayStorageStatus() const {
        std::cout << "Storage contains " << storage.size() << " products.\n";
    }
};

#endif // STORAGE_H
