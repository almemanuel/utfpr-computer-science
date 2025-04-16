#include "objeto_geometrico.h"

ObjetoGeometrico::ObjetoGeometrico(QString nome, Tipo tipo)
    : nome(nome), tipo(tipo) {}

QString ObjetoGeometrico::getNome() const {
    return nome;
}

ObjetoGeometrico::Tipo ObjetoGeometrico::getTipo() const {
    return tipo;
}
