program ee;

{$APPTYPE CONSOLE}     

uses
  SysUtils;
var
  count: array [1..100] of string;
  kol: array [1..100] of longint;
  reg: array [1..100, 1..100] of string;
  u, i, j, n, k, m, y, p: longint;
  c, s, help, q: string;
begin
  assign(input, 'numbers.in');
  reset(input);
  assign(output, 'numbers.out');
  rewrite(output);
  readln(n);
  for i := 1 to n do
  begin
    readln(c);
    u := pos(' ', c);
    q := copy(c, u + 1, length(c) - u);
    k := strtoint(q);
    delete(c, u, length(c) - u + 1);
    count[i] := c;
    kol[i] := k ;
    for j := 1 to k do
    begin
      readln(c);
      reg[i, j] := c;
    end;
  end;
  readln(m);
  for i := 1 to m do
  begin
    readln(s);
    p := 0;
    for j := 1 to n do
    begin
      help := copy(s, 1, length(count[j]));
      if (help = count[j]) and (p = 0) then
      begin
        for y := 1 to kol[j] do
        begin
          help := copy(s, length(count[j]) + 1, length(reg[j, y]));
          if (p = 0) and (help = reg[j, y]) and (length(s) - length(count[j]) - length(reg[j, y]) > 2) and (length(s) - length(count[j]) - length(reg[j, y]) < 8) then
          begin
            s := copy(s, length(count[j]) + length(reg[j, y]) + 1, length(s) - length(count[j]) - length(reg[j, y]));
            if s[1] = '0' then
            begin
              break;
            end;
            write('+', count[j], '(', reg[j, y], ')');
            if (length(s) = 3) then
            begin
              writeln(s);
            end;
            if (length(s) = 4) then
            begin
              writeln(s[1], s[2], '-', s[3], s[4]);
            end;
            if (length(s) = 5) then
            begin
              writeln(s[1], s[2], s[3], '-', s[4], s[5]);
            end;
            if (length(s) = 6) then
            begin
              writeln(s[1], s[2], '-', s[3], s[4], '-', s[5], s[6]);
            end;
            if (length(s) = 7) then
            begin
              writeln(s[1], s[2], s[3], '-', s[4], s[5], '-', s[6], s[7]);
            end;
            p := 1;
          end;
        end;
      end;
    end;
    if (p = 0) then writeln('Incorrect');
  end;




end.
