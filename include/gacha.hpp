#ifndef AYED_TP2_1C2024_GACHA_HPP
#define AYED_TP2_1C2024_GACHA_HPP

#include "salto.hpp"
#include "vector.hpp"

class gacha {
public:
    gacha();

    salto generar_salto();

    vector<salto> generar_salto_multiple();

    vector<salto> generar_salto_multiple(size_t cantidad);

    void exportar_saltos();
};

#endif