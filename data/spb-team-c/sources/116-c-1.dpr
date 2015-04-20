program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, i, j, t, cen, col:integer;
  a:array of integer;
  c:array of integer;
  sum:array of integer;
  fin, fout : textfile;
begin
  assignfile(fin, 'conquest.in');
  reset(fin);
  assignfile(fout, 'conquest.out');
  rewrite(fout);
  readln(fin, n);
  setlength(a, n+1);
  setlength(c, n+1);
  for i:= 1 to n do
    read(fin, a[i], c[i]);
  for i := 1 to n-1 do
  begin
    for j:= 1 to n-1 do
    begin
      if (a[j]>a[j+1]) then
      begin
        t:=a[j];
        a[j]:=a[j+1];
        a[j+1]:= t;

        t:=c[j];
        c[j]:=c[j+1];
        c[j+1]:= t;
      end else
      if (a[j] = a[j+1])then
      begin
        if (c[j]>c[j+1]) then
        begin
          t:=a[j];
          a[j]:=a[j+1];
          a[j+1]:= t;

          t:=c[j];
          c[j]:=c[j+1];
          c[j+1]:= t;
        end ;
      end ;
    end ;
  end ;
  col:=0;
  cen:=0;
  setlength(sum, n+1);
  sum[1]:=0;
  for i:=2 to n do
    sum[i]:= sum[i-1] + a[i-1];
  for i:= n downto 2 do
  begin
    if (sum[i]<a[i]) then
    begin
      col:= col+ a[i] - sum[i];
      cen:= cen + (a[i] - sum[i])*c[i];
      a[i]:= a[i] - (a[i] - sum[i]);
    end ;
  end;
  cen:= cen + (a[1] - col + 1)*c[1];
  writeln(fout, cen);
  closefile(fin);
  closefile(fout);
end.
