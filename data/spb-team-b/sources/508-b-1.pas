Var n, i, a, k:longint;
Begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  readln(n);
  k:=0;
  for i:=1 to n do
    begin
      read(a);
      if a>=i then
        begin
          inc(k);
        end
              else break;
    end;
  writeln(k);
  for i:=1 to k do writeln(i,' ',i);
  close(input);
  close(output);
End.