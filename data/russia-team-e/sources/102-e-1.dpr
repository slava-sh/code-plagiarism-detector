program Project2;

{$APPTYPE CONSOLE}
{$R+,Q+}

uses
  SysUtils;

var
  i, j, q, e, resti, n, m, country, t: integer;
  s, rest: string;
  c, cc, k: array[0..10000] of integer;
  r: array[0..1000, 0..1000] of integer;
  have: array[0..99999, 1..100] of boolean;

function gettel(s: string): string;
begin
  if length(s) = 3 then result := s;
  if length(s) = 4 then result := copy(s, 1, 2) + '-' + copy(s, 3, 2);
  if length(s) = 5 then result := copy(s, 1, 3) + '-' + copy(s, 4, 2);
  if length(s) = 6 then result := copy(s, 1, 2) + '-' + copy(s, 3, 2) + '-' + copy(s, 5, 2);
  if length(s) = 7 then result := copy(s, 1, 3) + '-' + copy(s, 4, 2) + '-' + copy(s, 6, 2);
end;

begin
  reset(input, 'numbers.in');
  rewrite(output, 'numbers.out');

  readln(n);
  for i := 1 to n do begin
    readln(c[i], k[i]);
    cc[c[i]] := i;
    for j := 1 to k[i] do begin
      readln(r[i][j]);
      have[r[i][j]][i] := true;
    end;
  end;

  readln(m);
  for i := 1 to m do begin
    readln(s);
    if s[1] = '0' then begin
      writeln('Incorrect');
      continue;
    end;

    q := -1;
    e := -1;
    for j := 1 to 3 do begin
      country := cc[strtoint(copy(s, 1, j))];
      rest := copy(s, j + 1, length(s) - j);
      if rest[1] = '0' then continue;
      if country = 0 then continue;
      for t := 3 to 5 do begin
        resti := strtoint(copy(s, j + 1, t));
        if not have[resti][country] then continue;
        if s[t + j + 1] = '0' then continue;
        e := t;
        q := j;
      end;
    end;
    
    if q = -1 then begin
      writeln('Incorrect');
      continue;
    end;

    write('+');
    write(copy(s, 1, q));
    write('(');
    write(copy(s, q + 1, e));
    write(')');
    write(gettel(copy(s, q + e + 1, length(s) - q - e)));
    writeln;
  end;
end. 
