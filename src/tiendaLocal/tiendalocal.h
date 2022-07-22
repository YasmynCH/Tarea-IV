#ifndef TIENDALOCAL_H
#define TIENDALOCAL_H

#include <QString>
#include <sstream>
#include <vector>


#include "productoLocal.h"

using namespace std;

class TiendaLocal
{

    vector <ProductoLocal *> inventario;


    char nombre[15];
    char direccionWeb[24];
    char direccionFisica[24];
    char telefono[9];

public:

    TiendaLocal (QString nombre, QString direccionWeb, QString direccionFisica, QString telefono);
    TiendaLocal ();
    ~TiendaLocal();

    void AgregarProducto(ProductoLocal *producto);
    void BuscarProducto(istream *streamEntrada, int idProductoBuscado);
    void EliminarProducto(int idProductoAEliminar);
    ProductoLocal ModificarNombreProducto(int idProductoAModificar, QString nombreModificar, int existenciaModificar);
    void GuardarEnStreamBinario(ostream *streamSalida);
    void CargarDesdeStream(istream *streamEntrada);

    friend ostream& operator << (ostream &o, const TiendaLocal *tienda);

};

#endif // TIENDALOCAL_H
