#include "modificar.h"
#include "ui_modificar.h"

modificar::modificar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modificar)
{
    ui->setupUi(this);
}

modificar::~modificar()
{
    delete ui;
}


void modificar::CargarInformacion(int id, std::string nombre, int existencias)
{
    QString stringID = QString::number(id);
    this->ui->txtIdModificar->setText(stringID);
    this->ui->txtIdModificar->setReadOnly(true);

    QString stringNombre = QString::fromStdString(nombre);
    this->ui->txtNuevoNombre->setText(stringNombre);

    QString stringExistencias = QString::number(existencias);
    this->ui->txtNuevaExistencia->setText(stringExistencias);

}

int modificar::getId()
{
    QString stringID = this->ui->txtIdModificar->text();
    int id = stringID.toInt();
    return id;
}

std::string modificar::getNombre()
{
    QString stringNombre = this->ui->txtNuevoNombre->text();
    std::string nombre = stringNombre.toStdString();
    return nombre;
}

int modificar::getExistencias()
{
    QString stringExistencias = this->ui->txtNuevaExistencia->text();
    int existencias = stringExistencias.toInt();
    return existencias;
}



