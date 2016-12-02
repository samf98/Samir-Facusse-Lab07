#pragma once
#include "persona.h"

class intern: public persona
{
	private:
		int dias;

	public:
		intern(string,string,string,int,int);
		~intern();
		void setDias(int);
		int getDias();
		virtual void setTipo(int);
		virtual int getTipo();
		virtual string toString();
};