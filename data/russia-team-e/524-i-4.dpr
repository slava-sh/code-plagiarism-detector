program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

procedure Sort(var arr:array of integer; count:integer);
  procedure downHeap(index,count:integer; current:integer);
    var
      Child:integer;
    begin
      while index<count div 2 do
        begin
          child:=(index+1)*2-1;
          if (child<count-1)and(arr[child]<arr[child+1]) then
            child:=child+1;
          if current>=arr[child] then
            break;
          arr[index]:=arr[child];
          index:=child;
        end;
      arr[index]:=current;
    end;
  var
    i:integer;
    current:integer;
  begin
    for i:=(Count div 2)-1 downto 0 do
      downHeap(i,count,arr[i]);
    for i:=Count-1 downto 0 do
      begin
        Current:=arr[i];
        arr[i]:=arr[0];
        downHeap(0,i,Current);
      end;
  end;
var
t:text;
a:array[0..100000] of integer;
n,d,i,max,p:integer;
begin
  assign(t,'sochi.in');
  reset(t);
  readln(t,n,d);
  for i:=0 to n-1 do
  begin
  read(t,a[i]);
  end;
  Sort(a,n);
  p:=a[n-1];
  max:=a[n-1];
  if a[n-1]<d then max:=a[n-1]
  else
  for i:=n-2 downto 0 do
    begin
    p:=a[i+1]-d;
    if (p-d>=d) and (a[i]-d>=d) then
      begin
      max:=max+a[i]-2*d;
      end;
    end;
 if max <= 0 then max:= a[n - 1];
 close(t);
 assign (t,'sochi.out');
 rewrite(t);
 write(t,max);
 close(t);
end.
