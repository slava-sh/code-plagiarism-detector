program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

  var
  a:array[1..200001] of integer;
  n,h,i,j,min,s,res:integer;

begin
  assignfile(input, 'seq.in');
  assignfile(output, 'seq.out');
  readln(n,h);
  for i:=1 to n do read(a[i]);

  min:=300000;

  for i:=1 to n do
  begin
    s:=0;
    res:=1;
    for j:=0 to h-1 do
    begin
      if a[i+j]>j+1 then begin res:=0; break end
      else s:=s+((j+1)-a[i+j])
    end;
    if res=1 then
      if s<min then min:=s;
  end;

  if min = 300000 then writeln(-1)
  else writeln(min) ;

  close (input);
  close (output);
end.
