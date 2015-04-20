uses math,crt;

var i,j,n,k,r:longint;
    m:array[1..300000] of longint;

begin
  assign(input,'che.in');
  assign(input,'che.out');
  reset(input);
  rewrite(output);
  readln(n,r);
  for i:=1 to n do
   read(m[i]);
  k:=0;
  for i:=1 to n do
    for j:=i+1 to n do
      if m[j]-m[i]>r then Inc(k);
  writeln(k);
  end.
