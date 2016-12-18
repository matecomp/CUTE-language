>.< Cute language example code >.<
oiee PROGRAMINHA;

intinho X1[1..5][1..5];

funcaozinha intinho MDC(intinho ref-a, intinho ref-b)[:
    a = 5;
    b = 10;
	retorninho a*b;
:]

inicinho[:
	
	intinho i, j, result;
	i = 3;
	j = 3;

	result = MDC(i, j);

	printinln(i);
	printinln(j);



	ifinho i == 2 or i > 2 [:
		printinln('Ok');
	:] elsinho [:
		printinln('Not');
	:]

:]finzinho
