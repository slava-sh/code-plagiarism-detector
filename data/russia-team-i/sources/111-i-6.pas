var a:array[0..111111]of longint;
    n,d,i,j,ost1,ost2,ans:longint;
Procedure qsort(l,r:longint);
var i,j,m,t:longint;
Begin
 i:=l;j:=r;
 m:=a[l+random(r-l+1)];
 repeat
  while a[i]>m do inc(i);
  while a[j]<m do dec(j);
  if i>j then break;
  t:=a[i];a[i]:=a[j];a[j]:=t;
  inc(i);dec(j);
 until i>j;
 if i<r then qsort(i,r);
 if l<j then qsort(l,j);
End;
Begin
 assign(input,'sochi.in');reset(input);
 assign(output,'sochi.out');rewrite(output);
 readln(n,d);
 for i:=1 to n do
  read(a[i]);
 qsort(1,n);ost1:=maxlongint;ost2:=maxlongint;ans:=a[1];
 for i:=2 to n do
  begin
   if a[i]<=d then break;
   if ost1<2*d then
    begin
     if ost2<2*d then break;
     if ans>ans+a[i]-d-d then break;
     ans:=ans+a[i]-d-d;
     ost2:=a[i]-d;
     if i=2 then ost1:=a[1]-d;
     continue;
    end;
   if ans>ans+a[i]-d-d then break;
   ans:=ans+a[i]-d-d;
   ost1:=a[i]-d;if i=2 then ost2:=a[1]-d;
  end;
 writeln(ans);
End.