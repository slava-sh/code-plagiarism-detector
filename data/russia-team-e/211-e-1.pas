type pref = record
  code, num, str: string;
end;
  mas = array[1..10000] of pref;
  matr = array[1..100, 1..100] of string;
  mas2 = Array[1..100] of string;
var
  coun, num: mas2;
  codes: mas;
  a: matr;
  total, n, m, i, j, s, q: longint;
function createpref(s1, s2: string): pref;
begin
  createpref.code := s1;
  createpref.num := s2;
  createpref.str := s1 + s2;
end;
procedure add(var a: mas; p: pref);
begin
  inc(total);
  a[total] := p;
end;
procedure sort(var ar:mas; l,h:longint);
   var i,j, ran:longint;
    m: string;
    wsp: pref;
begin
   i := l;
   j := h;
   ran := random(j - i + 1) + i;
   m := ar[ran].str;
   repeat
        while ar[i].str < m do inc(i);
        while ar[j].str > m do dec(j);
        if i <= j then
                begin
                        wsp := ar[i];
                        ar[i] := ar[j];
                        ar[j] := wsp;
                        inc(i);
                        dec(j);
                end;
   until i > j;
   if l < j then sort(ar, l, j);
   if i < h then sort(ar, i, h);
end;
procedure split(s: string; key: longint);
begin
  write('+');
  write(codes[key].code);
  write('(');
  write(codes[key].num);
  write(')');
  delete(s, 1, length(codes[key].str));
  case length(s) of
    3: write(s);
    4: begin
      write(s[1], s[2]);
      write('-');
      write(s[3], s[4]);
    end;
    5: begin
      write(s[1], s[2], s[3]);
      write('-');
      write(s[4], s[5]);
    end;
    6: begin
      write(s[1], s[2]);
      write('-');
      write(s[3], s[4]);
      write('-');
      write(s[5], s[6]);
    end;
    7: begin
      write(s[1], s[2], s[3]);
      write('-');
      write(s[4], s[5]);
      write('-');
      write(s[6], s[7]);
    end;
  end;
  writeln;
end;
procedure bs(x: string);
var l, r, m, j: longint;
    cop: string;
begin
  l := 1;
  r := total + 1;
 { for j := 1 to total do begin
//   writeln(j);
   writeln(codes[j].str);
 end;}
//  writeln(12);
  while r - l > 1 do begin
    m := (l + r) div 2;
    cop := x;
    delete(cop, length(codes[m].str) + 1, length(x) - length(codes[m].str) + 1);
    if cop < codes[m].str then begin
   //   write('R');
      r := m;
    end
    else begin
 //     write('L');
      l := m;
    end;
  end;
  cop := x;
  delete(cop, length(codes[l].str) + 1, length(x) - length(codes[l].str) + 1);

  if (cop <> codes[l].str) or (x[length(cop) + 1] = '0') then writeln('Incorrect')
  else split(x, l);
end;
begin
 assign(input, 'numbers.in');
 assign(output, 'numbers.out');
 reset(input);
 rewrite(output);
  readln(n);
  for i := 1 to n do
    begin
      readln(s, m);
      str(s, coun[i]);
      for j := 1 to m do begin
        readln(a[i][j]);
        add(codes, createpref(coun[i], a[i, j]));
      end;
    end;
  sort(codes, 1, total);
  readln(q);
  for i := 1 to q do
        readln(num[i]);
  for i := 1 to q do
    bs(num[i]);
    close(input);
    close(output);
end.
