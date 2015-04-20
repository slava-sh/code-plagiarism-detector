var n,i,k,sum: longint;
del: real;
a:array[1..100000] of longint;
BEGIN
assign(input, 'merlin.in');
assign(output, 'merlin.out');
reset(input);
rewrite(output);
      readln(n);
      k:=0;
      sum:=0;
      for i:=1 to n do begin
          read(a[i]);
          sum:=sum+a[i];
      end;
      del:=sum/n;
      for i:=1 to n do
            if a[i]>del then k:=k+1;
            
writeln(k);

close(output);
close(input);
ENd.
