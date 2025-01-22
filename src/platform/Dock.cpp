#ifndef DOCK_H
#define DOCK_H

#include "PlatformElement.h"
#include "Product.h"
#include <queue>
#include <stdexcept> 

class Dock : public PlatformElement {
private:
    bool isAvailable;
    std::queue<Product> waitingProducts;

public:
    Dock(int id, const std::string& name) 
        : PlatformElement(id, name), isAvailable(true) {}

    bool getAvailability() const { return isAvailable; }
    void setAvailability(bool availability) { isAvailable = availability; }

    void receiveProduct(const Product& product) {
        waitingProducts.push(product);
    }

    Product dispatchProduct() {
        if (!waitingProducts.empty()) {
            Product product = waitingProducts.front();
            waitingProducts.pop();
            return product;
        }
        throw std::runtime_error("No products to dispatch!");
    }

    void operate() override {
        // Logique spécifique pour gérer le quai
    }
};

#endif // DOCK_H
