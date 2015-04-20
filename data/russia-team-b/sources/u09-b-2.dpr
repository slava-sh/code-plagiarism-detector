program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i,j:integer;
  n,r,s,l:int64;
  d:array[0..300000] of int64;

begin
  assign(input,'che.in');
  reset(input);
  assign(output,'che.out');
  rewrite(output);
  read(n,r);
  s:=0;

  for i:=1 to n do
    read(d[i]);

  l:=d[1];

  for i:=2 to n do
  begin
    l:=l+d[i]-d[i-1];
    if l>r then
    
  begin

    for j:=i-1 downto 1 do
      if (d[i]-d[j])>r then

      begin
        s:=s+j;
        break;

      end;

  end;

  end;
  write(s);
end.
