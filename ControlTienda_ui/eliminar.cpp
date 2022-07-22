#include "eliminar.h"
#include "ui_eliminar.h"

eliminar::eliminar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eliminar)
{
    ui->setupUi(this);
}

eliminar::~eliminar()
{
    delete ui;
}


int eliminar::getId()
{
    QString stringID = this->ui->txtIDEliminar->text();
    int id = stringID.toInt();
    return id;
}
