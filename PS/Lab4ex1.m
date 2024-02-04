p = input("Give a number between 0 and 1: ");
N = input("Give the number of simuations: ");
U = rand(1,N);
X = (U>p);
U_X = [0 1];
n_x = hist(X, length(U_X));
rel_freq = n_x/N;
