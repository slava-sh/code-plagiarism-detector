

var i,j,n,r:longint;
    k:int64;
    m:array[1..300000] of longint;
    input,output:text;

begin
  assign(input,'che.in');
  assign(input,'che.out');
  reset(input);
  rewrite(output);
  readln(input,n,r);
  for i:=1 to n do
   read(input,m[i]);
  k:=0;
  for i:=1 to n-1 do
    begin
      j:=i+1;
      while (m[j]-m[i]<=r) and (j<=n) do Inc(j);
      Inc(k,n-j+1);
    end;
  writeln(output,k);
  close(input);
  close(output);
  end.
