#ifndef EXCEPCIONNOSEPUEDELEERARCHIVO_H
#define EXCEPCIONNOSEPUEDELEERARCHIVO_H

#include <exception>

using namespace std;

class ExcepcionNoSePuedeLeerArchivo : public exception
{
    public:
    ExcepcionNoSePuedeLeerArchivo() noexcept = default;
    ~ExcepcionNoSePuedeLeerArchivo() = default;

    virtual const char* what() const noexcept {
        return "Error al abrir el archivo";
    }

};

#endif // EXCEPCIONNOSEPUEDELEERARCHIVO_H
