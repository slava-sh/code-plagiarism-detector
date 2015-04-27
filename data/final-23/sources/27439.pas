program Solve;

{$APPTYPE CONSOLE}
{$O-}

uses
  Math;

const
  maxN = 262143;

var a:array[1..400010] of int64;
    i,n,m,c,l,r:longint;

procedure update(i,x:longint);
begin
  i := i + maxN;
  a[i] := x;
  while i > 1 do
  begin
    i := i div 2;
    a[i] := a[i * 2] + a[i * 2 + 1];
  end;
end;

function find(l,r:longint):longint;
begin
  Result := 0;
  inc(l,maxN);
  inc(r,maxN);
  while l <= r do
  begin
    if l and 1 = 1 then
    begin
      Result := Result + a[l];
      inc(l);
    end;
    if r and 1 = 0 then
    begin
      Result := Result + a[r];
      dec(r);
    end;
    l := l div 2;
    r := r div 2;
  end;
end;

begin
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');
  read(n);
  for i := 1 to n do
  begin
    read(c);
    if i and 1 = 0 then
      update(i,-c)
    else
      update(i,c);
  end;
  read(m);
  for i := 1 to m do
  begin
    read(c,l,r);
    if c = 0 then
      if l and 1 = 0 then
        update(l,-r)
      else
        update(l,r)
    else
      if l and 1 = 0 then
        writeln(-find(l,r))
      else
        writeln(find(l,r))
  end;
end.
 