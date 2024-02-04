X1 = [22.4, 21.7, 24.5, 23.4, 21.6, 23.3, 22.4 21.6, 24.8 20.0];
X2 = [17.7, 14.8, 19.6, 19.6, 12.1, 14.8, 15.4, 12.6, 14.0, 12.2];
n1 = length(X1);
n2 = length(X2);

%in practice aplha=0.05/0.01
%0.95/0.99 confidencelvl
conficence_level = input("Give the confidence level: ");
alpha = 1-conficence_level;
printf("We are solving the first subpoint");
sp = sqrt(((n1-1)*var(X1) + (n2-1)*var(X2))/ (n1+n2-2));
m1 = mean(X1) - mean(X2) - tinv((1-alpha)/2,n1+n2-2)*sp*sqrt(1/n1 + 1/n2);
m2 = mean(X1) - mean(X2) - tinv((1-alpha)/2,n1+n2-2)*sp*sqrt(1/n1 + 1/n2);
printf("confidence interval for the difference of the true means:(m1,m2) = (%4.3f, %4.3f)\n",m1,m2);

c = (var(X1)/n1) / (var(X1)/n1 + var(X2)/n2);
aux = c*c/(n1-1) + (1-c)*(1-c)/(n2-1);
n = ceil(1/aux);

