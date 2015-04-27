program csb;

const   fi='';
        fo='';

var     f,g:text;
        n,m:longint;
        a:array[0..100111]of boolean;
        t:array[0..100111]of char;
        c,b:array[0..100111]of longint;

procedure enter;
var i,j:longint;
begin
assign(f,fi);assign(g,fo);
reset(f);rewrite(g);
readln(f,n,m);
for i:=1 to m do readln(f,t[i],b[i]);
end;

procedure process;
var i,j,u,v,k,d:longint;
    ch:char;
    kt:array[0..100111]of boolean;
begin
fillchar(a,sizeof(a),true);
fillchar(kt,sizeof(kt),false);
fillchar(c,sizeof(c),0);
for i:=1 to m do
 begin
   if t[i]='-' then
    begin
       dec(c[i]);
       if not kt[b[i]] then inc(c[1]);
    end
   else
    begin
       inc(c[i]);
       kt[b[i]]:=true;
    end;
 end;
for i:=1 to m do c[i]:=c[i]+c[i-1];
i:=1;
while i<=m do
 begin
  if t[i]='+' then
   begin
     if (c[i]>1)or(i>1) then a[b[i]]:=false;
     inc(i);
   end
  else
   begin
     if (c[i]=0)and(((i<m)and(t[i+1]='+')and(b[i+1]=b[i]))or(i=m)) then inc(i)
     else a[b[i]]:=false;
     inc(i);
   end;
 end;
u:=0;
for i:=1 to n do if a[i] then inc(u);
writeln(g,u);
for i:=1 to n do if a[i] then write(g,i,' ');
end;

Begin
    enter;
    process;
    close(G);
end.











