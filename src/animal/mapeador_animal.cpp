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
        return new AveDomestica(); 
    };

    aMap["aveN"] = []() { 
        return new AveNativa(); 
    };

    aMap["aveE"] = []() { 
        return new AveExotica(); 
    };


    aMap["anfD"] = []() { 
        return new AnfibioDomestico(); 
    };

    aMap["anfN"] = []() { 
        return new AnfibioNativo(); 
    };

    aMap["anfE"] = []() { 
        return new AnfibioExotico(); 
    };

    
    aMap["repD"] = []() { 
        return new ReptilDomestico(); 
    };

    aMap["repN"] = []() { 
        return new ReptilNativo(); 
    };

    aMap["repE"] = []() { 
        return new ReptilExotico(); 
    };


    aMap["mamD"] = []() { 
        return new MamiferoDomestico(); 
    };

    aMap["mamN"] = []() { 
        return new MamiferoNativo(); 
    };

    aMap["mamE"] = []() { 
        return new MamiferoExotico(); 
    };
}