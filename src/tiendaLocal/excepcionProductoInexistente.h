#ifndef EXCEPCIONPRODUCTOINEXISTENTE_H
#define EXCEPCIONPRODUCTOINEXISTENTE_H

#include <exception>

using namespace std;

class ExcepcionProductoInexistente : public exception
{
    public:
    ExcepcionProductoInexistente() noexcept = default;
    ~ExcepcionProductoInexistente() = default;

    virtual const char* what() const noexcept {
        return "El producto indicado no existe";
    }

};

#endif // EXCEPCIONPRODUCTOINEXISTENTE_H
