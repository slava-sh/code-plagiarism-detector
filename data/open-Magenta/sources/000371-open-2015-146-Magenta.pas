var
  i:longint;
  gcou:longint;
  order:longint;
  ch:char;

begin
 ch:='#';
 While (ch<>'Y') and (ch<>'E') do
 begin
   If order mod 2 = 0 then inc(gcou);
   i:=0;
   While (i<gcou) and (ch<>'Y') and (ch<>'E') do
   begin
    inc(i);
    case order of
     0:writeln('U');
     1:writeln('L');
     2:writeln('D');
     3:writeln('R');
    end;
    flush(output);
    readln(ch);
   end;
   order:=(order+1) mod 4;
 end;
end.
