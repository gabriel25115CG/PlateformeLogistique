#ifndef PRODUCT_H
#define PRODUCT_H

#include "Entity.h"
#include <string>

class Product : public Entity {
private:
    std::string name;
    double weight;
    int quantity;
    double timeInStock;  // Temps que le produit a passé en stock (en heures ou autres unités)
    double totalTime;    // Temps total dans le système (en heures ou autres unités)

public:
    Product(int id, const std::string& name, double weight, int quantity) 
        : Entity(id), name(name), weight(weight), quantity(quantity), timeInStock(0), totalTime(0) {}

    const std::string& getName() const { return name; }
    double getWeight() const { return weight; }
    int getQuantity() const { return quantity; }
    double getTimeInStock() const { return timeInStock; }
    double getTotalTime() const { return totalTime; }

    void setName(const std::string& name) { this->name = name; }
    void setWeight(double weight) { this->weight = weight; }
    void setQuantity(int quantity) { this->quantity = quantity; }
    void setTimeInStock(double time) { timeInStock = time; }  // Met à jour le temps en stock
    void setTotalTime(double time) { totalTime = time; }  // Met à jour le temps total dans le système

    // Méthode pour simuler l'écoulement du temps en stock
    void updateTimeInStock(double timeDelta) {
        timeInStock += timeDelta;
    }

    // Méthode pour simuler l'écoulement du temps total dans le système
    void updateTotalTime(double timeDelta) {
        totalTime += timeDelta;
    }
};

#endif // PRODUCT_H
