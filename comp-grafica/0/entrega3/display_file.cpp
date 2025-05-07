#include "display_file.h"

void DisplayFile::adicionarObjeto(std::unique_ptr<ObjetoGeometrico> objeto) {
    objetos.push_back(std::move(objeto));
}

const std::vector<std::unique_ptr<ObjetoGeometrico>>& DisplayFile::getObjetos() const {
    return objetos;
}
