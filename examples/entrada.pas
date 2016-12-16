HappyHour Main;

Rodada mdc(a,b : CopoInteiro) : CopoInteiro;
:)
  Sera (a < b) Que
    Result <- mdc(b,a)
  else
    Sera ( (a % b) equals 0 ) Que
      Result <- b
    else
      Result <- mdc(b,a % b);
:(;

Amigos
  a,b,c,d,i : CopoInteiro;
  res: CharPointerMelhorado;
  ans: CharPointerMelhorado[1000];
  aux: CharPointerMelhorado[1000];
:)
    ColocaNaConta ('Diga quantas repeticoes ');
    Quanto(a);
    i <- 0;
    BebaEnquanto( i < a ) 
    :)
            ColocaNaConta('Hello, world! ');
            ColocaEFechaAConta('Insira dois inteiros!');
            res <- 'Eh... ';
            Quanto(b);
            Quanto(c);
            d <- mdc(b,c);
            ColocaEFechaAConta(d) ;
            Sera d equals 1 Que
                res <- res + 'Primo entre eles'
            else
                res <- res + 'Tem divisor em comum';
            ColocaEFechaAConta(res);
            i <- i + 1;
    :(;
      ColocaNaConta( 'Deseja quantas strings deseja concatenar? ' );
      Quanto(b);
      i <-  0;
      aux <- '';
      BebaEnquanto( i < b)
      :)
        Quanto(ans);
        aux <- aux + ans;
    
        i <- i + 1; 
        :(;
     ans <- aux;
      ColocaEFechaAConta( ans );  
:(.
