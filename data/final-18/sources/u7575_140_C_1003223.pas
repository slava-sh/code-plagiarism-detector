const maxn=100000;
type mang = array[1..3] of longint;
Type pair = record
val:longint;
count:longint;
end;

var f1,f2:text;
C:array[1..maxn] of pair;
A:array[0..maxn] of longint;
spt:longint;
Heap:array[1..maxn] of longint;
res:longint;
nHeap:longint;
n,i,j:longint;

kq:array[1..maxn] of mang;

Procedure QuickSort(L,H:longint;var A:mang);
var i,j:longint;
    tg,Pivot:longint;
Begin
     if L>=H then Exit;
     pivot := C[A[Random(H-L+1)+L]].val;
     i:=L; j:=H;
     Repeat
       while C[A[i]].val>pivot do Inc(i);
       While C[A[j]].val<Pivot do dec(j);
       if i<=j then
       Begin
         If i<j then
         Begin
           tg:=a[i];
           a[i]:=a[j];
           A[j]:=tg;
         End;
         inc(i);
         dec(j);
       End;
     Until i>j;
     quicksort(L,j,a); quicksort(i,H,a);
End;
Procedure Partition(L,H:longint);
var i,j:longint;
    tg,Pivot:longint;
Begin
     if L>=H then Exit;
     pivot := A[Random(H-L+1)+L];
     i:=L; j:=H;
     Repeat
       while A[i]<pivot do Inc(i);
       While A[j]>Pivot do dec(j);
       if i<=j then
       Begin
         If i<j then
         Begin
           tg:=a[i];
           a[i]:=a[j];
           A[j]:=tg;
         End;
         inc(i);
         dec(j);
       End;
     Until i>j;
     Partition(L,j); Partition(i,H);
End;

Procedure Swap1(const u,v:longint);
var tg:longint;
begin
        tg:=Heap[u];
        Heap[u]:=Heap[v];
        Heap[v]:=tg;
end;

Procedure Upheap(p:longint);
Begin
        While (p div 2>=1) and (C[Heap[p]].Count>C[Heap[p div 2]].count) do begin Swap1(p, p div 2); p:=p div 2; End;
end;

Procedure DownHeap(p:longint);
Begin
        p:=p*2;
        While (p<=nHeap) do
        Begin
          if (p+1<=nHeap) and (C[Heap[p+1]].count>C[heap[p]].count) then inc(p);
          if C[heap[p]].count>C[Heap[p div 2]].count then begin swap1(p,p div 2); p:=p * 2; End else break;
        end;
ENd;

Procedure push(const u:longint);       {Heap lon}
var p:longint;
begin
        inc(nHeap);
        heap[nHeap]:=u;
        UpHeap(nHeap);
end;

Function Pop:longint;               {heap lon}
begin
        Pop:=Heap[1];
        Heap[1]:=Heap[nHeap];
        dec(nHeap);
        DownHeap(1);
End;

procedure process;
var i,j:longint;
begin
        for i:=1 to n div 3 do
        begin
          for j:=1 to 3 do
          begin
            if nHeap=0 then exit;
            kq[i,j]:=pop;
          end;
          for j:=1 to 3 do
          begin
            DEc(C[kq[i,j]].Count);
            if C[kq[i,j]].count>0 then
            push(kq[i,j]);
          end;
          inc(res);
        end;
end;

begin
        assign(f1,'');reset(F1);
        assign(f2,'');rewrite(f2);
        readln(f1,n);
        for i:=1 to n do
        read(f1,A[i]);
        partition(1,n);
        a[0]:=-242;
        fillchar(c,sizeof(c),0);
        spt:=0;
        for i:=1 to n do
        begin
          if a[i]<>a[i-1] then
          begin
            inc(spt);
            C[spt].val:=a[i];
          end;
          Inc(C[spt].Count);
        end;
        for i:=1 to spt do push(i);
        process;
        writeln(f2,res);
        for i:=1 to res do
        Begin
        for j:=1 to 3 do
        begin
          quicksort(1,3,kq[i]);
          write(f2,C[kq[i,j]].val,' ');
        end;
        writeln(f2);
        End;
        close(F1);
        close(F2);
end.

































