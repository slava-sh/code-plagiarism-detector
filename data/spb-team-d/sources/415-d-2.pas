var
a:array [1..1000000000] of longint;
q,w,e,r,d,n,m,i,j:longint;
begin
  assign(input,'dunes.in');
  assign(output,'dunes.out');
  reset(input);
  rewrite(output);
  read (n,m);
  for i:= 1 to n do begin
    read(w,e,r);
    q:=1;
    for j:=w to e do begin
      a[j]:=a[j]+r;
      r:=-r;
    end;
  end;
  for i:= 1 to m do begin
    read(d);
    writeln (a[d]);
  end;
  close(input);
  close(output);
end.
     