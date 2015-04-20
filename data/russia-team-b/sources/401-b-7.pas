

var i,j,n,r:longint;
    k:int64;
    m:array[1..300000] of longint;

begin

 assign(input,'che.in');
 assign(output,'che.out');
 reset(input);
 rewrite(output);

  readln(n,r);
  for i:=1 to n do
   read(m[i]);
  k:=0;  j:=0;
  for i:=1 to n-1 do
      while j<n do
         begin
           Inc(j);
             if m[j]-m[i]>r then begin Inc(k,n-j+1); Dec(j); break; end;
         end;

  writeln(k);
  end.
