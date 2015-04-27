program Project2;

{$APPTYPE CONSOLE}
{$R+}

uses
  SysUtils;

var f1, f2, f1d, f2d: array[0..100000]of integer;
    n, i, x, m, l, r{, p}: integer;

procedure update1(k, i: integer);
begin
  while i <= n do begin
    f1[i] := f1[i] + k;
    i := i or (i + 1);
  end;
end;

procedure update1_d(k, i: integer);
begin 
  update1(k - f1d[i], i);
  f1d[i] := k;
end;

function get1(i: integer): integer;
begin
  result := 0;
  while (i >= 0) do begin
    result := result + f1[i];
    i := i and (i + 1) - 1;
  end;
end;

function getSum1(l, r: integer): integer;
begin
  if l mod 2 = 0 then inc(l);
  if r mod 2 = 1 then inc(r);

  l := (l + 1) div 2;
  r := r div 2;

  result := get1(r) - get1(l - 1);
end; 

procedure update2(k, i: integer);
begin
  while i <= n do begin
    f2[i] := f2[i] + k;
    i := i or (i + 1);
  end;
end;

procedure update2_d(k, i: integer);
begin
  update2(k - f2d[i], i);
  f2d[i] := k;
end;

function get2(i: integer): integer;
begin
  result := 0;
  while (i >= 0) do begin
    result := result + f2[i];
    i := i and (i + 1) - 1;
  end;
end;

function getSum2(l, r: integer): integer;
begin
  if l mod 2 = 1 then inc(l);
  if r mod 2 = 1 then dec(r);
  l := l div 2;
  r := r div 2;

  result := get2(r) - get2(l - 1);
end;

begin
  reset(input, 'signchange.in');
  rewrite(output, 'signchange.out');

  read(n);
  for i := 1 to n do begin
    read(x);
    if i mod 2 = 0 then update2_d(x, i div 2)
    else update1_d(x, i div 2 + 1);
  end;

  read(m);
  for i := 1 to m do begin
    read(x, l, r);
    if x = 0 then begin
      if l mod 2 = 0 then update2_d(r, l div 2)
      else update1_d(r, l div 2 + 1);
    end else begin
   {   for p := 1 to n do
        if p mod 2 = 0 then write(getSum2(p, p), ' ')
        else write(getSum1(p, p), ' ');
      writeln; }
      if l mod 2 = 0 then writeln(getSum2(l, r) - getSum1(l, r))
      else writeln(getSum1(l, r) - getSum2(l, r));
    end;
  end;
end.
 