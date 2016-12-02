#include "manager.h"
#include "persona.h"

manager::manager(string pUsuario, string pCorreo, string pContrasena, int pTipo, double pSueldo):persona(pUsuario, pCorreo, pContrasena, pTipo)
{
	sueldo = pSueldo;
}

manager::~manager()
{

}

void manager::setSueldo(double pSueldo)
{
	sueldo = pSueldo;
}

double manager::getSueldo()
{
	return sueldo;
}

void manager::setTipo(int pTipo)
{
	persona::tipo = pTipo;
}

int manager::getTipo()
{
	return persona::tipo;
}

string manager::toString()
{
	stringstream ss;
	ss << persona::toString()<<endl<<this->sueldo<<endl;
	return ss.str();
}
