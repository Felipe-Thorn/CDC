/*Perceptron
*Nome: Lucas Felipe Moreira Silva
*Matrícula: 201405021
*/

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bias 1   //Entry b (wb).
#define a 	 1	//Learning rate.

//What makes an individual:
typedef struct individual{
	int x, y;			//Two caracteristic entries (e1, e2);
	int o_expected;		//A desired output.
	int error;		 	//An error field that receveis a failed output.

}individual;

//What makes a neuron:
typedef struct neuron{
	int wb, w1, w2;      //Three sinapses (b, w1 e w2); coeficients in NET;
	int net;			//Net: summation of entries*sinapses. Net = wb*b + w1*e1 + w2*e2

}neuron;

individual initialize_individual(individual i, int x, int y, int s);

void new_epoch(individual vet[4], neuron n);

int calculates_net(individual i, neuron n);

int calculates_output(neuron n);

neuron calculates_sinapse(individual i, neuron n, int saida);

neuron initialize_neuron();

#endif







