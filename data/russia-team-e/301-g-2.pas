
uses Math;
var
   n, m: longint;
begin
  read(n, m);
  if (n = 1) or (m = 1) then
    writeln((max(n ,m) + 1) div 4)
  else
    if (n = 2) or (m = 2) then begin
      writeln(0);
    end
    else
      writeln(1);
end.           