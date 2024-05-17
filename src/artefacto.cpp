#include "artefacto.hpp"

#include <utility>

artefacto::artefacto(int id, std::string set, tipo tipo1, size_t nivel, rareza rareza1) {
    this->id = id;
    this->set = std::move(set);
    this->tipo1 = tipo1;
    this->nivel = nivel;
    this->rareza1 = rareza1;
}

std::ostream& operator<<(std::ostream& os, const artefacto& artefacto1) {
    os << artefacto1.id << ","
       << artefacto1.set << ","
       << artefacto1.tipo1 << ","
       << artefacto1.nivel << ","
       << artefacto1.rareza1;
    return os;
}

bool artefacto::operator==(const artefacto& artefacto1) const{
    return id == artefacto1.id;
}