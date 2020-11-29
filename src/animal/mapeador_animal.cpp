#include "mapeador_animal.hpp"

// FiltroAnimal::FiltroAnimal() {
//     filtro['A'] = [](Animal* animal) {
//         Ave* checar = dynamic_cast<Ave*>(animal);
//         return dynamic_cast<Animal*>(checar);
//     };

//     filtro['F'] = [](Animal* animal) {
//         Anfibio* checar = dynamic_cast<Anfibio*>(animal);
//         return dynamic_cast<Animal*>(checar);
//     };

//     filtro['R'] = [](Animal* animal) {
//         Reptil* checar = dynamic_cast<Reptil*>(animal);
//         return dynamic_cast<Animal*>(checar);
//     };

//     filtro['M'] = [](Animal* animal) {
//         Mamifero* checar = dynamic_cast<Mamifero*>(animal);
//         return dynamic_cast<Animal*>(checar);
//     };

//     filtro['T'] = [](Animal* animal) {
//         //Mamifero* checar = dynamic_cast<Mamifero*>(animal);
//         return animal;
//     };
// }

MapeadorAnimal::MapeadorAnimal() {
    aMap["aveD"] = []() { 
        return make_shared<AveDomestica>(); 
    };

    aMap["aveN"] = []() { 
        return make_shared<AveNativa>(); 
    };

    aMap["aveE"] = []() { 
        return make_shared<AveExotica>(); 
    };


    aMap["anfD"] = []() { 
        return make_shared<AnfibioDomestico>(); 
    };

    aMap["anfN"] = []() { 
        return make_shared<AnfibioNativo>(); 
    };

    aMap["anfE"] = []() { 
        return make_shared<AnfibioExotico>(); 
    };

    
    aMap["repD"] = []() { 
        return make_shared<ReptilDomestico>(); 
    };

    aMap["repN"] = []() { 
        return make_shared<ReptilNativo>(); 
    };

    aMap["repE"] = []() { 
        return make_shared<ReptilExotico>(); 
    };


    aMap["mamD"] = []() { 
        return make_shared<MamiferoDomestico>(); 
    };

    aMap["mamN"] = []() { 
        return make_shared<MamiferoNativo>(); 
    };

    aMap["mamE"] = []() { 
        return make_shared<MamiferoExotico>(); 
    };
}