type rec=record
     data:longint;
     count:longint;
     end;
var n,m,i,j,k,kol,answer,el1,el2,el3,kol1,kol2,kol3,qqq:longint;
    rsq,a,b:array[0..500001] of longint;
    c,ans1,ans2,ans3,mas:array[0..500001] of longint;
    heap:array[0..500001] of rec;
procedure swap(var t,y:longint);
var u:longint;
begin
u:=t; t:=y; y:=u;
end;

function max(a,b:longinT):longint;
begin
 if a>b then max:=a else max:=b;
end;



procedure sort(l,r:longint);
var i,j,x:longint;
begin
 x:=a[l+random(r-l)];
 i:=l; j:=r;
 repeat
 while a[i]<X do inc(i);
 while a[j]>X do dec(j);
 if i<=j then
  begin
   swap(a[i],a[j]);
   inc(i);
   dec(j);
  end;
 until i>j;
if l<j then sort(l,j);
if i<r then sort(i,r);
end;



procedure push(el:longint; cnt:longint);
var i:longint;
begin
 inc(kol);
 heap[kol].data:=el;
 heap[kol].count:=cnt;
 i:=kol;
 while (i<>1) and (heap[i].count>heap[i div 2].count) do
  begin
   swap(heap[i].count,heap[i div 2].count);
   swap(heap[i].data,heap[i div 2].data);
   i:=i div 2;
  end;
end;

procedure pop(var el,cnt:longint);
begin
 el:=heap[1].data;
 cnt:=heap[1].count;
 if kol=1 then
  begin
   kol:=0;
   exit;
  end;
 heap[1].data:=heap[kol].data;
 heap[1].count:=heap[kol].count;
 heap[kol].data:=0;
 heap[kol].count:=0;
  dec(kol);
 i:=1;
 while true do
  begin
   if i*2>kol then exit;
   if i*2=kol then
    begin
     if heap[i*2].count>heap[i].count then
      begin
       swap(Heap[i*2].count,heap[i].count);
       swap(heap[i*2].data,heap[i].data);
       i:=i*2;
      end;
     exit;
    end;
   if heap[i*2].count>=heap[i*2+1].count then
    begin
     if heap[i].count<heap[i*2].count then
      begin
       swap(Heap[i].count,heap[i*2].count);
       swap(heap[i].data,heap[i*2].data);
       i:=i*2;
      end else
      begin
       exit;
      end;
    end else
    begin
     if heap[i].count<heap[i*2+1].count then
      begin
       swap(Heap[i].count,heap[i*2+1].count);
       swap(heap[i].data,heap[i*2+1].data);
       i:=i*2+1;
      end else
      begin
       exit;
      end;
     end;
  end;
end;

function find(el:longint):longint;
var left,right,middle:longint;
begin
 left:=1; right:=qqq;
 while right-left>1 do
  begin
   middle:=(left+right) div 2;
   if mas[middle]<el then left:=middle else right:=middle;
  end;
 if mas[left]=el then find:=left else
 if mas[right]=el then find:=right else
 if mas[left-1]=el then find:=left-1 else
 find:=0;
end;


begin
 {assigN(input,'input.txt');
 reset(inpuT);
 assign(output,'output.txt');
 rewrite(output);  }
 readln(n);
 for i:= 1 to n do
  read(a[i]);
 sort(1,n);
 b[1]:=1;
 for i:= 2 to n do
  if a[i]=a[i-1] then b[i]:=b[i-1] else b[i]:=b[i-1]+1;
 qqq:=1;
 mas[1]:=a[1];
 for i:= 2 to n do
  if mas[qqq]<>a[i] then
   begin
    inc(qqq);
    mas[qqq]:=a[i];
   end;
 for i:= 1 to n do
  a[i]:=b[i];
 for i:= 1 to n do
  inc(c[a[i]]);
 n:=b[n];
 kol:=0;
 for i:= 1 to n do
  if c[i]>0 then push(i,c[i]);
 while kol>=3 do
  begin
   pop(el1,kol1);
   pop(el2,kol2);
   pop(el3,kol3);
   inc(answeR);
   ans1[answer]:=el1;
   ans2[answer]:=el2;
   ans3[answer]:=el3;
   kol1:=kol1-1;
   kol2:=kol2-1;
   kol3:=kol3-1;
   if kol1>0 then
   push(el1,kol1);
   if kol2>0 then
   push(el2,kol2);
   if kol3>0 then
   push(el3,kol3);
  end;
 writeln(Answer);
 for i:= 1 to answer do
  begin
   if ans1[i]>ans2[i] then swap(Ans1[i],ans2[i]);
   if ans2[i]>ans3[i] then swap(ans2[i],ans3[i]);
   if ans1[i]>ans2[i] then swap(Ans1[i],ans2[i]);
  end;
 for i:= 1 to answer do
  writeln(mas[Ans3[i]],' ',mas[ans2[i]],' ',mas[ans1[i]]);
end.





