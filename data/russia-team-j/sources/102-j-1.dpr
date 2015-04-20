program Project2;

{$APPTYPE CONSOLE}
{$R+,Q+}
{$M 10000000}

uses
  SysUtils;

const
  dx : array[1..4] of integer = (1, 0, -1, 0);
  dy : array[1..4] of integer = (0, 1, 0, -1);
  ss : array[1..4] of string = ('EW', 'SN', 'WE', 'NS');

type
  node = record
    d : integer;
    s : string;
  end;

var
  vis : array[0..101, 0..101] of boolean;
  ans : array[0..101, 0..101] of node;
  l, a : array[0..101, 0..101] of integer;
  w, h, i, j, px, py, k, pk, mn, res, resall, x, y, n : integer;
  a1, a2 : node;
  anss : string;
  s : array[1..100] of string;


begin
  reset(input, 'travel.in');
  rewrite(output, 'travel.out');

  readln(w, h, n);
  for i := 1 to h do begin
    readln(s[i]);
    for j := 1 to w do begin
      if (s[i][j] = 'V') then begin
        x := j;
        y := i;
      end;
      if (s[i][j] = 'T') then
        a[i][j] := 1
      else
        a[i][j] := 0;
    end;
  end;
          /////////////////////////546546
  for i := y downto 1 do
    for j := x to w do
      if (i <> y) or (j <> x) then begin
        a1 := ans[i + 1][j];
        a2 := ans[i][j - 1];
        if (a1.d > a2.d) then begin
          ans[i][j].d := a1.d + a[i][j];
          ans[i][j].s := a1.s + 'N';
        end else begin
          ans[i][j].d := a2.d + a[i][j];
          ans[i][j].s := a2.s + 'E';
        end;
      end;

  for i := y to h do
    for j := x downto 1 do
      if (i <> y) or (j <> x) then begin
        a1 := ans[i - 1][j];
        a2 := ans[i][j + 1];
        if (a1.d > a2.d) then begin
          ans[i][j].d := a1.d + a[i][j];
          ans[i][j].s := a1.s + 'S';
        end else begin
          ans[i][j].d := a2.d + a[i][j];
          ans[i][j].s := a2.s + 'W';
        end;
      end;

  for i := y to h do
    for j := x to w do
      if (i <> y) or (j <> x) then begin
        a1 := ans[i - 1][j];
        a2 := ans[i][j - 1];
        if (a1.d > a2.d) then begin
          ans[i][j].d := a1.d + a[i][j];
          ans[i][j].s := a1.s + 'S';
        end else begin
          ans[i][j].d := a2.d + a[i][j];
          ans[i][j].s := a2.s + 'E';
        end;
      end;

  for i := y downto 1 do
    for j := x downto 1 do
      if (i <> y) or (j <> x) then begin
        a1 := ans[i + 1][j];
        a2 := ans[i][j + 1];
        if (a1.d > a2.d) then begin
          ans[i][j].d := a1.d + a[i][j];
          ans[i][j].s := a1.s + 'N';
        end else begin
          ans[i][j].d := a2.d + a[i][j];
          ans[i][j].s := a2.s + 'W';
        end;
      end;
          /////////////////////////546546

  for i := 1 to h do begin
    for j := 1 to w do begin
      l[i][j] := abs(x - i) + abs(y - j) - ans[i][j].d;
    end;
  end;

  mn := maxint;
  for i := 1 to h do begin
    for j := 1 to w do begin
      if (l[i][j] < mn) and (a[i][j] = 1) and (ans[i][j].d <= n) then begin
        mn := l[i][j];
        px := j;
        py := i;
      end;
    end;
  end;

  anss := ans[py][px].s;
  for i := 1 to n - ans[py][px].d do
    if (py > 1) and (a[py - 1][px] <> 1) then
      anss := anss + 'NS'
    else
    if (py < h) and (a[py + 1][px] <> 1) then
      anss := anss + 'SN'
    else
    if (px > 1) and (a[py][px - 1] <> 1) then
      anss := anss + 'WE'
    else
      if (a[py][px + 1] <> 1) then
        anss := anss + 'EW';

  resall := maxint;
  for i := 1 to h do begin
    for j := 1 to w do begin
      for k := 1 to 4 do begin
        if (a[i][j] = 1) and (a[i + dy[k]][j + dx[k]] = 1) then begin
          res := length(ans[i][j].s) + n - ans[i][j].d;
          if (resall > res) then begin
            resall := res;
            px := j;
            py := i;
            pk := k;
          end;
        end;
      end;
    end;
  end;

  if (length(anss) > resall) then begin
    anss := ans[py][px].s;
    for k := 1 to (n - ans[py][px].d) div 2 do
      anss := anss + ss[pk];
    if ((n - ans[py][px].d) mod 2 = 1) then
      anss := anss + ss[pk][1];
  end;

  writeln(anss);

end.
