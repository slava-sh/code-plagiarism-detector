program p_E;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  s, w, cd, rcd, num, q: string;
  answer: array [1 .. 10001] of string;
  code: array [1 .. 1000] of longint;
  rcode: array[1 .. 1000, 0 .. 1000] of longint;
  n, m, i, j, z, k: longint;

begin
  reset(input, 'numbers.in');
  rewrite(output, 'numbers.out');
  readln(n);
  for i := 1 to n do begin
    readln(code[i], m);
    rcode[i, 0] := m;
    for j := 1 to m do
      readln(rcode[i, j]);
  end;

  readln(k);
  for i := 1 to k do begin
    readln(w);

    for j := 1 to n do begin
      if (answer[i] <> '') then
        break;
      s := w;
      cd := '';

      if (pos(inttostr(code[j]), s) = 1) then begin
        cd := '+' + inttostr(code[j]);
        delete(s, 1, length(inttostr(code[j])));
        rcd := '';
        q := s;

        for z := 1 to rcode[j, 0] do begin
          s := q;
          if (pos(inttostr(rcode[j, z]), s) = 1) then begin
            rcd := '(' + inttostr(rcode[j, z]) + ')';
            delete(s, 1, length(inttostr(rcode[j, z])));
            num := '';

            if (length(s) = 3) then
              num := s;
            if (length(s) = 4) then
              num := s[1] + s[2] + '-' + s[3] + s[4];
            if (length(s) = 5) then
              num := s[1] + s[2] + s[3] + '-' + s[4] + s[5];
            if (length(s) = 6) then
              num := s[1] + s[2] + '-' + s[3] + s[4] + '-' + s[5] + s[6];
            if (length(s) = 7) then
              num := s[1] + s[2] + s[3] + '-' + s[4] + s[5] + '-' + s[6] + s[7];

            if (num = '') or (num[1] = '0') then
              answer[i] := ''
            else begin
              answer[i] := cd + rcd + num;
              break;
            end;
          end;

          end;

      end;

    end;

  end;

  for i := 1 to k do
    if (answer[i] <> '') then
      writeln(answer[i])
    else
      writeln('Incorrect');
  close(input);
  close(output);
end.
