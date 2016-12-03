#include "persona.h"
#include "intern.h"

intern::intern(string pUsuario, string pCorreo, string pContrasena, int pTipo, int pDias):persona(pUsuario, pCorreo, pContrasena, pTipo)
{
	dias = pDias;
}

intern::~intern()
{

}

void intern::setDias(int pDias)
{
	dias = pDias;
}

int intern::getDias()
{
	return dias;
}

void intern::setTipo(int pTipo)
{
	persona::tipo = pTipo;
}

int intern::getTipo()
{
	return persona::tipo;
}

string intern::toString()
{
	stringstream ss;
	ss << persona::toString()<<this->dias<<endl;
	return ss.str();
}