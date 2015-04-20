program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,i,j,l:integer;
  r,c:int64;
  f:boolean;
  a:array[1..300000] of int64;
begin
  assign(input,'che.in');
  assign(output,'che.out');
  reset(input);
  rewrite(output);

  readln(n,r);
  for i:=1 to n do
    read(a[i]);
  l:=2;
  f:=true;
  for i:=1 to n do
    if f then
      for j:=l to n do
        begin
          if a[j]-a[i]>r then
            begin
              l:=j;
              c:=c+(n-j+1);
              f:=true;
              break;
            end
          else
            f:=false;
        end
    else
      break;
  write(c);
  close(input);
  close(output);
end.
