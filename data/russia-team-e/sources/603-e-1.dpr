{$R-,S-,Q-,I-,O+}
{$M 32000000}

{$APPTYPE CONSOLE}

uses Math;
const
  maxn = round(1e5) + 200;
  inf = round(1e9);
  md = inf + 7;
type
   node = record
            next : array [0..9] of longint;
            leaf : boolean;
          end;  
var
    n, i, j, m, country, town, len, v : longint;
    bor : array [0..1111] of array of node;
    c, k : array [1..111] of longint;
    s : string;
    num : array [1..20] of longint;
    ans : array [1..2] of longint;

  procedure Add(id, x : longint);
  var
    v, i, len : longint;
    a : array [1..6] of longint;
  begin
    v := 0; len := 0;
    while x > 0 do
    begin
      inc(len);
      a[len] := x mod 10;
      x := x div 10;
    end;
    for i := 1 to len div 2 do
    begin
      x := a[i]; a[i] := a[len - i + 1]; a[len - i + 1] := x;
    end;
    for i := 1 to len do
    if bor[id][v].next[a[i]] = -1 then
    begin
      bor[id][v].next[a[i]] := length(bor[id]);
      setlength(bor[id], length(bor[id]) + 1);
      fillchar(bor[id][length(bor[id]) - 1].next, sizeof(bor[id][length(bor[id]) - 1].next), -1);
      bor[id][length(bor[id]) - 1].leaf := false;
      v := bor[id][v].next[a[i]];
    end
    else
    v := bor[id][v].next[a[i]];

    bor[id][v].leaf := true;
  end;

  function go(id, v, c : longint) : longint;
  begin
    if (v = -1) or (length(bor[id]) = 0) then go := -1
                                         else go := bor[id][v].next[c];
  end;

  function GetAns(x, y : longint; s : string) : string;
  var
    i, j : longint;
    answer : string;
  begin
    answer := '+';
    for i := 1 to x do answer := answer + s[i];
    answer := answer + '(';
    for i := x + 1 to x + y do answer := answer + s[i];
    answer := answer + ')';
    if odd(length(s) - x - y) then
    begin
      if s[x + y + 1] = '0' then
      begin
        GetAns := 'Incorrect';
        exit;
      end;
      for i := x + y + 1 to x + y + 3 do answer := answer + s[i];
      j := x + y + 4;
    end
    else
    begin
      if s[x + y + 1] = '0' then
      begin
        GetAns := 'Incorrect';
        exit;
      end;
      for i := x + y + 1 to x + y + 2 do answer := answer + s[i];
      j := x + y + 3;
    end;  
    while j < length(s) do
    begin
      answer := answer + '-';
      for i := j to j + 1 do answer := answer + s[i];
      inc(j, 2);
    end;
    GetAns := answer;
  end;

begin
  reset(input, 'numbers.in');
  rewrite(output, 'numbers.out');
  randomize;
  readln(n);
  for i := 1 to n do
  begin
    readln(c[i], k[i]);
    if length(bor[c[i]]) = 0 then
    begin
      setlength(bor[c[i]], 1);
      fillchar(bor[c[i]][0].next, sizeof(bor[c[i]][0].next), -1);
      bor[c[i]][0].leaf := false; 
    end;
    for j := 0 to k[i] - 1 do
    begin
      readln(town);
      Add(c[i], town);
    end;  
  end;
  readln(m);
  for i := 1 to m do
  begin
    readln(s);
    ans[1] := -1; ans[2] := -1;
    for len := 1 to 11 do num[len] := ord(s[len]) - ord('0');
    country := 0;
    for len := 1 to 3 do
    begin
      country := country * 10 + num[len];
      v := 0;
      for j := 1 to 2 do v := go(country, v, num[len + j]);
      for j := 3 to 5 do
      begin
        v := go(country, v, num[len + j]);
        if v = -1 then break;
        if bor[country][v].leaf then
        begin
          ans[1] :=  len;
          ans[2] := j;
          break;
        end;
      end;
      if ans[1] <> -1 then break;
    end;

    if ans[1] <> -1 then writeln(GetAns(ans[1], ans[2], s))
                    else writeln('Incorrect');
  end;
end.
