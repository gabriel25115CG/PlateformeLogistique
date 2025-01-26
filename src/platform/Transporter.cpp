#include "Transporter.h"
#include <iostream>

// Constructeur de la classe Transporter
Transporter::Transporter(int id, const std::string& name, double emissionRate)
    : id(id), name(name), missionInProgress(false), productsDelivered(0),
      distanceTraveled(0.0), carbonEmissionRate(emissionRate) {
    std::cout << "Transporter " << name << " with ID " << id 
              << " created. Emission rate: " << emissionRate << " kg CO₂/km\n";
}

// Méthode pour obtenir l'ID du transporteur
int Transporter::getId() const {
    return id;
}

// Démarrer une mission pour le transporteur
void Transporter::startMission() {
    if (!missionInProgress) {
        missionInProgress = true;
        std::cout << "Transporter " << name << " (ID: " << id << ") has started the mission.\n";
    } else {
        std::cout << "Transporter " << name << " (ID: " << id << ") is already on a mission.\n";
    }
}

// Compléter la mission en cours pour le transporteur
void Transporter::completeMission() {
    if (missionInProgress) {
        missionInProgress = false;
        std::cout << "Transporter " << name << " (ID: " << id << ") has completed the mission.\n";
    } else {
        std::cout << "Transporter " << name << " (ID: " << id << ") is not on any mission.\n";
    }
}

// Vérifier si une mission est en cours
bool Transporter::isMissionInProgress() const {
    return missionInProgress;
}

// Récupérer le nom du transporteur
std::string Transporter::getName() const {
    return name;
}

// Récupérer le nombre de produits livrés
int Transporter::getProductsDelivered() const {
    return productsDelivered;
}

// Ajouter un produit livré
void Transporter::addDeliveredProduct() {
    productsDelivered++;
}

// Ajouter une distance parcourue
void Transporter::addDistanceTraveled(double distance) {
    distanceTraveled += distance;
}

// Récupérer la distance parcourue
double Transporter::getDistanceTraveled() const {
    return distanceTraveled;
}

// Calculer l'impact carbone
double Transporter::calculateCarbonImpact() const {
    return distanceTraveled * carbonEmissionRate;
}
