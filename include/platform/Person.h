#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    int id;                    // Identifiant unique de la personne
    std::string name;          // Nom de la personne
    bool isAvailable;          // Statut de disponibilité de la personne

public:
    // Constructeur
    Person(int id, const std::string& name)
        : id(id), name(name), isAvailable(true) {}

    // Getter pour l'ID de la personne
    int getId() const { return id; }

    // Getter pour le nom de la personne
    std::string getName() const { return name; }

    // Méthode pour vérifier la disponibilité
    bool checkAvailability() const {
        return isAvailable;
    }

    // Méthode pour rendre la personne disponible ou non
    void setAvailability(bool available) {
        isAvailable = available;
    }

    // Méthode virtuelle pure : chaque sous-classe devra implémenter son propre comportement
    virtual void performTask() = 0; 
    // Exemple : Un opérateur de manutention pourrait déplacer des produits, un chauffeur pourrait effectuer une livraison.
};

#endif // PERSON_H
