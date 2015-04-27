var
 os,str,ts:ansistring;
 ostr:array[1..10000]of ansistring;
 s,i,j,n,m,a,b,c,l:longint;

begin
 readln(l);
 readln(str);
 n:=length(str);
 for i:=1 to n do
 begin
  if str[i]='a' then inc(a)else
  if str[i]='b' then inc(b)else
  if str[i]='c' then inc(c);
 end;
 if a>0 then
 begin
  inc(s);
  ostr[s]:='a';
 end;
 if b>0 then
 begin
  inc(s);
  ostr[s]:='b';
 end;
 if c>0 then
 begin
  inc(s);
  ostr[s]:='c';
 end;
 if s<=2 then
 begin
  for i:=1 to l do
  begin
   os:=copy(str,1,i);
   ts:=str;
   while(copy(ts,1,i)=os)do delete(ts,1,i);
   if length(ts)>0 then continue;
   writeln(1);
   writeln(os);
   halt;
  end;
 end;
 writeln(s);
 for i:=1 to s do writeln(ostr[i]);
end.