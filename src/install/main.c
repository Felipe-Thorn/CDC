#include "perceptron.h"

int main(int argc,char *argv[]){
	individual vet[4];

	neuron  neu;

	int     e1, e2, s, op, i;

	for(i = 0; i < 4; i++){
		printf("Enter: X - Y - Output\n");

		scanf("%d",& e1);

		scanf("%d",& e2);

		scanf("%d",& s);

		vet[i] = initialize_individual(vet[i] , e1, e2, s);

	}

	neu = initialize_neuron();

	printf("\n---------Individuals---------");

	for(i = 0; i < 4; i++)
		printf("\nIndividual: %d X: %d Y: %d S: %d\n", i+1, vet[i].x, vet[i].y, vet[i].o_expected);

	new_epoch(vet, neu);

    exit(EXIT_SUCCESS);
}

