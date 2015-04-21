
var
  count:longint;
  prost:array[1..10] of longint;
  ch:char;
  a:longint;
begin
 randomize;
 count:=0;
 a:=random(10) + 1;
 prost[1]:=7;
 prost[2]:=17;
 prost[3]:=5;
 prost[4]:=3;
 prost[5]:=29;
 prost[6]:=31;
 prost[7]:=11;
 prost[8]:=19;
 prost[9]:=71;
 prost[10]:=37;

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
   count:=count mod prost[a];
  end;
  flush(output);
  readln(ch);
 end;
end.
