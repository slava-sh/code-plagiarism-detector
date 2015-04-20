program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n,i,j,m, k:integer;
  a:array of integer;
begin
  assignfile(input, 'chess.in');
  assignfile(output, 'chess.out');
  k := 0;
  readln(n);
  setlength (a, n);
  for i:=1 to n do
  begin
    read(a[i]);
  end;
  for j:=1 to n do
  begin
    if j <= a[j] then k:=k + 1
    else break;

  end;
  writeln(k);
  for m:=1 to k do writeln(m, ' ',  m);

  close(input);
  close(output);

end.
