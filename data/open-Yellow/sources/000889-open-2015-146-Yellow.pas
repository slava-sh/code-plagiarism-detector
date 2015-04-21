var
  ar:array[1..100000] of longint;
  n,q:longint;
  ans:longint;
  i,j,k:longint;

begin
 read(n);
 For i:=1 to n do
 begin
   read(ar[i]);
   If i<>1 Then
    If ar[i]<>ar[i-1] then inc(ans);
 end;
 read(q);
 For i:=1 to q do
 begin
   read(j,k);
   If j>1 Then
   begin
    If (ar[j-1]=ar[j]) and (ar[j-1]<>k) then inc(ans);
    If (ar[j-1]<>ar[j]) and (ar[j-1]=k) Then dec(ans);
   end;
   If j<n then
   begin
     If (ar[j+1]=ar[j]) and (ar[j+1]<>k) then inc(ans);
     if (ar[j+1]<>ar[j]) and (ar[j+1]=k) Then dec(ans);
   end;
   ar[j]:=k;
   writeln(ans+1);
 end;
 readln;
 readln;
end.
