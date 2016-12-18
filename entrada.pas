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
			ifinho ((i + j) % 2) == 0 [:
				X1[i][j] = 0;
			:]elsinho[:
				X1[i][j] = 1;
			:]
		:]
		X2[i] = i;
	:]

	forzinho i = 0..20[:
		forzinho j = 0..5[:
			printin(X1[i][j]);
			printin(' ');
		:]
		printinln(' ');
	:]

	txtzinho Mat;
	charzinho c;
	Mat = 'msjkhdsk';
	printinln(Mat);

:]finzinho
