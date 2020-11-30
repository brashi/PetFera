#include "mapeador_animal.hpp"

 FiltroAnimal::FiltroAnimal() {
     filtro['A'] = [](shared_ptr<Animal> animal) {
         shared_ptr<Ave> checar = dynamic_pointer_cast<Ave>(animal);
         return dynamic_pointer_cast<Animal>(checar);
     };

     filtro['F'] = [](shared_ptr<Animal> animal) {
         shared_ptr<Anfibio> checar = dynamic_pointer_cast<Anfibio>(animal);
         return dynamic_pointer_cast<Animal>(checar);
     };

     filtro['R'] = [](shared_ptr<Animal> animal) {
         shared_ptr<Reptil> checar = dynamic_pointer_cast<Reptil>(animal);
         return dynamic_pointer_cast<Animal>(checar);
     };

     filtro['M'] = [](shared_ptr<Animal> animal) {
         shared_ptr<Mamifero> checar = dynamic_pointer_cast<Mamifero>(animal);
         return dynamic_pointer_cast<Animal>(checar);
     };

     filtro['D'] = [](shared_ptr<Animal> animal) {
         shared_ptr<Domestico> checar = dynamic_pointer_cast<Domestico>(animal);
         return dynamic_pointer_cast<Animal>(checar);
     };

     filtro['E'] = [](shared_ptr<Animal> animal) {
         shared_ptr<Exotico> checar = dynamic_pointer_cast<Exotico>(animal);
         return dynamic_pointer_cast<Animal>(checar);
     };

     filtro['N'] = [](shared_ptr<Animal> animal) {
         shared_ptr<Nativo> checar = dynamic_pointer_cast<Nativo>(animal);
         return dynamic_pointer_cast<Animal>(checar);
     };

     filtro['X'] = [](shared_ptr<Animal> animal) {
         //Mamifero* checar = dynamic_cast<Mamifero*>(animal);
         return animal;
     };
}

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