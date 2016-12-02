#pragma once
#include "persona.h"

class manager: public persona
{
	private:
		double sueldo;

	public:
		manager(string,string,string,int,double);
		~manager();
		void setSueldo(double);
		double getSueldo();
		virtual void setTipo(int);
		virtual int getTipo();
		virtual string toString();
};