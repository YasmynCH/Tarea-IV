#include "tiendalocal.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <QString>



/*Tienda::Tienda(){
        strcpy(this->nombre, "");
        strcpy(this->direccionWeb, "");
        strcpy(this->direccionFisica, "");
        strcpy(this->telefono, "");
}*/

TiendaLocal::TiendaLocal(QString nombreNuevo, QString direccionWeb, QString direccionFisica, QString telefono){

        strcpy(this->nombre, nombreNuevo.toStdString().c_str());
        strcpy(this->direccionWeb, direccionWeb.toStdString().c_str());
        strcpy(this->direccionFisica, direccionFisica.toStdString().c_str());
        strcpy(this->telefono, telefono.toStdString().c_str());
}

TiendaLocal::~TiendaLocal()
{
    for (ProductoLocal *producto : this->inventario)
    {
        delete producto;
    }
}

void TiendaLocal::AgregarProducto(ProductoLocal *nuevoProducto)
{
    this->inventario.push_back(nuevoProducto);
}

void TiendaLocal::GuardarEnStreamBinario(ostream *streamSalida)
{

    TiendaLocal *infoTienda = new TiendaLocal(this->nombre, this->direccionWeb, this->direccionFisica, this->telefono);

    streamSalida->write((char *)infoTienda, sizeof(TiendaLocal));

    for (ProductoLocal *producto : this->inventario)
    {
        streamSalida->write((char *)producto, sizeof(ProductoLocal));
    }
}

void TiendaLocal::BuscarProducto(istream *streamEntrada, int posicionProducto)
{
    streamEntrada->seekg(sizeof(ProductoLocal) * posicionProducto +71);

    ProductoLocal *producto = new ProductoLocal();
    streamEntrada->read((char *)producto, sizeof(ProductoLocal));

    this->AgregarProducto(producto);
}

void TiendaLocal::CargarDesdeStream(istream *streamEntrada){

    streamEntrada->seekg(0, ios::end);
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = 71+(cantidadBytesEnArchivo / sizeof(ProductoLocal));

    // Leer cada empleado
    streamEntrada->seekg(0, ios::beg); // Empezar desde el principio del archivo
    TiendaLocal *tiendaLocal = new TiendaLocal(this->nombre, this->direccionWeb, this->direccionFisica, this->telefono);
    streamEntrada->read((char *)tiendaLocal, sizeof(TiendaLocal));

    for (int indice = 71; indice < cantidadProductos; indice++)
    {
        ProductoLocal *producto = new ProductoLocal();
        streamEntrada->read((char *)producto, sizeof(ProductoLocal)); // variable para guardar y cuántos bytes leo

        this->AgregarProducto(producto);
    }
}

ProductoLocal TiendaLocal::ModificarNombreProducto(int idProductoAModificar, QString nombreModificar, int existenciasAModificar){

        ifstream streamEntrada;
        streamEntrada.open("archivo_test.dat", ios::in | ios::binary);

        if (!streamEntrada.is_open()){

            throw exception();
        }

        ProductoLocal productoEncontrado;

        int posicion = sizeof(TiendaLocal) + (sizeof(ProductoLocal) * idProductoAModificar);
        streamEntrada.seekg(0, ios::beg);

        int tamanoStream = streamEntrada.tellg();

        if (posicion < tamanoStream){

            throw exception();
        }

        if (productoEncontrado.getId() == idProductoAModificar){

            streamEntrada.seekg(posicion);
            streamEntrada.read((char *) &productoEncontrado, sizeof(ProductoLocal));

            productoEncontrado.setNombre(nombreModificar);
            productoEncontrado.setExistencias(existenciasAModificar);


        }
         return  productoEncontrado;
 }

 void TiendaLocal::EliminarProducto(int idProductoBuscado){

        for (int indice= 0; indice<inventario.size(); indice++){

            if (inventario[indice]->getId() == idProductoBuscado){

                inventario.erase(inventario.begin()+ indice);
            }
        }

 }

ostream& operator << (ostream &o, const TiendaLocal *tiendaLocal)
{
    o << "Inventario: " << std::endl;

    for (ProductoLocal *producto : tiendaLocal->inventario)
    {
        o << producto << endl;
    }

    return o;
}
