#ifndef SHELF_H
#define SHELF_H

#include "Product.h" // Assurez-vous que la classe Product est incluse
#include <vector>    // Assurez-vous d'inclure le bon header pour std::vector

class Shelf {
private:
    int capacity; // Capacité du shelf
    std::vector<Product> products; // Déclarer le conteneur de produits

public:
    // Constructeur
    Shelf(int capacity);

    // Méthodes publiques
    bool addProduct(const Product& product);    // Ajouter un produit au shelf
    Product removeProduct(int productId);       // Retirer un produit du shelf par son ID
    bool hasProduct(int productId) const;      // Vérifier si un produit existe dans le shelf
};

#endif // SHELF_H
