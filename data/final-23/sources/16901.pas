program signchange;

{$APPTYPE CONSOLE}

var mas :array[1..262143] of integer;
    n,i,c,h,r,k,m:integer;

procedure peresh(h,r: integer);
var j : integer;
begin
  mas[h + 131071] := r;
  j := h + 131071;
  if j mod 2 = 1 then
  begin
    mas[j div 2] := mas[j - 1] - mas[j];
    j := j div 2;
  end
  else
  begin
    mas[j div 2] := mas[j] - mas[j + 1];
    j := j div 2;
  end;
  while j <> 1 do
  begin
    if j mod 2 = 1  then
    begin
      mas[j div 2] := mas[j - 1] + mas[j];
      j := j div 2;
    end
    else
    begin
      mas[j div 2] := mas[j + 1] + mas[j];
      j := j div 2;
    end;
  end;
end;

function podsh(h,f:integer): integer;
var l,r,sum,j:integer;
begin
  sum := 0;
  l := h + 131071;
  r := f + 131071;
  if l mod 2 = 1 then
  begin                       {проверка первого эл-та}
    sum := sum + mas[l];
    inc(l);
  end;


  while r - l > 1 do               {подсчет суммы до длины отрезка 1 или 2}
  begin
    if l mod 2 = 1 then
    begin
      if h mod 2 = 0 then
      begin
        sum := sum - mas[l];
        inc(l);
      end
      else
      begin
        sum := sum + mas[l];
        inc(l);
      end;
    end;
    if r mod 2 = 0 then
    begin
      if h mod 2 = 0 then
      begin
        sum := sum - mas[r];
        dec(r);
      end
      else
      begin
        sum := sum + mas[r];
        dec(r);
      end;
    end;
    l := l div 2;
    r := r div 2;
  end;


  if r = l then                 {подсчет если длина 1}
  begin
    if r mod 2 = 0 then
    begin
      if h mod 2 = 0 then
      begin
        sum := sum - mas[r];
        dec(r);
      end
      else
      begin
        sum := sum + mas[r];
        dec(r);
      end;
    end
    else
    begin
      if h mod 2 = 0 then
      begin
        sum := sum - mas[l];
        inc(l);
      end
      else
      begin
        sum := sum + mas[l];
        inc(l);
      end;
    end;
  end

  else                  {подсчет если длина 2}
  begin
    if r mod 2 = 0 then      {подсчет если r и l концы разных отрезков}
    begin
      if h mod 2 = 0 then
      begin
        sum := sum - mas[r];
        dec(r);
        sum := sum - mas[l];
        inc(l);
      end
      else
      begin
        sum := sum + mas[r];
        dec(r);
        sum := sum + mas[l];
        inc(l);
      end;
    end

    else            {подсчет если l и h концы одного подотрезка }
    begin
      if h mod 2 = 0 then
        sum := sum - mas[r div 2]
      else
        sum := sum + mas[r div 2];
    end;
  end;
  podsh := sum;
end;

begin
  reset(input, 'signchange.in');
  rewrite(output, 'signchange.out');
  read(n);
  for i := 1 to n do
    read (mas[i + 131071]);
  if n mod 2 = 1 then inc(n);
  i := n + 131071;
  while i <> 131071 do
  begin
    mas[i div 2] := mas[i - 1] - mas[i] ;
    i := i - 2;
  end;
  while i <> 1 do
  begin
    mas[i div 2] := mas[i - 1] + mas[i] ;
    i := i - 2;
  end;
  read(m);
  for i := 1 to m do
  begin
    read(c,h,r);
    if c = 0 then peresh(h,r);
    if c = 1 then
    begin
      k := podsh(h,r);
      writeln(k);
    end;
  end;
end.
 