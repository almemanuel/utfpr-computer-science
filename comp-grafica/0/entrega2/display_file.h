#ifndef DISPLAY_FILE_H
#define DISPLAY_FILE_H

#include <vector>
#include <memory>
#include "objeto_geometrico.h"

class DisplayFile {
public:
    void adicionarObjeto(std::unique_ptr<ObjetoGeometrico> objeto);
    const std::vector<std::unique_ptr<ObjetoGeometrico>>& getObjetos() const;

private:
    std::vector<std::unique_ptr<ObjetoGeometrico>> objetos;
};

#endif // DISPLAY_FILE_H
