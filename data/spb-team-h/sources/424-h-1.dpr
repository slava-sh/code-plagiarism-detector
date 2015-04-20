program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, j, q, c1, c2, curr: integer;
  flag: boolean;
  crd: array of integer;
  arr: array of record
    a, b, c: string;
  end;
  x: string;
  s, f, x1, x2: string;

procedure swap(var a1, a2: string);
  var wsp: string;

begin
  wsp:= a1;
  a1:= a2;
  a2:= wsp;
end;

begin
  assignfile(input, 'names.in');
  assignfile(output, 'names.out');
  readln(n);

  setlength(arr, n + 1);
  setlength(crd, n + 1);

  for i:= 1 to n do
  begin
    readln(s);
    for j:= 1 to length(s) do
      if s[j] = ' ' then
      begin
        c1:= j;
        break;
      end;
    for j:= c1 + 1 to length(s) do
      if s[j] = ' ' then
      begin
        c2:= j;
        break;
      end;


    f:= copy(s, 1, c1 - 1);
    arr[i].a:= f;
    f:= copy(s, c1 + 1, c2 - c1 - 1);
    arr[i].b:= f;
    f:= copy(s, c2 + 1, length(s));
    arr[i].c:= f;

  end;

  for i:= 1 to n do
  begin
    x:= arr[i].a;

    flag:= false;

    for j:= 1 to n do
      if i <> j then
        if (x = arr[j].a) or (x = arr[j].c) or (x = arr[j].b) then
        begin
          flag:= true;
          break;
        end;

    if flag = true then
      crd[i]:= 3
    else
      crd[i]:= 1;
  end;

  for i:= 1 to n do
    if crd[i] = 3 then
    begin
      x1:= arr[i].c;
      arr[i].c:= arr[i].a;
      arr[i].a:= x1;

      x2:= arr[i].c;
      arr[i].c:= arr[i].b;
      arr[i].b:= x2;

    end;
  
  for i:= 1 to n do
  begin
    f:= arr[i].a;
    curr:= i;

    for j:= i to n do
      if arr[j].a < f then
      begin
        f:= arr[j].a;
        curr:= j;
      end;

    swap(arr[i].a, arr[curr].a);
    swap(arr[i].b, arr[curr].b);
    swap(arr[i].c, arr[curr].c);
  end;

  for i:= 1 to n do
    writeln(arr[i].a, ' ', arr[i].b, ' ', arr[i].c);


end.
