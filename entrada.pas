oiee PROGRAMINHA;

intinho X1[0..20][0..5];
intinho X2[0..20];
intinho P;
intinho i, j;
charzinho C1;
txtzinho S;

inicinho[:

	forzinho i = 0..20[:
		forzinho j = 0..5[:
			X1[i][j] = i*6 + j;
		:]
		X2[i] = i;
	:]

	X1[-21][5] = 15;

	forzinho i = 0..20[:
		forzinho j = 0..5[:
			printin(X1[i][j]);
			printin(' ');
		:]
		printinln('');
	:]
	printinln(P);

:]finzinho
