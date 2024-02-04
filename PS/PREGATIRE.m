
pkg load statistics

%{
A = [1 0 -2; 2 1 3; 0 1 0]
B = [2 1 1; 1 0 -1; 1 1 0]

C = A - B
D = A * B
E = A.*B

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
x = linspace(0, 3, 100);

y1 = x .^ (5/10);
y2 = x .* sin(x);
y3 = cos(x);
hold on;

plot(x, y1, 'r--', 'LineWidth', 1.5);  % Plot x^(5/10) in red dashed line
plot(x, y2, 'g-.', 'LineWidth', 1.5);  % Plot x*sin(x) in green dash-dot line
plot(x, y3, 'b-', 'LineWidth', 1.5);   % Plot cos(x) in blue solid line

title('Graph of Functions');
legend('x^{5/10}', 'x*sin(x)', 'cos(x)');
hold off;  % Release the current graph
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure;  % Create a new figure
subplot(3, 1, 1);  % Create the first subplot

plot(x, y1, 'r--', 'LineWidth', 1.5);  % Plot x^(5/10) in red dashed line
title('Graph of x^{5/10}');

subplot(3, 1, 2);  % Create the second subplot

plot(x, y2, 'g-.', 'LineWidth', 1.5);  % Plot x*sin(x) in green dash-dot line
title('Graph of x*sin(x)');

subplot(3, 1, 3);  % Create the third subplot

plot(x, y3, 'b-', 'LineWidth', 1.5);   % Plot cos(x) in blue solid line
title('Graph of cos(x)');


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
n = input("Give the number of trials n = ")
p = input("Give the number of successes p = ")
%n is a natural number
%p is a value between 0 and 1

x = 0:1:n
px = binopdf(x, n, p)
plot(x, px, "r+")
hold on;
xx = 0:0.01:n
fx = binocdf(xx, n, p)
plot(xx, fx, "b")


n = 3
p = 0.5
x_values = 0:n
pdf_values = binopdf(x_values,n,p)
disp('Probability distribution function (PDF) for X:');
disp(['X = 0: P(X = 0) = ' num2str(pdf_values(1))]);
disp(['X = 1: P(X = 1) = ' num2str(pdf_values(2))]);
disp(['X = 2: P(X = 2) = ' num2str(pdf_values(3))]);
disp(['X = 3: P(X = 3) = ' num2str(pdf_values(4))]);


cdf_values = binocdf(x_values, n, p)
disp('Cumulative Distribution Function (CDF) for X:');
disp(['X = 0: F(X <= 0) = ' num2str(cdf_values(1))]);
disp(['X = 1: F(X <= 1) = ' num2str(cdf_values(2))]);
disp(['X = 2: F(X <= 2) = ' num2str(cdf_values(3))]);
disp(['X = 3: F(X <= 3) = ' num2str(cdf_values(4))]);


% Simulate 3 coin tosses
n = 3; % Number of coin tosses
X = sum(rand(1, n) < 0.5); % Count the number of heads (values < 0.5)

% Display the result
fprintf('Number of heads in 3 coin tosses: %d\n', X);


%always alpha and beta are numbers between 0 and 1
alpha=input('Give the order of the quantile alpha= ')
beta=input('Give the order of the quantile beta= ')


%P(X<=0)
m = input("Give m: ");
sigma = input("Give sigma: ");
n = normcdf(0, m, sigma);

%P(X>=0) = 1 - P(X<=0)
n1 = 1 - normcdf(0, m, sigma)

%P(-1<=X<=1)
%P(a<X<=b)=F(b)-F(a)
n2 = normcdf(1,m,sigma)-normcdf(-1,m,sigma)
%P(X<=-1) U P(X>=1)=1-P(-1<X<1)
x_alpha = norminv(alpha, m, sigma);
x_beta = norminv(1-beta, m, sigma);


p=input("Give a probability between 0.05 and 0.95: ");
for n=1:3:100
  k=0:n;
  y=binopdf(k,n,p);
  plot(k,y);
  pause(0.5)
endfor



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


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
p = input("Give a number between 0 and 1: ");
N = input("Give the number of simuations: ");
U = rand(1,N);
X = (U>p);
U_X = [0 1];
n_x = hist(X, length(U_X));
rel_freq = n_x/N;

p = input("Give a number between 0 and 1: ");
N = input("Give the number of simulations: ");

X = [zeros(1,N)];

for i = 1:N
  X(i) = 0;
  while rand>=p
    X(i) = X(i) + 1;
  endwhile
endfor

k = [0:20];
p_k = geopdf(k,p);

U_X = unique(X);
n_x = hist(X, length(U_X));
rel_freq = n_x/N;
plot(U_X, rel_freq, '*', k, p_k, 'ro');




%1-alpha - level of confidence
%alpha - rise prob - significance level
X = [7, 7, 4, 5, 9, 9,...
4, 12, 8, 1, 8, 7,...
3, 13, 2, 1, 17, 7,...
12, 5, 6, 2, 1, 13,...
14, 10, 2, 4, 9, 11,...
3, 5, 12, 6, 10, 7];

level_of_confidence= input("Give the level of confidence: ");
alpha = 1-level_of_confidence;
sigma = 5;
printf("We are solving the first subpoint");
n = length(X);
m1 = mean(X) - (sigma/sqrt(n)) * norminv(1 - alpha/2,0,1);
m2 = mean(X) - (sigma/sqrt(n)) * norminv(alpha/2,0,1);
printf("Confidence interval for the average number of files stored:(m1,m2) = (%4.3f, %4.3f)\n",m1,m2);

printf("We are solving the second subpoint");
m1b = mean(X) - (std(X) / sqrt(n))* tinv(1-alpha/2,n-1);
m2b = mean(X) - (std(X) / sqrt(n))* tinv(alpha/2,n-1);
printf("Confidence interval for the average number of files stored:(m1b,m2) = (%4.3f, %4.3f)\n",m1b,m2b);

printf("We are solving the third subpoint");

v1 = (n-1)*var(X)/chi2inv((1-alpha)/2,n-1);
v2 = (n-1)*var(X)/chi2inv((1-alpha)/2,n-1);
printf("confidence intervals for the variance:(v1,v2) = (%4.3f, %4.3f)\n",v1,v2);

s1 = sqrt(v1);
s2 = sqrt(v2);
printf("confidence intervals for the standard deviation:(v1,v2) = (%4.3f, %4.3f)\n",s1,s2);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%}

X =[7, 7, 4, 5, 9, 9,...
4, 12, 8, 1, 8, 7,...
3, 13, 2, 1, 17, 7,...
12, 5, 6, 2, 1, 13,...
14, 10, 2, 4, 9, 11,...
3, 5, 12, 6, 10, 7];
n = length(X);
alpha = input("Give the significance level \n"); %0.05
%the null hypothesis is H0:miu = 8.5(it goes together
%with miu > 8.5, the standard is met)
%the alternative hypothesis H1:miu<8.5(the standard
%is not met/not efficient)
%left tailed test for min when sigma known
printf("This is a left tailed test for the min when sigma known \n");
sigma = 5;
m0 = input("Input the value for the test value \n"); %8.5
[h, p, ci, zval] = ztest(X, m0, sigma, "alpha", alpha, "tail", "left");
%[h, pval, ci, zobs] = ztest(X, m0, sigma);
z_alpha = norminv(alpha, 0, 1);
RR = [-inf, z_alpha];
printf("The value of h is %f: ", h);
if h==1
  printf("The null hypothesis is rejected \n");
  printf("The data suggests that the standard is not met\n");
 else
  printf("The null hypothesis is not rejected\n");
  printf("The data suggests that the standard is met\n");
endif


printf("The rejection region is (%4.4f, %4.4f)\n", RR);
printf("The value of the test statistic is %4.4f\n", zval);
printf("The pvalue of the test is %4.4f\n", p);
%}
%{
%sol is with ttest - right tail test
%the quantiles are following the student's law
%2a. 2 tailed tests for comaring variances
%2b. right tailed test for the difference of min

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%A food owner recieves 1-liter water bottles from 2 suppliers. After some complaints
%from customers, he wants to check the accuracy of the weights of 1 liter water
%bottles. He finds the following weights(the two populations are approximately normally
%distributed)
%a) at 5% significance level, do the population variances seem to differ?

A = [1021, 980, 1017, 988, 1005, 998, 1014, 985, 995, 1004, 1030, 1015, 995, 1023]
B = [1070, 970, 993, 1013, 1006, 1002, 1014, 997, 1002, 1010, 975]

%H0 : miu1 = miu2
%H1 : miu1 != miu2

na = length(A)
nb = length(B)

sigma = 0.05

z_score = mean(A) - mean(B) - (

%}


%TESTS:
%sigma - ztest
%no sigma but average - ttest
%average 2 seturi - ttest2
%variance 2 seturi - vartest2
%vartest otherwise
%left tailed - standard is met
%right tailed - exceeds
%two tailed - equalc



























