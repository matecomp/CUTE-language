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

funcaozinha dbzinho multiplica( dbzinho a[][], dbzinho b[][]
						, intinho lin_a, intinho col_a
						, intinho lin_b, intinho col_b
						, dbzinho c[][] )[:
	intinho i, j, k;
	forzinho i = 0..lin_a [:
		forzinho j = 0..col_b[:
			dbzinho aux1, aux2, auxf;
			auxf = 0.0;
			forzinho k = 0..col_a[:
				aux1 = a[i][k];
				aux2 = b[k][j];
				auxf = auxf + (aux1 * aux2);
			:]
			c[i][j] = auxf;
		:]
	:]
	retorninho 0.0;
:]

funcaozinha intinho print( dbzinho matriz[][], intinho lin, intinho col)[:
	intinho i, j;
	forzinho i = 0..lin [:
		forzinho j = 0..col [:
			printin(matriz[i][j]);
			printin(' ');
		:]
		printinln('');
	:]
	printinln('');
	retorninho 0;
:]

inicinho[:

	seed = 5323;
	intinho i, j, k;
    dbzinho a[0..2][0..3];
    dbzinho b[0..3][0..1];
    dbzinho c[0..2][0..1];
    dbzinho ret;
	
	intinho lin_a, lin_b, lin_c, col_a, col_b, col_c;
	lin_a = 2;
	col_a = 3;
	lin_b = 3;
	col_b = 1;
	lin_c = lin_a;
	col_c = col_b;

	forzinho i = 0..lin_a [:
		forzinho j = 0..col_a [:
			a[i][j] = 1.0 * (pseudo_random() % 10);
		:]
	:]

	forzinho i = 0..lin_b [:
		forzinho j = 0..col_b [:
			b[i][j] = 1.0 * (pseudo_random() % 10);
		:]
	:]

	ret = multiplica(a,b,lin_a,col_a,lin_b,col_b,c);
	
	i = print( c, lin_c, col_c );


:]finzinho
