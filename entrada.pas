>.< Cute language example code >.<
oiee PROGRAMINHA;

inicinho[:

	intinho i;
    intinho matriz_1[1..3];
    intinho matriz_2[1..3];

	intinho lin_a, lin_b;
	lin_a = 3;
	lin_b = 3;

	forzinho i = 1..lin_a [:
		matriz_1[i] = 1;
	:]

	forzinho i = 1..lin_b [:
		matriz_2[i] = 1;
	:]

	matriz_2[1] = 15;

	ifinho matriz_1 == matriz_2 [:
		printinln('Okayy!!');
	:]

	ifinho matriz_1 != matriz_2 [:
		printinln('Dammn!!');
	:]


:]finzinho