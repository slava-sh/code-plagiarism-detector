Program ProbC;
Const MaxN=100000;
Var heap,d,val,a,pos:array[1..MaxN] of Longint;
    ds:array[1..maxN] of array[1..3] of Longint;
    n,nheap,c,count:longint;
Procedure Input;
Var f:Text;
    i:Longint;
Begin
  Assign(f,''); Reset(f);
  Readln(f,n);
  For i:=1 to n do Read(f,a[i]);
  Close(f)
End;

Procedure Swap(var a,b:longint);
Var t:longint;Begin t:=a; a:=b; b:=t End;

Procedure QuickSort(l,r:Longint);
Var i,j,k:Longint;
Begin
  If l>=r then exit;
  i:=l; j:=r;
  k:=a[random(r-l+1)+l];
  Repeat
    While a[i]<k do Inc(i);
    While a[j]>k do Dec(j);
    If i<=j then
      Begin
        if i<j then Swap(a[i],a[j]);
        Inc(i); Dec(j)
      End;
  Until i>j;
  Quicksort(l,j); QuickSort(i,r)
End;

{+++++++++++++++++++++}
Procedure UpHeap(v:Longint);
Var child,parent:Longint;
Begin
  child:=pos[v];
  parent:=child div 2;
  While (parent>0) and (d[heap[parent]]<d[v]) do
    Begin
      heap[child]:=heap[parent];
      pos[heap[child]]:=child;
      child:=parent;
      parent:=child div 2;
    End;
  heap[child]:=v;
  pos[v]:=child;
End;

Procedure DownHeap(v:Longint);
Var r,c:Longint;
Begin
  r:=pos[v];
  While r*2<=nHeap do
    Begin
      c:=r*2;
      If (c<nHeap) and (d[heap[c+1]]>d[heap[c]]) then Inc(c);
      If d[v]>=d[heap[c]] then Break;
      heap[r]:=heap[c];
      pos[heap[r]]:=r;
      r:=c;
    End;
  heap[r]:=v;
  pos[v]:=r;
End;

Procedure Push(v:Longint);
Begin
  Inc(nHeap);
  pos[v]:=nHeap;
  heap[nHeap]:=v;
  UpHeap(v);
End;

Function Pop:Longint;
Begin
  Pop:=heap[1];
  heap[1]:=heap[nHeap]; Dec(nHeap);
  pos[heap[1]]:=1;
  DownHeap(heap[1]);
End;
{+++++++++++++++++++++}

Procedure Init;
Var i,j:Longint;
Begin
  i:=1; c:=0;
  While i<=n do
    Begin
      j:=i;
      While (j<n) and (a[j+1]=a[i]) do Inc(j);
      Inc(c);
      val[c]:=a[i]; d[c]:=j-i+1;
      i:=j+1;
    End;
  For i:=1 to c do Push(i);
End;

Procedure Solve;
Var i,j,v1,v2,v3:Longint;
Begin
  count:=0;
  While nHeap>=3 do
    Begin
      v1:=Pop; v2:=Pop; v3:=Pop;
      Inc(count);
      ds[count][1]:=val[v1]; ds[count][2]:=val[v2]; ds[count][3]:=val[v3];
      Dec(d[v1]); Dec(d[v2]); Dec(d[v3]);
      if d[v1]>0 then Push(v1); If d[v2]>0 then Push(v2); If d[v3]>0 then Push(v3);
      For i:=1 to 2 do
        For j:=i+1 to 3 do
          If ds[count][i]<ds[count][j] then Swap(ds[count][i],ds[count][j]);
    End;
End;

Procedure Output;
Var i:Longint;
Begin
  Writeln(count);
  For i:=1 to count do Writeln(ds[i][1],' ',ds[i][2],' ',ds[i][3]);
End;

BEGIN
  Input;
  QuickSort(1,n);
  Init;
  Solve;
  Output;
END.