#include "persona.h"
#include "supervisor.h"


supervisor::supervisor(string pUsuario, string pCorreo, string pContrasena, int pTipo, int pEntradas):persona(pUsuario, pCorreo, pContrasena, pTipo)
{
	entradas = pEntradas;
}

supervisor::~supervisor()
{

}

void supervisor::setEntradas(int pEntradas)
{
	entradas = pEntradas;
}

int supervisor::getEntradas()
{
	return entradas;
}

void supervisor::setTipo(int pTipo)
{
	persona::tipo = pTipo;
}

int supervisor::getTipo()
{
	return persona::tipo;
}

string supervisor::toString()
{
	stringstream ss;
	ss << persona::toString()<<endl<<this->entradas<<endl;
	return ss.str();
}