>.< Cute language example code >.<
oiee PROGRAMINHA;


>.< Funcaozinha que formata seu nominho e sobrenominhuuu  >.<
funcaozinha intinho formata( txtzinho saida, txtzinho a, txtzinho b )[:
	ifinho a > b [:
		saida = 'Sr(a). ' + a + ' ' + b;
	:]elsinho[:
		saida = 'Mr(s). ' + b + ', ' + a;
	:]
	retorninho 0;
:]

inicinho[:
	
	txtzinho nome1;
	txtzinho nome2;
	txtzinho saida;

	intinho i;

	printin('Digite o seu nome: ');
	scanzin(nome1);

	printin('Digite o seu sobrenome: ');
	scanzin(nome2);

	printinln('');
	printin('Bom dia: ');
	i = formata(saida, nome1, nome2 );
	printinln(saida);
	printin('Bom dia: ');
	i = formata(saida, ' ' + nome1, nome2 );
	printinln(saida);
	printin('Bom dia: ');
	i = formata(saida, nome1, nome2 + ' ' );
	printinln(saida);

:]finzinho
