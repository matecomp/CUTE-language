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
	forzinho i = 1..lin_a [:
		forzinho j = 1..col_b[:
			dbzinho aux1, aux2, auxf;
			c[i][j] = 0.0;
			forzinho k = 1..col_a[:
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			:]
		:]
	:]
	retorninho 0.0;
:]

funcaozinha intinho print( dbzinho matriz[][], intinho lin, intinho col)[:
	intinho i, j;
	forzinho i = 1..lin [:
		forzinho j = 1..col [:
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
    dbzinho a[1..3][1..4];
    dbzinho b[1..4][1..2];
    dbzinho c[1..3][1..2];

    intinho x1[0..4];
    intinho x2[2..6];

    dbzinho ret;
	
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

	ret = multiplica(a,b,lin_a,col_a,lin_b,col_b,c);
	
	i = print( c, lin_c, col_c );


:]finzinho
