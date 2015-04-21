const
  a=17;
var
  count:longint;
  ch:char;
begin
 count:=0;
 While (ch<>'Y') and (ch<>'E') do
 begin
  If count<a Then
  begin
   writeln('U');
   count:=count+1;
  end
  else
  begin
   writeln('R');
   count:=count mod a;
  end;
  flush(output);
  readln(ch);
 end;
end.
