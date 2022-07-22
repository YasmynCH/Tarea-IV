#include "productoLocal.h"
#include <iostream>
#include <cstring>
#include <QString>

using namespace std;

ProductoLocal::ProductoLocal(int id, QString nombre, int existencias)
{
    this->id = id;
    strcpy(this->nombre, nombre.toStdString().c_str());
    this->existencias = existencias;
}

ProductoLocal::ProductoLocal()
{
    this->id = 0;
    strcpy(this->nombre, "");
    this->existencias = 0;

}

    int ProductoLocal::getId(){

        return this->id;
    }

    QString ProductoLocal::getNombre(){

        return this->nombre;
    }

    int ProductoLocal::getExistencias(){

        return this->existencias;
    }

    int ProductoLocal::setId(int idNuevo){

        id= idNuevo;
        return this->id;
    }

    QString ProductoLocal::setNombre(QString nombreNuevo){

         strcpy(this->nombre, nombreNuevo.toStdString().c_str());
        return this->nombre;
    }

    int ProductoLocal::setExistencias(int existenciaNueva){

        existencias= existenciaNueva;
        return this->existencias;
    }

ostream& operator << (ostream &o, const ProductoLocal *producto)
{
    o << "[" << producto->id << "] - " << producto->nombre << " " << producto->existencias;
    return o;
}
