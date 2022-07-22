#ifndef CONSULTARPRODUCTO_H
#define CONSULTARPRODUCTO_H

#include <QDialog>

namespace Ui {
class consultarProducto;
}

class consultarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit consultarProducto(QWidget *parent = nullptr);
    ~consultarProducto();

private:
    Ui::consultarProducto *ui;
};

#endif // CONSULTARPRODUCTO_H
