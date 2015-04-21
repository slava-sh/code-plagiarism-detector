var
  postr:array[1..5000] of longint;
  pos:array[1..5000] of longint;
  table:array[1..5000,1..5000] of longint;
  i,j,k,n:longint;
  delta,tmp:longint;
  ans:longint;
  p1,p2:longint;

begin
 read(n);
 For i:=1 to n do
 begin
   read(postr[i]);
 end;
 p1:=-1;
 p2:=-1;
 For i:=n-1 downto 1 do
 begin
   For j:=1 to n do
   begin
    table[i,j]:=table[i+1,j];
    If postr[i+1]<j Then inc(table[i,j]);
   end;
 end;
 For i:=1 to n do
 begin
  ans:=ans+table[i,postr[i]];
  pos[postr[i]]:=i;
 end;
 delta:=0;
 For i:=1 to n do
 begin
  For j:=i+1 to n do
  begin
   tmp:=table[j,postr[i]]-table[i,postr[i]]+table[i,postr[j]]-table[j,postr[j]];
   If postr[j]<postr[i] Then dec(tmp);
   If tmp<delta Then
   begin
    delta:=tmp;
    p1:=i;
    p2:=j;
   end;
  end;
 end;
 writeln(p1,' ',p2);
 readln;
 readln;
end.
