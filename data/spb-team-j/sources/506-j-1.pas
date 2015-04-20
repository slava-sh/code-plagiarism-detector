program nj;
var
k,p,i,y,q,j,a,b,n,x,h:longint;
begin
assign(input,'seq.in');
assign(output,'seq.out');
rewrite(output);
reset(input);
read(n);
readln(h);
k:=0;
x:=100;
p:=0;
y:=2;
reset(input);
for i:=1 to n-h+1 do
 begin
 for q:=1 to y+1 do read(a);
 y:=y+1;
 if a=1 then 
  begin
   j:=1;
   repeat
   begin
   read(b);  
   if b<=j+1 then k:=k+j+1-b else x:=0;
   j:=j+1;
   end;
   until (x=0) or (j=h);
  if j=0 then k:=0 else 
  begin
  if k<p then p:=k;
  if p=0 then p:=k;
  k:=0;
  end;
  end;
  reset(input);
 end;
if p>0 then
writeln(p) else writeln('-1');
close(input);
close(output);
end. 
  