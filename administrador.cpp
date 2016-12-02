#include "persona.h"
#include "administrador.h"

administrador::administrador(string pUsuario, string pCorreo, string pContrasena, int pTipo, string pFecha):persona(pUsuario, pCorreo, pContrasena, pTipo)
{
	fecha = pFecha;
}

administrador::~administrador()
{

}

void administrador::setFecha(string pFecha)
{
	fecha = pFecha;
}

string administrador::getFecha()
{
	return fecha;
}

void administrador::setTipo(int pTipo)
{
	persona::tipo = pTipo;
}

int administrador::getTipo()
{
	return persona::tipo;
}

string administrador::toString()
{
	stringstream ss;
	ss << "Administrador:"<<endl<<persona::toString()<<endl<<this->fecha<<endl;
	return ss.str();
}