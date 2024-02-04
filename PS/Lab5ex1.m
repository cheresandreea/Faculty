pkg load statistics

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




