Var n, m, l, r, i, j:longint;
    g:byte;
    x:integer;
    a:array[1..100000000] of longint;
Begin
  assign(input,'dunes.in');
  assign(output,'dunes.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to 100000000 do a[i]:=0;
  for i:=1 to n do
    begin
      read(l,r,x);
      g:=l mod 2;
      for j:=l to r do
        begin
          if a[j] mod 2=g then a[j]:=a[j]+x
                          else a[j]:=a[j]-x;
        end;
    end;
  for i:=1 to m do
    begin
      read(j);
      if i mod 2 =0 then writeln(a[j])
                    else writeln(a[j]*(-1));
    end;
  close(input);
  close(output);
End.