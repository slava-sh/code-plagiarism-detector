program dunes;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type vector3 = record
l, r, x : Integer;
end;

var
  i, k, x, q, l, n, m, r, j : Integer;
  winds : array[1..1000] of vector3;
  interest, len : array[1..1000] of Integer;

begin
  reset(input, 'dunes.in');
  rewrite(output, 'dunes.out');

  Read(n, m);

  for i:=1 to n do
    Read(winds[i].l, winds[i].r, winds[i].x);
  for i:=1 to m do
    Read(interest[i]);

  for i:=1 to m do
  begin
    for j:=1 to n do
    begin
      if (interest[i] >= winds[j].l) and (interest[i] <= winds[j].r) then
        if (winds[j].l mod 2) = (interest[i] mod 2) then
          len[i]:=len[i] + winds[j].x
        else len[i]:=len[i] - winds[j].x;
    end;
  end;

  for i:=1 to m do
    WriteLn(len[i]);

  {for k:=1 to n do
  begin
    Read(l, r, x);
    for i:=l to r do
      a[i]:=a[i] + x;
  end;

  for k:=1 to m do
  begin
    ReadLn(q);
    WriteLn(a[q]);
  end;      }
  close(output);
end.
