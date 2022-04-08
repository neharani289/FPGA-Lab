module Assignment5(
input wire a,
input wire b,
output wire redled,
output wire greenled,
output wire blueled
);

reg sum, carry;
always @(*)
begin
sum = a^b;
carry = a&b;
if(sum==1)
begin
redled=1;
end
else
begin
redled=0;
end

if(carry==1)
begin
blueled=1;
end
else
begin
blueled=0;
end
end
endmodule
