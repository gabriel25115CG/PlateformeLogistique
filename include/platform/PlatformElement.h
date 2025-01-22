#ifndef PLATFORM_ELEMENT_H
#define PLATFORM_ELEMENT_H

#include "Entity.h"
#include <string>

class PlatformElement : public Entity {
protected:
    std::string name;

public:
    PlatformElement(int id, const std::string& name) : Entity(id), name(name) {}
    virtual ~PlatformElement() = default;

    const std::string& getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }

    virtual void operate() = 0; // Méthode virtuelle pure pour spécifier un comportement
};

#endif // PLATFORM_ELEMENT_H
