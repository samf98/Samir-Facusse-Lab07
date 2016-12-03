#include <iostream>
#include "persona.h"
#include "administrador.h"
#include "manager.h"
#include "intern.h"
#include "supervisor.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int tipo_usuario;
	int pos;
	string text;

	string usuario;
	string contrasena;
	string correo;
	string fecha;
	int dias;
	int veces;
	double sueldo;

	int op = 0;
	persona* user;
	vector<persona*> usuarios;

	ifstream infile;
	infile.open("data.txt");
	int cont=1;
	while(!infile.eof())
	{
		getline(infile,text);
		switch(cont)
		{
			case 1:
			{
				usuario = text;
				break;
			}
			case 2:
			{
				correo = text;
				break;
			}
			case 3:
			{
				contrasena = text;
				break;
			}
			case 4:
			{
				if(text=="1")
				{
					tipo_usuario = 1;
				}
				else if(text == "2")
				{
					tipo_usuario = 2;
				}
				else if(text == "3")
				{
					tipo_usuario = 3;
				}
				else if(text == "4")
				{
					tipo_usuario = 4;
				}
				break;
			}
			case 5:
			{
				if(tipo_usuario == 1)
				{
					fecha = text;
					user = new administrador(usuario,correo,contrasena,1,fecha);
					usuarios.push_back(user);

				}
				else if(tipo_usuario == 2)
				{
					istringstream ss(text);
					ss >> sueldo;
					user = new manager(usuario,correo,contrasena,2,sueldo);
					usuarios.push_back(user);

				}
				else if(tipo_usuario == 3)
				{
					istringstream ss(text);
					ss >> dias;
					user = new intern(usuario,correo,contrasena,3,dias);
				}
				else if(tipo_usuario == 4)
				{
					istringstream ss(text);
					ss >> veces;
					user = new supervisor(usuario,correo,contrasena,4,veces);
				}

				break;
			}
		}
		if(cont < 5)
			cont++;
		else
			cont = 1;
	}
	infile.close();

	user = new administrador(usuario,correo,contrasena,1,fecha);

	usuarios.push_back(user);
	do
	{
		cout<<"1-Login"<<endl<<"2-Guardar en archivo"<<endl;
		cin>>op;

		switch(op)
		{
			case 1:
			{
				cout<<"Usuario: ";
				cin>>usuario;
				cout<<"Contraseña: ";
				cin>>contrasena;
				for (int i = 0; i < usuarios.size(); ++i)
				{
					if(usuarios.at(i)->getUsuario()==usuario && usuarios.at(i)->getContrasena()==contrasena)
					{
						tipo_usuario = usuarios.at(i)->getTipo();
						cout<<"Bienvenido "<<usuario<<" tipo "<<tipo_usuario<<endl;
						switch(tipo_usuario)
						{
							case 1:
							{
								cout<<"1-Ingresar nuevo usuario"<<endl<<"2-Borrar usuario existente"<<endl;
								cin>>op;
								if(op==1)
									{
										cout<<"Ingrese datos de nuevo usuario."<<endl;
										cout<<"Usuario: ";
										cin>>usuario;
										cout<<"Contraseña(tiene que tener 8 caracteres): ";
										cin>>contrasena;
										cout<<"Correo: ";
										cin>>correo;
										cout<<"Ingrese el tipo (2-Manager,3-Intern,4-Supervisor): ";
										cin>>tipo_usuario;
										if(contrasena.size()==8){
											switch(tipo_usuario)
											{
												case 2:
												{
													cout<<"Ingrese el sueldo: ";
													cin>>sueldo;
													if(sueldo>=0)
													{
														user = new manager(usuario,correo,contrasena,2,sueldo);
														usuarios.push_back(user);
													}
													else
														cout<<"Sueldo inválido."<<endl;
													break;
												}
											
												case 3:
												{
													cout<<"Ingrese el número de días que lleva trabajando: ";
													cin>>dias;
													if(dias>=0)
													{
														user = new intern(usuario,correo,contrasena,3,dias);
														usuarios.push_back(user);
													}
													else
														cout<<"Cantidad de días inválida."<<endl;
													break;
												}

												case 4:
												{
													cout<<"Ingrese las veces que ha entrado: ";
													cin>>veces;
													if(veces>=0)
													{
														user = new supervisor(usuario,correo,contrasena,4,veces);
														usuarios.push_back(user);
													}
													else
														cout<<"Cantidad de entradas inválida."<<endl;
													break;
												}

												default:
												{
													cout<<"Tipo inválido.";
													break;
												}
											}
										}
										else
										{
											cout<<"Contraseña inválida."<<endl;
										}
									}
									else if(op == 2)
										{
											cout<<"Ingrese la posición a eliminar: ";
											cin>>pos;
											if(pos>0&&pos<usuarios.size()){
												usuarios.erase(usuarios.begin()+pos);
											}
											else
												cout<<"Posición inválida."<<endl;
										}
										else if((op == 0) || (op != 1 && op == 2))
										{
											cout<<"Posición no es válida."<<endl;
										}
								break;
							}
							
							case 2:
							{
								cout<<"1-Ingresar nuevo usuario"<<endl<<"2-Borrar usuario existente"<<endl;
								cin>>op;
								cin>>pos;
								if(op==1)
									{
										cout<<"Ingrese datos de nuevo usuario."<<endl;
										cout<<"Usuario: ";
										cin>>usuario;
										cout<<"Contraseña(tiene que tener 8 caracteres): ";
										cin>>contrasena;
										cout<<"Correo: ";
										cin>>correo;
										cout<<"Ingrese el tipo (3-Intern,4-Supervisor): ";
										cin>>tipo_usuario;
										if(contrasena.size()==8){
											switch(tipo_usuario)
											{
											
												case 3:
												{
													cout<<"Ingrese el número de días que lleva trabajando: ";
													cin>>dias;
													if(dias>=0)
													{
														user = new intern(usuario,correo,contrasena,3,dias);
														usuarios.push_back(user);
													}
													else
														cout<<"Cantidad de días inválida."<<endl;
													break;
												}

												case 4:
												{
													cout<<"Ingrese las veces que ha entrado: ";
													cin>>veces;
													if(veces>=0)
													{
														user = new supervisor(usuario,correo,contrasena,4,veces);
														usuarios.push_back(user);
													}
													else
														cout<<"Cantidad de entradas inválida."<<endl;
													break;
												}

												default:
												{
													cout<<"Tipo inválido.";
													break;
												}
											}
										}
										else
										{
											cout<<"Contraseña inválida."<<endl;
										}
									}
									else if(op == 2)
										{
											cout<<"Ingrese la posición a eliminar: ";
											cin>>pos;
											if((pos>0&&pos<usuarios.size())&&(usuarios.at(i)->getTipo()!=0&&usuarios.at(i)->getTipo()!=1)){
												usuarios.erase(usuarios.begin()+pos);
											}
											else
												cout<<"Posición inválida."<<endl;
										}
										else if((op == 0) || (op != 1 && op == 2))
										{
											cout<<"Posición no es válida."<<endl;
										}
								break;
							}
							
							case 3:
							{
								cout<<"1-Ingresar nuevo usuario"<<endl<<"2-Borrar usuario existente"<<endl;
								cin>>op;
								cin>>pos;
								if(op==1)
									{
										cout<<"Ingrese datos de nuevo usuario."<<endl;
										cout<<"Usuario: ";
										cin>>usuario;
										cout<<"Contraseña(tiene que tener 8 caracteres): ";
										cin>>contrasena;
										cout<<"Correo: ";
										cin>>correo;
										tipo_usuario = 3;
										if(contrasena.size()==8){
											switch(tipo_usuario)
											{
											
												case 3:
												{
													cout<<"Ingrese el número de días que lleva trabajando: ";
													cin>>dias;
													if(dias>=0)
													{
														user = new intern(usuario,correo,contrasena,3,dias);
														usuarios.push_back(user);
													}
													else
														cout<<"Cantidad de días inválida."<<endl;
													break;
												}
											}
										}
										else
										{
											cout<<"Contraseña inválida."<<endl;
										}
									}
									else if(op == 2)
										{
											cout<<"Ingrese la posición a eliminar: ";
											cin>>pos;
											if((pos>0&&pos<usuarios.size())&&(usuarios.at(i)->getTipo()==3)){
												usuarios.erase(usuarios.begin()+pos);
											}
											else
												cout<<"Posición inválida."<<endl;
										}
										else if((op == 0) || (op != 1 && op == 2))
										{
											cout<<"Posición no es válida."<<endl;
										}
								break;
							}
							
							case 4:
							{
								cout<<"Presentando lista de usuarios..."<<endl;
								for (int i = 0; i < usuarios.size(); ++i)
								{
									text+=usuarios.at(i)->toString();
									text+="\n";
								}
								cout<<text;
								supervisor* supervisores = dynamic_cast<supervisor*>(usuarios.at(i));
								if(supervisores!=NULL)
								{
									supervisores->setEntradas(supervisores->getEntradas()+1);
								}
								break;
							}
						}	
					}
					else
					{
						cout<<"Usuario/Contraseña incorrecta"<<endl;
					}
				i = usuarios.size();
				}
				break;
			}

			case 2:
			{
				ofstream myfile;
				myfile.open("data.txt");
				text = "";
				for (int i = 0; i < usuarios.size(); ++i)
				{
					supervisor* supervisores = dynamic_cast<supervisor*>(usuarios.at(i));
					administrador* administradores = dynamic_cast<administrador*>(usuarios.at(i));
					manager* managers = dynamic_cast<manager*>(usuarios.at(i));
					intern* interns = dynamic_cast<intern*>(usuarios.at(i));
					
					if(supervisores!=NULL){
						text+=supervisores->toString();
					}
					else if(administradores!=NULL)
					{
						text+=administradores->toString();
					}
					else if(managers != NULL)
					{
						text+=managers->toString();
					}
					else if(interns != NULL)
					{
						text+=interns->toString();
					}
				}
				myfile << text;
				myfile.close();
				break;
			}
		}

		cout<<"Seguir?[0=Si||1=No] ";
		cin>>op;
	}while(op==0);

	for (int i = 0; i < usuarios.size(); ++i)
	{
		delete usuarios[i];
	}

	return 0;
}