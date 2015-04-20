var
 l,k,n,r,i,j:integer;
 s:array[1..400000]of integer;
 a,w:text;
begin
 assign(a,'che.in'); reset(a);
 assign(w,'che.out'); rewrite(w);
 readln(a,n,r);
 l:=0;
 for i:= 1 to n do
 read(a,s[i]);
 for i:=1 to n-1 do
 for k:=i+1 to n do
 if s[k]-s[i]>r then
 begin
 l:=l+(n-k)+1;
 break;
 end;
 writeln(w,l);
 close(a);
 close(w);
end.
