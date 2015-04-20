var a:array[0..111111]of longint;
    i,j,x,l,r,ans,n,m,q,qq:longint;f:boolean;
Procedure qsort(l,r:longint);
var i,j,m,t:longint;
Begin
 i:=l;j:=r;
 m:=a[l+random(r-l+1)];
 repeat
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i>j then break;
  t:=a[i];a[i]:=a[j];a[j]:=t;
  inc(i);dec(j);
 until i>j;
 if i<r then qsort(i,r);
 if l<j then qsort(l,j);
End;

Begin
 assign(input,'fence.in');reset(input);
 assign(output,'fence.out');rewrite(output);
 readln(n,m);
 r:=maxlongint;
 for i:=1 to n do
  begin
   read(a[i]);
   if r>a[i] then r:=a[i];
  end;
 qsort(1,n);
 l:=1;
 while r-l>1 do
  begin
   x:=(r+l)shr 1;
   q:=m;qq:=0;f:=true;
   for i:=1 to n do
    begin
     if (q<x)or((a[i]>qq)and(q<(a[i]-qq))) then begin f:=false;break; end;
     if qq>=a[i]-x then q:=q-x else q:=q-(a[i]-qq);
     qq:=a[i];
    end;
   if f=false then r:=x else
    begin
     if ans<x then ans:=x;
     l:=x+1;
    end;
  end;
 writeln(ans);
End.
