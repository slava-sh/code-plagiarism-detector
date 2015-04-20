program problemA;

var t, n, j, a, b : int64;
    i, o : text;

begin
     assign(i,'abcd.in');
     assign(o,'abcd.out');
     reset(i);
     rewrite(o);
          readln(i, t);
          for j:=1 to t do
          begin
               readln(i, n);
               a:=n mod 100;
               b:=n div 100;
               if ((sqr(a)+sqr(b)) mod 7)=1 then writeln(o,'YES')
                                            else writeln(o,'NO');
          end;
     close(i);
     close(o);
end.
