#include "persona.h"

persona::persona(string pUsuario, string pCorreo, string pContrasena, int pTipo)
{
	usuario = pUsuario;
	correo = pCorreo;
	password = pContrasena;
	tipo = pTipo;
}

persona::~persona()
{

}

void persona::setUsuario(string pUsuario)
{
	usuario = pUsuario;
}

string persona::getUsuario()
{
	return usuario;
}

void persona::setCorreo(string pCorreo)
{
	correo = pCorreo;
}

string persona::getCorreo()
{
	return correo;
}

void persona::setContrasena(string pContrasena)
{
	password = pContrasena;
}

string persona::getContrasena()
{
	return password;
}

string persona::toString()
{
	stringstream ss;
	ss << this->usuario<<endl<<this->correo<<this->password<<endl<<this->tipo<<endl;
}

