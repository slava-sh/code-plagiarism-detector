program III;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  key = 239017;
  base = 1000000009;

var
  h1, h2, st : array[0..200001] of int64;
   n, r, i, qwe, j, z : integer;
   s:string;

function get1(l, r : integer) : integer;
var
  res : int64;
begin
  res := (h1[r] - h1[l - 1] * st[r - l + 1] + base) mod base;
  result := res;
end;

function get2(l, r : integer) : integer;
var
  res : int64;
begin
  res := (h2[l] - h2[r + 1] * st[r - l + 1] + base) mod base;
  result := res;
end;

begin
  reset(input, 'inventory.in');
  rewrite(output, 'inventory.out');
  readln(n);
  st[0] := 1;
  for i := 1 to 200000 do
    st[i] := (st[i - 1] * key) mod base;
  for qwe := 1 to n do begin
    readln(s);
    r := length(s);
    s := s + s;
    for j := 1 to length(s) do begin
      h1[j] := (h1[j - 1] * key + ord(s[j])) mod base;
    end;
    h2[length(s) + 1] := 0;
    for j := length(s) downto 1 do begin
      h2[j] := (h2[j + 1] * key + ord(s[j])) mod base;
    end;
    z := -1;
    if odd(r) then begin
      for i := 1 to length(s) do begin
        if ((i + r div 2) <= length(s)) and ((i - r div 2) > 0) then
          if get1(i, i + r div 2) = get2(i - (r div 2), i) then begin
            z := (i - 1) mod r + 1;
            break;
          end;
      end;
    end else begin
      for i := 2 to length(s) do begin
        if ((i + r div 2 - 1) <= length(s)) and ((i - r div 2 - 1) > 0) then
          if get1(i, i + r div 2 - 1) = get2(i - r div 2, i - 1) then begin
            z := (i - 1) mod r + 1;
            break;
          end;
      end;
    end;
    if z <> -1 then begin
        if odd(r) then begin
          if z < (r + 1) div 2 then
            writeln((r + 1) div 2 + z - 1)
          else
            writeln(z - (r + 1) div 2);
        end else begin
          if z <= r div 2 then
            writeln(r div 2 + z - 1)
          else
            writeln(z - r div 2 - 1);
        end;
      end else writeln(-1);
  end;

end.
 