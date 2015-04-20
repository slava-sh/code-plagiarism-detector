Var n, m, i, j, s, b:longint;
    a:array[1..1000,1..3] of longint;
    c:array[1..1000] of longint;
Begin
  assign(input,'dunes.in');
  assign(output,'dunes.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to 3 do read(a[i,j]);
  for i:=1 to m do c[i]:=0;
  for i:=1 to m do
    begin
      read(b);
      for s:=1 to n do
        begin
          if (b>=a[s,1]) and (b<=a[s,2]) then if b mod 2=a[s,1] mod 2 then c[i]:=c[i]+a[s,3]
                                                                      else c[i]:=c[i]-a[s,3];
        end;
      writeln(c[i]);
    end;
  close(input);
  close(output);
End.