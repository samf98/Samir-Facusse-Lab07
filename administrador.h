#pragma once
#include "persona.h"

class administrador: public persona
{
	private:
		string fecha;

	public:
		administrador(string,string,string,int,string);
		~administrador();
		void setFecha(string);
		string getFecha();
		virtual void setTipo(int);
		virtual int getTipo();
		virtual string toString();
};