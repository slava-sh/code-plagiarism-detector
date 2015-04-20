var
  n,m,k,q,i,j: longint;
  a:array[1..1000,1..3] of longint;
begin
  assign(input, 'dunes.in');
  assign(output, 'dunes.out');
  reset(input);
  rewrite(output);
  read(n,m);
  for i:=1 to n do read( a[i,1], a[i,2], a[i,3]);
  for i:=1 to m do
  begin
    read(q);
    k:=0;
    for j:=1 to n do
    begin
     if (q<= a[j,2]) and (q>=a[j,1]) then k:=k + a[j,3]*(1-2*((q-a[j,1]) mod 2));
    end;
    writeln(k);
   end;


  close(input);
  close(output);
end.
