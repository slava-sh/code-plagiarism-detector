type arr=array[1..2]of longint;
var a:array[1..200000]of longint;
    l2:arr;
    flag: boolean;
    b,min,n,h,i:longint;
function fun (x:longint):arr;
var j,ch:longint;
    flag:boolean;
    l: arr;
begin
	ch:=0;
	flag:=true;
	for j:=0 to h-1 do
		ch:=ch+(j+1-a[x+j]);
		if a[x+j]<=j+1 then flag:=flag
		else flag:=false;
	if flag then begin l[1]:=ch; l[2]:=1 end else begin l[1]:=0; l[2]:=0 end;
	fun:=l;
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
		l2:=fun(i);
		if ((a[i]=1) or (a[i]=0)) and (l2[2]=1) then
			if (l2[1]<min) then min:=l2[1];
	end;
	if min = 400001 then min:=-1;
	writeln(min);
end.