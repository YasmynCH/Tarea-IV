#ifndef PRODUCTOLOCAL_H
#define PRODUCTOLOCAL_H

#include <QString>
#include <sstream>

using namespace std;

class ProductoLocal
{

    int id;
    char nombre[20];
    int existencias;

public:

    ProductoLocal(int id, QString nombre, int existencias);
    ProductoLocal();

    int getId();
    QString getNombre();
    int getExistencias();
    int setId(int idNuevo);
    QString setNombre(QString nombreNuevo);
    int setExistencias(int existenciaNueva);


    friend ostream& operator << (ostream &o, const ProductoLocal *producto);

};

#endif // PRODUCTOLOCAL_H
