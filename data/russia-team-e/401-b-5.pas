

var i,j,n,r:longint;
    k:int64;
    m:array[1..300000] of longint;
    input,output:text;

begin
  assign(input,'che.in');
  assign(input,'che.out');
  reset(input);
  rewrite(output);
  readln(n,r);
  for i:=1 to n do
   read(m[i]);
  k:=0;
  for i:=1 to n-1 do
      for j:=i+1 to n do
        if m[j]-m[i]>r then begin Inc(k,n-j+1); break; end;
  writeln(k);
  end.
