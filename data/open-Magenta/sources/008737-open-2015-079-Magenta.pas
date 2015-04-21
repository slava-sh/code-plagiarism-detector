var res:char;
     a:array[0..4] of char;
begin
randomize;
res := 'N';
a[0] := 'R';
a[1] := 'L';
a[2] := 'D';
a[3] := 'U';
while (res = 'N') do begin
      writeln(a[random(4)]);
      flush(output);
      readln(res);
end;
end.