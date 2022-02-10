clc

%Exercise 1
Y=[1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0]; %The vector

m=length(Y);
H=hadamard(m);
Co=zeros(1,m);

for i=1:m
    if Y(i)==0
        Co(i)=1;
    else
        Co(i)=-1;
    end
end

Co(10)=0; %Because this is de undefined value
S=Co*H