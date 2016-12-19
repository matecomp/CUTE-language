>.< Cute language example code >.<
oiee PROGRAMINHA;

>.< variavelzinha global >.<
intinho seed;

>.< Funcaozinha que formata seu nominho e sobrenominhuuu  >.<
funcaozinha intinho pseudo_random()[:
	intinho aux;
	
	seed = (8253729 * seed + 2396403);

	aux = (seed % 32767 + 32767) % 32767;
	retorninho aux;
:]

inicinho[:
	
	seed = 5323;
	intinho i;
	i = pseudo_random();
	printinln(i);

:]finzinho
