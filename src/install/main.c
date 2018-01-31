#include "perceptron.h"

int main(int argc,char *argv[]){
<<<<<<< HEAD
	individual vet[4];

	neuron  neu;

	int     e1, e2, s, op, i;

	for(i = 0; i < 4; i++){
		printf("Enter: X - Y - Output\n");
=======
	individuo vet[4];

	neuronio  neu;

	int		  e1, e2, s, op, i;

	for(i = 0; i < 4; i++){
		printf("Digite: X - Y - Saída\n");
>>>>>>> 2955222a4b3416cf3ea15889af8d493e868636c2

		scanf("%d",& e1);

		scanf("%d",& e2);

		scanf("%d",& s);

<<<<<<< HEAD
		vet[i] = initialize_individual(vet[i] , e1, e2, s);

	}

	neu = initialize_neuron();

	printf("\n---------Individuals---------");

	for(i = 0; i < 4; i++)
		printf("\nIndividual: %d X: %d Y: %d S: %d\n", i+1, vet[i].x, vet[i].y, vet[i].o_expected);

	new_epoch(vet, neu);
=======
		vet[i] = inicializa_individuo(vet[i] , e1, e2, s);

	}

	neu = inicializa_neuronio();

	printf("\n---------Individuos---------");

	for(i = 0; i < 4; i++)
		printf("\nIndividuo: %d X: %d Y: %d S: %d\n", i+1, vet[i].x, vet[i].y, vet[i].s_esperada);

	nova_epoca(vet, neu);
>>>>>>> 2955222a4b3416cf3ea15889af8d493e868636c2

    exit(EXIT_SUCCESS);
}
