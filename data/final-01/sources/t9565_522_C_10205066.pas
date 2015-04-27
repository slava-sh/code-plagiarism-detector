Var t,n,k,i,j,h,p:longint;
    a:array[1..200000] of int64;
    x,y:array[1..200000] of longint;
    res:array[1..200000] of char;
    s,min:int64;
    f:boolean;
Begin
Readln(t);
For i:=1 to t do
 Begin
  Readln;
  Readln(n,k);
  For j:=1 to k do Read(a[j]);
  Readln;
  For j:=1 to k do res[j]:='N';
  For j:=1 to n-1 do
   Begin
    Readln(x[j],y[j]);
    If x[j]<>0 Then inc(a[x[j]],999999);
   End;
  s:=0;
  f:=true;
  For j:=1 to n-1 do
   Begin
    If (y[j]=1) and (f=true) Then
     Begin
      f:=false;
      min:=1000000000000000;
      For h:=1 to k do
       Begin
        If a[h]<min Then Begin min:=a[h]; p:=h; End;
        If a[h]-s<=0 Then res[h]:='Y';
       End;
      dec(s,a[p]);
      a[p]:=0;
     End;
    If x[j]=0 Then inc(s)
              Else dec(a[x[j]],1000000);
   End;
  For j:=1 to k do
   Begin
    If a[j]-s<=0 Then res[j]:='Y';
    Write(res[j]);
   End;
  Writeln;
 End;
End.
