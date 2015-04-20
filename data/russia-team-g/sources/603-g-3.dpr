{$R-,S-,Q-,I-,O+}
{$M 32000000}

{$APPTYPE CONSOLE}

uses Math;
const
  maxn = round(1e5) + 200;
  inf = round(1e9);
  md = inf + 7;
var
   n, m : longint;
begin
  reset(input, 'prizes.in');
  rewrite(output, 'prizes.out');
  readln(n, m);
  if n = 1 then
  begin
    writeln((m + 1) div 4);
    halt; 
  end;
  if m = 1 then
  begin
    writeln((n + 1) div 4);
    halt;
  end;
  if min(n, m) = 2 then writeln(0)
                   else writeln(1);
end.
