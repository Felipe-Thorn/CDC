#include "perceptron.h"

//Initializes a neuron.
neuronio inicializa_neuronio(){
	neuronio n;

	n.wb = 0;			//All synapses of a neuron start with a value of 0.
	n.w1 = 0;
	n.w2 = 0;

	return n;			//Returns a new neuron.

}

//Initializes a individual (new test entry).
individuo inicializa_individuo(individuo i, int x, int y, int s){
	individuo aux;

	i.x = x;			//The inputs and the expected output are assigned to an individual.
	i.y = y;
	i.s_esperada = s;

	aux = i;

	return aux;			//Returns the new individual (input neuron.

}

//Calculates the sum of entries * synapses.
int calcula_net(individuo i, neuronio n){
	int net = (n.wb * bias) + (n.w1 * i.x) + (n.w2 * i.y);	//Make the summation.

	return net;			//Returns the summation.

}

//Calculates the output according to NET value.
int calcula_saida(neuronio n){
	if(n.net > 0)   return 1;	//The outputs are calculated using the ladder function.
	else			return 0;	//The output of the ladder function is binary (0 or 1).

}

//Calculating a new synapse for a neuron.
neuronio calcula_sinapse(individuo i, neuronio n, int saida){

	neuronio aux;

	i.erro = i.s_esperada - saida;	//Calculates the error with the output expected by the test 
									//according to its inputs minus the output obtained.

	printf("\nCalcula sinapse inicio:\tWb %d - W1 %d - W2 %d", n.wb, n.w1, n.w2);//Shows the neuron before it is updated.

	n.wb = n.wb + a * i.erro * bias;		//Updates the neuron from the error found and the input signals.
	n.w1 = n.w1 + a * i.erro * i.x;
	n.w2 = n.w2 + a * i.erro * i.y;

	aux = n;

	printf("\nCalcula sinapse fim:\tWb %d - W1 %d - W2 %d", n.wb, n.w1, n.w2);	//Shows the feedback result.

	return aux;			//Returns the new neuron with the new synapses.

}

//Updates neurons from received data until correct output is found.
void nova_epoca(individuo vet[4], neuronio n){

	int op = -1, saida, soma, aux, aux2, i, usado[4], ran, check;

	srand((unsigned)time(NULL));

	while(op != 0){//While the correct output was not found.

		printf("\n-----------------------------------------------");

		printf("\nNeuronio Época: wb = %d ---- w1 = %d ---- w2 = %d\n", n.wb, n.w1, n.w2);	//Shows the first neuron of the epoch.

		soma = 0;

		aux2 = 0;

		n.net = calcula_net(vet[0], n);	//Calculates the net for the first test.

		saida = calcula_saida(n);		//Calculates the output for the first net.

		for(i = 0; i < 4; i++) usado[i] = 0;	//For used to assist in choosing the order of the tests.

		while(aux2 < 4){//While the four individuals have not been tested.

			check = -1;

			while(check != 0){//While not finding an individual who has not yet been chosen.

				ran = rand() % 4;//Try to find a new test.

				if(usado[ran] == 0){//If the test was already done at this epoch.
					check = 0;
					i = ran;
					usado[ran] = 1;
				}

			}

			printf("\n\nEscolhido %d - Esperado %d - Obtido: %d", i+1, vet[i].s_esperada, saida);//Shows the chosen test, as expected
																								 //and the output found.
			n = calcula_sinapse(vet[i], n, saida);	//Updates the neuron.

			if(vet[i].s_esperada != saida) soma++; //Checks if every test has its expected result.

			printf("\nNET = %d SAÍDA = %d", n.net, saida);	//Shows the Net and its output.

			if(i != 3)n.net = calcula_net(vet[i+1], n);
			else      n.net = calcula_net(vet[0], n);

			saida = calcula_saida(n);			   //Calculates the next output.

			aux2++;

		}

		if(soma == 0) op = 0;

		printf("\n-----------------------------------------------");

		printf("\n\n");

	}

	op = -1;

	printf("\n--------------Checar-------------");

	int e1, e2, net;
	individuo in;

	while(op != 0){

		printf("\n1 - Novo teste\n0 - Sair\n");
		scanf("%d",& op);

		if(op != 0){
			printf("\nDigite Entrada 1 | Entrada 2\n");
			scanf("%d",& e1);
			scanf("%d",& e2);

		in = inicializa_individuo(in , e1, e2, 0);
		net = calcula_net(in, n);

		if(net > 0)  printf("\n1");
		else 		 printf("\n-1");
		}
		printf("\n");
	}


	return;			//Returns to main when it finds the correct synapses.

}
