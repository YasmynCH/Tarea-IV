#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agregarproducto.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <sstream>
#include <fstream>
#include "./tiendalocal.h"
#include "./excepcionNoSePuedeLeerArchivo.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TiendaLocal *tienda= new TiendaLocal(this->ui->txtNombreTienda->text(), this->ui->txtDireccionWeb->text(), this->ui->txtDireccionFisica->text(), this->ui->txtTelefono->text());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAgregar_clicked()
{

    AgregarProducto agregarProductoNuevo (this);
    int resultado = agregarProductoNuevo.exec();

    if (resultado == QDialog::Accepted) {

      [[maybe_unused]] int id = agregarProductoNuevo.getId();
       std::string nombre = agregarProductoNuevo.getNombre();
      [[maybe_unused]] int existencias = agregarProductoNuevo.getExistencias();

     try {
           [[maybe_unused]] ProductoLocal *producto= new ProductoLocal();
          // int id = this->ui->lista->count();
           QString opcion =  QString::number(id) + " " + nombre.c_str() + " " + QString::number(existencias);

           QListWidgetItem *itemNuevo = new QListWidgetItem(opcion);
           itemNuevo->setData(1, id);

           this->ui->lista->addItem(itemNuevo);

           [[maybe_unused]] TiendaLocal *tienda= new TiendaLocal(this->ui->txtNombreTienda->text(), this->ui->txtDireccionWeb->text(), this->ui->txtDireccionFisica->text(), this->ui->txtTelefono->text());
           tienda->AgregarProducto(producto);
       }

     catch (...){
           QMessageBox *msgbox = new QMessageBox(this);
           msgbox->setWindowTitle("Error al agregar producto");
           msgbox->setText("Datos de producto inválidos");
           msgbox->open();
       }
       }
}


void MainWindow::on_btnConsultar_clicked()
{
    QListWidgetItem *itemSeleccionado = this->ui->lista->currentItem();

    if (itemSeleccionado == nullptr)
    {
        // no hay ítem seleccionado
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Lista de Productos");
        msgbox->setText("No hay ítem seleccionado");
        msgbox->open();
    }
    else
    {
        QString stringID = itemSeleccionado->data(1).toString();
        QString stringNombre = itemSeleccionado->data(2).toString();
        QString stringExistencias = itemSeleccionado->data(3).toString();

        int idProducto = stringID.toInt();
        string nombreProducto = stringNombre.toStdString();
        int existencias = stringExistencias.toInt();


        AgregarProducto agregarProducto {this};
        agregarProducto.CargarInformacion(idProducto, nombreProducto, existencias);

        int resultado = agregarProducto.exec();

    }

}


void MainWindow::on_btnGuardarArchivo_clicked()
{

    QString archivoBinario = QFileDialog::getSaveFileName(this,
               "Guardar archivo de datos", "",
               tr("Archivo de datos (*.dat);;All Files (*)"));


       if (archivoBinario != "")
       {

           // Convertir QString a std::string
           std::string name = archivoBinario.toStdString();

           QMessageBox *msgbox = new QMessageBox(this);
           msgbox->setWindowTitle("Escritura de archivo binario");
           msgbox->setText(archivoBinario);
           msgbox->open();
       }
    }



void MainWindow::on_btnAbrirArchivo_clicked()
{
    QString archivoBinario = QFileDialog::getOpenFileName(this,
            "Abrir archivo de datos", "",
            tr("Archivo de datos (*.dat);;All Files (*)"));


    if (archivoBinario != "")
    {

       // Convertir QString a std::string
        std::string name = archivoBinario.toStdString();

        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Abrir archivo binario");
        msgbox->setText(archivoBinario);
        msgbox->open();
    }
}

