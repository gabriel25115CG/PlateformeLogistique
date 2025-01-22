#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    int id; // Identifiant unique

public:
    Entity(int id) : id(id) {}
    virtual ~Entity() = default;

    int getId() const { return id; }
    void setId(int id) { this->id = id; }
};

#endif // ENTITY_H
