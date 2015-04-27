program inventory;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  p = 239;

var
  n, i, j, len: integer;
  s: string;
  pr, pri, st: array[0..1000000] of int64;
  f: boolean;

function revers(s: string): string;
var
  ans: string;
begin
  ans := '';
  for i := length(s) downto 1 do
    ans := ans + s[i];
  result := ans;
end;

function hash_pr(l, r: integer): int64;
begin
  result := pr[r] - pr[l - 1] * st[r - l + 1];
end;

function hash_pri(l, r: integer): int64;
begin
  result := pri[r] - pri[l - 1] * st[r - l + 1];
end;


begin
    reset(input,'inventory.in');
    rewrite(output,'inventory.out');

    readln(n);
    st[0] := 1;
    for i := 1 to 100000 do
      st[i] := st[i - 1] * p;

    for i := 1 to n do begin
      f := true;
      readln(s);
      len := length(s);
      s := s + s;
      pr[0] := 0;
      for j := 1 to length(s) do
        pr[j] := pr[j - 1] * p + ord(s[j]) - ord('a');
      s := revers(s);
      pri[0] := 0;
      for j := 1 to length(s) do
        pri[j] := pri[j - 1] * p + ord(s[j]) - ord('a');
      for j := 0 to len - 1 do
        if hash_pr(j + 1, j + len) = hash_pri(len - j + 1 ,len * 2 - j) then begin
          writeln(j);
          f := false;
          break;
        end;
      if f then
        writeln(-1);
    end;
end.
