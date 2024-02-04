n=input('Give n, n>=30: ');
p=input('Give p, p<=0.05: ');
%Poisson(lambda=np)
k=0:n;
lambda=n*p;
y=binopdf(k,n,p);
z=poisspdf(k,lambda);
plot(k,y);
hold;
plot(k,z);
