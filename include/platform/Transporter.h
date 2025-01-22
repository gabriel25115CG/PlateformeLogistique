#ifndef TRANSPORTER_H
#define TRANSPORTER_H

#include <string>

class Transporter {
private:
    std::string name;
    int id;  // Identifiant unique pour le transporteur
    bool missionInProgress;
    int productsDelivered;  // Nombre de produits livrés
    double distanceTraveled;  // Distance parcourue par le transporteur (en kilomètres ou autres unités)

public:
    // Constructeur
    Transporter(int id, const std::string& name);

    // Méthode pour obtenir l'ID du transporteur
    int getId() const;

    // Démarrer une mission
    void startMission();

    // Compléter une mission
    void completeMission();

    // Vérifier si une mission est en cours
    bool isMissionInProgress() const;

    // Récupérer le nom du transporteur
    std::string getName() const;

    // Récupérer le nombre de produits livrés
    int getProductsDelivered() const;

    // Ajouter un produit livré
    void addDeliveredProduct();

    // Ajouter une distance parcourue
    void addDistanceTraveled(double distance);

    // Récupérer la distance parcourue
    double getDistanceTraveled() const;
};

#endif // TRANSPORTER_H
