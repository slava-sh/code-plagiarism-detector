var k,l,r: longint;
n,m,x,i,j,z:integer;
s: array[1..1000] of string;
a: array[1..100000000] of longint;
q: array[1..1000] of longint;
begin
  reset(input, 'dunes.in');
  rewrite(output, 'dunes.out');
 readln(n,m);
 for i:=1 to n do
 begin
     readln(s[i]);
 end;

 for z:=1 to m do
 begin
     readln(q[z]);
 end;
 
 for i:=1 to n do
 begin
 k:=0;
 l:=ord(s[i][1])-ord('0');
 r:=ord(s[i][3])-ord('0');
 x:=ord(s[i][5])-ord('0');
 
     for j:=l to r do
  begin
  inc(k);
     //a[j]:=0;
     if((k mod 2)=0) then
     begin
         a[j]:=a[j]-x;
        
     end
     else
     begin
          a[j]:=a[j]+x;
          
     end;
  end;

 end;
 for z:=1 to m do
 begin
 j:=q[z];
     writeln(a[j]);
 end;

   close(output);
end.