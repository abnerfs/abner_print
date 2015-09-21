#ifndef ABMSG_H_
#define ABMSG_H_

#include <string>
#include "windows.h"
#include "stdio.h"


/**Emprime uma string de forma especial
	@param msg		A mensagem a ser emprimida.
	@param times 	Quantas vezes cada linha será repetida
	@param delay	O intervalo de milisegundos entre uma linha e outra */
	
void abner_print(std::string msg, int times=5, int delay=100)
{
	char temp[1024];
	sprintf(temp, "");

	for(int i = 0; i < msg.size();i++)
	{
		sprintf (temp, "%s%c", temp, msg[i]);
		if(!isspace(msg[i]))
		{
			if(i == msg.size()-1)
				times *= 2; //Repeti a ultima linha o dobro de vezes.
			for(int j = 0;j < times; j++)
			{	
				std::cout << temp << std::endl;
				Sleep(delay);
			}
	    }
	}
}

/**Emprime uma string de forma especial e pisca a tela
	@param msg		A mensagem a ser emprimida.
	@param times 	Quantas vezes cada linha será repetida
	@param delay	O intervalo de milisegundos entre uma linha e outra 
	@param cor1 	Primeira cor do cmd (Para o efeito pisca-pisca).
	@param cor2 	Segunda cor do cmd (Para o efeito pisca-pisca).*/
	
void abner_print_color(std::string msg, int times=5, int delay=100, const char* cor1="07", const char* cor2="70")
{
	char temp[1024];
	sprintf(temp, "");

	for(int i = 0; i < msg.size();i++)
	{
		sprintf (temp, "%s%c", temp, msg[i]);
		if(!isspace(msg[i]))
		{
			if(i == msg.size()-1)
				times *= 2; //Repeti a ultima linha o dobro de vezes.
			for(int j = 0;j < times; j++)
			{	
				char cor[100];
				
				if(j % 2 == 0)
				{
					sprintf(cor, "color %s", cor1);
				}	
				else
				{
					sprintf(cor, "color %s", cor2);
				}
				
				system(cor);
				std::cout << temp << std::endl;
				Sleep(delay);
			}
	    }
	}
}

#endif
