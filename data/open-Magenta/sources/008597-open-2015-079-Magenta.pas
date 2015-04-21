var res:char;
begin
res := 'N';
while (res = 'N') do begin
      writeln('R');
      flush(output);
      readln(res);
end;
end.