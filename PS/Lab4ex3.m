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
