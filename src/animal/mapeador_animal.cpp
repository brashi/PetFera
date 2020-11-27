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
        return new AveDomestica({}, {}, {}, {}, {}, false, false, false); 
        };

    aMap["aveN"] = []() { 
        return new AveNativa({}, {}, {}, {}, {}, false, {}, {}, false); 
        };

    aMap["aveE"] = []() { 
        return new AveExotica({}, {}, {}, {}, {}, false, {}, false); 
        };


    aMap["anfD"] = []() { 
        return new AnfibioDomestico({}, {}, {}, {}, {}, false, false, false, false); 
        };

    aMap["anfN"] = []() { 
        return new AnfibioNativo({}, {}, {}, {}, {}, false, {}, {}, false, false); 
        };

    aMap["anfE"] = []() { 
        return new AnfibioExotico({}, {}, {}, {}, {}, false, {}, false, false); 
        };

    
    aMap["repD"] = []() { 
        return new ReptilDomestico({}, {}, {}, {}, {}, false, false, {}); 
        };

    aMap["repN"] = []() { 
        return new ReptilNativo({}, {}, {}, {}, {}, false, {}, {}, {}); 
        };

    aMap["repE"] = []() { 
        return new ReptilExotico({}, {}, {}, {}, {}, false, {}, {}); 
        };


    aMap["mamD"] = []() { 
        return new MamiferoDomestico({}, {}, {}, {}, {}, false, false, false); 
        };

    aMap["mamN"] = []() { 
        return new MamiferoNativo({}, {}, {}, {}, {}, false, {}, {}, false); 
        };

    aMap["mamE"] = []() { 
        return new MamiferoExotico({}, {}, {}, {}, {}, false, {}, false); 
        };
}