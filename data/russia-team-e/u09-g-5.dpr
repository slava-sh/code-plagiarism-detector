program Project2; 
  
{$APPTYPE CONSOLE}
  
uses
  SysUtils; 
 var n,m:longint; 
begin
assign(input,'prizes.in'); 
reset(input); 
assign(output,'prizes.out'); 
rewrite(output); 
read(n,m); 
if (n=2)or(m=2) then
begin
write(0); 
exit; 
end else
if n=1 then
begin
if (m mod 4)=3 then
begin
write((m div 4)+1); 
exit; 
end else
begin
write(m div 4); 
exit; 
end; 
end else
if m=1 then
begin
if (n mod 4)=3 then
begin
write(n div 4+1); 
exit; 
end else
begin
write(n div 4); 
exit; 
end; 
end else
write(1); 
  
  
end. 
