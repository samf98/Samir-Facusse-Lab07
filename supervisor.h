#include "persona.h"

class supervisor: public persona
{
	private:
		int entradas;

	public:
		supervisor(string,string,string,int,int);
		~supervisor();
		void setEntradas(int);
		int getEntradas();
		virtual void setTipo(int);
		virtual int getTipo();
		virtual string toString();
};