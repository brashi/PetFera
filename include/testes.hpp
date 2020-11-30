#include <memory>
#include <string>
#include "petshop.hpp"

#include "ave_domestica.hpp"
#include "ave_nativa.hpp"
#include "ave_exotica.hpp"

#include "anfibio_domestico.hpp"
#include "anfibio_nativo.hpp"
#include "anfibio_exotico.hpp"

#include "reptil_domestico.hpp"
#include "reptil_nativo.hpp"
#include "reptil_exotico.hpp"

#include "mamifero_domestico.hpp"
#include "mamifero_nativo.hpp"
#include "mamifero_exotico.hpp"

#include "veterinario.hpp"
#include "tratador.hpp"

using std::shared_ptr;
using std::make_shared;

void acionarTestes(shared_ptr<Petshop> ps);