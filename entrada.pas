oiee PROGRAMINHA;

intinho X1[0..20][0..5];
intinho X2[0..20];

funcaozinha intinho MDC(intinho a, intinho b)[:
	retorninho a*b;
:]

inicinho[:
	
	intinho i;
	intinho j;
	
	forzinho i = 0..20[:
		forzinho j = 0..5[:
			X1[i][j] = i*6 + j;
		:]
		X2[i] = i;
	:]

	X1[20][5] = 15;

	forzinho i = 0..20[:
		forzinho j = 0..5[:
			printin(X1[i][j]);
			printin(' ');
		:]
		printinln('');
	:]

	i = MDC(80, 80);
	printinln(i);

:]finzinho
