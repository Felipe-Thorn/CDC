/*Perceptron
*Nome: Lucas Felipe Moreira Silva
*Matrícula: 201405021
*/

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

<<<<<<< HEAD
#define bias 1          //Entry b (wb).
#define a 	 1	//Learning rate.

//What makes an individual:
typedef struct individual{
	int x, y;			//Two caracteristic entries (e1, e2);
	int s_esperada;                 //A desired output.
	int error;		 	//An error field that receveis a failed output.

}individual;

//What makes a neuron:
typedef struct neuron{
	int wb, w1, w2;                 //Three sinapses (b, w1 e w2); coeficients in NET;
	int net;			//Net: summation of entries*sinapses. Net = wb*b + w1*e1 + w2*e2

}neuron;

individual initialize_individual(individual i, int x, int y, int s);

void new_epoch(individual vet[4], neuron n);

int calculates_net(individual i, neuron n);

int calculates_output(neuron n);

neuron calculates_sinapse(individual i, neuron n, int saida);

neuron initialize_neuron();
=======
#define bias 1	//Entrada de b (wb).
#define a 	 1	//Taxa de aprendizagem.

//Um indivíduo é composto de:
typedef struct individuo{
	int x, y;			//Duas entradas (e1, e2);
	int s_esperada; 	//Uma saída esperada dada as duas entradas.
	int erro;		 	//Um campo erro que recebe a saída desejada - saída.

}individuo;

//Um neurônio é composto de:
typedef struct neuronio{
	int wb, w1, w2; 	//Três sinapses (b, w1 e w2); coeficientes em NET;
	int net;			//Net: somatório de entradas*sinapses. Net = wb*b + w1*e1 + w2*e2

}neuronio;

individuo inicializa_individuo(individuo i, int x, int y, int s);

void nova_epoca(individuo vet[4], neuronio n);

int calcula_net(individuo i, neuronio n);

int calcula_saida(neuronio n);

neuronio calcula_sinapse(individuo i, neuronio n, int saida);

neuronio inicializa_neuronio();
>>>>>>> 2955222a4b3416cf3ea15889af8d493e868636c2

#endif







