
program Project2;
 
{$APPTYPE CONSOLE}
 
uses
  SysUtils;
 
var
  n, x, i, l: integer;
  s: string;
  arr: array of integer;
 
begin
  assignfile(input, 'chess.in');
  assignfile(output, 'chess.out');
  readln(n);
  setlength(arr, n + 1);

  for i:= 1 to n do
    read(arr[i]);

  for i:= 2 to n do
    if (arr[i] < i) then
    begin
      l:= i-1;
      break;
    end;

  if l = 0 then inc(l);
  writeln (l);
  for i:= 1 to l do
    writeln (i, ' ', i);
end.
