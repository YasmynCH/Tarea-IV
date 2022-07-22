#include "consultarproducto.h"
#include "ui_consultarproducto.h"

consultarProducto::consultarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consultarProducto)
{
    ui->setupUi(this);
}

consultarProducto::~consultarProducto()
{
    delete ui;
}
