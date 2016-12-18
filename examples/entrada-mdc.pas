>.< Cute language example code >.<
oiee PROGRAMINHA;


>.< Funcaozinha que faz MDCs fofos >.<
funcaozinha intinho MDC(intinho a, intinho b)[:
	intinho saida;
    ifinho b == 0 [:
    	saida = a;
    :] elsinho [:
    	saida = MDC( b, a % b );
    :]
	retorninho saida;
:]

inicinho[:
	
	intinho a, b;
	printinln( 'Programinha MDC' );
	printinln( 'Digite o primeiro digitozinho:' );
	scanzin(a);
	printinln( 'Digite o segundo digitozinho:' );
	scanzin(b);

	printin( 'O MDC entre ');
	printin( a );
	printin(' e ' );
	printin( b );
	printin( ' é: ' );
	printinln( MDC(a,b) );

:]finzinho
