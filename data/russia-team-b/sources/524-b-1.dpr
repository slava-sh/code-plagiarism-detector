program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,i,j:integer;
  r,c:int64;
  a:array[1..300000] of int64;
begin
  assign(input,'che.in');
  assign(output,'che.out');
  reset(input);
  rewrite(output);

  readln(n,r);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    for j:=i+1 to n do
      if a[j]-a[i]>r then
        begin
          c:=c+(n-j+1);
          break;
        end;
  write(c);
  close(input);
  close(output);
end.
 