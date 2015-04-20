program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    i,j,r,n,count: integer;
    arr:array[0..300001] of integer;
begin
    assign(input, 'che.in'); reset(input);
    assign(output, 'che.out'); rewrite(output);
    
    read(n,r);
    count := 0;
    for i:=0 to n-1 do
      begin
        read(arr[i]);
      end;

    for i:=0 to n-2 do
      begin
        for j:=i+1 to n-1 do
          begin
            if (arr[j] - arr[i]) > r then
              begin
                count := count + (n-j);
                break;
              end;
          end;
      end;

      writeln(count);


end.
