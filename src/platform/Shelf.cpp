#include "Shelf.h"
#include "Product.h"

// Constructeur de Shelf
Shelf::Shelf(int capacity) : capacity(capacity) {}

// Méthode pour ajouter un produit
bool Shelf::addProduct(const Product& product) {
    if (products.size() < capacity) {
        products.push_back(product);  // Ajoute le produit au vecteur
        return true;
    }
    return false;
}

// Méthode pour retirer un produit
Product Shelf::removeProduct(int productId) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == productId) {
            Product removedProduct = *it;  // Crée une copie du produit à retirer
            products.erase(it);  // Retire le produit du vecteur
            return removedProduct; // Retourne le produit supprimé
        }
    }
    // Retourne un produit "vide" si l'ID n'est pas trouvé
    return Product(0, "", 0.0, 0);  
}

// Méthode pour vérifier si un produit est dans le shelf
bool Shelf::hasProduct(int productId) const {
    for (const auto& product : products) {
        if (product.getId() == productId) {
            return true;  // Produit trouvé
        }
    }
    return false;  // Produit non trouvé
}
