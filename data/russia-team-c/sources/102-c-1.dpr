program Project1;

{$APPTYPE CONSOLE}
{$M 10000000}
{$R+,Q+}

uses
  SysUtils, Math;

var
  v1, v2, n, tmp1, tmp2, i, ans: integer;
  len, d, p, max_from, d_not_v2, bad: array[0..300000] of integer;
  a: array[0..300000] of array of integer;
  vis: array[0..300000] of boolean;

function get_deeps(v, pre, deep: integer): integer;
var
  i: integer;
begin
  d[v] := deep;
  p[v] := pre;
  vis[v] := true;
  max_from[v] := d[v];
  for i := 1 to len[v] do
    if not vis[a[v][i]] then begin
      max_from[v] := max(max_from[v], get_deeps(a[v][i], v, deep + 1));
    end;
  result := max_from[v];
end;

procedure get_max_deep_not_v2(v, bad_boy: integer);
var
  i: integer;
begin
  bad[v] := bad_boy;

  d_not_v2[v] := 0;
  for i := 1 to len[v] do
    if (a[v][i] <> bad_boy) and (p[v] <> a[v][i]) then
      d_not_v2[v] := max(d_not_v2[v], max_from[a[v][i]] - d[v]);

  if p[v] <> v then
    get_max_deep_not_v2(p[v], v);
end;

procedure get_ans(v, now_v1_ans: integer);
begin
  now_v1_ans := max(now_v1_ans, d_not_v2[v] + d[v]);
  ans := max(ans, min(now_v1_ans, max(d[v2] - (d[v] + 1) + d_not_v2[bad[v]], max_from[v2] - d[v2])));
  if bad[v] <> 0 then
    get_ans(bad[v], now_v1_ans);
end;

begin
  reset(input, 'dwarfs.in');
  rewrite(output, 'dwarfs.out');

  readln(n);
  for i := 1 to n - 1 do begin
    readln(tmp1, tmp2);

    inc(len[tmp1]);
    if len[tmp1] > length(a[tmp1]) - 2 then
      setlength(a[tmp1], len[tmp1] * 2 + 2);
    a[tmp1][len[tmp1]] := tmp2;

    inc(len[tmp2]);
    if len[tmp2] > length(a[tmp2]) - 2 then
      setlength(a[tmp2], len[tmp2] * 2 + 2);
    a[tmp2][len[tmp2]] := tmp1;
  end;
  readln(v1, v2);

  get_deeps(v1, v1, 0);
  get_max_deep_not_v2(p[v2], v2);
  get_ans(v1, 0);

  writeln(ans + 1);
end.
