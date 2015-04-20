uses math;  
var c,q,n,m:longint;
procedure incc1(n,m:longint);
begin
c:=(n div 4)+(m div 2)+c;
q:=c;
end;

procedure incq1(n,m:longint);
begin
c:=(n div 4)+(m div 4)+c;
q:=c;
end;


procedure incc(n:longint);
begin
c:=(n div 4)+c;
end;
procedure incq(n:longint);
begin
q:=(m div 4)+q;
end;

begin 

	assign(input,'prizes.in');reset(input);
	assign(output,'prizes.out');rewrite(output);
read(n,m);

if n>2 then c:=1;
if m>2 then q:=1;
n:=n-2;m:=m-2;
if n mod 4=0 then incc(n) else incc1(n,m);
if m mod 4=0 then incq(m) else incq1(n,m);
write(min(c,q));
	close(input);
	close(output);
end.