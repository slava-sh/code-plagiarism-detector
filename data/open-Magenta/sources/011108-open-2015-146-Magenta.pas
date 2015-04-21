
var
  count:longint;
  ch:char;
  a:longint;

begin
 randomize;
 count:=0;
 If random(2) = 1 then
 begin
  a:=17;
 end
 else
 begin
  a:=7;
 end;
 ch:='N';
 While (ch='N') do
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
