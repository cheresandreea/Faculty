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
[h, pval, ci, zobs] = ztest(X, m0, sigma);
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

printf("The rejection region is (%4.3f, %4.3f)\n", RR);
printf("The observed value of the test statistic is %4.3f\n", zobs);
printf("The pval of the test is %4.3f\n", pval);


%sol is with ttest - right tail test
%the quantiles are following the student's law
%2a. 2 tailed tests for comaring variances
%2b. right tailed test for the difference of min






