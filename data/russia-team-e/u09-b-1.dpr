program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
i,n,r,k,j:integer;
d:array[1..300000] of int64;
begin
  Assign(input,'che.in');
  Reset(input);
  Assign(output,'che.out');
  rewrite(output);
  read(n,r); k:=0;
  for i:=1 to n do
  read(d[i]);
  
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (d[i]+r)<d[j] then k:=k+1;
      
   Write(k);
end.
