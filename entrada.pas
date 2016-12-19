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
	intinho i, j, k;
    dbzinho a[1..3][1..4];
    dbzinho b[1..4][1..2];
    dbzinho c[1..3][1..2];
	
	intinho lin_a, lin_b, lin_c, col_a, col_b, col_c;
	lin_a = 3;
	col_a = 4;
	lin_b = 4;
	col_b = 2;
	lin_c = lin_a;
	col_c = col_b;

	forzinho i = 1..lin_a [:
		forzinho j = 1..col_a [:
			a[i][j] = 1.0 * (pseudo_random() % 10);
		:]
	:]

	forzinho i = 1..lin_b [:
		forzinho j = 1..col_b [:
			b[i][j] = 1.0 * (pseudo_random() % 10);
		:]
	:]

	forzinho i = 1..lin_a [:
		forzinho j = 1..col_a [:
			printin(a[i][j]);
			printin(' ');
		:]
		printinln('');
	:]
	printinln('');

	forzinho i = 1..lin_b [:
		forzinho j = 1..col_b [:
			printin(b[i][j]);
			printin(' ');
		:]
		printinln('');
	:]
	printinln('');

	dbzinho test[1..2];
	test[1] = 1.0;
	test[2] = 2.0;
	forzinho i = 1..lin_a [:
		forzinho j = 1..col_b[:
			dbzinho aux1, aux2, auxf;
			auxf = 0.0;
			forzinho k = 1..col_a[:
				aux1 = a[i][k];
				aux2 = b[k][j];
				auxf = auxf + aux1 * aux2;
			:]
			c[i][j] = auxf;
		:]
	:]
	
	forzinho i = 1..lin_c [:
		forzinho j = 1..col_c [:
			printin(c[i][j]);
			printin(' ');
		:]
		printinln('');
	:]
	printinln('');

:]finzinho
