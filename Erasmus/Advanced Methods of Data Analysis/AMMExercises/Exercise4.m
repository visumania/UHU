clc

%Exercise 4

prompt="Insert the value of N (matrix NxN): ";
N = input(prompt);
A=zeros(N,N);
A(1,1)=8;

spectrum=dct2(A);
figure('Name','Cosine spectrum','NumberTitle','off')
figure(1);
mesh(spectrum)

spectrum