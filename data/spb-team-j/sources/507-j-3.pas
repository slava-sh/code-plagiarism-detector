var a:array[1..200000]of longint;
    b,min,n,h,i:longint;
function fun (x:longint):boolean;
var j:longint;
    flag:boolean;
begin
	flag:=true;
	for j:=0 to h-1 do
		if a[i+j]<=j+1 then flag:=flag
		else flag:=false;
	fun:=flag;
end;             
function fun2 (x:longint):longint;
var j,ch:longint;
begin
	ch:=0;
	for j:=0 to h-1 do
		ch:=ch+(j+1-a[i+j]);
	fun2:=ch;
end;                  
begin
	assign(input,'seq.in');reset(input);
	assign(output,'seq.out');rewrite(output);
	read(n);
	read(h);
	readln;
	for i:=1 to n do
		read(a[i]);
	min:=400001;
	b:=400001;
	for i:=1 to n-h+1 do begin
		if ((a[i]=1) or (a[i]=0)) and (fun(i)) then begin
			b:=fun2(i);
			if (b<min) then min:=b;
		end;                        
	end;
	if min = 400001 then min:=-1;
	writeln(min);
end.