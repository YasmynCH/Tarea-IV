#include "agregarproducto.h"
#include "ui_agregarproducto.h"

AgregarProducto::AgregarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarProducto)
{
    ui->setupUi(this);
}

AgregarProducto::~AgregarProducto()
{
    delete ui;
}

void AgregarProducto::CargarInformacion(int id, std::string nombre, int existencias)
{
    QString stringID = QString::number(id);
    this->ui->txtID->setText(stringID);
    this->ui->txtID->setReadOnly(true);

    QString stringNombre = QString::fromStdString(nombre);
    this->ui->txtNombre->setText(stringNombre);

    QString stringExistencias = QString::number(existencias);
    this->ui->txtExistencias->setText(stringExistencias);

}

int AgregarProducto::getId()
{
    QString stringID = this->ui->txtID->text();
    int id = stringID.toInt();
    return id;
}

std::string AgregarProducto::getNombre()
{
    QString stringNombre = this->ui->txtNombre->text();
    std::string nombre = stringNombre.toStdString();
    return nombre;
}

int AgregarProducto::getExistencias()
{
    QString stringExistencias = this->ui->txtExistencias->text();
    int existencias = stringExistencias.toInt();
    return existencias;
}

