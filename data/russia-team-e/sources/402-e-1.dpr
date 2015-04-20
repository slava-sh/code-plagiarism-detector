program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  country, opkol: array[1..100] of integer;
  op: array[1..100, 1..100] of integer;
  n, i, m, j, k: integer;
  bool: boolean;
  s: string;

procedure print(var s: string; n, m: integer);
var
  l, k: integer;
begin
  if s[n + m + 1] = '0' then
    exit;
    
  bool := true;
  write('+');

  for l := 1 to n do
    write(s[l]);

  write('(');

  for l := 1 to m do
    write(s[n + l]);

  write(')');

  k := length(s) - n - m;

  if k = 3 then
    write(s[n + m + 1] + s[n + m + 2] + s[n + m + 3]);

  if k = 4 then
    write(s[n + m + 1] + s[n + m + 2] + '-' + s[n + m + 3] + s[n + m + 4]);

  if k = 5 then
    write(s[n + m + 1] + s[n + m + 2] + s[n + m + 3] + '-' + s[n + m + 4] + s[n + m + 5]);

  if k = 6 then
    write(s[n + m + 1] + s[n + m + 2] + '-' + s[n + m + 3] + s[n + m + 4] + '-' + s[n + m + 5] + s[n + m + 6]);

  if k = 7 then
    write(s[n + m + 1] + s[n + m + 2] + s[n + m + 3] + '-' + s[n + m + 4] + s[n + m + 5] + '-' + s[n + m + 6] + s[n + m + 7]);

  writeln;
end;

begin
  reset(input, 'numbers.in');
  rewrite(output, 'numbers.out');
  readln(n);

  for i := 1 to n do
  begin
    readln(country[i], opkol[i]);

    for j := 1 to opkol[i] do
      readln(op[i, j]);
  end;

  readln(m);

  for i := 1 to m do
  begin
    readln(s);
    bool := false;

    if s[1] <> '0' then
    for j := 1 to n do
    begin
      if country[j] < 10 then
        if (strtoint(s[1]) = country[j]) then
          if s[2] <> '0' then
          for k := 1 to opkol[j] do
          begin
            if op[j, k] < 1000 then
              if strtoint(s[2] + s[3] + s[4]) = op[j, k] then
                print(s, 1, 3);

            if op[j, k] < 10000 then
              if strtoint(s[2] + s[3] + s[4] + s[5]) = op[j, k] then
                print(s, 1, 4);

            if op[j, k] < 100000 then
              if strtoint(s[2] + s[3] + s[4] + s[5] + s[6]) = op[j, k] then
                print(s, 1, 5);
          end;

      if country[j] < 100 then
        if strtoint(s[1] + s[2]) = country[j] then
          if s[3] <> '0' then
          for k := 1 to opkol[j] do
          begin
            if op[j, k] < 1000 then
              if strtoint(s[3] + s[4] + s[5]) = op[j, k] then
                print(s, 2, 3);

            if op[j, k] < 10000 then
              if strtoint(s[3] + s[4] + s[5] + s[6]) = op[j, k] then
                print(s, 2, 4);

            if op[j, k] < 100000 then
              if strtoint(s[3] + s[4] + s[5] + s[6] + s[7]) = op[j, k] then
                print(s, 2, 5);
          end;

      if country[j] < 1000 then
        if strtoint(s[1] + s[2] + s[3]) = country[j] then
          if s[4] <> '0' then
          for k := 1 to opkol[j] do
          begin
            if op[j, k] < 1000 then
              if strtoint(s[4] + s[5] + s[6]) = op[j, k] then
                print(s, 3, 3);

            if op[j, k] < 10000 then
              if strtoint(s[4] + s[5] + s[6] + s[7]) = op[j, k] then
                print(s, 3, 4);

            if op[j, k] < 100000 then
              if strtoint(s[4] + s[5] + s[6] + s[7] + s[8]) = op[j, k] then
                print(s, 3, 5);
          end;
    end;

    if not bool then
        writeln('Incorrect');
  end;
end.
