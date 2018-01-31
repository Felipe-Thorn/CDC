#include "perceptron.h"

//Initializes a neuron.

neuron initialize_neuron(){
	neuron n;

	n.wb = 0;			//All synapses of a neuron start with a value of 0.
	n.w1 = 0;
	n.w2 = 0;

	return n;			//Returns a new neuron.

}

//Initializes a individual (new test entry).
individual initialize_individual(individual i, int x, int y, int s){
	individual aux;

	i.x = x;			//The inputs and the expected output are assigned to an individual.
	i.y = y;
	i.o_expected = s;

	aux = i;

	return aux;			//Returns the new individual (input neuron.

}

//Calculates the sum of entries * synapses.
int calculates_net(individual i, neuron n){
	int net = (n.wb * bias) + (n.w1 * i.x) + (n.w2 * i.y);	//Make the summation.

	return net;	//Returns the summation.
	
}

//Calculates the output according to NET value.

int calculates_output(neuron n){

	if(n.net > 0)   return 1;	//The outputs are calculated using the ladder function.
	else			return 0;	//The output of the ladder function is binary (0 or 1).
	
}

//Calculating a new synapse for a neuron.
neuron calculates_sinapse(individual i, neuron n, int output){

	neuron aux;

	i.error = i.o_expected - output;	//Calculates the error with the output expected by the test 
									//according to its inputs minus the output obtained.

	printf("\nCalculates first sinapse:\tWb %d - W1 %d - W2 %d", n.wb, n.w1, n.w2);//Shows the neuron before it is updated.

	n.wb = n.wb + a * i.error * bias;		//Updates the neuron from the error found and the input signals.
	n.w1 = n.w1 + a * i.error * i.x;
	n.w2 = n.w2 + a * i.error * i.y;

	aux = n;

	printf("\nCalculates final sinapse:\tWb %d - W1 %d - W2 %d", n.wb, n.w1, n.w2);	//Shows the feedback result.

	return aux;			//Returns the new neuron with the new synapses.

}

//Updates neurons from received data until correct output is found.
void new_epoch(individual vet[4], neuron n){

	int op = -1, output, sum, aux, aux2, i, used[4], ran, check;

	srand((unsigned)time(NULL));

	while(op != 0){//While the correct output was not found.

		printf("\n-----------------------------------------------");

		printf("\nEpoch Neuron: wb = %d ---- w1 = %d ---- w2 = %d\n", n.wb, n.w1, n.w2);	//Shows the first neuron of the epoch.

		sum = 0;

		aux2 = 0;

		n.net = calculates_net(vet[0], n);	//Calculates the net for the first test.

                calculates_output(n);                   //Calculates the output for the first net.

		for(i = 0; i < 4; i++) used[i] = 0;	//For used to assist in choosing the order of the tests.

		while(aux2 < 4){//While the four individuals have not been tested.

			check = -1;

			while(check != 0){//While not finding an individual who has not yet been chosen.

				ran = rand() % 4;//Try to find a new test.

				if(used[ran] == 0){//If the test was already done at this epoch.
					check = 0;
					i = ran;
					used[ran] = 1;

				}

			}


			printf("\n\nChosen %d - Expected %d - Obtained: %d", i+1, vet[i].o_expected, output);//Shows the chosen test, as expected
																								 //and the output found.
            calculates_sinapse(vet[i], n, output);	//Updates the neuron.

			if(vet[i].o_expected != output) sum++; //Checks if every test has its expected result.

			printf("\nNET = %d OUTPUT = %d", n.net, output);	//Shows the Net and its output.

			if(i != 3)n.net = calculates_net(vet[i+1], n);
			else      n.net = calculates_net(vet[0], n);

			output = calculates_output(n);			   //Calculates the next output.

			aux2++;

		}

		if(sum == 0) op = 0;

		printf("\n-----------------------------------------------");

		printf("\n\n");

	}

	op = -1;

	printf("\n--------------Verify-------------");

	int e1, e2, net;
	individual in;

	while(op != 0){

		printf("\n1 - New Test\n0 - Exit\n");
		scanf("%d",& op);

		if(op != 0){
			printf("\nEntry 1 | Entry 2\n");
			scanf("%d",& e1);
			scanf("%d",& e2);

		in = initialize_individual(in , e1, e2, 0);
		net = calculates_net(in, n);

		if(net > 0)        printf("\n 1");
		else               printf("\n-1");

		}
		printf("\n");
	}


	return;			//Returns to main when it finds the correct synapses.

}
