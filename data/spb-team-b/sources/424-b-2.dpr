program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, x, i, l: integer;
  s: string;
  arr: array of integer;

begin
  //assignfile(input, 'chess.in');
  //assignfile(output, 'chess.out');
  readln(n);
  setlength(arr, n + 1);

  for i:= 1 to n do
  begin
    read(arr[i]);

    if i >= arr[i] then
    begin
      if i = arr[i] then
        l:= i
      else
        l:= i - 1;
      break;
    end;
  end;

  if l > 0 then
  begin
    writeln(l);
    for i:= 1 to l do
      writeln(i, ' ', i);
  end
  else
  begin
    writeln(1);
    writeln(1, ' ', 1);
  end;
end.
