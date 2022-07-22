#ifndef MODIFICAR_H
#define MODIFICAR_H

#include <QDialog>

namespace Ui {
class modificar;
}

class modificar : public QDialog
{
    Q_OBJECT

public:
    explicit modificar(QWidget *parent = nullptr);
    ~modificar();

    void CargarInformacion(int id, std::string nombre, int existencias);
    int getId();
    std::string getNombre();
    int getExistencias();

    int setId();
    std::string setNombre();
    int setExistencias();

private:
    Ui::modificar *ui;
};

#endif // MODIFICAR_H
