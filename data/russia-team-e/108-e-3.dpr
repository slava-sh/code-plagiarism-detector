program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  c : array[1..100] of integer;
  d : array[1..100, 100..99999] of boolean;
  i, j, n, o, x, m, first, second, q, k, k1, i1 : integer;
  s : string;
  z, r : boolean;

begin
  reset(input , 'numbers.in');
  rewrite(output, 'numbers.out');
  read(n);
  for i := 1 to n do
    for j := 100 to 99999 do
      d[i, j] := false;
  for i := 1 to n do begin
     read(o);
     c[i] := o;
     read(k);
     for j := 1 to k do begin
        read(x);
        d[i, x] := true;
     end;
  end;
  readln(m);
  for i := 1 to m do begin
    readln(s);
    z := true;
    for k := 1 to 3 do begin
      if (z) then begin
        first := 0;
        for k1 := 1 to k do begin
          first := first * 10 + (ord(s[k1]) - ord('0'));
        end;
        // Посчитали первую часть
        for j := 3 to 5 do begin
          second := 0;
          for k1 := 1 to j do begin
            second := (ord(s[k1 + k]) - ord('0')) + second * 10;
          end;
          // Посчитали вторую часть
          r := false;
          for k1 := 1 to n do begin
            if (c[k1] = first) then begin
              if (d[k1, second]) and (s[j + k + 1] <> '0') and (s[1] <> '0') and (s[k + 1] <> '0') then begin
                r := true;
                break;
              end;
            end;
          end;
          if (r) then begin
            z := false;
            write('+');
            write(first);
            write('(');
            write(second);
            write(')');
            k1 := 11 - k - j;
            if (k1 = 3) then begin
              for i1 := 9 to 11 do begin
                write(s[i1]);
              end;
            end;
            if (k1 = 4) then begin
              for i1 := 8 to 9 do begin
                write(s[i1]);
              end;
              write('-') ;
              write(s[10], s[11]);
            end;
            if (k1 = 5) then begin
              for i1 := 7 to 9 do begin
                write(s[i1]);
              end;
              write('-') ;
              write(s[10], s[11]);
            end;
            if (k1 = 6) then begin
              write(s[6], s[7]);
              write('-') ;
              write(s[8], s[9]);
              write('-') ;
              write(s[10], s[11]);
            end;
            if (k1 = 7) then begin
              write(s[5], s[6], s[7]);
              write('-') ;
              write(s[8], s[9]);
              write('-') ;
              write(s[10], s[11]);
            end;
            writeln;
          end;
        end;  
      end;
    end;
    if (z) then begin
      writeln('Incorrect');
    end;
  end;


end.
