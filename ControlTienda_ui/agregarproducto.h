#ifndef AGREGARPRODUCTO_H
#define AGREGARPRODUCTO_H

#include <QDialog>

namespace Ui {
class AgregarProducto;
}

class AgregarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarProducto(QWidget *parent = nullptr);
    ~AgregarProducto();

    void CargarInformacion(int id, std::string nombre, int existencias);
    int getId();
    std::string getNombre();
    int getExistencias();

private:
    Ui::AgregarProducto *ui;
};

#endif // AGREGARPRODUCTO_H
