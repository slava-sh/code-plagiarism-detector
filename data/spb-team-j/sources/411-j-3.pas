program p_1;
var
a:array[1..200000] of longint;
k, pk, h, i, j, n : longint;
b:boolean;
begin
assign (input, 'seq.in');
assign (output, 'seq.out');
reset (input);
rewrite (output);
b:=false;
read (n);
read (h);
for i:=1 to n do
read (a[i]);
k:=0;
pk:=64000;
for i:=1 to n-h+1 do
begin
        if (a[i]<=1)and (a[i+h-1]<=h) then
        begin
                for j:=i to i+h-1 do
                begin
                        if (k<>-1) then
                        begin
                                if (a[j]<=j-i+1) then
                                k:=j-i+1-a[j]+k
                                else
                                k:=-1;
                        end;
                end;



        if (k>-1) and (k<pk) then
        begin
                pk:=k;
                b:=true;

        end;
        end;
        k:=0;
end;
if (b=true) then
writeln (pk)
else
writeln ('-1');
close (input);
close (output);
end.
