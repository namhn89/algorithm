procedure unzip;

var i,j,del:longint;

begin

 sort(1,3*n);

 A[3*n+1].val:=high(longint);

 i:=1; del:=0;

 repeat

 inc(del);

 j:=i;

 while A[i].val=A[j].val do

 begin

 B[A[j].pos]:=del;

 inc(j);

 end;

 i:=j;

 until i=3*n+1;

end;

// Phần tính toán kết quả bằng Binary Indexed Tree

for i:=n downto 2 do

 begin

 update(B[i]);

 res:=res+get(B[i-1+2*n])-get(B[i-1+n]);

 end;
