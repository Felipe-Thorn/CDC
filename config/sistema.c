//sistema.h it's a  previously CMake configured header
#include "sistema.h"

int main(){

	//This T.A.D is defined in sistema.h
	struct system s;
	
	//Verifies the system ID
	if		(ID == 1)		s.nome = "Windows";
	else if	(ID == 2) 		s.nome = "Unix";
	
	//set-up the RAM of the system
	s.memo = RAM;

	//Prints system info
	printf("\nSystem: %s"
           "\nRAM Memory: %d"
           "\n", s.nome, s.memo);

}
