#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class persona
{
	private:
		string usuario;
		string correo;
		string password;

	protected:
		int tipo;

	public:
		persona(string,string,string,int);
		~persona();
		void setUsuario(string);
		string getUsuario();
		void setCorreo(string);
		string getCorreo();
		void setContrasena(string);
		string getContrasena();
		virtual void setTipo(int);
		virtual int getTipo();
		virtual string toString();
};