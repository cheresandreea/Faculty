N = input("Give the number of simulations: ");
p = input("Give a number between 0 and 1: ");
n = input("Give the number of trials: ");

U = rand(n,N);
X = sum(U<p);
k = [0:1:n];
p_k = binopdf(k,n,p);
U_X = unique(X);

n_x = hist(X, length(U_X));
rel_freq = n_x/N;

clf

plot(U_X, rel_freq, '*', k, p_k, 'ro');
