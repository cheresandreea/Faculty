%always alpha and beta are numbers between 0 and 1
alpha=input('Give the order of the quantile alpha= ')
beta=input('Give the order of the quantile beta= ')

%P(X<=0)
m=input("Give m: ");
sigma=input("Give sigma: ");
n=normcdf(0,m,sigma);

%P(X>=0)
%P(X>=0)=1-P(X<0)
%       =1-P(X<=0)
1-normcdf(0,m,sigma);

%P(-1<=X<=1)
%P(a<X<=b)=F(b)-F(a)
%normcdf(1,m,sigma)-normcdf(-1,m,sigma)
%P(X<=-1) U P(X>=1)=1-P(-1<X<1)
1-normcdf(1,m,sigma)-normcdf(-1,m,sigma);

x_alpha=norminv(alpha,m,sigma);
x_beta=norminv(1-beta,m,sigma);
